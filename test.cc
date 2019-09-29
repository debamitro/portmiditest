#include "portmidi.h"
#include "porttime.h"

#include <iostream>
#include <cstdlib>
#include <vector>

// Based on portmidi/pm_test/test.c

void doit ()
{
    Pm_Initialize ();

    int id = Pm_GetDefaultOutputDeviceID ();
    if (id == pmNoDevice)
    {
        std::cout << "No MIDI output device found\n";
        return;
    }


    std::cout << "Default output device is " << id << "\n";

    /* It is recommended to start timer before PortMidi */
    Pt_Start(1, 0, 0);

    /* open output device -- since PortMidi avoids opening a timer
       when latency is zero, we will pass in a NULL timer pointer
       for that case. If PortMidi tries to access the time_proc,
       we will crash, so this test will tell us something. */
    PmStream * midi;
    int32_t latency = 500; // unit is ms
#define INPUT_BUFFER_SIZE 100
#define OUTPUT_BUFFER_SIZE 0
#define DRIVER_INFO NULL
#define TIME_PROC ((int32_t (*)(void *)) Pt_Time)
#define TIME_INFO nullptr

    Pm_OpenOutput(&midi,
                  id,
                  DRIVER_INFO,
                  OUTPUT_BUFFER_SIZE,
                  (latency == 0 ? NULL : TIME_PROC),
                  (latency == 0 ? NULL : TIME_INFO),
                  latency);
    std::cout << "Midi Output opened with " << latency << "ms latency.\n";

    std::cout << "Press enter to proceed\n";

    std::getchar ();

    PmEvent buffer[200];

    buffer[0].timestamp = TIME_PROC(TIME_INFO);
    buffer[0].message = Pm_Message(0xC0, 0, 0);
    Pm_Write(midi, buffer, 1);

    std::cout << "Press enter to send notes\n";
    std::getchar ();

    std::vector <int> events = {57,60,62,64,65,64,62,60,
                                57,60,62,64,65,64,62,60,
                                57,60,62,64,65,64,62,60,
                                57,60,62,64,65,64,62,60,
                                62,64,65,64,62,60,
                                62,64,65,64,62,60,
                                62,64,65,64,62,60,
                                62,64,65,64,62,60,
                                62,64,65,64,62,60,62,60};

    int messageItr = 0;
    int duration = 35;
    int eventItr = 0;
    for (auto event : events)
    {
        int strength = 70;

        if (eventItr == 8 ||
            eventItr == 16 ||
            eventItr == 24 ||
            eventItr == 32 ||
            eventItr == 38 ||
            eventItr == 44 ||
            eventItr == 50 ||
            eventItr == 56)
        {
            strength = 100;
        }

        buffer[messageItr].timestamp = TIME_PROC(TIME_INFO) + messageItr * duration;
        buffer[messageItr].message = Pm_Message (0x90, event + 2, strength);

        buffer[messageItr+1].timestamp = TIME_PROC(TIME_INFO) + (messageItr + 1) * duration;
        buffer[messageItr+1].message = Pm_Message (0x90, event + 2, 0);

        messageItr += 2;
        ++eventItr;
    }

    Pm_Write(midi, buffer, messageItr);

    buffer[0].timestamp = TIME_PROC(TIME_INFO) + messageItr * duration;
    buffer[0].message = Pm_Message (0x90, 60, 100);

    buffer[1].timestamp = TIME_PROC(TIME_INFO) + (messageItr * duration) + 1000;
    buffer[1].message = Pm_Message (0x90, 60, 0);

    Pm_Write(midi, buffer, 2);

    std::cout << "Press enter to quit\n";
    std::getchar ();

    Pm_Close(midi);
    Pm_Terminate();

    std::cout << "Midi Output closed\n";
}

int main (int argc, char ** argv)
{
    doit ();
    return 0;
}

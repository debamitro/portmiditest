#include "portmidi.h"
#include "porttime.h"

#include <iostream>
#include <cstdlib>

void doit ()
{
    Pm_Initialize ();

    /* It is recommended to start timer before PortMidi */
    Pt_Start(1, 0, 0);

    /* open output device -- since PortMidi avoids opening a timer
       when latency is zero, we will pass in a NULL timer pointer
       for that case. If PortMidi tries to access the time_proc,
       we will crash, so this test will tell us something. */
    PmStream * midi;
    int i = 1;
    int32_t latency = 500; // unit is ms
#define INPUT_BUFFER_SIZE 100
#define OUTPUT_BUFFER_SIZE 0
#define DRIVER_INFO NULL
#define TIME_PROC ((int32_t (*)(void *)) Pt_Time)
#define TIME_INFO nullptr

    Pm_OpenOutput(&midi,
                  i,
                  DRIVER_INFO,
                  OUTPUT_BUFFER_SIZE,
                  (latency == 0 ? NULL : TIME_PROC),
                  (latency == 0 ? NULL : TIME_INFO),
                  latency);
    std::cout << "Midi Output opened with " << latency << "ms latency.\n";

    std::cout << "Press enter to proceed\n";

    std::getchar ();

    PmEvent buffer[10];

    buffer[0].timestamp = TIME_PROC(TIME_INFO);
    buffer[0].message = Pm_Message(0xC0, 0, 0);
    Pm_Write(midi, buffer, 1);

    std::cout << "Press enter to send note on\n";
    std::getchar ();

    buffer[0].timestamp = TIME_PROC(TIME_INFO);
    buffer[0].message = Pm_Message(0x90, 60, 100);
    Pm_Write(midi, buffer, 1);

    std::cout << "Press enter to send note off\n";
    std::getchar ();

    buffer[0].timestamp = TIME_PROC(TIME_INFO);
    buffer[0].message = Pm_Message(0x90, 60, 0);
    Pm_Write(midi, buffer, 1);

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

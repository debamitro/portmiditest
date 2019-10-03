#include "MusicEvent.hh"

#include <vector>

std::vector <MusicEvent> events = {
    Ma(70,100),Ga(),Re(),Sa(),_Ni(),Sa(),Re(),Ma(),
    Pa(),Ni(),Sa(),Re_(),Sa(),Ni1(),Dha(),Pa(),
    Ma(70,100),Ga(),Re(),Sa(),_Ni(),Sa(),Re(),Ma(),
    Pa(),Ni(),Sa(),Re_(),Sa(),Ni(),Sa(1000)
};

std::vector <MusicEvent> get_composition ()
{
    return events;
}

#include "MusicEvent.hh"

#include <vector>

std::vector <MusicEvent> events = {
    _Ni(70,100),Re(),Ga(),Ma2(),Pa(),Ma2(),Ga(),Re(),
    _Ni(70,100),Re(),Ga(),Ma2(),Pa(),Ma2(),Ga(),Re(),
    _Ni(70,100),Re(),Ga(),Ma2(),Pa(),Ma2(),Ga(),Re(),
    _Ni(70,100),Re(),Ga(),Ma2(),Pa(),Ma2(),Ga(),Re(),
    Ga(70,100),Ma2(),Pa(),Ma2(),Ga(),Re(),
    Ga(70,100),Ma2(),Pa(),Ma2(),Ga(),Re(),
    Ga(70,100),Ma2(),Pa(),Ma2(),Ga(),Re(),
    Ga(70,100),Ma2(),Pa(),Ma2(),Ga(),Re(),
    Ga(70,100),Ma2(),Pa(),Ma2(),Pa(),Ma2(),Ga(),Re(),
    Sa(1000)
};

std::vector <MusicEvent> get_composition ()
{
    return events;
}

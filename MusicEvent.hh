#ifndef MUSIC_EVENT_HH
#define MUSIC_EVENT_HH

class MusicEvent
{
public:
    MusicEvent (int note, int durationInMs, int strength) :
        note_ (note),
        duration_ (durationInMs),
        strength_ (strength) {}
    ~MusicEvent () = default;

    int note () const
    {
        return note_;
    }

    int durationInMs () const
    {
        return duration_;
    }

    int strength () const
    {
        return strength_;
    }

protected:
    static const int SA = 60;
    static const int DEFAULT_DURATION = 70;
    static const int DEFAULT_STRENGTH = 70;
private:

    int note_;
    int duration_;
    int strength_;
};

class Sa : public MusicEvent
{
public:
    Sa (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA, duration, strength) {}
};

class _Ni : public MusicEvent
{
public:
    _Ni (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA-1, duration, strength) {}
};

class Re : public MusicEvent
{
public:
    Re (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+2, duration, strength) {}
};

class Ga : public MusicEvent
{
public:
    Ga (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+4, duration, strength) {}
};

class Ma : public MusicEvent
{
public:
    Ma (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+5, duration, strength) {}
};

class Ma2 : public MusicEvent
{
public:
    Ma2 (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+6, duration, strength) {}
};

class Pa : public MusicEvent
{
public:
    Pa (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+7, duration, strength) {}
};

class Dha : public MusicEvent
{
public:
    Dha (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+9, duration, strength) {}
};

class Ni1 : public MusicEvent
{
public:
    Ni1 (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+10, duration, strength) {}
};

class Ni : public MusicEvent
{
public:
    Ni (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+11, duration, strength) {}
};

class Sa_ : public MusicEvent
{
public:
    Sa_ (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+12, duration, strength) {}
};

class Re_ : public MusicEvent
{
public:
    Re_ (int duration = DEFAULT_DURATION,
        int strength = DEFAULT_STRENGTH) :
        MusicEvent (SA+14, duration, strength) {}
};

#endif

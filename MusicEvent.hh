#ifndef MUSIC_EVENT_HH
#define MUSIC_EVENT_HH

class MusicEvent
{
public:
    MusicEvent (int note, int durationInMs) :
        note_ (note),
        duration_ (durationInMs) {}
    ~MusicEvent () = default;

    int note () const
    {
        return note_;
    }

    int durationInMs () const
    {
        return duration_;
    }

protected:
    static const int SA = 60;
    static const int DEFAULT_DURATION = 70;

private:

    int note_;
    int duration_;
};

class Sa : public MusicEvent
{
public:
    Sa (int duration = DEFAULT_DURATION) :
        MusicEvent (SA, duration) {}
};

class _Ni : public MusicEvent
{
public:
    _Ni (int duration = DEFAULT_DURATION) :
        MusicEvent (SA-1, duration) {}
};

class Re : public MusicEvent
{
public:
    Re (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+2, duration) {}
};

class Ga : public MusicEvent
{
public:
    Ga (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+4, duration) {}
};

class Ma : public MusicEvent
{
public:
    Ma (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+5, duration) {}
};

class Ma2 : public MusicEvent
{
public:
    Ma2 (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+6, duration) {}
};

class Pa : public MusicEvent
{
public:
    Pa (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+7, duration) {}
};

class Dha : public MusicEvent
{
public:
    Dha (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+9, duration) {}
};

class Ni : public MusicEvent
{
public:
    Ni (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+11, duration) {}
};

class Sa_ : public MusicEvent
{
public:
    Sa_ (int duration = DEFAULT_DURATION) :
        MusicEvent (SA+12, duration) {}
};

#endif


PORTMIDI_HOME :=
PORTMIDI_LIBRARY = $(PORTMIDI_HOME)/pm_common/libportmidi_s.a
FRAMEWORK_ARGS := -framework CoreAudio -framework CoreMIDI -framework CoreFoundation -framework CoreServices

all: comp1 comp2

clean:
	rm -f *.o comp1 comp2 > /dev/null

comp1: test.o composition1.o $(PORTMIDI_LIBRARY)
	$(CXX) -Wall -o $@ $^ $(FRAMEWORK_ARGS)

comp2: test.o composition2.o $(PORTMIDI_LIBRARY)
	$(CXX) -Wall -o $@ $^ $(FRAMEWORK_ARGS)

%.o: %.cc
	$(CXX) -std=c++17 -c -Wall -o $@ -I $(PORTMIDI_HOME)/pm_common -I $(PORTMIDI_HOME)/porttime $<

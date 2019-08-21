
PORTMIDI_HOME :=

all: test

clean:
	rm -f *.o test > /dev/null

test: test.o
	$(CXX) -Wall -o $@ $< $(PORTMIDI_HOME)/pm_common/libportmidi_s.a -framework CoreAudio -framework CoreMIDI -framework CoreFoundation -framework CoreServices

%.o: %.cc
	$(CXX) -std=c++17 -c -Wall -o $@ -I $(PORTMIDI_HOME)/pm_common -I $(PORTMIDI_HOME)/porttime $<

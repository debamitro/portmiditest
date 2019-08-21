
PORTMIDI_HOME :=

all: test

clean:
	rm -f *.o test >2 /dev/null

test: test.o
	$(CXX) -Wall -o $@ $< $(PORTMIDI_HOME)/pm_common/libportmidi_s.a /System/Library/Frameworks/CoreAudio.framework/CoreAudio /System/Library/Frameworks/CoreMIDI.framework/CoreMIDI /System/Library/Frameworks/CoreFoundation.framework/CoreFoundation /System/Library/Frameworks/CoreServices.framework/CoreServices
%.o: %.cc
	$(CXX) -std=c++17 -c -Wall -o $@ -I $(PORTMIDI_HOME)/pm_common -I $(PORTMIDI_HOME)/porttime $<

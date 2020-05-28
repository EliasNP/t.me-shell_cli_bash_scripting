# Makefile for pastebincl (command-line pastebin) by BASTIAN Théophile (aka Tobast)

ENC_KEY=`python genkey.py`

CXX=g++
CXXFLAGS=-Wall -Werror -O2
CXXLIBS=-lcurl
TARGET=pastebincl
OBJS=CurlPost.o func.o main.o ParameterRead.o ConfigRead.o

all: inputdevcode checkdevcode $(TARGET)
	cp $(TARGET) ../

inputdevcode:
	@if [[ ! -f data_devcode.h ]]; then cp data_devcode_default.h data_devcode.h; fi
	@if (( `cat data_devcode.h | grep -c '#define DEVELOPPER_CODE ""'` != 0 )); then echo -e "\n" ; bash input_devcode.sh; fi

checkdevcode:
	@if [[ ! -f data_devcode.h ]]; then echo -e "\nERROR: No 'data_devcode.h' file (common error). Please read \"COMPILE.txt\" for more help.\n" ; false ; fi
	@if (( `cat data_devcode.h | grep -c '#define DEVELOPPER_CODE ""'` != 0 )); then echo -e "\nERROR: 'DEVELOPPER_CODE' undefined (common error). Please read \"COMPILE.txt\" for more help.\n" ; false ; fi

#### Useful while developping. To enable it, uncomment and add it as a dependence of 'all' ####
#makeuser:
#	./pastebincl --usergen < userinput &> /dev/null

$(TARGET): $(OBJS)
	$(CXX) $(CXXLIBS) $^ $(CXXFLAGS) -o $@

ConfigRead.o: ConfigRead.cpp
	$(CXX) $(CXXLIBS) -c $< $(CXXFLAGS) -o $@ -DENCODING_KEY=\"${ENC_KEY}\"

%.o: %.cpp
	$(CXX) $(CXXLIBS) -c $< $(CXXFLAGS) -o $@


.PHONY: clean

clean:
	rm -f *.o

mrproper: clean
	rm -f $(TARGET)


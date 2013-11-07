CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=CString.cpp  CXKUsername.cpp  main.cpp  MD5.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PREFIX=/usr/bin
SCRIPT=./auto
INSTALLDIR=/usr/share/netkeeper
INFOFILE=/usr/share/netkeeper/userinfo
EXECUTABLE=zshanxun

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp .o:
	$(CC) $(CFLAGS) $< -o $@

establish:
	nm-connection-editor &

install:establish
	chmod +x $(EXECUTABLE)
	cp $(EXECUTABLE) $(PREFIX)
	cp $(SCRIPT) $(PREFIX)
	mkdir -p $(INSTALLDIR)
	touch $(INFOFILE)

clean:
	rm *.o zshanxun 

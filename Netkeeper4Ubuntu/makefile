CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=CString.cpp  CXKUsername.cpp  MD5.cpp  dail.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PREFIX=/usr/bin
SCRIPT=./netkeeper
INSTALLDIR=/usr/share/netkeeper
INFOFILE=/usr/share/netkeeper/userinfo
EXECUTABLE=dialnetkeeper
CONF=./PPPOE.conf
INTERFACE=/etc/network/interfaces

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp .o:
	$(CC) $(CFLAGS) $< -o $@

install: ni
	chmod +x $(EXECUTABLE)
	chmod +x $(SCRIPT)
	cp $(EXECUTABLE) $(PREFIX)
	cp $(SCRIPT) $(PREFIX)
	cp $(CONF) $(PREFIX)
	mkdir -p $(INSTALLDIR)
	touch $(INFOFILE)

ni:
#network interface
	mv /etc/network/interfaces /etc/network/interfaces.bak
	echo "auto lo" > $(INTERFACE)
	echo "iface lo inet loopback " >> $(INTERFACE)
	echo "" >> $(INTERFACE)
	echo "iface dsl-provider inet ppp" >> $(INTERFACE)
	echo "pre-up /sbin/ifconfig eth0 up # line maintained by pppoeconf" >> $(INTERFACE)
	echo "provider dsl-provider" >> $(INTERFACE)
	echo "" >> $(INTERFACE)
	echo "auto eth0" >> $(INTERFACE)
	echo "iface eth0 inet dhcp" >> $(INTERFACE)

clean:
	rm *.o $(EXECUTABLE)

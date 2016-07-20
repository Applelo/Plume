##
##
##	Author: Applelo
##		  Samir88Nasri
##
##
TARGET = Plume
OBJS   = src/Buttons.o src/Engine.o src/Font.o src/main.o src/Menu.o src/Timer.o \
img/plume.o img/grid.o img/cloud.o img/block.o img/grass.o


LIBS = -lvita2d -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub \
	-lSceCommonDialog_stub -lUVLoader_stub -lSceHttp_stub -lSceNetCtl_stub -lSceNet_stub \
	-lfreetype -lpng -lz -lm -lSceTouch_stub -lc -lstdc++ -lgcc

VITASDK = ~/gcc-arm-vita-eabi-4_9-2015q3/arm-vita-eabi/
PREFIX  = arm-vita-eabi
CC := arm-vita-eabi-gcc
CXX := arm-vita-eabi-g++
STRIP := arm-vita-eabi-strip
READELF = $(PREFIX)-readelf
OBJDUMP = $(PREFIX)-objdump
CFLAGS  = -Wl,-q -Wall -O3 -I$(VITASDK)/include -L$(VITASDK)/lib
CXXFLAGS= $(CFLAGS) -std=c++11
ASFLAGS = $(CFLAGS)


all: $(TARGET).velf

$(TARGET).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.png
		$(PREFIX)-ld -r -b binary -o $@ $^

$(TARGET).velf: $(TARGET).elf
	$(STRIP) -g $<
	vita-elf-create $< $@

clean:
	-rm -f $(TARGET).velf $(TARGET).elf $(OBJS)

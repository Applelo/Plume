##
##
##	Author: Applelo
##		  Samir88Nasri
##
##

TITLE_ID = PLUM00001
TARGET = Plume
OBJS   = src/Buttons.o src/Engine.o src/Font.o src/main.o src/Menu.o src/Timer.o \
src/Plume.o src/Grid.o src/Grass.o img/plume.o img/grid.o img/cloud.o img/block.o \
img/grass.o


LIBS = -lvita2d -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub \
	-lSceCommonDialog_stub -lUVLoader_stub -lSceHttp_stub -lSceNetCtl_stub \
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

all: $(TARGET).vpk

%.vpk: eboot.bin
		vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
		vita-pack-vpk -s param.sfo -b eboot.bin $@

%.o: %.png
		$(PREFIX)-ld -r -b binary -o $@ $^

eboot.bin: $(TARGET).velf
			vita-make-fself $< $@

%.velf: %.elf
			vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	-rm -f $(TARGET).velf $(TARGET).elf $(OBJS) \
	eboot.bin param.sfo $(TARGET).vpk

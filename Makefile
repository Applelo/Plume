##
##
##	Author: Applelo
##		  Samir88Nasri
##		    Mister_Alex
##
##

PSVITAIP = 192.168.0.14

TITLE_ID = PLUM00001
TARGET = Plume
OBJS   = src/Buttons.o src/Engine.o src/Font.o src/main.o src/Menu.o src/Timer.o \
src/Plume.o src/Grid.o src/Grass.o src/Cloud.o src/Block.o src/Splash.o \
img/plume.o img/grid.o img/cloud.o img/block.o img/grass.o img/pause.o img/geki.o


LIBS = -lSceDisplay_stub -lSceGxm_stub -lvita2d \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub \
	-lSceCommonDialog_stub -lSceHttp_stub -lSceNetCtl_stub \
	-lfreetype -lpng -lz -lm -lSceTouch_stub -lc -lstdc++ -lgcc

VITASDK = ~/gcc-arm-vita-eabi-4_9-2015q3/arm-vita-eabi/
PREFIX  = arm-vita-eabi
CC := arm-vita-eabi-gcc
CXX := arm-vita-eabi-g++
STRIP := arm-vita-eabi-strip
READELF = $(PREFIX)-readelf
OBJDUMP = $(PREFIX)-objdump
CFLAGS  = -Wl,-q -Wall -fno-lto -I$(VITASDK)/include -L$(VITASDK)/lib
CXXFLAGS= $(CFLAGS) -std=c++11
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -d PARENTAL_LEVEL=1 -s APP_VER=01.00 -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin $@ \
	--add sce_sys/icon0.png=sce_sys/icon0.png \
	--add sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png \
	--add sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png \
	--add sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

eboot.bin: $(TARGET).velf
	vita-make-fself -s $< $@


%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	-rm -f $(TARGET).velf $(TARGET).elf $(OBJS) \
	eboot.bin param.sfo $(TARGET).vpk

send: eboot.bin
		curl -T eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/
		@echo "Sent."

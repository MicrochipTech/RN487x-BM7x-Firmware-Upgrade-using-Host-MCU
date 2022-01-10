include	$(ROOT)/../defines.mk

_VPATH	:= .

include $(ROOT)/eth/source/Makefile.inc
include $(ROOT)/can/source/Makefile.inc
include $(ROOT)/timer/source/Makefile.inc
include $(ROOT)/reset/source/Makefile.inc
include $(ROOT)/pcache/source/Makefile.inc
include $(ROOT)/osc/source/Makefile.inc
include $(ROOT)/int/source/Makefile.inc
include $(ROOT)/incap/source/Makefile.inc
include $(ROOT)/rtcc/source/Makefile.inc
include $(ROOT)/spi/source/Makefile.inc
include $(ROOT)/spi/legacy/Makefile.inc
include $(ROOT)/pmp/source/Makefile.inc
include $(ROOT)/power/source/Makefile.inc
include $(ROOT)/nvm/source/Makefile.inc
include $(ROOT)/dma/source/Makefile.inc
include $(ROOT)/dma/legacy/Makefile.inc
include $(ROOT)/ports/source/Makefile.inc
include $(ROOT)/uart/source/Makefile.inc
include $(ROOT)/uart/legacy/Makefile.inc
include $(ROOT)/i2c/legacy/Makefile.inc
include $(ROOT)/i2c/source/Makefile.inc

vpath	%.c		$(_VPATH)
vpath	%.cc		$(_VPATH)
vpath	%.s		$(_VPATH)
vpath	%.sx		$(_VPATH)
vpath	%.S		$(_VPATH)
vpath	%.h		$(_VPATH)
vpath	Makefile	$(_VPATH)

CPPFLAGS += -I$(ROOT)/include -I$(ROOT)/../include
CFLAGS += -I$(ROOT)/include -I$(ROOT)/../include
ASFLAGS += $(VAR)

all: libmchp_peripheral.a

libmchp_peripheral.a: $(LIBOBJ)
	$(STRIP) $(STRIPFLAGS) $(LIBOBJ)
	$(AR) rcs $@ $(LIBOBJ)

$(PLIB)-all:  $(PROCOBJ)
	$(AR) rcs $(PLIB) $(PROCOBJ)

$(PLIB)-install: $(PLIB)-all
	mkdir -p $(LIBDESTDIR)/$(SUBDIR)
	rm -f $(LIBDESTDIR)/$(SUBDIR)/$(PLIB)
	cp -p $(PLIB) $(LIBDESTDIR)/$(SUBDIR)/$(PLIB)

$(PLIB)-clean:
	rm -f $(PLIB)

install: libmchp_peripheral.a
	mkdir -p $(LIBDESTDIR)/$(SUBDIR)
	rm -f $(LIBDESTDIR)/$(SUBDIR)/libmchp_peripheral.a
	cp -p libmchp_peripheral.a $(LIBDESTDIR)/$(SUBDIR)/libmchp_peripheral.a

clean:
	rm -f libmchp_peripheral.a *.o core* *~

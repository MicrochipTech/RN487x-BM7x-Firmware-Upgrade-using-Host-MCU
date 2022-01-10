#
# Makefile for PIC32-MX libp.a
#
# This makefile will only work with GNU make
#

ROOT := $(shell pwd)

include $(ROOT)/../defines.mk

MAKEFILE = -f $(ROOT)/libp.mk

# Processor lists for 1xx Devices:
PROCESSORS_11X := $(subst P32MX11,32MX11,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx11\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_12X := $(subst P32MX12,32MX12,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx12\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_13X := $(subst P32MX13,32MX13,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx13\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_15X := $(subst P32MX15,32MX15,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx15\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_17X := $(subst P32MX17,32MX17,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx17\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

#Processor lists for 2xx Devices
PROCESSORS_21X := $(subst P32MX21,32MX21,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx21\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_22X := $(subst P32MX22,32MX22,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx22\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_23X := $(subst P32MX23,32MX23,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx23\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_25X := $(subst P32MX25,32MX25,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx25\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_27X := $(subst P32MX27,32MX27,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx27\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

#Processor lists for 3xx Devices
PROCESSORS_32X := $(subst P32MX32,32MX32,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx32\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_33X := $(subst P32MX33,32MX33,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx33\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_34X := $(subst P32MX34,32MX34,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx34\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_35X := $(subst P32MX35,32MX35,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx35\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_36X := $(subst P32MX36,32MX36,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx36\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_37X := $(subst P32MX37,32MX37,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx37\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

#Processor lists for 4xxDevices
PROCESSORS_42X := $(subst P32MX42,32MX42,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx42\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_43X := $(subst P32MX43,32MX43,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx43\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_44X := $(subst P32MX44,32MX44,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx44\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_45X := $(subst P32MX45,32MX45,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx45\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_46X := $(subst P32MX46,32MX46,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx46\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_47X := $(subst P32MX47,32MX47,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx47\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))


#Processor lists for 5xxDevices
PROCESSORS_53X := $(subst P32MX53,32MX53,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx53\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_55X := $(subst P32MX55,32MX55,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx55\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_56X := $(subst P32MX56,32MX56,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx56\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))

PROCESSORS_57X := $(subst P32MX57,32MX57,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx57\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))


#Processor lists for 6xxDevices
PROCESSORS_6XX := $(subst P32MX6,32MX6,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx6\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))


#Processor lists for 7xxDevices
PROCESSORS_7XX := $(subst P32MX7,32MX7,$(basename $(notdir $(shell find $(ROOT)/../include/proc -name p32mx7\*.h ! -name p32mxgeneric.h | tr [:lower:] [:upper:]))))


all install:
	@$(MAKE) doall T=$@

install-baseline:
	@$(MAKE) doall T=install

install-src:
	mkdir -p $(TGTLIBSRC)/peripheral
	cp Makefile $(TGTLIBSRC)/peripheral
	cp libp.mk $(TGTLIBSRC)/peripheral
	 $(foreach dir,$(shell find . -type d  | grep -v .svn | grep -v OBJ), \
	   mkdir -p $(TGTLIBSRC)/peripheral/$(dir); \
	   cp $(dir)/* ${TGTLIBSRC}/peripheral/$(dir) 2>>/dev/null; )


install-proc:

clean:
	@$(MAKE) doall T=$@
	[ ! -d OBJ ] || rm -r OBJ
	rm -f *[~#]

doall: dodir
# Build libraries for 1xx devices - broken into subsets
# Build libraries for 11X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
				$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
				$(foreach P,$(PROCESSORS_11X), \
					PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
					pdir=OBJ/$$rdir/$P; \
					[ -d $$pdir ] || mkdir -p $$pdir; \
					$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		else \
		    echo "Skipping -mmicromips for $$flags"; \
		fi; )

# Build libraries for 12X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
				$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
				$(foreach P,$(PROCESSORS_12X), \
					PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
					pdir=OBJ/$$rdir/$P; \
					[ -d $$pdir ] || mkdir -p $$pdir; \
					$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		else \
		    echo "Skipping -mmicromips for $$flags"; \
		fi; )

# Build libraries for 13X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
				$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
				$(foreach P,$(PROCESSORS_13X), \
					PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
					pdir=OBJ/$$rdir/$P; \
					[ -d $$pdir ] || mkdir -p $$pdir; \
					$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		else \
		    echo "Skipping -mmicromips for $$flags"; \
		fi; )

# Build libraries for 15X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
				$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
				$(foreach P,$(PROCESSORS_15X), \
					PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
					pdir=OBJ/$$rdir/$P; \
					[ -d $$pdir ] || mkdir -p $$pdir; \
					$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		else \
		    echo "Skipping -mmicromips for $$flags"; \
		fi; )

# Build libraries for 17X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
				$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
				$(foreach P,$(PROCESSORS_17X), \
					PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
					pdir=OBJ/$$rdir/$P; \
					[ -d $$pdir ] || mkdir -p $$pdir; \
					$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		else \
		    echo "Skipping -mmicromips for $$flags"; \
		fi; )


# Build libraries for 2xx devices - broken into subsets
# Build libraries for 21X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_21X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 22X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_22X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 23X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_23X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 25X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_25X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 27X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_27X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )


# Build libraries for 3xx devices - broken into subsets
# Build libraries for 32x devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_32X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 33x devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_33X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 34x devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_34X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 35x devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_35X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 36x devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_36X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 37x devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_37X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )


# Build libraries for 4xx devices - broken into subsets
# Build libraries for 42X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_42X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 43X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_43X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 44X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_44X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 45X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_45X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 46X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_46X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 47X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_47X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )


# Build libraries for 5xx devices - broken into subsets
# Build libraries for 53X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_53X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 55X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_55X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 56X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_56X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )

# Build libraries for 57X devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_57X), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )


# Build libraries for 6XX devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_6XX), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )


# Build libraries for 7XX devices
	$(foreach ML,$(shell $(CC) --print-multi-lib), \
		set -e; \
		rdir=`echo "$(ML)" | sed -e 's/;.*$$//'`; \
		dir=OBJ/$$rdir; \
		[ -d $$dir ] || mkdir -p $$dir; \
		flags=`echo "$(ML)" | sed -e 's/^[^;]*;//' -e 's/@/ -/g'`; \
		if echo "$$flags" | egrep -v 'mmicromips' | egrep -v '$(SKIPARCHS)' >/dev/null; then \
			if echo "$$flags" | grep 'mips16' >/dev/null; then \
				makevar="CODESIZEOPT=1"; \
			else \
				makevar=""; \
			fi; \
			$(MAKE) -C $$dir $(MAKEFILE) $$makevar VAR="$$flags" SUBDIR=$$rdir $F $T; \
			$(foreach P,$(PROCESSORS_7XX), \
				PROCESSOR_LIB=${patsubst %,libmchp_peripheral_%.a, $(P)}; \
				pdir=OBJ/$$rdir/$P; \
				[ -d $$pdir ] || mkdir -p $$pdir; \
				$(MAKE) -C $$pdir $(MAKEFILE) $$makevar VAR="$$flags -mprocessor=$P" SUBDIR=$$rdir PLIB=$$PROCESSOR_LIB $F $$PROCESSOR_LIB-$T; ) \
		fi; )


doone: dodir
	set -e; \
	rdir=`$(CC) --print-multi-dir $(VAR)`; \
	dir=OBJ/$$rdir; \
	[ -d $$dir ] || mkdir -p $$dir; \
	$(MAKE) -C $$dir $(MAKEFILE) VAR="$(VAR)" SUBDIR=$$rdir $F $T

dodir: Makefile $(ROOT)/libp.mk
	mkdir -p OBJ

.PHONY: all install clean doall doone dodir install-baseline install-proc

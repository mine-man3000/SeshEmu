CC=gcc
LD=gcc
CFLAGS= -g
LDFLAGS=
override CFILES    := $(shell cd src && find . -type f -name '*.c')
override OBJ_C     := $(subst .c,.o,$(CFILES))
override OBJ       := $(subst ./,build/,$(OBJ_C))
vpath %.c 

all: semu

test:
	$(info $(CFILES) ==> $(OBJ))

semu: $(OBJ)
	@mkdir -p $(@D)
	@$(info $s    LD $< ==> $@)
	@$(LD) $(LDFLAGS) $< -o $@

build/%.o: src/%.c
	@mkdir -p $(@D)
	@$(info $s    CC $< ==> $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
CC := gcc
CFLAGS := -o
SOURCEFIES := handleInputs.c voltageDiv.c
LDFLAGS := -lncurses

all: VD

VD: $(patsubst %.c,EEFunctions/%.o,$(SOURCEFILES))
    $(CC) $(CFLAGS) $^ $(LDFLAGS)

test: VD
    @echo
    @echo "Testing one  missing value:"
    @echo
    .VD 0 5 10 10
    .VD 10 0 10 10
    .VD 10 5 0 10
    .VD 10 5 10 0
    @echo
    @echo "Testing two valid missing values:"
    @echo
    .VD 10 5 0 0
    .VD 0 0 10 10
    @echo
    @echo "Testing two invalid missing values:"
    @echo
    .VD 0 5 10 0
    .VD 0 5 0 10
    .VD 10 0 10 0
    .VD 10 0 0 10
    @echo
    @echo "Testing three missing values:"
    @echo
    .VD 10 0 0 0
    .VD 0 5 0 0
    .VD 0 0 10 0
    .VD 0 0 0 10
    @echo
    @echo "Testing four missing values:"
    @echo
    .VD 0 0 0 0

%.o: %.c Makefile
    $(CC) -o $@ -c $< $(CFLAGS)

clean:
    rm -f *~ EEFunctions/*~ EEFunctions/*.o VD
    rm -f core core.* vgcore.*

.PHONY: all test clean

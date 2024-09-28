CC := gcc
CFLAGS := -o
SOURCEFILES := handleInputs.c voltageDiv.c
VDIR := -iquote ~/AmplifierAnalysisAutomation/EEFunctions

all:
	make VD

VD:
	$(CC) $(VDIR) $(SOURCEFILES) $(CFLAGS) VD.o

test: VD
	@echo
	@echo "1.) Integer values"
	@echo
	@echo "Testing one  missing value:"
	@echo
	./VD.o 0 5 10 10
	./VD.o 10 0 10 10
	./VD.o 10 5 0 10
	./VD.o 10 5 10 0
	@echo
	@echo "Testing two valid missing values:"
	@echo
	./VD.o 10 5 0 0
	./VD.o 0 0 10 10
	@echo
	@echo "Testing two invalid missing values:"
	@echo
	./VD.o 0 5 10 0
	./VD.o 0 5 0 10
	./VD.o 10 0 10 0
	./VD.o 10 0 0 10
	@echo
	@echo "Testing three missing values:"
	@echo
	./VD.o 10 0 0 0
	./VD.o 0 5 0 0
	./VD.o 0 0 10 0
	./VD.o 0 0 0 10
	@echo
	@echo "Testing four missing values:"
	@echo
	./VD.o 0 0 0 0
	@echo
	@echo
	@echo "2.) Floating-point / Double values"
	@echo
	./VD.o 0 13.2455255602 6.6971 1050.1
	./VD.o 13.33 0 6.6971 1050.1
	./VD.o 13.33 13.2455255602 0 1050.1
	./VD.o 13.33 13.2455255602 6.6971 0

%.o: %.c Makefile
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f VD.o

.PHONY: all test clean

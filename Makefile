CC := gcc
CFLAGS := -Wall
RM := rm -rf

CHECK_TARGET := check_numerals

SRCDIR := src
TESTDIR := test
BINDIR := bin

all: check

check: $(TESTDIR)/$(CHECK_TARGET).c | $(BINDIR)
	$(CC) $(CFLAGS) $(SRCDIR)/numerals.c $(TESTDIR)/$(CHECK_TARGET).c -o $(BINDIR)/$(CHECK_TARGET) `pkg-config --libs check`
	./$(BINDIR)/$(CHECK_TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: clean
clean:
	$(RM) $(BINDIR)

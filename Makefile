CC=gcc
TARGET=zoo_tycoon_patcher bobo2_patcher

BUILDDIR=build

CFLAGS=

############################################

TARGET:=$(patsubst %,$(BUILDDIR)/%,$(TARGET))

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	@mkdir $(BUILDDIR)

# Link all objects and compile executable.
$(BUILDDIR)/zoo_tycoon_patcher: zoo_tycoon/zoo_tycoon_patcher.c
	$(CC) $(CFLAGS) -o $@ $<

$(BUILDDIR)/bobo2_patcher: bobo2/bobo2_patcher.c
	$(CC) $(CFLAGS) -o $@ $<

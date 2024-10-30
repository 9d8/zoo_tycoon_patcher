CC=gcc
TARGET=zoo_tycoon_patcher

CFLAGS=

############################################

# Link all objects and compile executable.
$(TARGET): zoo_tycoon_patcher.c
	$(CC) $(CFLAGS) -o $@ $<

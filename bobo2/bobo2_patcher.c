#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {

    if(argc < 2) {
        printf("usage: %s [path to bobo2.exe]\n", argv[0]);
        return 1;
    }

    char* bobo2_exe_path = argv[1];
    
    FILE* bobo2_exe = fopen(bobo2_exe_path, "r+");
    if(bobo2_exe == NULL) {
        printf("error: failed to open '%s' -- %s\n", bobo2_exe_path, strerror(errno));
        return 1;
    }

    // Seek to offset of the "CD-ROM check" function call handler.
    fseek(bobo2_exe, 0x422968, SEEK_SET);

    // Overwrite the instructions with 2 nop instructions, forcing the check to
    // always succeed.
    char instructions[2];
    memset(instructions, 0x90, sizeof(instructions));
    fwrite(instructions, sizeof(instructions), 1, bobo2_exe);

    fclose(bobo2_exe);
    printf("'%s' successfully patched!\n", bobo2_exe_path);
    return 0;
}

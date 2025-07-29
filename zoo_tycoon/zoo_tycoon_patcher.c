#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {

    if(argc < 2) {
        printf("usage: %s [path to zoo.exe]\n", argv[0]);
        return 1;
    }

    char* zoo_exe_path = argv[1];
    
    FILE* zoo_exe = fopen(zoo_exe_path, "r+");
    if(zoo_exe == NULL) {
        printf("error: failed to open '%s' -- %s\n", zoo_exe_path, strerror(errno));
        return 1;
    }

    // Seek to offset of the "CD-ROM check" function call handler.
    fseek(zoo_exe, 0xBC946, SEEK_SET);

    // Overwrite the instructions with 8 nop instructions, forcing the check to
    // always succeed.
    char instructions[8];
    memset(instructions, 0x90, sizeof(instructions));
    fwrite(instructions, sizeof(instructions), 1, zoo_exe);

    fclose(zoo_exe);
    printf("'%s' successfully patched!\n", zoo_exe_path);
    return 0;
}

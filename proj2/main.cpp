#include <stdio.h>
#include <iostream>
#include <fstream>

#include "../ext/AFL/afl-record-compat.h"

__AFL_FUZZ_INIT();

static int* ptr;

void function_to_fuzz(char *str) {
    if (str[0] == 'C')
        if (str[1] == 'R')
            if (str[2] == 'A')
                if (str[3] == 'S')
                    if (str[4] == 'H') {
                        ptr = ((int*)0);
                        *ptr = 0;
                    }

}

int main(int argc, char** argv) { // int argc, char** argv

    #ifdef __AFL_HAVE_MANUAL_CONTROL
        __AFL_INIT();
    #endif

    static char buf[100];
    FILE* f;

    if (argc < 2) {
        std::fprintf(stderr, "Input error");
        return 1;
    }

    while (__AFL_LOOP(1000)) {
        f = fopen(argv[1], "r");
        if (!f) {
            std::fprintf(stderr, "Open file error");
            return 2;
        }
        fread(buf, 1, sizeof(buf), f);
        fclose(f);
        function_to_fuzz(buf);
    }
    
    return 0;
}
#include <stdio.h>
#include <iostream>
#include <fstream>

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

int main() { // int argc, char** argv
    static char buf[100];
    std::cin >> buf;
    function_to_fuzz(buf);
    return 0;
}
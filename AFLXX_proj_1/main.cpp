#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int sqrt_int(int x) {
	int left = 0, right = x, middle;

	while(left < right) {
	    int middle = right + (left-right)/2;
        // This can cause int overflow
	    if ( middle * middle <= x )
		    left = middle;
	    else
		    right = middle-1;
	}

	return left;
}

int main(int, char**) {
    static char buf[24];
    std::cin >> buf;
    std::cout << sqrt_int(atoi(buf)) << std::endl;
    return 0;
}

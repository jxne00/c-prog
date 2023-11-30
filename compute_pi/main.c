#include <stdio.h>  
#include <stdlib.h> 
#include "pi.h"     

#define SEED 123456789U

void print_row(int iterations) {
    printf("%-10i%18.12f%19.12f%19.12f\n",
        iterations, trapezoid_pi(iterations), montecarlo_pi(SEED, iterations), leibniz_pi(iterations));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: Provide option s or m or l for small or medium or large iteration counts\n");
        return 0;
    }

    printf("Approximations for pi: \n");
    printf("Iterations      Trapezoid         Monte Carlo          Leibniz\n");
    printf("-------------------------------------------------------------------\n");

    int choice = argv[1][0];
    switch (choice) {
    case 's': // small iteration count  
        for (int i = 1; i <= 20; i += 2) {
            print_row(i);
        }
        break;
    case 'm': // medium iteration count 
        for (int i = 1; i <= 1000; i *= 10) {
            print_row(i);
        }
        break;
    case 'l': // large iteration count
        for (int i = 1; i <= 100000000; i *= (i == 1000000 ? 100 : 10)) {
            print_row(i);
        }
        break;
    }
    return 0;
}

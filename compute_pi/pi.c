#include "pi.h"

/**
 * Calculates the approximate value of PI using the trapezoid algorithm.
 *
 * @param num_rects number of rectangles to use.
 * @return The approximate value of PI.
*/
double trapezoid_pi(int num_rects) {
    if (num_rects <= 0) {
        return 0.0;
    }

    double sum_area = 0.0;
    double width = 1.0 / num_rects;

    // sum up the areas of all the trapezoids
    for (int i = 0; i < num_rects; i++) {
        double x_left = width * i;
        double x_right = width * (i + 1);
        double avg_height = (sqrt(1 - x_left * x_left) + sqrt(1 - x_right * x_right)) / 2.0;
        sum_area += avg_height;
    }

    double quarter_area = sum_area * width;

    // x4.0 for the area of the full circle
    return 4.0 * quarter_area;
}


/**
 * Calculates an approximation of PI using Monte Carlo method.
 *
 * @param seed Random seed for the random number generator.
 * @param num_of_trails Number of trails to use.
 * @return The approximate value of PI.
*/
double montecarlo_pi(unsigned int seed, int num_of_trails) {
    if (num_of_trails <= 0) {
        return 0.0;
    }

    srand(seed); // seed the random number generator
    int total_count = 0;

    for (int i = 0; i < num_of_trails; i++) {
        double x = (double)rand() / RAND_MAX; // random x-coordinate [0, 1)
        double y = (double)rand() / RAND_MAX; // random y-coordinate [0, 1)
        double z = x * x + y * y;

        if (z <= 1) {
            total_count++;
        }
    }

    return (double)total_count / num_of_trails * 4;
}

/**
 * Calculates an approximation of PI using the Leibniz formula.
 *
 * @param num_elements The number of elements in the series to use.
 * @return The approximate value of PI.
*/
double leibniz_pi(int num_elements) {
    if (num_elements <= 0) {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < num_elements; i++) {
        double term = (i % 2 == 0) ? 1.0 : -1.0; // +1 for even, -1 for odd
        sum += term / (2 * i + 1); // 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
    }

    return sum * 4.0;
}
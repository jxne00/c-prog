#include "arrays.h"

/**
 * This function reverses the order of the elements in the array.
 *
 * @param a[] The array to reverse.
 * @param size The size of the array.
*/
void reverse_array(int a[], int size) {
    // first and last position in the array
    int first = 0;
    int last = size - 1;

    // continuously swap the ends of the array till it reaches the middle
    while (first < last) {
        int store = a[first];
        a[first] = a[last];
        a[last] = store;

        ++first;
        --last;
    }
}

/**
 * This function adds up the elements of 2 arrays and stores the result in a third array.
 *
 * @param a The first array.
 * @param b The second array.
 * @param c The third array.
 * @param size The size of the arrays.
*/
void add_arrays(int const a[], int const b[], int c[], int size) {
    int a_val = 0;
    int b_val = 0;

    for (int i = 0; i < size; ++i) {
        // get the values in [i] of both arrays
        a_val = a[i];
        b_val = b[i];
        // store the sum in c[i]
        c[i] = a_val + b_val;
    }
}

/**
 * This function multiplies each value in an array with a multiplier(scale_factor).
 *
 * @param a The array to multiply.
 * @param size The size of the array.
 * @param scale_factor The multiplier.
*/
void scalar_multiply(int a[], int size, int scale_factor) {
    for (int i = 0; i < size; i++) {
        int x = a[i];
        a[i] = x * scale_factor;
    }
}

/**
 * This function returns the dot product (int value) of the elements in 2 arrays.
 *
 * @param a[] The first array.
 * @param b[] The second array.
 * @param size The size of the arrays.
 * @return The dot product of the elements in the 2 arrays.
*/
int dot_product(int const a[], int const b[], int size) {
    int val_a = 0;
    int val_b = 0;
    int x = 0;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        val_a = a[i];
        val_b = b[i];
        x = val_a * val_b;
        sum += x;
    }
    return sum;
}

/**
 * This function calculates the cross product of 2 arrays and stores the result in a third array.
 *
 * @param a The first array.
 * @param b The second array.
 * @param c The third array.
*/
void cross_product(int const a[], int const b[], int c[]) {
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

/**
 * This function calculates the Euclidean length of a vector (array).
 *
 * @param a[] The array.
 * @param size The size of the array.
 * @return The length of the elements in the array.
*/
double length(int const a[], int size) {
    // check for invalid inputs
    if (size < 0 || a == NULL) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += (double)a[i] * a[i];
    }

    return sqrt(sum);
}
#include "str.h"

/**
 * Converts a string representation of an integer into its integer value.
 *
 * @param str The string to convert.
 * @return The integer value of the string.
*/
int str_to_int(char const str[]) {
    int sign = 1, num = 0, i = 0;

    // set negative sign if the first char is '-'
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = (num * 10) + (str[i] - '0');
        }
    }

    return num * sign;
}


/**
 * Converts an integer into its string representation.
 *
 * @param num The integer to convert.
 * @param str The string to store the result.
*/
void int_to_str(int num, char str[]) {
    int count = 0;
    int negative;

    if (num < 0) {
        num *= -1;
        negative = 1;
    }

    for (; num != '\0'; ++count) {
        str[count] = (num % 10) + '0';
        num /= 10;
    }

    if (negative == 1) {
        count += 1;
    }

    str[count] = 0;

    for (int i = 0; i < count / 2; ++i) {
        char c = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = c;
    }

    if (negative == 1) {
        str[0] = '-';
    }
}

/**
 * Calculates the length of a string.
 *
 * @param str The string to calculate the length of.
 * @return The length of the string.
*/
int str_len(char const str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/**
 * Concatenates two strings.
 *
 * @param dest The destination string.
 * @param src The source string.
*/
void str_concat(char dest[], char const src[]) {
    int dest_len = str_len(dest);
    int src_len = str_len(src);

    for (int i = 0; i < src_len; ++i) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + src_len] = '\0';
}
#include "roman.h"
#include <string.h>

/**
 * Returns the Roman numeral equivalent of the thousands digit.
*/
const char* get_thousands(int num) {
    static const char* thousands[] = { "", "M", "MM", "MMM" };
    return thousands[num];
}

/**
 * Returns the Roman numeral equivalent of the hundreds digit.
*/
const char* get_hundreds(int num) {
    static const char* hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    return hundreds[num];
}

/**
 * Returns the Roman numeral equivalent of the tens digit.
*/
const char* get_tens(int num) {
    static const char* tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    return tens[num];
}

/**
 * Returns the Roman numeral equivalent of the ones digit.
*/
const char* get_ones(int num) {
    static const char* ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    return ones[num];
}

/**
 * Implements the conversion of integers to its Roman numeral equivalent.
 *
 * @param value The integer to be converted.
 * @return A static buffer containing the resulting Roman numeral.
 */
char* int_to_roman(int value) {
    // static buffer to store the result
    static char result[20];

    // check if value is within range
    if (value <= 0 || value > 3999) {
        strcpy(result, "Invalid value");
        return result;
    }

    // convert each digit
    strcpy(result, get_thousands(value / 1000));
    strcat(result, get_hundreds((value % 1000) / 100));
    strcat(result, get_tens((value % 100) / 10));
    strcat(result, get_ones(value % 10));

    return result;
}
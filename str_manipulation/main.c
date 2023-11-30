#include <stdio.h>
#include "str.h"

#define MAX_STR_LEN 12

void test_str_to_int(char const* str) {
    printf("str_to_int(%s) = %d\n", str, str_to_int(str));
}

void test_int_to_str(int num, char* str) {
    int_to_str(num, str);
    printf("int_to_str(%d) = |%s|\n", num, str);
}

void test_str_len(char const* str) {
    printf("str_len(%s) = %d\n", str, str_len(str));
}

void test_str_concat(char* dest, char const* src) {
    printf("str_concat(%s, %s) = ", dest, src);
    str_concat(dest, src);
    printf("%s\n", dest);
}

int main(void) {
    printf("=========== Tests for str_to_int() ===========\n");
    test_str_to_int("0");
    test_str_to_int("-1");
    test_str_to_int("1");
    test_str_to_int("12");
    test_str_to_int("123");
    test_str_to_int("1234");
    test_str_to_int("1234567890");
    test_str_to_int("-0");
    test_str_to_int("-12");
    test_str_to_int("-123");
    test_str_to_int("-124");
    test_str_to_int("-1234567890");

    printf("\n=========== Tests for int_to_str() ===========\n");
    char string[MAX_STR_LEN];
    test_int_to_str(1, string);
    test_int_to_str(12, string);
    test_int_to_str(123, string);
    test_int_to_str(1234, string);
    test_int_to_str(1234567890, string);
    test_int_to_str(-0, string);
    test_int_to_str(-1, string);
    test_int_to_str(-12, string);
    test_int_to_str(-123, string);
    test_int_to_str(-1234, string);
    test_int_to_str(-1234567890, string);

    printf("\n=========== Tests for str_len() ===========\n");
    test_str_len("");
    test_str_len("a");
    test_str_len("ab");
    test_str_len("abc");
    test_str_len("abcd");
    test_str_len("abcde");
    test_str_len("abcdef");
    test_str_len("abcdefg");
    test_str_len("abcdefgh");
    test_str_len("abcdefghi");
    test_str_len("abcdefghij");
    test_str_len("abcdefghijk");
    test_str_len("abcdefghijkl");
    test_str_len("abcdefghijklm");

    printf("\n=========== Tests for str_concat() ===========\n");
    char dest[MAX_STR_LEN] = "";
    test_str_concat(dest, "");
    test_str_concat(dest, "a");
    test_str_concat(dest, "ab");
    test_str_concat(dest, "abc");
    test_str_concat(dest, "abcd");
    test_str_concat(dest, "abcde");

    return 0;
}
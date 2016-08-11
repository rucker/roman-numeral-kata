#include <stdlib.h>
#include <check.h>
#include "../src/numerals.h"

START_TEST(add_i_and_i_produces_ii) {
    const char first[] = "i";
    const char second[] = "i";
    const char expected[] = "ii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    add(first, second, result);
	ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(add_i_and_ii_produces_iii) {
    const char first[] = "i";
    const char second[] = "ii";
    const char expected[] = "iii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    add(first, second, result);
       ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(add_iv_and_viii_produces_xii) {
    const char first[] = "iv";
    const char second[] = "viii";
    const char expected[] = "xii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    add(first, second, result);
       ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(add_xxvii_and_xl_produces_lxvii) {
    const char first[] = "xxvii";
    const char second[] = "xl";
    const char expected[] = "lxvii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    add(first, second, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(addition_total_out_of_range_produces_result_nulla) {
    const char first[] = "mmd";
    const char second[] = "mmd";
    const char expected[] = "nulla";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    add(first, second, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(subtract_ix_from_c_produces_xci) {
    const char first[] = "c";
    const char second[] = "ix";
    const char expected[] = "xci";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    subtract(first, second, result);
       ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(subtract_xix_from_xliii_produces_xxiv) {
    const char first[] = "xliii";
    const char second[] = "xix";
    const char expected[] = "xxiv";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    subtract(first, second, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(subtract_v_from_v_produces_value_nulla) {
    const char first[] = "v";
    const char second[] = "v";
    const char expected[] = "nulla";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    subtract(first, second, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(subtract_x_from_v_produces_value_nulla) {
    const char first[] = "v";
    const char second[] = "x";
    const char expected[] = "nulla";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    subtract(first, second, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(numeral_ii_translates_to_int_2) {
    const char numeral[] = "ii";
    const int expected = 2;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_iii_translates_to_int_3) {
    const char numeral[] = "iii";
    const int expected = 3;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_iv_translates_to_int_4) {
    const char numeral[] = "iv";
    const int expected = 4;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_vi_translates_to_value_6) {
    const char numeral[] = "vi";
    const int expected = 6;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_vii_translates_to_value_7) {
    const char numeral[] = "vii";
    const int expected = 7;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_viii_translates_to_value_8) {
    const char numeral[] = "viii";
    const int expected = 8;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_ix_translates_to_value_9) {
    const char numeral[] = "ix";
    const int expected = 9;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_xl_translates_to_value_40) {
    const char numeral[] = "xl";
    const int expected = 40;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mcmxcii_translates_to_value_1992) {
    const char numeral[] = "mcmxcii";
    const int expected = 1992;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mmxvi_translates_to_value_2016) {
    const char numeral[] = "mmxvi";
    const int expected = 2016;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mmdxxv_translates_to_value_2525) {
    const char numeral[] = "mmdxxv";
    const int expected = 2525;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mmmcmxcix_translates_to_value_3999) {
    const char numeral[] = "mmmcmxcix";
    const int expected = 3999;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeralToInt_should_handle_values_out_of_range) {
    const char numeral[] = "mmmmmmxcix";
    const int expected = 0;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeralToInt_should_check_for_null_input_string) {
    const char *numeral = NULL;
    const int expected = 0;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(char_i_or_I_translates_to_int_1) {
    const char numeral[] = "i";
    const int expected = 1;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_v_or_V_translates_to_int_5) {
    const char numeral[] = "v";
    const int expected = 5;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_x_or_X_translates_to_int_10) {
    const char numeral[] = "v";
    const int expected = 5;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_l_or_L_translates_to_int_50) {
    const char numeral[] = "x";
    const int expected = 10;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_c_or_C_translates_to_int_100) {
    const char numeral[] = "l";
    const int expected = 50;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_d_or_D_translates_to_int_500) {
    const char numeral[] = "c";
    const int expected = 100;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_m_or_M_translates_to_int_1000) {
    const char numeral[] = "d";
    const int expected = 500;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(invalid_char_translates_to_int_0) {
    const char numeral[] = "z";
    const int expected = 0;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(int_2_translates_to_numeral_ii) {
    const int number = 2;
    char expected[] = "ii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_3_translates_to_numeral_iii) {
    const int number = 2;
    const char expected[] = "ii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_4_translates_to_numeral_iv) {
    const int number = 4;
    const char expected[] = "iv";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_9_translates_to_numeral_ix) {
    const int number = 9;
    const char expected[] = "ix";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_40_translates_to_numeral_xl) {
    const int number = 40;
    const char expected[] = "xl";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_90_translates_to_numeral_xc) {
    const int number = 90;
    const char expected[] = "xc";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_400_translates_to_numeral_cd) {
    const int number = 400;
    const char expected[] = "cd";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_900_translates_to_numeral_cm) {
    const int number = 900;
    const char expected[] = "cm";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(intToNumeral_should_check_for_null_buffer) {
    const int number = 900;
    const char expected = 0;
    char *result = NULL;
    intToNumeral(number, result);
    ck_assert_int_eq(result, expected);
}
END_TEST

Suite * numerals_suite(void) {
    Suite *s;
    TCase *tc_basic;

    s = suite_create("numerals");
    tc_basic = tcase_create("basic");

    tcase_add_test(tc_basic, add_i_and_i_produces_ii);
    tcase_add_test(tc_basic, add_i_and_ii_produces_iii);
    tcase_add_test(tc_basic, add_iv_and_viii_produces_xii);
    tcase_add_test(tc_basic, add_xxvii_and_xl_produces_lxvii);
    tcase_add_test(tc_basic, addition_total_out_of_range_produces_result_nulla);

    tcase_add_test(tc_basic, subtract_ix_from_c_produces_xci);
    tcase_add_test(tc_basic, subtract_xix_from_xliii_produces_xxiv);
    tcase_add_test(tc_basic, subtract_v_from_v_produces_value_nulla);
    tcase_add_test(tc_basic, subtract_x_from_v_produces_value_nulla);

    tcase_add_test(tc_basic, char_i_or_I_translates_to_int_1);
    tcase_add_test(tc_basic, char_v_or_V_translates_to_int_5);
    tcase_add_test(tc_basic, char_x_or_X_translates_to_int_10);
    tcase_add_test(tc_basic, char_l_or_L_translates_to_int_50);
    tcase_add_test(tc_basic, char_c_or_C_translates_to_int_100);
    tcase_add_test(tc_basic, char_d_or_D_translates_to_int_500);
    tcase_add_test(tc_basic, char_m_or_M_translates_to_int_1000);
    tcase_add_test(tc_basic, invalid_char_translates_to_int_0);

    tcase_add_test(tc_basic, numeral_ii_translates_to_int_2);
    tcase_add_test(tc_basic, numeral_iii_translates_to_int_3);
    tcase_add_test(tc_basic, numeral_iv_translates_to_int_4);
    tcase_add_test(tc_basic, numeral_vi_translates_to_value_6);
    tcase_add_test(tc_basic, numeral_vii_translates_to_value_7);
    tcase_add_test(tc_basic, numeral_viii_translates_to_value_8);
    tcase_add_test(tc_basic, numeral_ix_translates_to_value_9);
    tcase_add_test(tc_basic, numeral_xl_translates_to_value_40);
    tcase_add_test(tc_basic, numeral_mcmxcii_translates_to_value_1992);
    tcase_add_test(tc_basic, numeral_mmxvi_translates_to_value_2016);
    tcase_add_test(tc_basic, numeral_mmdxxv_translates_to_value_2525);
    tcase_add_test(tc_basic, numeral_mmmcmxcix_translates_to_value_3999);
    tcase_add_test(tc_basic, numeralToInt_should_handle_values_out_of_range);
    tcase_add_test(tc_basic, numeralToInt_should_check_for_null_input_string);

    tcase_add_test(tc_basic, int_2_translates_to_numeral_ii);
    tcase_add_test(tc_basic, int_3_translates_to_numeral_iii);
    tcase_add_test(tc_basic, int_2_translates_to_numeral_ii);
    tcase_add_test(tc_basic, int_3_translates_to_numeral_iii);
    tcase_add_test(tc_basic, int_4_translates_to_numeral_iv);
    tcase_add_test(tc_basic, int_9_translates_to_numeral_ix);
    tcase_add_test(tc_basic, int_40_translates_to_numeral_xl);
    tcase_add_test(tc_basic, int_90_translates_to_numeral_xc);
    tcase_add_test(tc_basic, int_400_translates_to_numeral_cd);
    tcase_add_test(tc_basic, int_900_translates_to_numeral_cm);
    tcase_add_test(tc_basic, intToNumeral_should_check_for_null_buffer);

    suite_add_tcase(s, tc_basic);

    return s;
}

const int main(void) {
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = numerals_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

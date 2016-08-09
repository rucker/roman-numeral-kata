#include <stdlib.h>
#include <check.h>
#include "../src/numerals.h"

START_TEST(test_add_i_and_i_returns_ii) {
    char first[] = "i";
    char second[] = "i";
    char expected[] = "ii";
    char result[sizeof(expected)];
    add(first, second, result);
	ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(numeral_ii_translates_to_int_2) {
    char numeral[] = "ii";
    int expected = 2;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_iii_translates_to_int_3) {
    char numeral[] = "iii";
    int expected = 3;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_iv_translates_to_int_4) {
    char numeral[] = "iv";
    int expected = 4;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_vi_translates_to_value_6) {
    char numeral[] = "vi";
    int expected = 6;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_vii_translates_to_value_7) {
    char numeral[] = "vii";
    int expected = 7;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_viii_translates_to_value_8) {
    char numeral[] = "viii";
    int expected = 8;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_ix_translates_to_value_9) {
    char numeral[] = "ix";
    int expected = 9;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_xl_translates_to_value_40) {
    char numeral[] = "xl";
    int expected = 40;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mcmxcii_translates_to_value_1992) {
    char numeral[] = "mcmxcii";
    int expected = 1992;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mmxvi_translates_to_value_2016) {
    char numeral[] = "mmxvi";
    int expected = 2016;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mmdxxv_translates_to_value_2525) {
    char numeral[] = "mmdxxv";
    int expected = 2525;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(numeral_mmmcmxcix_translates_to_value_3999) {
    char numeral[] = "mmmcmxcix";
    int expected = 3999;
    ck_assert_int_eq(numeralToInt(numeral), expected);
}
END_TEST

START_TEST(char_i_or_I_translates_to_int_1) {
    char numeral[] = "i";
    int expected = 1;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_v_or_V_translates_to_int_5) {
    char numeral[] = "v";
    int expected = 5;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_x_or_X_translates_to_int_10) {
    char numeral[] = "v";
    int expected = 5;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_l_or_L_translates_to_int_50) {
    char numeral[] = "x";
    int expected = 10;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_c_or_C_translates_to_int_100) {
    char numeral[] = "l";
    int expected = 50;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_d_or_D_translates_to_int_500) {
    char numeral[] = "c";
    int expected = 100;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(char_m_or_M_translates_to_int_1000) {
    char numeral[] = "d";
    int expected = 500;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(invalid_char_causes_program_exit_with_status_1) {
    char numeral[] = "z";
    int expected = 0;
    ck_assert_int_eq(charToInt(numeral), expected);
}
END_TEST

START_TEST(int_2_translates_to_numeral_ii) {
    int number = 2;
    char expected[] = "ii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(int_3_translates_to_numeral_iii) {
    int number = 2;
    char expected[] = "ii";
    size_t expectedSize = sizeof expected;
    char result[expectedSize];
    memset(result, 0, expectedSize);
    intToNumeral(number, result);
    ck_assert_str_eq(result, expected);
}
END_TEST

Suite * numerals_suite(void) {
    Suite *s;
    TCase *tc_basic;

    s = suite_create("numerals");
    tc_basic = tcase_create("basic");

    tcase_add_test(tc_basic, test_add_i_and_i_returns_ii);
    tcase_add_test(tc_basic, char_i_or_I_translates_to_int_1);
    tcase_add_test(tc_basic, char_v_or_V_translates_to_int_5);
    tcase_add_test(tc_basic, char_x_or_X_translates_to_int_10);
    tcase_add_test(tc_basic, char_l_or_L_translates_to_int_50);
    tcase_add_test(tc_basic, char_c_or_C_translates_to_int_100);
    tcase_add_test(tc_basic, char_d_or_D_translates_to_int_500);
    tcase_add_test(tc_basic, char_m_or_M_translates_to_int_1000);
    tcase_add_exit_test(tc_basic, invalid_char_causes_program_exit_with_status_1, 1);

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

    tcase_add_test(tc_basic, int_2_translates_to_numeral_ii);
    tcase_add_test(tc_basic, int_3_translates_to_numeral_iii);

    suite_add_tcase(s, tc_basic);

    return s;
}

int main(void) {
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

// --------------------------------
// TestTwoButtons.c++
// Copyright (C) 2015
// Adrian Iley
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "TwoButtons.h"

using namespace std;

// -----------
// TestTwoButtons
// -----------

// ----
// read
// ----

TEST(TwoButtonsFixture, read) {
    string s("1 10\n");
    const pair<int, int> p = buttons_read(s);
    ASSERT_EQ(10, p.first);
    ASSERT_EQ(1, p.second);}

// ----
// eval
// ----

TEST(TwoButtonsFixture, eval_1) {
    const int v = buttons_eval(1000, 1000);
    ASSERT_EQ(0, v);}

TEST(TwoButtonsFixture, eval_2) {
    const int v = buttons_eval(6, 4);
    ASSERT_EQ(2, v);}

TEST(TwoButtonsFixture, eval_3) {
    const int v = buttons_eval(1, 10);
    ASSERT_EQ(9, v);}

TEST(TwoButtonsFixture, eval_4) {
    const int v = buttons_eval(2, 16);
    ASSERT_EQ(14, v);}

TEST(TwoButtonsFixture, eval_5) {
    const int v = buttons_eval(16, 2);
    ASSERT_EQ(3, v);}

TEST(TwoButtonsFixture, eval_6) {
    const int v = buttons_eval(5678, 1234);
    ASSERT_EQ(528, v);}

TEST(TwoButtonsFixture, eval_7) {
    const int v = buttons_eval(9383, 886);
    ASSERT_EQ(305, v);}

TEST(TwoButtonsFixture, eval_8) {
    const int v = buttons_eval(100, 99);
    ASSERT_EQ(50, v);}

TEST(TwoButtonsFixture, eval_9) {
    const int v = buttons_eval(3, 1);
    ASSERT_EQ(3, v);}


// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1000 1000\n4 6\n10 1\n16 2\n2 16\n");
    ostringstream w;
    buttons_solve(r, w);
    ASSERT_EQ("0\n2\n9\n14\n3\n", w.str());}

TEST(TwoButtonsFixture, eval_10) {
 const int v = buttons_eval(6, 4);
 ASSERT_EQ(2, v);}

TEST(TwoButtonsFixture, eval_11) {
 const int v = buttons_eval(1, 10);
 ASSERT_EQ(9, v);}

TEST(TwoButtonsFixture, eval_12) {
 const int v = buttons_eval(2, 1);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_13) {
 const int v = buttons_eval(1, 2);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_14) {
 const int v = buttons_eval(3, 1);
 ASSERT_EQ(3, v);}

TEST(TwoButtonsFixture, eval_15) {
 const int v = buttons_eval(1, 3);
 ASSERT_EQ(2, v);}

TEST(TwoButtonsFixture, eval_16) {
 const int v = buttons_eval(10, 2);
 ASSERT_EQ(5, v);}

TEST(TwoButtonsFixture, eval_17) {
 const int v = buttons_eval(99, 100);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_18) {
 const int v = buttons_eval(100, 99);
 ASSERT_EQ(50, v);}

TEST(TwoButtonsFixture, eval_19) {
 const int v = buttons_eval(17, 10);
 ASSERT_EQ(3, v);}

TEST(TwoButtonsFixture, eval_20) {
 const int v = buttons_eval(6666, 666);
 ASSERT_EQ(255, v);}

TEST(TwoButtonsFixture, eval_21) {
 const int v = buttons_eval(666, 6666);
 ASSERT_EQ(6000, v);}

TEST(TwoButtonsFixture, eval_22) {
 const int v = buttons_eval(8192, 1);
 ASSERT_EQ(13, v);}

TEST(TwoButtonsFixture, eval_23) {
 const int v = buttons_eval(8193, 1);
 ASSERT_EQ(27, v);}

TEST(TwoButtonsFixture, eval_24) {
 const int v = buttons_eval(10000, 9999);
 ASSERT_EQ(5000, v);}

TEST(TwoButtonsFixture, eval_25) {
 const int v = buttons_eval(9999, 10000);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_26) {
 const int v = buttons_eval(1, 10000);
 ASSERT_EQ(9999, v);}

TEST(TwoButtonsFixture, eval_27) {
 const int v = buttons_eval(5678, 1234);
 ASSERT_EQ(528, v);}

TEST(TwoButtonsFixture, eval_28) {
 const int v = buttons_eval(9103, 9102);
 ASSERT_EQ(4552, v);}

TEST(TwoButtonsFixture, eval_29) {
 const int v = buttons_eval(1, 8192);
 ASSERT_EQ(8191, v);}

TEST(TwoButtonsFixture, eval_30) {
 const int v = buttons_eval(1023, 9912);
 ASSERT_EQ(8889, v);}

TEST(TwoButtonsFixture, eval_31) {
 const int v = buttons_eval(500, 100);
 ASSERT_EQ(41, v);}

TEST(TwoButtonsFixture, eval_32) {
 const int v = buttons_eval(9999, 9997);
 ASSERT_EQ(4999, v);}

TEST(TwoButtonsFixture, eval_33) {
 const int v = buttons_eval(10000, 5000);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_34) {
 const int v = buttons_eval(7997, 4000);
 ASSERT_EQ(3, v);}

TEST(TwoButtonsFixture, eval_35) {
 const int v = buttons_eval(10000, 1);
 ASSERT_EQ(20, v);}

TEST(TwoButtonsFixture, eval_36) {
 const int v = buttons_eval(8191, 1);
 ASSERT_EQ(14, v);}

TEST(TwoButtonsFixture, eval_37) {
 const int v = buttons_eval(10000, 9999);
 ASSERT_EQ(5000, v);}

TEST(TwoButtonsFixture, eval_38) {
 const int v = buttons_eval(9998, 9097);
 ASSERT_EQ(4099, v);}

TEST(TwoButtonsFixture, eval_39) {
 const int v = buttons_eval(9383, 886);
 ASSERT_EQ(305, v);}

TEST(TwoButtonsFixture, eval_40) {
 const int v = buttons_eval(9, 1);
 ASSERT_EQ(7, v);}

TEST(TwoButtonsFixture, eval_41) {
 const int v = buttons_eval(10000, 1918);
 ASSERT_EQ(671, v);}

TEST(TwoButtonsFixture, eval_42) {
 const int v = buttons_eval(3, 1);
 ASSERT_EQ(3, v);}

TEST(TwoButtonsFixture, eval_43) {
 const int v = buttons_eval(4, 1);
 ASSERT_EQ(2, v);}

TEST(TwoButtonsFixture, eval_44) {
 const int v = buttons_eval(10000, 2);
 ASSERT_EQ(19, v);}

TEST(TwoButtonsFixture, eval_45) {
 const int v = buttons_eval(10000, 3);
 ASSERT_EQ(17, v);}

TEST(TwoButtonsFixture, eval_46) {
 const int v = buttons_eval(10000, 4);
 ASSERT_EQ(18, v);}

TEST(TwoButtonsFixture, eval_47) {
 const int v = buttons_eval(10000, 9998);
 ASSERT_EQ(4999, v);}

TEST(TwoButtonsFixture, eval_48) {
 const int v = buttons_eval(10000, 5000);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_49) {
 const int v = buttons_eval(10000, 5001);
 ASSERT_EQ(2, v);}

TEST(TwoButtonsFixture, eval_50) {
 const int v = buttons_eval(1, 10000);
 ASSERT_EQ(9999, v);}

TEST(TwoButtonsFixture, eval_51) {
 const int v = buttons_eval(9999, 1);
 ASSERT_EQ(21, v);}

TEST(TwoButtonsFixture, eval_52) {
 const int v = buttons_eval(9999, 7777);
 ASSERT_EQ(2779, v);}

TEST(TwoButtonsFixture, eval_53) {
 const int v = buttons_eval(100, 2);
 ASSERT_EQ(9, v);}

TEST(TwoButtonsFixture, eval_54) {
 const int v = buttons_eval(8722, 10);
 ASSERT_EQ(18, v);}

TEST(TwoButtonsFixture, eval_55) {
 const int v = buttons_eval(4561, 848);
 ASSERT_EQ(283, v);}

TEST(TwoButtonsFixture, eval_56) {
 const int v = buttons_eval(9973, 9967);
 ASSERT_EQ(4982, v);}

TEST(TwoButtonsFixture, eval_57) {
 const int v = buttons_eval(10000, 5555);
 ASSERT_EQ(556, v);}

TEST(TwoButtonsFixture, eval_58) {
 const int v = buttons_eval(10000, 999);
 ASSERT_EQ(378, v);}

TEST(TwoButtonsFixture, eval_59) {
 const int v = buttons_eval(6, 3);
 ASSERT_EQ(1, v);}

TEST(TwoButtonsFixture, eval_60) {
 const int v = buttons_eval(38, 9);
 ASSERT_EQ(8, v);}


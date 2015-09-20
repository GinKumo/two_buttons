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

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1000 1000\n4 6\n10 1\n16 2\n2 16\n");
    ostringstream w;
    buttons_solve(r, w);
    ASSERT_EQ("0\n2\n9\n14\n3\n", w.str());}


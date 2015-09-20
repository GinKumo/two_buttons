#ifndef __TWO_BUTTONS
#define __TWO_BUTTONS 1

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// buttons_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of numbers n and m, where n is of arbitrary length, and m is target number for Two buttons problem.
 */
pair<int, int> buttons_read (const string& s);

// -------------
// buttons_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void buttons_solve (istream& r, ostream& w);


/**
 * @param m the goal
 * @param n the beginning number
 * @return the number of button presses
 */
int buttons_eval (int m, int n);

#endif /* __TWO_BUTTONS */

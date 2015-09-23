#include <iostream>

#include "TwoButtons.h"

#include <cstring> // std::strcmp, std::strcpy
#include <sstream>  // istringstream
#include <queue>
#include <limits>

using namespace std;

#ifndef DEBUG
#define DEBUG 0
#endif

#if defined(__GNUC__) && !defined(NO_builtin_ctz)
#define ctz __builtin_ctz
#else /* if we don't have GNUC then use this pretty quick implementation */
/* https://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightMultLookup */
static int ctz(int v) {  // find the number of trailing zeros in 32-bit v
    int r;            // result goes here
    static const int MultiplyDeBruijnBitPosition[32] =
    {
      0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
      31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
    };
   return MultiplyDeBruijnBitPosition[((uint32_t)((v & -v) * 0x077CB531U)) >> 27];
}
#endif /* __GNUC__ */


#if defined(__GNUC__) && !defined(NO_builtin_clz)
#define clz __builtin_clz
#else /* if we don't have GNUC then use this pretty quick implementation */

#define clz nlz2
// from http://www.hackersdelight.org/hdcodetxt/nlz.c.txt
int nlz2(unsigned x) {
   unsigned y;
   int n;

   n = 32;
   y = x >>16;  if (y != 0) {n = n -16;  x = y;}
   y = x >> 8;  if (y != 0) {n = n - 8;  x = y;}
   y = x >> 4;  if (y != 0) {n = n - 4;  x = y;}
   y = x >> 2;  if (y != 0) {n = n - 2;  x = y;}
   y = x >> 1;  if (y != 0) return n - 2;
   return n - x;
}
#endif /* __GNUC__ */

#if defined(__GNUC__) && !defined(NO_builtin_popcount)
#define popcount __builtin_popcount
#else /* if we don't have GNUC then use this pretty quick implementation */

// from http://graphics.stanford.edu/~seander/bithacks.html
int popcount(unsigned v) {
    v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
}
#endif /* __GNUC__ */


// ------------
// buttons_read
// ------------

pair<int, int> buttons_read (const string& s) {
    istringstream sin(s);
    int n;
    int m;
    sin >> n >> m;
    return make_pair(m, n);}

// -------------
// buttons_solve
// -------------

void buttons_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = buttons_read(s);
        //cout << "int:" << p.first << " str:" << p.second << endl;
        const int            m = p.first;
        const int            n = p.second;
        const int            v = buttons_eval(m, n);
        w << v << endl;
        }}


// ------------
// buttons_eval
// ------------

int buttons_eval (int m, int n)
{
    int cnt = 0;
    if (n >= m) {
        return n-m;
    }

    int nn = n;
    int sh = 0;

    sh = clz(nn)-clz(m);
    nn <<= sh;
    if (nn < m) {
        nn <<= 1;
        ++sh;
    }

    if (nn == m) {
        return sh;
    }

    cnt = n-(m >> sh);
    m -= ((m>>(sh+1))-1)<<(sh+1);

    return sh+cnt-1+__builtin_popcount( (((m>>(sh))+1)<<sh)-m);
}


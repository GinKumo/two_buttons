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

int buttons_eval (int m, int n) {
    queue<pair<int,int>> buttonQ;
    int cnt = std::numeric_limits<int>::max();
    int max_iter = 100000;
    //cout << "buttons_eval:m:" << m << " n:" << n << endl;
    if (n >= m) {
        // push subtract button until n decreases to m
        cnt = n-m;
    } else {
        buttonQ.push(std::pair<int,int>(n,0));
        while (max_iter && !buttonQ.empty()) {
            max_iter--;
            int l = buttonQ.size();
            while (l--) {
                pair<int,int> cur = buttonQ.front();
                buttonQ.pop();
                if (cur.first == m) {
                    // is this the smallest count found so far
                    if (cnt > cur.second) {
                        cnt = cur.second;
                    }
                    continue;
                }
                // skip on if this won't grow us a better solution
                if (cur.second + 1 >= cnt) {
                    continue;
                }
                if (cur.first*2 >= m) {
                    int tmp = cur.second+1+(cur.first*2-m);
                    if (cnt > tmp) {
                        cnt = tmp;
                    }
                } else {
                    buttonQ.push(pair<int,int>(cur.first*2,cur.second+1));
                }
                if (cur.first > 1) {
                    buttonQ.push(pair<int,int>(cur.first-1,cur.second+1));
                }
            }
        }
    }
    /* Debug */
    if (!buttonQ.empty()) {
        int l = buttonQ.size();
        while (l--) {
            pair<int,int> cur = buttonQ.front();
            buttonQ.pop();
            cout << "(" << cur.first << ", " << cur.second << ")" << endl;
        }
    }
    return cnt;
}


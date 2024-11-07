#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    // first try, thought it'd be cool to share that <(˘ ˘ ˘)>
    // core idea is basically cut out and append last digit of x ireversedx using % and /, also overflow checking
    // turn all negative into positive to
    // NOTE TO SELF: can't negate INT_MIN, since -INT_MIN > INT_MAX by 1, so calling it would cause overflow
    int reverse(int x) {
        int reversedx = 0;
        bool neg = 0;

        // negative numbers
        if (x < 0){
            // edge case: x == INT_MIN (-2147483648)
            // can't negate INT_MIN, would overflow, so return 0
            if (x == INT_MIN) return 0;
            x = -x;
            neg = 1; // remember that the original number was negative
        }

        // reverse
        while(x != 0){
            int pop = x % 10; // get the last digit
            x = x / 10; // remove the last digit from x

            // check for potential overflow before multiplying by 10
            if (reversedx > INT_MAX / 10) return 0;
            // if reversedx == INT_MAX / 10, need to check last digit
            // since INT_MAX = 2147483647, ex: if reversedx == 214748364 and x = 9, we would overflow
            if (reversedx == INT_MAX / 10 && x % 10 > 7) return 0;

            reversedx = reversedx * 10 + pop; // reverse append digit of x -> reversedx
        }

        // turn back to negative if initially does
        return neg ? -reversedx : reversedx;
    }
};

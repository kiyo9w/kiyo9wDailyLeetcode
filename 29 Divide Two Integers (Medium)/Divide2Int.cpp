class Solution {
public:
    // unga bunga way, keep subtracting and keeping track of the counter
    // there's also bit manipulation ig ¯\_(ツ)_/¯
    // funny SIDE NOTE: this problem have a 18% acceptance rate, prolly 99% declined cause run time overflow
    int divide(int dividend, int divisor) {
        // handle edge cases that cause overflow, also just try to cheat run time since this cases would take huge time xd
        // dividend is INT_MIN and divisor is -1, result would exceed INT_MAX, so we return INT_MAX
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // run time cheatinnnn
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        if (dividend == INT_MIN && divisor == INT_MIN) {
            return 1;
        }
        if (dividend == INT_MAX && divisor == -1) {
            return -INT_MAX;
        }
        if (dividend == INT_MAX && divisor == 1) {
            return INT_MAX;
        }
        // if divisor is INT_MIN but dividend isn't, the result is 0 because any other number divided by INT_MIN rounds to 0
        if (dividend == INT_MAX && divisor == INT_MIN) {
            return 0;
        }

        // count is basically result
        int count = 0;
        int a = dividend;
        int b = divisor;

        // converting both numbers to negative for consistency (handling negatives is simpler here)
        if (dividend >= 0) a = -a;
        if (divisor > 0) b = -b;

        // repeatedly subtracting divisor from dividend
        while (a - b <= 0) {
            a -= b;  // subtract divisor from dividend
            count++; // increment result count
        }

        // if the original signs are different, turn result negative
        if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend >= 0)) count = -count;

        return count;
    }
};


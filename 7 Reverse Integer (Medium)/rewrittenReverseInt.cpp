class Solution {
public:
    // dumbass really checked for negative number 💀
    // SIDE NOTE: basically same time complexity O(1) (>0 <10), but removing a lot of the redundant process bring it down from beating 40% to 100%
    int reverse(int x) {
        int reversedx = 0;

        while(x != 0){
            int pop = x % 10; // get the last digit
            x /= 10; // remove the last digit from x

            // optimized checking for overflow/underflow:

            // for overflow:
            // if reversedx > INT_MAX / 10, multiplying by 10 will overflow
            // if reversedx == INT_MAX / 10, and pop > 7 (since INT_MAX % 10 == 7), it will overflow
            if (reversedx > INT_MAX/10 || (reversedx == INT_MAX / 10 && pop > 7)) return 0;

            // for underflow:
            // if reversedx < INT_MIN / 10, multiplying by 10 will underflow
            // if reversedx == INT_MIN / 10, and pop < -8 (since INT_MIN % 10 == -8), it will underflow
            if (reversedx < INT_MIN/10 || (reversedx == INT_MIN / 10 && pop < -8)) return 0;

            reversedx = reversedx * 10 + pop; // reverse append digit of x -> reversedx
        }

        return reversedx;
    }
};

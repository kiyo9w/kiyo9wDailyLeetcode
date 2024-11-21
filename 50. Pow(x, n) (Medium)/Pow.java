class Solution {
    // actually a pretty fun problem once I get the hang of it (in the solution pannel)
    // raise to negative power => 1 / raise to positive power
    public double myPow(double x, int n) {
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long) n);
    }

    // core idea: instead of multiplying the result by x n times O(n)
    //            we take in account of two numbers: ans and a
    //            we check if the power is divisable by 2, if it is then we raise a by a
    //            if it is not divisible by 2 (odd), then we raise both ans by a and a by a
    //            since we  dividing n by 2 at each step, the problem size logarithmically reduced.
    //            O(log(n))
    private double qpow(double a, long n) {
        double ans = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1) {
                ans = ans * a;
            }
            a = a * a;
        }
        return ans;
    }
}
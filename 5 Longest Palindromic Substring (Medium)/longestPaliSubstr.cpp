#include <iostream>
#include <string>

using namespace std;

// this was my one of my early past attemps at sovlving leetcode, don't judge >-<
// prolly gonna write a better version for this later
string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }
    if (s.length() == 1) {
        return s;
    }
    string longest = "", temp = "";
    int mid = 0;
    int even = 0;
    while (even < 2) {
        while (mid < s.length() - 1) {
            temp += s[mid];
            int i = mid, j = mid + even;
            while (j >= 0 && i < s.length() && s[i] == s[j]) {
                temp = s.substr(j, i - j + 1);
                ++i;
                --j;
                longest = (temp.length() > longest.length()) ? temp : longest;
            }
            mid++;
        }
        mid = 0;
        even++;
    }
    return longest;
}

int main() {

    string s1 = "babad";
    cout << longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << longestPalindrome(s2) << endl;

    string s3 = "a";
    cout << longestPalindrome(s3) << endl;

    string s4 = "ac";
    cout << longestPalindrome(s4) << endl;

    return 0;
}
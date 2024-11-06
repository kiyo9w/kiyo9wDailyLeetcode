#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> memo;

// recursion, string trimming
// the reason I chose trimming is for better code readability and idea execution, this is horrible for memory complexity though, this can definitely be done with indexing but wont be so easy to read
bool isMatch(string s, string p) {
    // memoi to reduce time complexity, first time I submitted was declined for time limit exceeded
    string key = s + "," + p;
    if (memo.find(key) != memo.end()) return memo[key];

    // edge case: p empty -> both empty then true, otherwise false
    if (p.empty()) return s.empty();
    // current char match (0 since we always cut down both string if match)
    bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

    bool result;

    // if the next character is a "*" then two cases: 1. if first_match not true (then basically this two [ex: "a*"] are useless, then cut p by 2 (skip p first_match and "*")
    //                                                2. if first_match is true -> then keep cutting s till first_match no longer true (if it's "." before * then it will cut s entirely)
    // interesting SIDE NOTE: we do not need to check first_match for case 1 since "*" in regex can mean zero occurences, so we can still keep checking even if p[0] doesn't match.
    if (p.length() >= 2 && p[1] == '*') {
        result = (isMatch(s, p.substr(2)) ||
                  (first_match && isMatch(s.substr(1), p)));
    } else {
    // not "*" then normal matching check, cut down both by one if match
        result = first_match && isMatch(s.substr(1), p.substr(1));
    }

    memo[key] = result;
    return result;
}

int main() {
    vector<pair<string, string> > testCases = {
            {"aa", "a"},
            {"aa", "a*"},
            {"ab", ".*"},
            {"aab", "c*a*b"},
            {"mississippi", "mis*is*p*."},
            {"", ".*"},
            {"abc", ".*"},
            {"abc", "a.c"},
            {"", "a*"},
            {"a", "a*"},
            {"aaa", "a*"},
            {"", ""}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        bool result = isMatch(testCases[i].first, testCases[i].second);
        cout << testCases[i].first << ", " << testCases[i].second << " result: " << ((result) ? "true" : "false") << endl;
    }

    return 0;
}
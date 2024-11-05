#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// basic hash map
// NOTE TO SELF: unorder set insert return value is a pair <pointer, boolean>, pointer points to the location of the newy inserted element or the equivalent element in map, boolean indicating the succession of insertion
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> check;
    for (int num : nums) {
        if (!check.insert(num).second) return true;
    }
    return false;
}

int main() {
    vector<int> testVector = *new vector<int> {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << containsDuplicate(testVector);
    return 0;
}

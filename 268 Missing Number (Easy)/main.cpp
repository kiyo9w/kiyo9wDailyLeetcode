#include <iostream>
#include <vector>

using namespace std;

// Basically calculate the expected sum of the natural array 0 -> n, then minus it with the missing array to find the /one/ missing number
int missingNumber(vector<int>& nums) {
    int lenn = nums.size();
    int naturalSum = lenn * (lenn + 1) / 2;
    int curSum = 0;
    for(int num : nums){
        curSum += num;
    }
    return naturalSum - curSum;
}

int main() {
    int n;
    vector<int> testVector = *new vector<int> {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(testVector);
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// requirement note: two sorted arrays
// using two pointers to iterate until the median index of merged array (without merging), ultilizing the fact that two arrays are sorted
// NOTE TO SELF: O(m + n) since worst case it just iterate to the end of both arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int len1 = nums1.size(), len2 = nums2.size();
    const int size = (len1 + len2), median = size / 2;
    int med1, med2;
    int i = 0, j = 0; // two pointers
    // total numbers odd or even for cal median
    const bool oe = size % 2;
    // two pointer iterate until it reach the median value
    for(int toMed = 0; toMed <= median; toMed++){
        // med2 to keeps the previous median value (case where total numbers even)
        med2 = med1;
        // essentially just iterate whichever array where current element is lower than the other, bounder checking also
        if(i < len1 && (j >= len2 || nums1[i] <= nums2[j])) med1 = nums1[i++];
        else med1 = nums2[j++];
    }
    return (oe)? med1: (med1 + med2) / 2.0;
}

int main() {
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1};
    nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 3};
    nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {-5, -3, -1};
    nums2 = {-2, 0, 2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2, 2};
    nums2 = {2, 3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = vector<int>(1000, 1);
    nums2 = vector<int>(1000, 2);
    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;


}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// merge both arrays and use nth_element to find the median elements without fully sorting the array.
// NOTE TO SELF: O(m + n) since bottle neck nth_element() run in O(m + n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int size = (nums1.size() + nums2.size()), median = size / 2;
    // total numbers odd or even for cal median
    const bool oe = size % 2;
    nums2.insert(nums2.end(), nums1.begin(), nums1.end());
    // neat function
    nth_element(nums2.begin(), nums2.begin()+(median), nums2.end());
    if(!oe) nth_element(nums2.begin(), nums2.begin() + median - 1, nums2.end());
    return (oe)? nums2[median]: (nums2[median - 1] + nums2[median]) / 2.0;
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

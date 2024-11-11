class Solution {
public:
    // got multiple rejects with time limit exceeded so decided to look up answer 😡(really mad)
    // sliding window, start off from [0, end] to find fitting window for k ([startfit, end]), then shrink down to find shortest
    // next iteration will go from [startfit + 1, end + 1] since we already got that [startfit, end] is one answer, we can continue checking from startfit + 1

    // use to expand or shrink window to left/right
    void update(vector<int>& bits, int x, int change) {
        // keep count of the window expanding
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1) {
                bits[i] += change;
            }
        }
    }

    // function to reconstruct the OR result from the bits counts
    // basically, if any bit has a positive count, it's set in the OR result
    int bitsToNum(const vector<int>& bits) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] > 0) {
                result |= (1 << i); // set bit i
            }
        }
        return result;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int min_length = INT_MAX;
        vector<int> bits(32); // bits counts for current window
        int left = 0; // left pointer of the window

        // sliding window from left to right
        for (int right = 0; right < n; ++right) {
            // include nums[right] into the window
            update(bits, nums[right], 1);

            // try to shrink the window while the OR result is >= k
            while (left <= right && bitsToNum(bits) >= k) {
                // update min_length if we found a smaller window
                min_length = min(min_length, right - left + 1);

                // remove nums[left] from the window
                update(bits, nums[left], -1);
                left++; // move the left pointer
            }
        }

        // if min_length wasn't updated, no valid subarray was found
        return min_length == INT_MAX ? -1 : min_length;
    }
};

class Solution {
    bool canChange(String start, String target) {
        int n = start.length    ;
        int i = 0, j = 0;

        while (i < n || j < n) {
            // skip blanks in both strings
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If one reaches the end while the other doesn't
            if (i == n || j == n) {
                return i == j;
            }

            // Check if characters are different
            if (start[i] != target[j]) {
                return false;
            }

            // Validate position constraints
            if (start[i] == 'L' && i < j) {
                return false;
            }
            if (start[i] == 'R' && i > j) {
                return false;
            }

            // Move to the next character
            i++;
            j++;
        }

        return true;
    }
}
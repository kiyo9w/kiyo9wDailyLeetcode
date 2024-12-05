public class Solution {
    // yeah I did not come up with this answer 💀


    //    Test cases for visualization:
    //    start = "_LL___R__R_", target = "L___L____RR"
    //    Execution:
    //            1. i=1, j=0, start[i]='L', target[j]='L' -> Valid ('L' can move left).
    //            2. i=2, j=4, start[i]='L', target[j]='L' -> Invalid ('L' cannot move right).
    //    Result: false

    //    start = "_L__R__R_", target = "L______RR"
    //    Execution:
    //            1. i=1, j=0, start[i]='L', target[j]='L' -> Valid ('L' can move left).
    //            2. i=3, j=7, start[i]='R', target[j]='R' -> Valid ('R' can move right).
    //            3. i=6, j=8, start[i]='R', target[j]='R' -> Valid ('R' can move right).
    //    Result: true
    public boolean canChange(String start, String target) {
        int n = start.length();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // skip blanks in both strings
            while (i < n && start.charAt(i) == '_') i++;
            while (j < n && target.charAt(j) == '_') j++;

            // if one of the pointer reached the end, check if the other also do
            if (i == n || j == n) {
                return i == j;
            }

            // check if characters are different (for case where L and R collide)
            if (start.charAt(i) != target.charAt(j)) {
                return false;
            }

            // core: validate position constraints
            // after skipping all the dashes, we can check
            // if both are 'L', then the 'L' of start must be above 'L' of target, since it can only shift left
            if (start.charAt(i) == 'L' && i < j) {
                return false;
            }
            // if both are 'R', then the 'R' of start must be under 'R' of target, since it can only shift right
            if (start.charAt(i) == 'R' && i > j) {
                return false;
            }

            // move both pointer up if the last check was correct
            i++;
            j++;
        }

        return true;
    }
}
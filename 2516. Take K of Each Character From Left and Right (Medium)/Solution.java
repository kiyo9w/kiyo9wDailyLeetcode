class Solution {
    // sliding window, honestly this problem is way too hard for a medium
    // core idea: track the maximum window where the outside of it fit the condition, basically reversed the requirement.
    public int takeCharacters(String s, int k) {
        int count[] = new int[3];

        // count all existing chars appearance
        for(char ch: s.toCharArray()){
            count[ch - 'a']++;
        }

        // edge case: total count not valid
        for(int i = 0; i < 3; i++){
            if (count[i] < k) return -1;
        }

        // sliding window Ex: "aabaaaacaabc" k = 2
        int left = 0;
        int n = s.length();
        int maxWin = 0;

        // right pointer check whenever there's a position where that window make the outside invalid Ex: 1: "[aab]aaaacaabc" since outside of this window, count['b'] < 2 
        //          2: "aab[aaaac]aabc"
        //          3: "aabaaaac[aab]c"
        for(int right = 0; right < n; right++){
            char c = s.charAt(right);
            count[c - 'a']--;

            // if any count < k, left pointer increment until the outside is valid again 
            // Ex: 1: -> "aab[]aaaacaabc" count['b'] is 2 again
            //     2: -> "aabaaaac[]aabc"
            while(count[0] < k || count[1] < k || count[2] < k){
                char cl = s.charAt(left);
                count[cl - 'a']++;
                left++;
            }

            // track whenever window is valid Ex: aab[aaaa]caabc is valid, maxWin = 4. then right pointer move up leading to invalid -> left pointer move up
            maxWin = Math.max(maxWin, right - left + 1);
        }
        return n - maxWin;
    }
}
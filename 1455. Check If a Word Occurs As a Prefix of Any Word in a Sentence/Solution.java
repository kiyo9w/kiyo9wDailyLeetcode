class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int index = 1;
        int n = sentence.length();
        int i = 0;

        while (i < n) {
            while (i < n && sentence.charAt(i) == ' ') {
                i++;
            }
            if (i >= n) break;

            int wordStart = i;
            boolean isPrefix = true;

            for (int j = 0; j < searchWord.length(); j++) {
                if (i + j >= n || sentence.charAt(i + j) != searchWord.charAt(j)) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                return index;
            }
            while (i < n && sentence.charAt(i) != ' ') {
                i++;
            }
            index++;
        }
        return -1;
    }
}

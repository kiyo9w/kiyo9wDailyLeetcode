class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        Set<Character> set = new HashSet<>();

        for(char ch: allowed.toCharArray()){
            set.add(ch);
        }
        int count = 0;

        for(String word: words){
            if(isConsistence(word, set)){
                count++;
            }
        }
        return count;
    }

    public boolean isConsistence(String word, Set<Character> set){
        for(char ch:word.toCharArray()){
            if(!set.contains(ch)){
                return false;
            }
        }
        return true;
    }
}
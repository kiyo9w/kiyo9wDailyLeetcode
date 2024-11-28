class Solution {
    public String replaceDigits(String s) {
        StringBuilder result = new StringBuilder();
        for(int i = 0; i < s.length(); i++){
            char current = s.charAt(i);
            // if current is a digit
            if(Character.isDigit(current)){
                // append to result last character + current (numerical value)
                result.append( (char) ((int) s.charAt(i - 1) + current - '0') );
            } else result.append(s.charAt(i)); // non-digit then just append
        }
        return result.toString();
    }
}
class Solution {
    public int longestValidParentheses(String s) {
        // kinda similar to 20.
        Stack<Integer> stack = new Stack<>();
        int max = 0;

        stack.push(-1); // push -1 to handle the base for the first valid substring

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                stack.push(i); // push the index of '(' onto the stack
            } else {
                stack.pop(); // pop the last '(' index
                if (stack.isEmpty()) {
                    stack.push(i); // push the current ')' index as a new base
                } else {
                    max = Math.max(max, i - stack.peek()); // calculate the length of the current valid substring
                }
            }
        }
        return max;
    }
}

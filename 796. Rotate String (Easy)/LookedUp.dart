class Solution {
  bool rotateString(String s, String goal) {
    if(s.length != goal.length) return false;
    // really simple and intuitive approach that I looked up
    // literally took 5 seconds understand
    return (s + s).contains(goal);
  }
}
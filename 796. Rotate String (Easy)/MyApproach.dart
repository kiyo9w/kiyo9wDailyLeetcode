class Solution {
  bool rotateString(String s, String goal) {

    if (s.length != goal.length) return false;

    // brute force
    for (int shift = 0; shift < s.length; shift++) {
      // check if shift result in goal
      bool matches = true;
      for (int i = 0; i < s.length; i++) {
        if (s[i] != goal[(shift + i) % s.length]) {
          matches = false;
          break;
        }
      }
      if (matches) {
        return true;
      }
    }

    return false;
  }
}

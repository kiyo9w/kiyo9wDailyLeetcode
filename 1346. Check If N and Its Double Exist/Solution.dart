class Solution {
  bool checkIfExist(List<int> arr) {
    bool ans = false;
    // brute force
    for(int i = 0; i < arr.length; i++) {
      for(int j = 0; j < arr.length; j++) {
        if(i != j) {
          if(arr[i] == 2*arr[j]) {
            ans = true;
            return ans;
          }
        }
      }
    }
    return ans;
  }
}
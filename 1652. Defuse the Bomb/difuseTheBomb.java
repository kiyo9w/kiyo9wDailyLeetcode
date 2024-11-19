class Solution {
    // core concept: circular array wraps around at the ends (at [n - 1], next index is [0])
    // should always have step k, for positive k or wrap forward use (currentIndex + k) % N
    // for negative k or wrap backward use (currentIndex - k + N) % N

    public int[] decrypt(int[] code, int k) {
        // base case: k = 0
        if(k == 0){
            return new int[code.length];
        }

        int codelen = code.length;
        int[] result = new int[codelen];
        int step = Math.abs(k); // number of steps to move

        // iterate through each element in the code array
        for(int i = 0; i < codelen; i++){
            // sum the next or previous k elements based on the value of k
            for(int j = 1; j <= step; j++){
                if(k > 0){
                    // moving forward, wrap around using modulo
                    result[i] += code[(i + j) % codelen];
                }
                else{
                    // moving backward, ensure allowed index by adding codelen before modulo => positive
                    result[i] += code[(i - j + codelen) % codelen];
                }
            }
        }
        return result;
    }
}

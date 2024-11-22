class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        // started off thinking about flipping columns individually, but realized a smarter approach was needed 
        // using a frequency map to group rows that can be made identical by flipping certain columns
        // Time Complexity: O(n * m)
        //   - n is the number of rows in the matrix
        //   - m is the number of columns in each row
        //   - we traverse each row and each element within the row once.

        Map<String, Integer> freqMap = new HashMap<>();
        int maxEqualRows = 0; // to keep track of the maximum number of equal rows after flips

        for(int[] row : matrix) {
            // create a binary string by XOR-ing each element with the first element of the row
            // this normalizes the row, making rows that can be made identical have the same binary string
            String binaryString = arrayToXorString(row, row[0]);

            // update the frequency map with the normalized binary string
            int currentCount = freqMap.getOrDefault(binaryString, 0) + 1;
            freqMap.put(binaryString, currentCount);

            // keep track of the maximum frequency encountered
            maxEqualRows = Math.max(maxEqualRows, currentCount);
        }
        return maxEqualRows; // return the highest number of identical rows achievable
    }

    // helper method to convert an array to a binary string after XOR-ing with a given value
    private String arrayToXorString(int[] arr, int xor) {
        StringBuilder sb = new StringBuilder();
        for(int num : arr) {
            sb.append(num ^ xor); // flip the bit if xor is 1, keep it the same if xor is 0
        }
        return sb.toString(); // return the normalized binary string
    }
}
// @leet start
class Solution {
    public int[] platesBetweenCandles(String s, int[][] queries) {
        int answer[] = new int[queries.length];
        char charStr[] = s.toCharArray();

        for (int i = 0; i < queries.length; i++) {
            int q[] = queries[i];
            answer[i] = this.plateCountHelper(charStr, q[0], q[1]);
        }
        
        return answer;
    }

    private int plateCountHelper(char charStr[], int left, int right) {
        boolean hasLeft = false;
        int count = 0;
        int currCount = 0;
        for (int i = left; i <= right; i++) {
            if (charStr[i] == '|') {
                count += currCount;
                if (hasLeft) {
                    currCount = 0;
                } else {
                    hasLeft = true;
                }
            } else if (hasLeft) {
                currCount++;
            }
        }
        return count;
    }
}
// @leet end

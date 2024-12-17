// @leet start
class Solution {
    public int minChanges(String s) {
        if (s.length() % 2 == 1) {
            return this.minChangesHelper(s);
        }

        int result = 0;
        char charStr[] = s.toCharArray();
        for (int i = 1; i < s.length(); i += 2) {
            if (charStr[i] != charStr[i-1]) {
                result++;
            }
        }
        return result;
    }

    public int minChangesHelper(String s) {
        int numOnes = 0;
        int numZeros = 0;
        char charStr[] = s.toCharArray();

        for (char i : charStr) {
            if (i == '0') {
                numZeros++;
            } else {
                numOnes++;
            }
        }
       
        return Math.min(numOnes, numZeros);
    }
}
// @leet end

// @leet start
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int result = -1;
        int backPos[] = new int[26];
        int frontPos[] = new int[26];
        char charStr[] = s.toCharArray();

        for (int i = 0; i < backPos.length; i++) {
            backPos[i] = -1;
            frontPos[i] = -1;
        }

        for (int i = 0; i < charStr.length; i++) {
            int charIdx = charStr[i] - 'a';
            if (backPos[charIdx] == -1) {
                backPos[charIdx] = i;
            }
            frontPos[charIdx] = i;
        }

        for (int i = 0; i < backPos.length; i++) {
            int val = frontPos[i] == backPos[i] ? -1 : frontPos[i] - backPos[i] - 1;
            result = Math.max(result, val);
        }

        return result;
    }
}
// @leet end

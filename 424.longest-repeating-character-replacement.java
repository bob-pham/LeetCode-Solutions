// @leet start
class Solution {
    public int characterReplacement(String s, int k) {
        int charMap[] = new int[26];
        char strChar[] = s.toCharArray();
        int result = 0;
        int l = 0;
        char most = strChar[0];
        int replaceNum = 0;

        for (int r = 0; r < strChar.length; r++) {
            int currIdx = strChar[r] - 'A';
            charMap[currIdx]++;
            if (strChar[r] == most) {
                result = Math.max(result, r - l + 1);
                continue;
            }
            replaceNum++;
            while (replaceNum > k && l < r) {
                if (strChar[l] != most) {
                    replaceNum--;
                }

                int lIdx = strChar[l] - 'A';
                int count = --charMap[lIdx];
                l++;
            }

            int mostCount = charMap[most - 'A'];
            for (int i = 0; i < charMap.length; i++) {
                if (charMap[i] > mostCount) {
                    most = (char) (i + 'A');
                    mostCount = charMap[i];
                }
            }

            result = Math.max(result, r - l + 1);
        }

        return result;
    }
}
// @leet end

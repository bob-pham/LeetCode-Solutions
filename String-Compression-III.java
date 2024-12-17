class Solution {
	public String compressString(String word) {
		StringBuilder resultSB = new StringBuilder();
		char wordChars[] = world.toCharArray();
		char curr = wordChars[0];
		int wordLen = 1;

		for (int i = 1; i < wordChars.length; i++) {
			if (wordChars[i] == curr) {
				wordLen++;
				if(wordLen > 9) {
					resultSB.append((char) wordLen + '0');
					resultSB.append(curr);
					wordLen = 1;
				}
			} else {
				resultSB.append((char) wordLen + '0');
				resultSB.append(curr);
			}
			curr = wordChars[i];
		}
	}
}

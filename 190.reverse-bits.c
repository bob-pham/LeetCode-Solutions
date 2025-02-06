// @leet start
// 00000010100101000001111010011100
// 00111001011110000010100101000000
// 11111101011010111110000101100011
uint32_t reverseBits(uint32_t n) {
	uint32_t result = 0;

	for (int i = 0; i < 31; i++) {
		result |= n & 1;
		result <<= 1;
		n >>= 1;
	}
	result |= n & 1;

	return result;
}
// @leet end

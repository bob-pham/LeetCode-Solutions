// @leet start
void reverseString(char* s, int sSize) {

	int front = sSize - 1;
	int back = 0;

	while (back < front) {
		char temp = s[back];
		s[back] = s[front];
		s[front] = temp;
		back++;
		front--;
	}
    
}
// @leet end

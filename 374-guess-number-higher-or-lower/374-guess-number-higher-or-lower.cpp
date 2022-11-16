/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
    
        int lower = 0;
        int upper = n;
        n /= 2;
        int ans = guess(n);
        
        while (ans != 0 && lower < upper) {
            if (ans == 1) {
                lower = n + 1;
            } else {
                upper = n - 1;
            }
            n = (upper - lower) / 2 + lower;
            ans = guess(n);
        }
        
        return n;
    }
};
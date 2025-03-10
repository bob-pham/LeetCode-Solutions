// @leet start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int back = 0;
        int front = 0;
        int curr_flips = 0;
        int min_flips = 100;
        int sze = blocks.size();

        while (front < sze) {

            while (front < sze && k > 0) {
                if (blocks[front] == 'W') {
                    curr_flips++;
                }
                k--;
                front++;
            }

            min_flips = min(curr_flips, min_flips);

            while (back < front) {
                if (blocks[back] == 'W') {
                    while (blocks[back] == 'W') {
                        curr_flips--;
                        back++;
                        k++;
                    }
                    break;
                } else {
                    k++;
                }
                back++;
            }
        }

        return min_flips;

        
    }
};
// @leet end

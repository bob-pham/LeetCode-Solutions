class Solution {
public:
    int climbStairs(int n) {
        
        int mem[3];
        
        if (n == 1) {
            return 1;
        }
        
        mem[0] = 0;
        mem[1] = 1;
        mem[2] = 2;
        
        for (int i = 3; i <= n; i++){
            int temp = i % 3;
            mem[temp] = mem[(temp + 1) % 3] + mem[(temp + 2) % 3];
        }        
        
        return mem[n % 3];
        
    }
};
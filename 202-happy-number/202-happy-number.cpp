class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> visited;       
        
        while (true) {
            if (n == 1) 
                return true;
            
            if (visited[n])
                return false;
            
            visited[n]++;
            int step1 = 0;
            
            while(n) {
                int temp = n % 10;
                temp *= temp;
                step1 += temp;
                n /= 10;
            }
            n = step1;
        }        
        return true;
    }
};
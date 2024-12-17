// @leet start
class Solution {
    public int punishmentNumber(int n) {
        int result = 0;

        for (int i = 1; i <= n; i++) {
            int iSqr = i * i;
            Set<Integer> sums = this.allPossibleSums(String.valueOf(iSqr), iSqr);
            if (sums.contains(i)) {
                result += iSqr;
            }
        }
        
        return result;
    }

    private Set<Integer> allPossibleSums(String num, int target) {
        Set<Integer> result = new HashSet<>();

        if (num.length() == 1 && Integer.valueOf(num) == target) {
            result.add(Integer.valueOf(num));
        }

        for (int i = 1; i < num.length(); i++) {
            String left = num.substring(0, i);
            String right = num.substring(i, num.length());
            int leftVal = Integer.valueOf(left);
            int rightVal = Integer.valueOf(right); 
            int currVal = leftVal + rightVal;
            result.add(currVal);

            // end early
            if (currVal == target) {
                return result;
            }
            Set<Integer> leftSums = this.allPossibleSums(left, target);
            Set<Integer> rightSums = this.allPossibleSums(right, target);

            for (int lSum : leftSums) {
                int localSum = lSum + rightVal;
                result.add(localSum);
                if (localSum == target) {
                    return result;
                }
            }

            for (int rSum : rightSums) {
                int localSum = rSum + leftVal;
                result.add(localSum);
                if (localSum == target) {
                    return result;
                }
            }


            for (int lSum : leftSums) {
                for (int rSum : rightSums) {
                    int localSum = rSum + lSum;
                    result.add(localSum);
                    if (localSum == target) {
                        return result;
                    }
                }
            }
        }

        return result;
    }
}
// @leet end

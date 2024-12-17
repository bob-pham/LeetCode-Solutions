// @leet start
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());

        for (int stone : stones) {
            queue.add(stone);
        }
        
        while (queue.size() > 1) {
            int first = queue.poll();
            int second = queue.poll();
            int diff = first - second;
            if (diff > 0) {
                queue.add(diff);
            }
        }
        return queue.size() == 0 ? 0 : queue.poll();
    }
}
// @leet end

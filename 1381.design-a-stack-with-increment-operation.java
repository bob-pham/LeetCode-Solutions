// @leet start
import java.util.Deque;
import java.util.ArrayDeque; 

class CustomStack {
    private int maxSize;
    private Deque<Integer> deque;

    public CustomStack(int maxSize) {
        this.deque = new ArrayDeque<>();
        this.maxSize = maxSize;
    }
    
    public void push(int x) {
        if (this.deque.size() < maxSize) {
            this.deque.addFirst(x);
        }
    }
    
    public int pop() {
        if (this.deque.size() <= 0) {
            return -1;
        }
       return this.deque.removeFirst(); 
    }
    
    public void increment(int k, int val) {
        int size = this.deque.size();
        Stack<Integer> tempStack = new Stack<>();
        for (int i = 0; i < k && i < size; i++) {
            tempStack.push(this.deque.removeLast() + val);
        }

        for (int i = 0; i < k && i < size; i++) {
            this.deque.addLast(tempStack.pop());
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
// @leet end

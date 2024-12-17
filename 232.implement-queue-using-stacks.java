// @leet start
class MyQueue {
    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

    public MyQueue() {
        this.inStack = new Stack<>();
        this.outStack = new Stack<>();
    }
    
    public void push(int x) {
        while(this.outStack.size() > 0) {
            this.inStack.add(this.outStack.pop());
        }
        this.inStack.add(x);
    }
    
    public int pop() {
        while(this.inStack.size() > 0) {
            this.outStack.add(this.inStack.pop());
        }
        return this.outStack.pop();
    }
    
    public int peek() {
        while(this.inStack.size() > 0) {
            this.outStack.add(this.inStack.pop());
        }
        return this.outStack.peek();
        
    }
    
    public boolean empty() {
       return this.inStack.size() == 0 && this.outStack.size() == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
// @leet end

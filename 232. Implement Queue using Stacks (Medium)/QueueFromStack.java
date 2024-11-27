// Reverse the stack to get the front, then reverse it again to original state
class MyQueue {
    Stack<Integer> one;
    Stack<Integer> two;

    public MyQueue() {
        one = new Stack<>();
        two = new Stack<>();
    }
    
    public void push(int x) {
        one.push(x);
        return;
    }
    
    public int pop() {
        while(!one.isEmpty()){
            two.push(one.pop());
        }
        int temp = two.pop();
        while(!two.isEmpty()){
            one.push(two.pop());
        }
        return temp;
    }
    
    public int peek() {
        while(!one.isEmpty()){
            two.push(one.pop());
        }
        int temp = two.peek();
        while(!two.isEmpty()){
            one.push(two.pop());
        }
        return temp;
    }
    
    public boolean empty() {
        return one.isEmpty();
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
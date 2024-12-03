class MyStack {
    Queue<Integer> queue;
    public MyStack() {
        queue = new LinkedList<>();
    }

    public void push(int x) {
        queue.add(x);
    }

    public int pop() {
        // move all the elements preceding the last element back to the end of the queue
        for(int i = 0; i < queue.size() - 1; i++){
            queue.add(queue.remove());
        }
        return queue.remove(); // remove the last element
    }

    public int top() {
        // move all the elements preceding the last element back to the end of the queue
        for(int i = 0; i < queue.size() - 1; i++){
            queue.add(queue.remove());
        }
        int result = queue.peek(); // peek the last element
        queue.add(queue.remove()); // move the last element to the end of the queue
        return result;
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
    /**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 * // @return true if this NestedInteger holds a single integer, rather than a
 * nested list.
 * public boolean isInteger();
 *
 * // @return the single integer that this NestedInteger holds, if it holds a
 * single integer
 * // Return null if this NestedInteger holds a nested list
 * public Integer getInteger();
 *
 * // @return the nested list that this NestedInteger holds, if it holds a
 * nested list
 * // Return empty list if this NestedInteger holds a single integer
 * public List<NestedInteger> getList();
 * }
 */
import java.util.*; 

public class NestedIterator implements Iterator<Integer> {
    private Deque<NestedInteger> stack;

    public NestedIterator(List<NestedInteger> nestedList) {
        // used stack as an easier approach, I know there's a recursion one
        // initialize the stack and push all elements of nestedList in reverse order
        // so that we can process them in the original order using LIFO
        stack = new ArrayDeque<>();
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stack.push(nestedList.get(i)); // push elements onto the stack
        }
    }

    @Override
    public Integer next() {
        // check that there is a next integer to return
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        return stack.pop().getInteger();
    }

    @Override
    public boolean hasNext() {
        // flatten the nested structure until we find an integer on top of the stack
        while (!stack.isEmpty()) {
            NestedInteger current = stack.peek(); // top element
            if (current.isInteger()) {
                return true; // the top element is an integer, so we have a next
            }
            // the top element is a list, flatten it
            stack.pop(); // remove the list from the stack
            List<NestedInteger> nestedList = current.getList();
            // push all elements of the nested list onto the stack in reverse order
            for (int i = nestedList.size() - 1; i >= 0; i--) {
                stack.push(nestedList.get(i));
            }
        }
        // if the stack is empty, there are no more integers
        return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
/*
Implement a first in first out (FIFO) queue using only two stacks. The
implemented queue should support all the functions of a normal queue (`push`,
`peek`, `pop`, and `empty`).

Implement the `MyQueue` class:

  * `void push(int x)` Pushes element x to the back of the queue.
  * `int pop()` Removes the element from the front of the queue and returns it.
  * `int peek()` Returns the element at the front of the queue.
  * `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

 **Notes:**

  * You must use **only** standard operations of a stack, which means only `push
to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
  * Depending on your language, the stack may not be supported natively. You may
simulate a stack using a list or deque (double-ended queue) as long as you use
only a stack's standard operations.

 **Example 1:**



     **Input** ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2],
[], [], []] **Output** [null, null, null, 1, 1, false] **Explanation** MyQueue
myQueue = new MyQueue();myQueue.push(1); // queue is: [1]myQueue.push(2); //
queue is: [1, 2] (leftmost is front of the queue)myQueue.peek(); // return
1myQueue.pop(); // return 1, queue is [2]myQueue.empty(); // return false

 **Constraints:**

  * `1 <= x <= 9`
  * All the calls to `pop` and `peek` are valid.

 **Follow-up:** Can you implement the queue such that each operation is
**[amortized](https://en.wikipedia.org/wiki/Amortized_analysis)** `O(1)` time
complexity? In other words, performing `n` operations will take overall `O(n)`
time even if one of those operations may take longer.


*/

#include "leetcode.hpp"

class MyQueue {
public:
  stack<int> st1, st2;
  MyQueue() {}

  void push(int x) {
    while (st1.size()) {
      int elem = st1.top();
      st1.pop();
      st2.push(elem);
    }
    st1.push(x);
    while (st2.size()) {
      int elem = st2.top();
      st2.pop();
      st1.push(elem);
    }
  }

  int pop() {
    int elem = st1.top();
    st1.pop();
    return elem;
  }

  int peek() { return st1.top(); }

  bool empty() { return st1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

TEST_CASE("implement-queue-using-stacks", "[0232]") {
  MyQueue *obj = new MyQueue();
  obj->push(1);
  obj->push(2);
  CHECK(obj->peek() == 1);
  CHECK(obj->pop() == 1);
  CHECK_FALSE(obj->empty());
}

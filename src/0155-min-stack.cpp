/*
Design a stack that supports push, pop, top, and retrieving the minimum
element in constant time.

Implement the `MinStack` class:

  * `MinStack()` initializes the stack object.
  * `void push(int val)` pushes the element `val` onto the stack.
  * `void pop()` removes the element on the top of the stack.
  * `int top()` gets the top element of the stack.
  * `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

 **Example 1:**



     **Input**
["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]
**Output** [null,null,null,null,-3,null,0,-2] **Explanation** MinStack minStack
= new
MinStack();minStack.push(-2);minStack.push(0);minStack.push(-3);minStack.getMin();
// return -3minStack.pop();minStack.top();    // return 0minStack.getMin(); //
return -2

 **Constraints:**

  * `-231 <= val <= 231 - 1`
  * Methods `pop`, `top` and `getMin` operations will always be called on
**non-empty** stacks.
  * At most `3 * 104` calls will be made to `push`, `pop`, `top`, and `getMin`.


*/

#include "leetcode.hpp"

class MinStack {
public:
  stack<int> mainStack, minTrackingStack;
  MinStack() {}

  void push(int val) {
    mainStack.push(val);
    if (minTrackingStack.size() == 0 or minTrackingStack.top() >= val) {
      minTrackingStack.push(val);
    }
  }

  void pop() {
    if (minTrackingStack.top() == mainStack.top())
      minTrackingStack.pop();

    mainStack.pop();
  }

  int top() {
    return mainStack.top();
  }

  int getMin() {
    return minTrackingStack.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

TEST_CASE("min-stack", "[0155]") {
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  CHECK(obj->getMin() == -3);
  obj->pop();
  CHECK(obj->top() == 0);
  CHECK(obj->getMin() == -2);
}

// https://leetcode.cn/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150
/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

class MinStack {
    public:
        MinStack() { m_min.push(INT_MAX); }
    
        void push(int val) {
            m_val.push(val);
            m_min.push(min(m_min.top(), val));
        }
    
        void pop() {
            m_val.pop();
            m_min.pop();
        }
    
        int top() { return m_val.top(); }
    
        int getMin() { return m_min.top(); }
    
    private:
        stack<int> m_val;
        stack<int> m_min;
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */
// https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/
/*
请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，需要实现的功能有：

get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1
add(value)：将价格为 value 的商品加入待结算商品队列的尾部
remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1
注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1)

 

示例 1：

输入: 
["Checkout","add","add","get_max","remove","get_max"]
[[],[4],[7],[],[],[]]

输出: [null,null,null,7,4,7]
示例 2：

输入: 
["Checkout","remove","get_max"]
[[],[],[]]

输出: [null,-1,-1]
*/

class Checkout {
    public:
        Checkout() {
            
        }
        
        int get_max() {
            return m_max_stk.empty()?-1:m_max_stk.top();
        }
        
        void add(int value) {
            while(!m_max_stk.empty()&&m_max_stk.top()<value)
            {
                m_max_stk.pop();
            }
    
            if(m_max_stk.empty()||m_max_stk.top()<value)
            {
                m_max_stk.push(value);
            }
    
            m_que.push(value);
            
        }
        
        int remove() {
            if(m_que.empty())
            {
                return -1;
            }
    
            int val=m_que.front();
            m_que.pop();
            while(!m_max_stk.empty()&&m_max_stk.top()==val)
            {
                m_max_stk.pop();
            }
    
            if(m_max_stk.empty()&& !m_que.empty())
            {
                queue<int> helper;
                int max_val=-1;
                while(!m_que.empty())
                {
                    max_val=max(max_val,m_que.front());
                    helper.push(m_que.front());
                    m_que.pop();
                }
    
                m_max_stk.push(max_val);
                while(!helper.empty())
                {
                    m_que.push(helper.front());
                    helper.pop();
                }
            }
    
            return val;
        }
    
    private:
        queue<int> m_que;
        stack<int> m_max_stk;
    };
    
    /**
     * Your Checkout object will be instantiated and called as such:
     * Checkout* obj = new Checkout();
     * int param_1 = obj->get_max();
     * obj->add(value);
     * int param_3 = obj->remove();
     */
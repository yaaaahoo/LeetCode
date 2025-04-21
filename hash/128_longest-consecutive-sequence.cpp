// https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
示例 3：

输入：nums = [1,0,1,2]
输出：3
*/

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> st;
            for(auto& n: nums)
            {
                st.insert(n);
            }
    
            int max_len=0;
            for(auto& val: st)
            {
                if(st.find(val-1)==st.end())
                {
                    int cur_len=1;
                    int cur_num=val;
                    while(st.find(cur_num+1)!=st.end())
                    {
                        cur_len++;
                        cur_num++;
                    }
    
                    max_len=max(max_len, cur_len);
                }
            }
    
            return max_len;
        }
    };
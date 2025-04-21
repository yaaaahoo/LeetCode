// https://leetcode.cn/problems/intersection-of-two-arrays/description/
/*
给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> s1, s2;
            for(auto& v1: nums1) s1.insert(v1);
            for(auto& v2: nums2) s2.insert(v2);
    
            vector<int> ans;
            for(auto& val: s1)
            {
                if(s2.find(val)!=s2.end())
                {
                    ans.push_back(val);
                }
            }
    
            return ans;
        }
    };
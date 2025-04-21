// https://leetcode.cn/problems/subsets-ii/description/
/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/

class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> path;
    
            sort(nums.begin(), nums.end());
            for(int k=0;k<=nums.size();++k)
            {
                backtracing(0, k, nums, path, res);
            }
    
            return res;
        }
    
        void backtracing(int start, int k, vector<int>& nums, vector<int>& path, vector<vector<int>>& res)
        {
            if(path.size()==k)
            {
                res.push_back(path);
                return;
            }
    
            for(int i=start; i<nums.size(); ++i)
            {
                if(i>start&&nums[i]==nums[i-1])
                {
                    continue;
                }
    
                path.push_back(nums[i]);
                backtracing(i+1, k, nums, path, res);
                path.pop_back();
            }
        }
    };
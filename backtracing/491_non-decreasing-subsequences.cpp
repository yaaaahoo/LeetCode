// https://leetcode.cn/problems/non-decreasing-subsequences/description/

/*
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

 

示例 1：

输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：

输入：nums = [4,4,3,2,1]
输出：[[4,4]]
*/

class Solution {
    public:
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> path;
    
            for(int k=2;k<=nums.size();++k)
            {
                backtracing(0,k,nums,path,res);
            }
    
            return res;
        }
    
        void backtracing(int start, int k, vector<int>& nums, vector<int>& path, vector<vector<int>>& res)
        {
            if(path.size()==k)
            {
                if(check(path, res)) 
                    res.emplace_back(path);
                
                return;
            }
    
            for(int i=start;i<nums.size();++i)
            {
                if(!path.empty() && nums[i]<path.back())
                {
                    continue;
                }
    
                path.push_back(nums[i]);
                backtracing(i+1,k, nums, path, res);
                path.pop_back();
            }
        }
    
        bool check(const vector<int>& path, const vector<vector<int>>& res)
        {
            // 在结果集中能找到完全相同的数组则返回 false
            // 否则返回 true
            for(auto& vec: res)
            {
                if(path.size()!=vec.size()) continue;
    
                int i;
                for(i=0;i<path.size();++i)
                {
                    if(path[i]!=vec[i])
                    {
                        break;
                    }
                }
    
                if(i==path.size())
                {
                    return false;
                }
            }
    
            return true;
        }
    };
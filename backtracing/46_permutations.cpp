// https://leetcode.cn/problems/permutations/description/
/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
*/

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> path;
            vector<int> used;
            used.resize(nums.size());
            dfs(nums, used, path, ans);
            return ans;
        }
    
        void dfs(vector<int>& nums,vector<int>& used, vector<int>& path, vector<vector<int>>& ans)
        {
            if(path.size()==nums.size())
            {
                ans.emplace_back(path);
                return;
            }
    
            for(int i=0;i<nums.size();++i)
            {
                if(used[i]==1) continue;
    
                path.push_back(nums[i]);
                used[i]=1;
                dfs(nums, used, path, ans);
                path.pop_back();
                used[i]=0;
            }
        }
    };
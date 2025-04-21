// https://leetcode.cn/problems/combination-sum-ii/
/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<int> path;
            vector<vector<int>> res;
            sort(candidates.begin(),candidates.end());
            backtracing(0,target,0,candidates,path,res);
    
            return res;
        }
    
        void backtracing(int start,int target,int curr, vector<int>& candidates,vector<int>& path, vector<vector<int>>& res)
        {
            if(curr==target)
            {
                res.emplace_back(path);
                return;
            }
    
            for(int i=start;i<candidates.size();++i)
            {
                if(candidates[i]+curr>target)
                {
                    return;
                }
    
                // 剪枝操作：如果在当前层的区间中选择了数字k，则后续的k不再进行选择。
                if(i>start&&candidates[i]==candidates[i-1])
                {
                    continue;
                }
    
                path.push_back(candidates[i]);
                backtracing(i+1,target,curr+candidates[i], candidates,path, res);
                path.pop_back();
            }
        }
    };
// https://leetcode.cn/problems/combinations/description/
/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
示例 2：

输入：n = 1, k = 1
输出：[[1]]
*/

class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<int> path;
            vector<vector<int>> res;
            backtracing(n,k,1,path,res);
    
            return res;
        }
    
        void backtracing(int n,int k,int start,vector<int>&path, vector<vector<int>>& res)
        {
            if(path.size()==k)
            {
                res.emplace_back(path);
                return;
            }
    
            for(int i=start;i<=n;i++)
            {
                path.push_back(i);
                backtracing(n,k,i+1,path,res);
                path.pop_back();
            }
        }
    };
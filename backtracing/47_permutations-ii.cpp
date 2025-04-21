// https://leetcode.cn/problems/permutations-ii/description/
/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> path;
            vector<int> used;
            used.resize(nums.size());
            dfs(nums, path, used, ans);
    
            return ans;
        }
    
        void dfs(vector<int>& nums, vector<int>& path, vector<int>& used, vector<vector<int>>& ans)
        {
            if(path.size()==nums.size()&&checkValid(ans,path))
            {
                ans.emplace_back(path);
                return;
            }
    
            for(int i=0;i<nums.size();++i)
            {
                if(used[i]==1) continue;
    
                used[i]=1;
                path.push_back(nums[i]);
                dfs(nums,path,used,ans);
                used[i]=0;
                path.pop_back();
            }
        }
    
        bool checkValid(vector<vector<int>>& ans, vector<int>& sub)
        {
            for(auto& vec: ans)
            {
                int i;
                for(i=0;i<vec.size();++i)
                {
                    if(vec[i]!=sub[i])
                    {
                        break;
                    }
                }
    
                if(i==vec.size()) return false;
            }
    
            return true;
        }
    };
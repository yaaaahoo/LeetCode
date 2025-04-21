// https://leetcode.cn/problems/palindrome-partitioning/description/
/*
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

 

示例 1：

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：

输入：s = "a"
输出：[["a"]]
*/

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> path;
    
            backtracing(0, s, path, res);
            return res;
        }
    
        void backtracing(int start, string& s, vector<string>& path, vector<vector<string>>& res)
        {
            if(start>=s.size())
            {
                res.emplace_back(path);
                return;
            }
    
            for(int i=start; i<s.size();++i)
            {
                string tmp=s.substr(start, i-start+1);
                if(!check(tmp))
                {
                    continue;
                }
    
                path.push_back(tmp);
                backtracing(i+1, s, path, res);
                path.pop_back();
            }
        }
    
        bool check(string tmp)
        {
            if(tmp.size()==1)
            {
                return true;
            }
    
            for(int i=0,j=tmp.size()-1;i<j;i++,j--)
            {
                if(tmp[i]!=tmp[j])
                {
                    return false;
                }
            }
    
            return true;
        }
    };
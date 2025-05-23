// https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]
*/

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> ans;
            unordered_map<string, vector<string>> mp;
            for(auto& str: strs)
            {
                string key=str;
                sort(key.begin(), key.end());
                mp[key].emplace_back(str);
            }
    
            for(auto iter=mp.begin();iter!=mp.end();iter++)
            {
                ans.emplace_back(iter->second);
            }
    
            return ans;
        }
    };

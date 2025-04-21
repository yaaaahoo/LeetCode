// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
*/

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> res;
            if(digits.empty())
            {
                return res;
            }
    
            map<int, string> mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},
                                 {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
            string sub="";
            backtracing(sub,res,0,mp,digits);
            return res;
        }
    
        void backtracing(string& sub, vector<string>& res, int index, map<int, string>& mp, string& digits)
        {
            if(digits.size()==sub.size())
            {
                res.emplace_back(sub);
                return;
            }
    
            if(index>=digits.size())
            {
                return;
            }
    
            string str=mp[digits[index]-'0'];
            for(int i=0;i<str.size();++i)
            {
                sub.push_back(str[i]);
                backtracing(sub, res, index+1, mp, digits);
                sub.pop_back();
            }
        }
    };
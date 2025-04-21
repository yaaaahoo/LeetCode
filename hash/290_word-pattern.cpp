// https://leetcode.cn/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150
/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

 

示例1:

输入: pattern = "abba", s = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false
*/

class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            vector<string> words;
            string w;
            for(int i=0;i<s.size();++i)
            {
                if(s[i]!=' ')
                {
                    w+=s[i];
                }
                else
                {
                    words.emplace_back(w);
                    w.clear();
                }
            }
            if(!w.empty()) words.emplace_back(w);
    
            if(pattern.size()!=words.size())
            {
                return false;
            }
    
            unordered_map<char, string> p2s;
            unordered_map<string, char> s2p;
            for(int i=0;i<pattern.size();++i)
            {
                if(p2s.find(pattern[i])!=p2s.end()&&p2s[pattern[i]]!=words[i])
                {
                    return false;
                }
                else if(s2p.find(words[i])!=s2p.end()&&s2p[words[i]]!=pattern[i])
                {
                    return false;
                }
                else
                {
                    p2s[pattern[i]]=words[i];
                    s2p[words[i]]=pattern[i];
                }
            }
    
            return true;
        }
    };
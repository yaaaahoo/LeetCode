// https://leetcode.cn/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150
/*
给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

 

示例 1:

输入：s = "egg", t = "add"
输出：true
示例 2：

输入：s = "foo", t = "bar"
输出：false
示例 3：

输入：s = "paper", t = "title"
输出：true
*/

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            if (s.size() != t.size()) {
                return false;
            }
            unordered_map<char, char> s2t;
            unordered_map<char, char> t2s;
            for (int i = 0; i < s.size(); ++i) {
                if (s2t.find(s[i]) != s2t.end() && s2t[s[i]] != t[i]) {
                    return false;
                } else if (t2s.find(t[i]) != t2s.end() && t2s[t[i]] != s[i]) {
                    return false;
                } else {
                    s2t[s[i]] = t[i];
                    t2s[t[i]] = s[i];
                }
            }
            return true;
        }
    };
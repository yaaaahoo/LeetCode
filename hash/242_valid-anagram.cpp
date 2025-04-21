// https://leetcode.cn/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150
/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。

 

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
*/

class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int> hash(26);
            for (auto& ch : s) {
                hash[ch - 'a']++;
            }
            for (auto& ch : t) {
                hash[ch - 'a']--;
            }
    
            for (auto& val : hash) {
                if (val != 0) {
                    return false;
                }
            }
            return true;
        }
    };
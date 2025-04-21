// https://leetcode.cn/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150
/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

 

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true
*/

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if(magazine.size()<ransomNote.size()) return false;
    
            unordered_map<char, int> mp;
            for(auto& ch: magazine)
            {
                mp[ch]++;
            }
    
            for(auto& ch: ransomNote)
            {
                if(mp.find(ch)==mp.end())
                {
                    return false;
                }
                else
                {
                    mp[ch]--;
                    if(mp[ch]<0)
                    {
                        return false;
                    }
                }
            }
    
            return true;
        }
    };
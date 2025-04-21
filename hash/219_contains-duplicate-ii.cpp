// https://leetcode.cn/problems/contains-duplicate-ii/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,1], k = 3
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1
输出：true
示例 3：

输入：nums = [1,2,3,1,2,3], k = 2
输出：false
*/

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            for(int i=0;i<nums.size();++i)
            {
                for(int j=i+1;j<=i+k&&j<nums.size();++j)
                {
                    if(nums[i]==nums[j])
                    {
                        return true;
                    }
                }
            }
    
            return false;
        }
    };
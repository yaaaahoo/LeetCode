// https://leetcode.cn/problems/subsets/description/
/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> results;
            for (int mask = 0; mask < (1 << n); mask++) {
                vector<int> res;
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        res.emplace_back(nums[i]);
                    }
                }
                results.emplace_back(move(res));
            }
            return results;
        }
    };
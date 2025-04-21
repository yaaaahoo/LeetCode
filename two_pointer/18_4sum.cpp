// https://leetcode.cn/problems/4sum/description/
/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            if(nums.size()<4) return ans;
    
            sort(nums.begin(), nums.end());
            for(int i=0;i<nums.size();++i)
            {
                if(i>0&&nums[i]==nums[i-1])
                {
                    continue;
                }
                for(int j=i+1;j<nums.size();++j)
                {
                    if(j>i+1&&nums[j]==nums[j-1])
                    {
                        continue;
                    }
    
                    int left=j+1;
                    int right=nums.size()-1;
                    while(left<right)
                    {
                        long val=(long)nums[i]+nums[j]+nums[left]+nums[right];
                        if(val<target)
                        {
                            left++;
                        }
                        else if(val>target)
                        {
                            right--;
                        }
                        else
                        {
                            ans.push_back({nums[i], nums[j], nums[left], nums[right]});
    
                            while(left<right&&nums[left]==nums[left+1]) left++;
                            while(left<right&&nums[right]==nums[right-1]) right--;
    
                            left++;
                            right--;
                        }
                    }
                }
            }
    
            return ans;
        }
    };
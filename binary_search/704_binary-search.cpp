
// https://leetcode.cn/problems/binary-search/description/
/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
*/
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            sort(nums.begin(),nums.end());
            int l=0,r=nums.size()-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(nums[mid]<target)
                {
                    l=mid+1;
                }
                else if(nums[mid]>target)
                {
                    r=mid-1;
                }
                else
                {
                    return mid;
                }
            }
    
            return -1;
        }
    };
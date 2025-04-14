// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
*/

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            if(nums.empty()) return {-1,-1};
            int left=binarySearch(nums, target, true);
            int right=binarySearch(nums,target,false)-1;
            if(left<=right&&left>=0&&right<nums.size()&&nums[left]==target&&nums[right]==target)
            {
                return {left,right};
            }
            
            return {-1,-1};
        }
    
        int binarySearch(vector<int>& nums, int target, bool equal)
        {
            int l=0,r=nums.size()-1;
            int ans=nums.size();
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(nums[mid]>target||(equal&&nums[mid]==target))
                {
                    r=mid-1;
                    ans=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            return ans;
        }
    };
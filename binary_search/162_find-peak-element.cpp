// https://leetcode.cn/problems/find-peak-element/
/*
峰值元素是指其值严格大于左右相邻值的元素。
s
给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
*/

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            auto GetVal=[nums](int index)->int64_t{
                if(index>=0&&index<=nums.size()-1)
                {
                    return nums[index];
                }
                return INT64_MIN;
            };
            int l=0,r=nums.size()-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(GetVal(mid)>GetVal(mid-1)&&GetVal(mid)>GetVal(mid+1))
                {
                    return mid;
                }
                else if(GetVal(mid)>GetVal(mid+1))
                {
                    r=mid-1;
                }
                else if(GetVal(mid)<GetVal(mid+1))
                {
                    l=mid+1;
                }
            }
    
            return 0;
        }
    };
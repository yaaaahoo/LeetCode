// https://leetcode.cn/problems/median-of-two-sorted-arrays/
/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> nums;
            nums.resize(nums1.size()+nums2.size());
            int i=0,j=0,k=0;
            while(i<nums1.size()&&j<nums2.size())
            {
                if(nums1[i]<nums2[j])
                {
                    nums[k++]=nums1[i++];
                }
                else
                {
                    nums[k++]=nums2[j++];
                }
            }
    
            while(i<nums1.size()) nums[k++]=nums1[i++];
            while(j<nums2.size()) nums[k++]=nums2[j++];
    
            int mid=nums.size()/2;
            return nums.size()%2?nums[mid]:(nums[mid-1]+nums[mid])/2.0;
        }
    };
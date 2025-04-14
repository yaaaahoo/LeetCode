// https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/
/*
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

你必须尽可能减少整个操作步骤。
*/

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int l=0,r=nums.size()-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(nums[mid]==target)
                {
                    return true;
                }
    
                if(nums[l]==nums[mid]&&nums[mid]==nums[r])
                {
                    l++;
                    r--;
                }
                else if(nums[l]<=nums[mid]) // 这里必须是等于的判断，否则区间划分将出现问题
                {
                    if(nums[mid]>target&&nums[l]<=target)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                else
                {
                    if(nums[mid]<target&&target<=nums[r])
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
            }
    
            return false;
        }
    };
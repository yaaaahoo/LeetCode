// https://leetcode.cn/problems/spiral-matrix-ii/
/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*/

class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> ans;
            ans.resize(n);
            for(auto& vec: ans) vec.resize(n);
    
            int top=0,bottom=n-1,left=0,right=n-1;
            int val=1;
            while(left<=right&&top<=bottom)
            {
                for(int j=left;j<=right;++j)
                {
                    ans[top][j]=val++;
                }
                for(int i=top+1;i<=bottom;++i)
                {
                    ans[i][right]=val++;
                }
                if(left<right&&top<bottom)
                {
                    for(int j=right-1;j>left;--j)
                    {
                        ans[bottom][j]=val++;
                    }
                    for(int i=bottom;i>top;--i)
                    {
                        ans[i][left]=val++;
                    }
                }
    
                top++;
                bottom--;
                left++;
                right--;
            }
    
            return ans;
        }
    };
// https://leetcode.cn/problems/spiral-matrix/
/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
            while(top<=bottom&&left<=right)
            {
                for(int j=left;j<=right;++j)
                {
                    ans.push_back(matrix[top][j]);
                }
                for(int i=top+1;i<=bottom;++i)
                {
                    ans.push_back(matrix[i][right]);
                }
                if(left<right&&top<bottom)
                {
                    for(int j=right-1;j>left;--j)
                    {
                        ans.push_back(matrix[bottom][j]);
                    }
                    for(int i=bottom;i>top;--i)
                    {
                        ans.push_back(matrix[i][left]);
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
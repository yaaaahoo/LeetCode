// https://leetcode.cn/problems/find-a-peak-element-ii/
/*
一个 2D 网格中的 峰值 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。

给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 峰值 mat[i][j] 并 返回其位置 [i,j] 。

你可以假设整个矩阵周边环绕着一圈值为 -1 的格子。

要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法
*/

class Solution {
    public:
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int top=0,bottom=mat.size()-1;
            while(top<=bottom)
            {
                int mid=top+(bottom-top)/2;
                auto max_iter=std::max_element(mat[mid].begin(),mat[mid].end());
                int j=std::distance(mat[mid].begin(),max_iter);
                if(check(mat, mid, j))
                {
                    return {mid,j};
                }
                else
                {
                    if(mid-1>=0&&mat[mid-1][j]>mat[mid][j])
                    {
                        bottom=mid-1;
                    }
                    else if(mid+1<=bottom&&mat[mid+1][j]>mat[mid][j])
                    {
                        top=mid+1;
                    }
                }
            }
    
            return {};
        }
    
        bool check(vector<vector<int>>& mat, int i, int j)
        {
            bool ret=true;
            int cur=mat[i][j];
            if(i-1>=0&&mat[i-1][j]>cur)
            {
                ret = false;
            }
            else if(i+1<mat.size()&&mat[i+1][j]>cur)
            {
                ret = false;
            }
            else if(j-1>=0&&mat[i][j-1]>cur)
            {
                ret = false;
            }
            else if(j+1<mat[0].size()&&mat[i][j+1]>cur)
            {
                ret = false;
            }
            
            return ret;
        }
    };
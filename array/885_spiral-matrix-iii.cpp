// https://leetcode.cn/problems/spiral-matrix-iii/
/*
在 rows x cols 的网格上，你从单元格 (rStart, cStart) 面朝东面开始。网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。

你需要以顺时针按螺旋状行走，访问此网格中的每个位置。每当移动到网格的边界之外时，需要继续在网格之外行走（但稍后可能会返回到网格边界）。

最终，我们到过网格的所有 rows x cols 个空间。

按照访问顺序返回表示网格位置的坐标列表。
*/

class Solution {
    public:
        enum class Direction
        {
            RIGHT,
            DOWN,
            LEFT,
            UP
        };
    
        vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
            vector<vector<int>> ans;
    
            int index=0;
            int r=rStart,c=cStart;
            int left=cStart-1,right=cStart+1,top=rStart-1,bottom=rStart+1;
            vector<vector<int>> op={{0,1},{1,0},{0,-1},{-1,0}};
            Direction dir=Direction::RIGHT;
    
            while(index<rows*cols)
            {
                if(r>=0&&r<rows&&c>=0&&c<cols)
                {
                    ans.push_back({r,c});
                    index++;
                }
    
                if(dir==Direction::RIGHT&&c==right)
                {
                    dir=Direction::DOWN;
                    right++;
                }
                else if(dir==Direction::DOWN&&r==bottom)
                {
                    dir=Direction::LEFT;
                    bottom++;
                }
                else if(dir==Direction::LEFT&&c==left)
                {
                    dir=Direction::UP;
                    left--;
                }
                else if(dir==Direction::UP&r==top)
                {
                    dir=Direction::RIGHT;
                    top--;
                }
    
                r+=op[static_cast<int>(dir)][0];
                c+=op[static_cast<int>(dir)][1];
            }
            return ans;
        }
    };
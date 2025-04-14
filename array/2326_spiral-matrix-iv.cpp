// https://leetcode.cn/problems/spiral-matrix-iv/
/*
给你两个整数：m 和 n ，表示矩阵的维数。

另给你一个整数链表的头节点 head 。

请你生成一个大小为 m x n 的螺旋矩阵，矩阵包含链表中的所有整数。链表中的整数从矩阵 左上角 开始、顺时针 按 螺旋 顺序填充。如果还存在剩余的空格，则用 -1 填充。

返回生成的矩阵。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
            vector<vector<int>> ans;
            ans.resize(m);
            for(auto& vec: ans) vec.resize(n);
    
            int left=0,right=n-1,top=0,bottom=m-1;
            while(left<=right&&top<=bottom)
            {
                for(int j=left;j<=right;++j)
                {
                    ans[top][j]=head!=nullptr?head->val:-1;
                    if(head!=nullptr) head=head->next;
                }
                for(int i=top+1;i<=bottom;++i)
                {
                    ans[i][right]=head!=nullptr?head->val:-1;
                    if(head!=nullptr) head=head->next;
                }
                if(left<right&&top<bottom)
                {
                    for(int j=right-1;j>left;--j)
                    {
                        ans[bottom][j]=head!=nullptr?head->val:-1;
                        if(head!=nullptr) head=head->next;
                    }
                    for(int i=bottom;i>top;--i)
                    {
                        ans[i][left]=head!=nullptr?head->val:-1;
                        if(head!=nullptr) head=head->next;
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
// https://leetcode.cn/problems/reverse-nodes-in-k-group/?envType=study-plan-v2&envId=top-interview-150
/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head) return nullptr;
    
            ListNode* left_node=head;
            ListNode* right_node=head;
            for(int i=0;i<k;++i)
            {
                if(!right_node)
                {
                    return head;
                }
                
                right_node=right_node->next;
            }
    
            ListNode*nhead=reverseList(left_node,right_node);
            ListNode*ntail=nhead;
            for(int i=0;i<k-1;++i)
            {
                ntail=ntail->next;
            }
    
            ntail->next=reverseKGroup(right_node, k);
    
            return nhead;
        }
    
        ListNode* reverseList(ListNode* left_node,ListNode* right_node)
        {
            ListNode* pre=nullptr;
            ListNode* cur=left_node;
            ListNode* nxt=left_node;
            while(cur!=right_node)
            {
                nxt=cur->next;
                cur->next=pre;
                pre=cur;
                cur=nxt;
            }
    
            return pre;
        }
    };
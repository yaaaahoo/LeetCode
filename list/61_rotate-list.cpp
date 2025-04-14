// https://leetcode.cn/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
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
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head) return head;
            
            int len=getLen(head);
            k=k%len;
            if(k==0) return head;
    
            int n=len-k;
            ListNode* pre_tail=head;
            ListNode* nhead=head;
            for(int i=0;i<n;++i)
            {
                pre_tail=nhead;
                nhead=nhead->next;
            }
            pre_tail->next=nullptr;
    
            ListNode* ntail=nhead;
            while(ntail&&ntail->next)
            {
                ntail=ntail->next;
            }
            ntail->next=head;
            return nhead;
        }
    
        int getLen(ListNode* head)
        {
            int len=0;
            ListNode* node=head;
            while(node)
            {
                node=node->next;
                len++;
            }
    
            return len;
        }
    };
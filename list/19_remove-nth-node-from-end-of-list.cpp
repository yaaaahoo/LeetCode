// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
    
            ListNode* start=new ListNode();
            start->next=head;
            
            ListNode* slow=start;
            ListNode* fast=start->next;
            while(n--)
            {
                fast=fast->next;
            }
    
            while(fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
    
            slow->next=slow->next->next;
            return start->next;
        }
    };
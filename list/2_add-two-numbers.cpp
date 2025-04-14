// https://leetcode.cn/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* start=new ListNode();
            ListNode* cur=start;
            int num=0; // 进位
            while(l1||l2)
            {
                int val1=l1?l1->val:0;
                int val2=l2?l2->val:0;
                int val=val1+val2+num;
                num=val/10;
    
                ListNode* node=new ListNode(val%10);
                cur->next=node;
                cur=cur->next;
    
                if(l1) l1=l1->next;
                if(l2) l2=l2->next;
            }
    
            if(num!=0)
            {
                ListNode* node=new ListNode(num);
                cur->next=node;
            }
    
            return start->next;
        }
    };
// https://leetcode.cn/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* start=new ListNode();
            ListNode* cur=start;
            while(list1&&list2)
            {
                if(list1->val<list2->val)
                {
                    cur->next=list1;
                    list1=list1->next;
                }
                else
                {
                    cur->next=list2;
                    list2=list2->next;
                }
    
                cur=cur->next;
            }
    
            if(list1) cur->next=list1;
            if(list2) cur->next=list2;
    
            return start->next;
        }
    };
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan-v2&envId=top-interview-150
/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* start=new ListNode();
            start->next=head;
    
            ListNode* node=start;
            while(node->next!=nullptr&&node->next->next!=nullptr)
            {
                if(node->next->val==node->next->next->val)
                {
                    int target=node->next->val;
                    while(node->next&&node->next->val==target)
                    {
                        node->next=node->next->next;
                    }
                }
                else
                {
                    node=node->next;
                }
            }
    
            return start->next;
        }
    };
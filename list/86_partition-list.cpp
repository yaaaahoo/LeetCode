// https://leetcode.cn/problems/partition-list/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。
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
        ListNode* partition(ListNode* head, int x) {
            ListNode* left_start=new ListNode();
            ListNode* left_node=left_start;
            ListNode* right_start=new ListNode();
            ListNode* right_node=right_start;
    
            ListNode* node=head;
            while(node)
            {
                if(node->val<x)
                {
                    left_node->next=node;
                    left_node=left_node->next;
                }
                else
                {
                    right_node->next=node;
                    right_node=right_node->next;
                }
    
                node=node->next;
            }
    
            left_node->next=right_start->next;
            right_node->next=nullptr;
    
            return left_start->next;
        }
    };
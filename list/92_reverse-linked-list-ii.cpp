// https://leetcode.cn/problems/reverse-linked-list-ii/?envType=study-plan-v2&envId=top-interview-150
/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(!head) return nullptr;
            if(left==right) return head;
    
            ListNode* start=new ListNode();
            start->next=head;
    
            int n=left-1;
            ListNode* left_tail=start;
            while(n--)
            {
                left_tail=left_tail->next;
            }
    
            n=right-left+1;
            ListNode* right_head=left_tail->next;
            while(n--)
            {
                right_head=right_head->next;
            }
    
            ListNode* node=reverseList(left_tail->next, right_head);
            left_tail->next=node;
            n=right-left;
            while(n--)
            {
                node=node->next;
            }
            node->next=right_head;
    
            return start->next;
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
// https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if(!head) return nullptr;
            addNode(head);
            addRandom(head);
            return breakList(head);
        }
    
        void addNode(Node* head)
        {
            Node* node=head;
            while(node)
            {
                Node* copy_node=new Node(node->val);
                copy_node->next=node->next;
                node->next=copy_node;
                node=node->next->next;
            }
        }
    
        void addRandom(Node* head)
        {
            Node* node=head;
            while(node)
            {
                node->next->random=node->random!=nullptr?node->random->next:nullptr;
                node=node->next->next;
            }
        }
    
        Node* breakList(Node* head)
        {
            Node* nhead=head->next;
            Node* cur=head;
            Node* ncur=head->next;
            while(cur)
            {
                cur->next=cur->next->next;
                cur=cur->next;
                if(cur)
                {
                    ncur->next=cur->next;
                    ncur=ncur->next;
                }
            }
    
            return nhead;
        }
    };
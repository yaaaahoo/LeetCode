// https://leetcode.cn/problems/lru-cache/?envType=study-plan-v2&envId=top-interview-150
/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/


class Node {
    public:
        Node(int k = 0, int v = 0) : key(k), val(v) {}
    
        int key = 0;
        int val = 0;
        Node* pre = nullptr;
        Node* next = nullptr;
    };
    
    class DoubleList {
    public:
        DoubleList() {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->next = head;
        }
    
        void addNode(Node* node) {
            node->pre = head;
            node->next = head->next;
            head->next->pre = node;
            head->next = node;
            len++;
        }
    
        void deleteNode(Node* node) {
            node->pre->next = node->next;
            node->next->pre = node->pre;
            len--;
        }
    
        Node* deleteLastNode() {
            if (len > 0) {
                Node* node = tail->pre;
                deleteNode(node);
                return node;
            }
            return nullptr;
        }
    
        int getLen() { return len; }
    
    private:
        int len = 0;
        Node* head = nullptr;
        Node* tail = nullptr;
    };
    
    class LRUCache {
    public:
        LRUCache(int capacity) {
            cap = capacity;
            list = new DoubleList();
        }
    
        int get(int key) {
            if (mp.find(key) != mp.end()) {
                updateRecently(key);
                auto node = mp[key];
                return node->val;
            }
            return -1;
        }
    
        void put(int key, int value) {
            if (mp.find(key) != mp.end()) {
                deleteKey(key);
            } else {
                if (list->getLen() == cap) {
                    deleteRecentlyUnUsed();
                }
            }
            addRecently(key, value);
        }
    
    private:
        void updateRecently(int key) {
            if (mp.find(key) != mp.end()) {
                auto node = mp[key];
                deleteKey(key);
                addRecently(key, node->val);
            }
        }
    
        void addRecently(int key, int val) {
            Node* node = new Node(key, val);
            list->addNode(node);
            mp[key] = node;
        }
    
        void deleteKey(int key) {
            if (mp.find(key) != mp.end()) {
                auto node = mp[key];
                mp.erase(key);
                list->deleteNode(node);
            }
        }
    
        void deleteRecentlyUnUsed() {
            auto node = list->deleteLastNode();
            mp.erase(node->key);
        }
    
    private:
        int cap = 0;
        unordered_map<int, Node*> mp;
        DoubleList* list = nullptr;
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
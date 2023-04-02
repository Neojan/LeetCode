/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
//定义双链表
// @lc code=start
class LRUCache {
private:
    //双向链表
    struct Node
    {
        int   key;
        int   value;
        Node *prev;
        Node *next;
        Node(int _key, int _value)
            : key(_key), value(_value), prev(NULL), next(NULL){};
    };
    Node                      *head;
    Node                      *tail;
    int                        m_capacity;
    unordered_map<int, Node *> hash;

public:
    LRUCache(int n)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        m_capacity = n;
    }
    void insertToHead(Node *p)
    {
        //插入到头部
        p->next          = head->next;
        p->prev          = head;
        head->next->prev = p;
        head->next       = p;
    }
    void remove(Node *p)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    int get(int key)
    {
        if (0 == hash.count(key))
        {
            return -1;
        }
        auto p = hash[key];
        // 将p移到开头
        remove(p);
        insertToHead(p);
        return p->value;
    }
    void put(int key, int value)
    {
        if (hash.count(key))
        {
            auto p   = hash[key];
            p->value = value;
            remove(p);
            insertToHead(p);
        }
        else
        {
            if (m_capacity == hash.size())
            {
                auto p = tail->prev;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            insertToHead(p);
            hash[key] = p;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

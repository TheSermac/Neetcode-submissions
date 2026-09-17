class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode() : key(-1), val(-1), next(nullptr), prev(nullptr) {}

        ListNode(int k, int v)
            : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    int cap;
    int curr_size;

    unordered_map<int, ListNode*> lru_map;

    // head = most recently used
    // tail = least recently used
    ListNode* head;
    ListNode* tail;

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert_front(ListNode* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : cap(capacity), curr_size(0) {
        head = new ListNode();
        tail = new ListNode();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (lru_map.find(key) == lru_map.end()) {
            return -1;
        }

        ListNode* node = lru_map[key];

        // This key was just used, so move it to the front.
        remove(node);
        insert_front(node);

        return node->val;
    }

    void put(int key, int value) {
        // Key already exists
        if (lru_map.find(key) != lru_map.end()) {
            ListNode* node = lru_map[key];

            node->val = value;

            // It was just used, so move it to the front.
            remove(node);
            insert_front(node);

            return;
        }

        // New key
        ListNode* node = new ListNode(key, value);

        lru_map[key] = node;
        insert_front(node);
        curr_size++;

        // Cache is too large -> remove LRU node
        if (curr_size > cap) {
            ListNode* lru = tail->prev;

            lru_map.erase(lru->key);
            remove(lru);
            delete lru;

            curr_size--;
        }
    }
};

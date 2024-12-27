class LRUCache {
public:
    class DLL {
    public:
        int key;
        int val;
        DLL* prev;
        DLL* next;

        DLL(int key, int val) {
            this->key = key;  // Corrected the constructor
            this->val = val;
        }
    };

    DLL* head = new DLL(-1, -1);
    DLL* tail = new DLL(-1, -1);
    int cap;
    unordered_map<int, DLL*> hash;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;  // Initialize head and tail pointers
        tail->prev = head;
    }

    void addnode(DLL* newNode) {
        DLL* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(DLL* delNode) {
        DLL* prevv = delNode->prev;
        DLL* nextt = delNode->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()) {
            DLL* Node = hash[key];
            int ans = Node->val;
            hash.erase(key);
            deleteNode(Node);
            addnode(Node);
            hash[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            DLL* curr = hash[key];
            hash.erase(key);
            deleteNode(curr);
        }

        if (hash.size() == cap) {
            hash.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addnode(new DLL(key, value));
        hash[key] = head->next;
    }
};

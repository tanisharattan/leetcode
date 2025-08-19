class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

 
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

   
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            int ans = node->val;

            delNode(node);
            addNode(node);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
      
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            delNode(existingNode);
            m.erase(key);
            delete existingNode; 
        }

        
        if (m.size() == limit) {
            Node* lru = tail->prev;
            delNode(lru);
            m.erase(lru->key);
            delete lru;
        }

       
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

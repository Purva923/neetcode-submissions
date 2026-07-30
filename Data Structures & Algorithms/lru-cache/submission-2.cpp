class LRUCache {
private:
    struct Node
    {
        int key, val;
        Node *next;
        Node *prev;

        Node(int key, int val)
            : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    int cap = 0, occ = 0;
    map<int, Node*> mp;
    Node *left = nullptr;
    Node *right = nullptr;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node *temp = mp[key];

        if (temp == right)
            return right->val;

        if (temp == left)
        {
            left = left->next;
            left->prev = nullptr;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        temp->next = nullptr;
        temp->prev = right;
        right->next = temp;
        right = temp;

        return right->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end())
        {
            mp[key]->val = value;
            get(key);              // move it to the rear
            return;
        }

        if (cap == 0)
            return;

        if (occ == cap)
        {
            Node *old = left;

            if (left == right)
            {
                left = right = nullptr;
            }
            else
            {
                left = left->next;
                left->prev = nullptr;
            }

            mp.erase(old->key);
            delete old;
            occ--;
        }

        Node *newnode = new Node(key, value);

        if (occ == 0)
        {
            left = right = newnode;
        }
        else
        {
            right->next = newnode;
            newnode->prev = right;
            right = newnode;
        }

        mp[key] = newnode;
        occ++;
    }
};
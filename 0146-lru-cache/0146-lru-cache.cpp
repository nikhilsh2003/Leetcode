struct Node {
    int key,val;
    Node *prev,*next;
    Node(int key, int val) {
        this->key=key;
        this->val=val;
        this->prev=NULL;
        this->next=NULL;
    }

};
class LRUCache {
public:
    Node *head,*tail;
    int capacity;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=head->prev=tail;
        tail->next=tail->prev=head;
    }

    void deleteNode(Node* node) {
        mp.erase(node->key);
        node->prev->next=node->next;
        node->next->prev=node->prev;
        capacity++;
        delete node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* curr=mp[key];
        if(curr->prev==head) return curr->val;
        int val=curr->val;
        deleteNode(curr);
        put(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            deleteNode(mp[key]);
        }
        if(capacity==0) {
            deleteNode(tail->prev);            
        }
        Node* newNode=new Node(key,value);
        // cout<<key<<" "<<value<<endl;
        mp[key]=newNode;
        head->next->prev=newNode;
        newNode->next=head->next;
        newNode->prev=head;
        head->next=newNode;
        capacity--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
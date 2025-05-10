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
        Node* curr=head;
        map<Node*, Node*> mp;
        while(curr) {
            Node* temp=new Node(curr->val);
            mp[curr]=temp;
            curr=curr->next; 
        }
        curr=head;
        while(curr) {
            Node* newNode=mp[curr];
            newNode->next=mp[curr->next];
            newNode->random=mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
    }
};
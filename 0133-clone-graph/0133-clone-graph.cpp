/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<int, Node*> newNode;
        stack<Node*> st;
        st.push(node);
        newNode[1]=new Node(1);
        while(!st.empty()) {
            Node* topV=st.top();
            st.pop();
            for(auto &x:topV->neighbors) {
                if(newNode.find(x->val)!=newNode.end()) continue;
                newNode[x->val]=new Node(x->val);
                st.push(x);
            }
        }
        st.push(node);
        set<int> stCount;
        stCount.insert(1);
        while(!st.empty()) {
            Node* topV=st.top();
            Node* newTop=newNode[topV->val];
            st.pop();
            for(auto &x:topV->neighbors) {
                newTop->neighbors.push_back(newNode[x->val]);
                if(stCount.count(x->val)!=0) continue;
                stCount.insert(x->val);
                st.push(x);
            }
        }
        return newNode[1];
    }
};
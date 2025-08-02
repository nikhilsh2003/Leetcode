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
        map<int, Node*> oldMap;
        stack<Node*> st;
        st.push(node);
        map<int, Node*> newMap;
        oldMap[node->val]=node;
        while(!st.empty()) {
            Node* topV=st.top();
            newMap[topV->val]=new Node(topV->val);
            st.pop();
            for(auto &x:topV->neighbors) {
                if(oldMap.find(x->val)!=oldMap.end()) continue;
                oldMap[x->val]=x;
                st.push(x);
            }
        }
        for(auto &x:oldMap) {
            for(auto y:x.second->neighbors) {
                newMap[x.first]->neighbors.push_back(newMap[y->val]);
            }
        }
        return newMap[1];
    }
};
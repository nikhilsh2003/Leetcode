/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    vector<int> elements;
    FindElements(TreeNode* root) {
        if(!root) return;
        root->val=0;
        elements.push_back(0);
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* top=st.top();
            st.pop();
            if(top->left) {
                int x=top->val*2+1;
                top->left->val=x;
                st.push(top->left);
                elements.push_back(x);
            }
            if(top->right) {
                int x=top->val*2+2;
                top->right->val=x;
                st.push(top->right);
                elements.push_back(x);
            }
        }
        sort(elements.begin(),elements.end());
    }
    
    bool find(int target) {
        int low=0,high=elements.size()-1,mid;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(elements[mid]==target) return 1;
            else if(elements[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
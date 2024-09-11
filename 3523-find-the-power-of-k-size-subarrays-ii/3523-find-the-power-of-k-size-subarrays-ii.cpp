class Solution {
public:
    void emptyQueue(queue<int> &q) {
        queue<int> empty;
        swap(q,empty);
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        queue<int> q;
        int n=nums.size();
        for(int i=0;i<k-1;i++) {
            if(q.empty() or q.front()+q.size()==nums[i])
                q.push(nums[i]);
            else
                {emptyQueue(q);
                q.push(nums[i]);}
        }
        vector<int> ans;
        for(int i=k-1;i<n;i++) {
            if(q.size()==k) q.pop();
            if(q.empty() or q.front()+q.size()==nums[i])
                q.push(nums[i]);
            else
                {emptyQueue(q);
                q.push(nums[i]);}
            if(q.size()==k)
                ans.push_back(q.front()+q.size()-1);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
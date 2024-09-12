class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> q;
        vector<int> ans;
        for(int i=0;i<queries.size();i++) {
            q.push(abs(queries[i][0])+abs(queries[i][1]));
            if(q.size()>k) q.pop();
            if(q.size()<k) ans.push_back(-1);
            else ans.push_back(q.top());
        }
        return ans;
    }
};
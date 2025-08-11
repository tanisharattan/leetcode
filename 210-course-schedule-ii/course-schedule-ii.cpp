class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);

        }
vector<int>indegrees(numCourses,0);
        for(int i =0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegrees[it]++;
            }
        }

        queue<int>q;
        vector<int>ans;
        int count =0;
        for(int i =0;i<numCourses;i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                indegrees[it]--;
                if(indegrees[it]==0){
                    q.push(it);
                }
            }
        }

        if(ans.size()==numCourses)return ans;
        else {
            return {};
        }
    }
};
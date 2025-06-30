class Solution {
    private:
   void dfs(vector<vector<int>>&adjLs,int node ,vector<int>&vis ){
         vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
       dfs(adjLs,it ,vis );
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int V=isConnected.size();
       vector<vector<int>>adjLs(V);
       for(int i=0;i<V;i++){
       
        for(int j=0;j<V;j++){
            if(isConnected[i][j]==1 && i!=j){
                adjLs[i].push_back(j);
                   adjLs[j].push_back(i);

            }
        }


       }

       vector<int>vis(V,0);
       int count =0;
       for(int i=0;i<V;i++){
        if(!vis[i]){
            count ++;
            dfs(adjLs,i,vis);
        }
       }

       
return count ;
    }
};
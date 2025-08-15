class Solution {
    private:
    int find(vector<int>& heights){
       int n = heights.size();
        stack<int>st;
        vector<int>left(n);
        vector<int>right(n);

        for(int i =n-1 ; i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
              st.pop();
            }
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

         for(int i =0 ; i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
              st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }

       int ans=0;
       for(int i =0;i<n;i++){
        int width=right[i]-left[i]-1;
        int Area=heights[i]*width;
        ans=max(Area, ans);
       }
       return ans;
        
        
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()|| matrix[0].empty())return 0;
        int maxArea=0;
        int cols=matrix[0].size();
        int rows=matrix.size();
        vector<int>height(cols,0);
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(matrix[r][c]=='1'){
                    height[c]+=1;
                }
                else height[c]=0;
            }
            maxArea=max(maxArea,find(height));
        }
return maxArea;
    }
};
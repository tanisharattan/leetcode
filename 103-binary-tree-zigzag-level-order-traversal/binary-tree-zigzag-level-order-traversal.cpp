class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>traversal;
       queue<TreeNode*>q;
       if(root==NULL){
        return traversal;
       }
       bool leftToRight=true;
       q.push(root);
       while(!q.empty()){
        int size=q.size();
        vector<int>row(size);
        for(int i =0;i<size;i++){
    TreeNode* node = q.front();
    q.pop();
    int index=(leftToRight)? i:(size-1-i);
    row[index]=node->val;

    if(node->left)q.push(node->left);
       if(node->right)q.push(node->right);
        }
        traversal.push_back(row);
        leftToRight=!leftToRight;
       }
       return traversal;

    }
};

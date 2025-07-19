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
class Solution {
       private:
    int find(TreeNode* root,int &maxi){

  if (root==NULL){
    return 0;
  }
  int lh=max(0,find(root->left,maxi));
  int rh=max(0,find(root->right,maxi));
  maxi=max(maxi,lh+rh+root->val);
  return max(lh,rh)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
 
   int path=INT_MIN ;
   find(root,path);
   return path;
    }
};
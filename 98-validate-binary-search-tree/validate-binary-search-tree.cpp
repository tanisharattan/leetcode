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
    bool solve ( TreeNode* root , long long mn , long long mx){
        if(!root){
            return true;
        }
        if( root->val<=mn || root->val>=mx){
            return false;
        }
    return solve(root->left, mn, root->val) && 
               solve(root->right, root->val, mx);
    }
public:
    bool isValidBST(TreeNode* root) {
       return solve (root , LLONG_MIN,LLONG_MAX);
    }
};
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
    int find(TreeNode* root,int &diameter){
if(root==NULL)return 0;
int left=find(root->left,diameter);
int right=find(root->right,diameter);

diameter=max(left+right, diameter);
return 1+max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
    int diameter=0;
    find(root,diameter);
    return diameter;
    }
};
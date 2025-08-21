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
    vector<int>val;
void inOrder(TreeNode* root){

    if(root==NULL){
        return ;
    }

    else{
        inOrder(root->left);
val.push_back(root->val);
inOrder(root->right);
    }
}
public:
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int left =0;
        int right =val.size()-1;
        while(left<right){
            int s= val[left]+val[right];
            if(s==k){
                return true;
            }
            else if(s>k){
               right--;
            }
            else{
                left++;
            }
        }
return false;
    }
};
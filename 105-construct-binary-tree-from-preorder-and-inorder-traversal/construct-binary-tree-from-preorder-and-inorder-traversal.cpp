/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // Helper function to find index of current root in inorder traversal
    int search(vector<int>& inorder, int left, int right, int target) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == target) return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preInd, int left, int right) {
        if (left > right) return NULL;

        // Root node is the current preorder element
        TreeNode* root = new TreeNode(preorder[preInd]);
        preInd++;

        // Find root index in inorder
        int inIndex = search(inorder, left, right, root->val);

        // Recursively build left and right subtrees
        root->left = helper(preorder, inorder, preInd, left, inIndex - 1);
        root->right = helper(preorder, inorder, preInd, inIndex + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd = 0;
        return helper(preorder, inorder, preInd, 0, inorder.size() - 1);
    }
};

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
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        int n = vec.size();
        int start = 0;
        int end = n -1 ;
        int mid = (start + end)/2;
        TreeNode* head = new TreeNode(vec[mid]);
        head ->left = placenodes(start , mid-1,vec);
        head->right = placenodes(mid+1, end , vec);
        return head;
    }
    TreeNode* placenodes(int start , int end , vector<int> vec){
        if(start <= end){
            int mid = (start+end)/2;
            TreeNode * root = new TreeNode(vec[mid]);
            root->left = placenodes(start,mid -1 , vec);
            root->right = placenodes(mid+1 , end , vec);
            return root;
        }
        return nullptr;
    }
    void inorder(TreeNode * root , vector<int>&vec){
        if(root){
            inorder(root->left,vec);
            vec.push_back(root->val);
            inorder(root->right,vec);
        }
    }
};
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

    int greatestElementIndex(int &s, int &e, vector<int> &nums) {
        int maxi = s;
        for (int i = s; i <= e; i++) {
            if (nums[i] > nums[maxi]) maxi = i;
        }

        return maxi;
    }

    TreeNode* solve(int s, int e, vector<int> &nums) {
        // bc
        if (s > e) return NULL;

        
        int maxi = greatestElementIndex(s, e, nums);
      
        TreeNode* root = new TreeNode(nums[maxi]);
        
        // baaki rec sambhalega
        root->left = solve(s, maxi-1, nums);
        root->right = solve(maxi+1, e, nums);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        

      
        stack<TreeNode*> st;

        for (auto num : nums) {
            TreeNode* newNode = new TreeNode(num);

          
            while (!st.empty() && st.top()->val < num){
                // connect curr to stack's left
                newNode->left = st.top();
                st.pop();
            }
            
           
            if (!st.empty()) {
                st.top()->right = newNode;
            }

           
            st.push(newNode);
        }

        
        while (st.size() != 1) st.pop();

        return st.top();
    }
};
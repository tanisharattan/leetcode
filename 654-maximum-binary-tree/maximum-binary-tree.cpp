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

        // ek case mai sambhalunga
        // find greatest element index in curr range
        int maxi = greatestElementIndex(s, e, nums);
        // create node of maxi index
        TreeNode* root = new TreeNode(nums[maxi]);
        
        // baaki rec sambhalega
        root->left = solve(s, maxi-1, nums);
        root->right = solve(maxi+1, e, nums);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // // 01 approach - o(n2)
        // int s = 0;
        // int e = nums.size()-1;

        // return solve(s, e, nums);

        // 02 approach - monotonic stack - o(n) - ** need to revise again **
        stack<TreeNode*> st;

        for (auto num : nums) {
            // create node of curr element
            TreeNode* newNode = new TreeNode(num);

            // bigger element found in array
            // if smaller than newNode are found in stack
            // then connect newNode' left to stack node 
            while (!st.empty() && st.top()->val < num){
                // connect curr to stack's left
                newNode->left = st.top();
                st.pop();
            }
            
            // stack not mepty means there is node in stack > num
            if (!st.empty()) {
                st.top()->right = newNode;
            }

            // greater node found, push
            st.push(newNode);
        }

        // retrieve head of the tree
        while (st.size() != 1) st.pop();

        return st.top();
    }
};
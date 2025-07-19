class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* curr = p.first;
            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(curr->val);  

            if (curr->left) {
                todo.push({curr->left, {x - 1, y + 1}});
            }
            if (curr->right) {
                todo.push({curr->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

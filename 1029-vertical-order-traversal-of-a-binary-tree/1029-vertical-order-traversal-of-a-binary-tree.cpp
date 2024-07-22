/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> m;

        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int verticle = it.second.first;
            int level = it.second.second;

            m[verticle][level].insert(node->val);

            if (node->left) {
                q.push({node->left, {verticle - 1, level + 1}});
            }

            if (node->right) {
                q.push({node->right, {verticle + 1, level + 1}});
            }
        }

        vector<vector<int>> result;

        for (auto in_map : m) {
            vector<int> each_level;
            for (auto in_map_map : in_map.second) {
                each_level.insert(each_level.end(), in_map_map.second.begin(),
                                  in_map_map.second.end());
            }

            result.push_back(each_level);
        }

        return result;
    }
};
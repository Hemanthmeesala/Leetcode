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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int index = 0;
        return helper(preorder, inorder, 0, preorder.size() - 1, map, index);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, unordered_map<int, int>& map, int& index) {
        if (left > right) {
            return nullptr;
        }

        int curr = preorder[index++];
        TreeNode* node = new TreeNode(curr);

        if (left == right) {
            return node;
        }

        int inorderIndex = map[curr];
        node->left = helper(preorder, inorder, left, inorderIndex - 1, map, index);
        node->right = helper(preorder, inorder, inorderIndex + 1, right, map, index);

        return node;
    }
};
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
    int diameterOfBinaryTree(TreeNode* root) {
        // Define a helper function to calculate the diameter recursively
        int res = 0;
        diameter(root, res);
        return res;
    }

private:
    int diameter(TreeNode* node, int& res){
        // Base case: if the nodeent node is null, return 0
        if (!node) return 0;
        
        // Recursively calculate the diameter of left and right subtrees
        int left = diameter(node->left, res);
        int right = diameter(node->right, res);

        // Update the maximum diameter encountered so far
        res = std::max(res, left + right);
        
        // Return the depth of the nodeent node
        return std::max(left, right) + 1;
    }
};
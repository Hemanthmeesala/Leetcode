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
public:
    void build(TreeNode *root, unordered_map<int,vector<int>> &g)
    {
        if(root->left)
        {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            build(root->left,g);
        }

        if(root->right)
        {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            build(root->right,g);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
        {
            vector<int> a;
            a.push_back(target->val);
            return a;
        }

        unordered_map<int,vector<int>> g;
        build(root,g);
        unordered_map<int,bool> vis;

        vector<int> ans;
        queue<int> q;
        int dist=0;

        q.push(target->val);

        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int curr=q.front();
                q.pop();
                vis[curr]=true;
                for(auto it: g[curr])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                    }
                }
            }
            dist++;
            if(dist==k)
            {
                while(!q.empty())
                {
                    ans.push_back(q.front());
                    q.pop();
                }
            }
        }
        return ans;
    }
};
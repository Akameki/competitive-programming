#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        queue<int> level;

        q.push(root);
        level.push(0);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            int l = level.front(); level.pop();
            if (!t) continue;

            if (l == ans.size()) ans.push_back(t->val);
            else ans[l] = max(ans[l], t->val);

            q.push(t->left);
            level.push(l + 1);
            q.push(t->right);
            level.push(l + 1);
        }
        return ans;
    }
};
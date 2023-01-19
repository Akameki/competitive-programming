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
private:
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return ans;
    }

    void traverse(TreeNode *node) {
        if (node == nullptr) return;
        ans.push_back(node->val);
        traverse(node->left);
        traverse(node->right);
    }
};
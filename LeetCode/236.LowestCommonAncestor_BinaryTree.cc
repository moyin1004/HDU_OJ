/// @file    236.LowestCommonAncestor_BinaryTree.cc
/// @data    2020-07-10 17:40:41

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 非递归解法
class Solution {
public:
    bool FindTreeNode(TreeNode *T, TreeNode *p) {
        if (!T) return false;
        if (T == p) return true;
        if (FindTreeNode(T->left, p) || FindTreeNode(T->right, p))
            return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        stack<TreeNode *> s;
        TreeNode *r, *bt = root;
        // 后序遍历，首次找到p或q
        while (bt || !s.empty()) {
            while (bt && bt != q && bt != p) {
                s.push(bt);
                bt = bt->left;
            }
            if (bt == q || bt == p) {
                if (bt == q) swap(p, q);
                break;
            }
            bt = s.top();
            if (bt->right && bt->right != r) {
                bt = bt->right;
            }
            else {
                r = bt;
                bt = NULL;
                s.pop();
            }
        }
        // 寻找祖先结点，首先查找首次遍历到的结点的子树
        if (FindTreeNode(p, q)) return p;
        r = p;
        while (!s.empty()) {
            bt = s.top();
            s.pop();
            // 每次查找栈内祖先结点的右子树
            if (bt->right != r && FindTreeNode(bt->right, q)) {
                return bt;
            }
            r = bt;
        }
        return NULL;
    }
};

// 递归解法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
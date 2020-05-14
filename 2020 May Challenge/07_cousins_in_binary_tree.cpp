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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
            return false;

        int parentX = -1;
        int heightX = findHeight(root, parentX, x, 0);

        int parentY = -1;
        int heightY = findHeight(root, parentY, y, 0);

        if(parentX != parentY && heightX == heightY)
            return true;

        return false;
    }

    int findHeight(TreeNode* root, int& parent, int value, int height){

        //boundary case
        if(root == NULL)
            return 0;

        //if found, return height of node
        if(root->val == value)
            return height;

        //update parent, and search for value in left subtree
        parent = root->val;
        int left = findHeight(root->left, parent, value, height + 1);
        if(left) //node is found
            return left;

        //if node is not found, //update parent, and search for value in right subtree
        parent = root->val;
        int right = findHeight(root->right, parent, value, height + 1);
        return right;
    }
};

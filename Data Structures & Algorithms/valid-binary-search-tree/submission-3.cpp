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
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* curr, long left, long right){
        if(!curr){
            return true;
        }

        if(!(left < curr->val && curr->val < right)){
            return false;
        }
    

        return helper(curr->left, left, curr->val) && helper(curr->right,  curr->val, right);
    }
};

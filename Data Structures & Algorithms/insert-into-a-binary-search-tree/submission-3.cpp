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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(5);
        }
        helper(root, val);
        return root;
        
    }

    void helper(TreeNode* root, int val){
        if(root->val > val){
            if(!root->left){
                TreeNode* newNode = new TreeNode(val);
                root->left = newNode;
                return; 
            }
            helper(root->left, val);
        }else{
             if(!root->right){
                TreeNode* newNode = new TreeNode(val);
                root->right = newNode;
                return; 
            }
            helper(root->right, val);
        }

        return;
    }
};
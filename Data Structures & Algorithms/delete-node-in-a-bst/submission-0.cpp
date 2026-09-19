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
   TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == nullptr){
            return nullptr;
        }
        
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            
        }else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else{
            //find the in order predecessor
            if(!root->right){
                return root->left;
            }else if(!root->left){
                return root->right;
            }

            TreeNode* pred = inPred(root->right);
            pred->left = root->left;
            TreeNode* res = root->right;
            
            delete root;

            return res;
        }

        return root;
    }

    TreeNode* inPred(TreeNode* root){
        if(root->left){
            return inPred(root->left);
        }
        return root;
    }
};
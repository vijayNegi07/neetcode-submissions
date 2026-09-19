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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root){
            return result;
        }

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            int levelSize = qu.size();
            vector<int> level;

            for(int i = 0; i < levelSize; i++){
                auto it = qu.front();
                qu.pop();

                level.push_back(it->val);

                if(it->left){
                    qu.push(it->left);
                }

                if(it->right){
                    qu.push(it->right);
                }
            }


            result.push_back(level.back());
        }

        return result;

    }
};

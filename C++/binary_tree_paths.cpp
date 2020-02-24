/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string> 

class Solution {
public:
    void storePaths(vector<string>& result, TreeNode* root, string path) {
            if(root == NULL) return;

            if(root->right == NULL && root->left == NULL) {
                result.push_back(path + to_string(root->val));
                return;
            }
            
            path += to_string(root->val) + "->";
            
            storePaths(result, root->left, path);
            storePaths(result, root->right, path);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        storePaths(result, root, "");      
        return result;
    }
};

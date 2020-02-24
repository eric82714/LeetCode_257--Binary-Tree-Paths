/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void copy(char* result, int solution[], int len) {
    int j = 0;
    for(int i = 0; i < len; i++) {
        j += sprintf(result+j, "%d->", solution[i]);
    }

    result[j-2] = '\0';
}

void storePaths(char** result, int path[], struct TreeNode* root, int* size1, int size2){
    if(!root) return;
    
    if(!root->right && !root->left){
        result[*size1] = (char*)malloc(1000 * sizeof(char));
        path[size2++] = root->val;
        copy(result[*size1], path, size2);
        (*size1)++;
        return;
    }
    
    path[size2++] = root->val;
            
    storePaths(result, path, root->left, size1, size2);
    storePaths(result, path, root->right, size1, size2);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    char** result = malloc(1000 * sizeof(char*));
    int path[1000];
    storePaths(result, path, root, returnSize, 0);      
    return result;
}

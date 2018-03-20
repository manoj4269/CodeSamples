/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    struct TreeNode* left_r;
    while(root!=NULL){
        if(root->left != NULL) {
        left_r = root->left;
        while(left_r->right != NULL) left_r = left_r->right;
        left_r->right = root->right;
        root->right = root->left;
        root->left = NULL;
        }
        root = root->right;
    }
}

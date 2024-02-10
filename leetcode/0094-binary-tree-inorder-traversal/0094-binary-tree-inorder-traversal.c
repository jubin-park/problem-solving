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
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* ret = malloc(100 * sizeof(int));
    *returnSize = 0;

    recursive(root, ret, returnSize);

    return ret;
}

void recursive(struct TreeNode* root, int* places, int* returnSize)
{
    if (root == NULL)
        return;
    
    if (root->left)
        recursive(root->left, places, returnSize);

    places[(*returnSize)++] = root->val;

    if (root->right)
        recursive(root->right, places, returnSize);
}
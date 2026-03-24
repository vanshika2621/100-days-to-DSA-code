struct TreeNode* lowestCommonAncestor(struct TreeNode* root,
                                      struct TreeNode* p,
                                      struct TreeNode* q) {
    // Base case
    if (root == NULL || root == p || root == q)
        return root;

    // Search in left and right subtree
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides found something → current node is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-null child
    return (left != NULL) ? left : right;
}
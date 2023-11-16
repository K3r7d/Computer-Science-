int singleChild(BSTNode* root) {
    if (!root) return 0;

    if ((root->left == nullptr)^(root->right == nullptr)) {
        return 1 + singleChild(root->left) + singleChild(root->right);
    }

    return singleChild(root->left) + singleChild(root->right);
}
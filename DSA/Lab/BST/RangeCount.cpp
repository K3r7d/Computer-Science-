int rangeCount(BTNode* root, int lo, int hi) {
    if(!root) return 0;
    if(root->val<=hi && root->val >= lo) return 1 + rangeCount(root->left, lo, hi) + rangeCount(root->right,lo, hi);
    return rangeCount(root->left, lo, hi) + rangeCount(root->right,lo, hi); 
}
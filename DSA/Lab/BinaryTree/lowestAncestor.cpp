int lowestAncestor(BTNode* root, int a, int b) {
    if(!root) return -1;
    if(root->val == a || root->val == b) return root->val;
    
    int l = lowestAncestor(root->left, a, b);
    int r = lowestAncestor(root->right, a, b);
    if (l!=-1 && r!=-1) return root->val;
    else if(l!=-1) return l;
    else return r;
}
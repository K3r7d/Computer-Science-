void helper(BSTNode* root, vector<int>& v){
    if(!root) return;
    v.push_back(root->val);
    helper(root->right, v);
    helper(root->left, v);
}
int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    vector<int> v;
    helper(root,v);
    sort(v.begin(),v.end());
    return v[k-1];
}
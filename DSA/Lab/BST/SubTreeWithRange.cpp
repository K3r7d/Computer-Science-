void help(BSTNode* root, int lo, int hi, int* arr, int &len){
    if (!root) return;
    if (root->val <= hi && root->val>= lo) {
        arr[len] = root->val;
        len++;
    }
    help(root->left, lo, hi, arr, len);
    help(root->right, lo, hi, arr, len);
}


BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    // STUDENT ANSWER
    int arr[100000];
    int len = 0;
    help(root, lo, hi, arr, len);
    BSTNode* ans = BSTNode::createBSTree(arr, arr+len);
    return ans;
}
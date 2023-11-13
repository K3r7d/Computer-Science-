const int MOD = 27022001;
int sumDigitPathUlti(BTNode* root, int currNum) {
    if (!root) return 0;
        currNum = (currNum * 10 + root->val) % MOD;
    if (!root->left && !root->right)
    return currNum;
        int leftSum = sumDigitPathUlti(root->left, currNum) % MOD;
        int rightSum = sumDigitPathUlti(root->right, currNum) % MOD;
    return (leftSum+rightSum) % MOD;
}
int sumDigitPath(BTNode* root) {
    if (!root) return 0;
    int result = sumDigitPathUlti(root, 0);
    return result;
}
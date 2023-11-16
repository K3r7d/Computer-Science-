std::vector<int> levelAlterTraverse(BSTNode* root) {
    if (!root) return {};

    std::vector<int> ans;
    std::queue<BSTNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        std::vector<int> levelVals(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            BSTNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : levelSize - 1 - i;
            levelVals[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.insert(ans.end(), levelVals.begin(), levelVals.end());
        leftToRight = !leftToRight;
    }

    return ans;
}
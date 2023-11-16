// STUDENT ANSWER BEGIN
// You can define other functions here to help you.


T min(Node* root){
    if(!root) return 0;
    if(!root->pLeft) return root->value;
    return min(root->pLeft);
}

T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    return min(root);
}

T max(Node* root){
    if(!root) return 0;
    if(root->pRight==nullptr) return root->value;
    return max(root->pRight);
}

T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    return max(root);
}

// STUDENT ANSWER END
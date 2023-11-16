// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

bool findR(T i, Node* root){
    if(!root) return 0;
    if(i == root->value) return true;
    else return (findR(i,root->pRight) || findR(i,root->pLeft));
}

bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    return findR(i, root);
}
void sumR(T l, T r, Node* root, T &sum){
    if(!root) return;
    if(root->value <= r && root->value >= l) sum+= root->value;
    sumR(l,r,root->pRight,sum);
    sumR(l,r,root->pLeft,sum);
}
T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    T sum = 0;
    sumR(l,r,root,sum);
    return sum;
}

// STUDENT ANSWER END
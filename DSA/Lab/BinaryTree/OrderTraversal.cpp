// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int height(Node* root){
    if(!root) return 0;
    else return 1 + max(height(root->pRight), height(root->pLeft));
}

int getHeight() {
    // TODO: return height of the binary tree.
    return height(root);
}

void pre(Node* root, stringstream& ss){
    if(root){
        ss << root->value << " ";
        pre(root->pLeft, ss);
        pre(root->pRight, ss);
    }
}

string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    stringstream ss;
    pre(root, ss);
    return ss.str();
}

void in(Node* root, stringstream &ss){
    if(root){
        in(root->pLeft, ss);
        ss << root->value << " ";
        in(root->pRight, ss);
    }
}

string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    stringstream ss;
    in(root, ss);
    return ss.str();
}

void post(Node* root, stringstream& ss){
    if(root){
        post(root->pLeft, ss);
        post(root->pRight, ss);
        ss << root->value << " ";
    }
}

string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    stringstream ss;
    post(root, ss);
    return ss.str();
}
// STUDENT ANSWER END

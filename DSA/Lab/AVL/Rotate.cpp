Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* temp = root->pLeft;
    root->pLeft = temp->pRight;
    temp->pRight = root;
    return temp;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* temp = root->pRight;
    root->pRight = temp->pLeft;
    temp->pLeft = root;
    return temp;
}
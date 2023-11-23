//Helping functions

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

int getBalance(Node* root){
    if(!root) return 0;
    return getHeightRec(root->pLeft) - getHeightRec(root->pRight);
}

Node* Insert(const T &value, Node* node){
    if(!node) return new Node(value);
    if(value<node->data){
        node->pLeft = Insert(value, node->pLeft);
    }
    else if(value>=node->data){
        node->pRight = Insert(value,node->pRight); 
    }
    
    int balance = getBalance(node);
    if(balance > 1 && value < node->pLeft->data)
        return rotateRight(node);
    if(balance < -1 && value >= node->pRight->data)
        return rotateLeft(node);
    if(balance > 1 && value >= node->pLeft->data){
        node->pLeft = rotateLeft(node->pLeft);
        return rotateRight(node);
    }
    if(balance < -1 && value < node->pRight->data){
        node->pRight = rotateRight(node->pRight);
        return rotateLeft(node);
    }
    return node;
}

void insert(const T &value){
    //TODO
    this->root = Insert(value, this->root);
}


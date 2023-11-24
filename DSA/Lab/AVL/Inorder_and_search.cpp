void Inorder(Node* root){
    if(!root) return;
    Inorder(root->pLeft);
    cout<<root->data<<" ";
    Inorder(root->pRight);
}

void printInorder(){
        //TODO
        Inorder(root);
    }
    
    bool s(const T &value, Node* root){
        if(!root) return 0;
        if(root->data == value) return 1;
        return s(value, root->pLeft) || s(value, root->pRight);
    }
    
    bool search(const T &value){
        //TODO
        return s(value, this->root);
    }
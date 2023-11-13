        //Helping functions
void help(Node* root,int &sum){
    if(!root) return;
    if(root && root->pRight==nullptr && root->pLeft==nullptr){
        sum+= root->value;
    }
    help(root->pRight, sum);
    help(root->pLeft, sum);
    return;
}

int sumOfLeafs(){
    //TODO
    int sum = 0;
    help(root,sum);
    return sum;
}
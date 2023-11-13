// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
void helper(Node* root,int &count){
    if(!root) return;
    if(root->pRight!=nullptr && root->pLeft!= nullptr) count++;
    helper(root->pRight,count);
    helper(root->pLeft,count);
    
}


int countTwoChildrenNode()
{
    int count = 0;
    helper(root, count);
    return count;
}
// STUDENT ANSWER END
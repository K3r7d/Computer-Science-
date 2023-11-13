// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
void BFSf(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->value << " ";

        if (current->pLeft != nullptr) {
            q.push(current->pLeft);
        }

        if (current->pRight != nullptr) {
            q.push(current->pRight);
        }
    }
}



void BFS()
{
    BFSf(root);
}
// STUDENT ANSWER END
#include <iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = removeRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

    void preorderTraversal(){
        preorderTraversalRecursive(root);
    }

    void postorderTraversal(){
        postorderTraversalRecursive(root);
    }

    void breadthFirstTraversal(){
        BFS(root);
    }

    void depthFirstTraversal(){
        DFS(root);
    }

private:
    TreeNode* insertRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    TreeNode* removeRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = removeRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = removeRecursive(root->right, value);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* minNode = findMinNode(root->right);
            root->data = minNode->data;
            root->right = removeRecursive(root->right, minNode->data);
        }

        return root;
    }

    bool searchRecursive(TreeNode* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (value == root->data) {
            return true;
        } else if (value < root->data) {
            return searchRecursive(root->left, value);
        } else {
            return searchRecursive(root->right, value);
        }
    }

    void inorderTraversalRecursive(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        inorderTraversalRecursive(root->left);
        std::cout << root->data << " ";
        inorderTraversalRecursive(root->right);
    }

    void preorderTraversalRecursive(TreeNode * root){
        if(root == nullptr){
            return;
        }
        cout<< root->data << " ";
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);     
    }

    void postorderTraversalRecursive(TreeNode * root){
        if(root == nullptr){
            return;
        }
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        cout<< root->data<<" ";
    }

    void BFS(TreeNode* root) {
        if (root == nullptr)
            return;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    void DFS(TreeNode* root) {
        if (root == nullptr)
            return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();

            cout << current->data << " ";

            if (current->right != nullptr)
                st.push(current->right);

            if (current->left != nullptr)
                st.push(current->left);
        }
    }


    TreeNode* findMinNode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
};

int main() {
    BinaryTree tree;

    // Inserting elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Performing inorder traversal
    cout << "Inorder traversal: ";
    tree.inorderTraversal();
    cout << endl;
    cout << "Preorder traversal ";
    tree.preorderTraversal();
    cout << endl;
    cout << "Postorder traversal ";
    tree.postorderTraversal();
    cout << endl;
    cout << "Breadth First traversal ";
    tree.breadthFirstTraversal();
    cout << endl;
    cout << "Depth First traversal ";
    tree.depthFirstTraversal();
    cout << endl;


    // Searching for an element
    int value = 40;
    if (tree.search(value)) {
        cout << value << " is found in the tree." << std::endl;
    } else {
        cout << value << " is not found in the tree." << std::endl;
    }

    // Removing an element
    value = 30;
    tree.remove(value);
    cout << "Inorder traversal after removing " << value << ": ";
    tree.inorderTraversal();
    cout << std::endl;

    return 0;
}

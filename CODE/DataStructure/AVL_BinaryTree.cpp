#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL_tree {
public:
    Node* root;
    AVL_tree() {
        root = nullptr;
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    Node* leftRotate(Node* node) {
        Node* right = node->right;
        Node* left = right->left;
        right->left = node;
        node->right = left;
        node->height = max(height(node->left), height(node->right)) + 1;
        right->height = max(height(right->left), height(right->right)) + 1;
        return right;
    }

    Node* rightRotate(Node* node) {
        Node* left = node->left;
        Node* right = left->right;
        left->right = node;
        node->left = right;
        node->height = max(height(node->left), height(node->right)) + 1;
        left->height = max(height(left->left), height(left->right)) + 1;
        return left;
    }

    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr) return new Node(data);
        if (data < node->data) node->left = insert(node->left, data);
        else if (data > node->data) node->right = insert(node->right, data);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) return rightRotate(node);
        if (balance < -1 && data > node->right->data) return leftRotate(node);
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* remove(Node* node, int data) {
        if (node == nullptr) return node;
        if (data < node->data) node->left = remove(node->left, data);
        else if (data > node->data) node->right = remove(node->right, data);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr) return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
        if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void print() {
        inOrder(root);
    }
};

int main() {
    AVL_tree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);
    tree.print();
    cout << endl;

    tree.root = tree.remove(tree.root, 30);
    cout << "After removing 30:" << endl;
    tree.print();
    cout << endl;

    tree.root = tree.insert(tree.root, 90);
    tree.root = tree.insert(tree.root, 100);
    cout << "After inserting 90 and 100:" << endl;
    tree.print();
    cout << endl;

    return 0;
}

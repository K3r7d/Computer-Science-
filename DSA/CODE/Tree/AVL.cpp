#include<iostream>

using namespace std;

class AVL_tree{
    public:
    class Node{
        public:
        int data;
        Node* left;
        Node* right;
        enum Balance {L, R, H};
        Node() : data(0), left(nullptr), right(nullptr) {};
        Node(int x) : data(x), left(nullptr), right(nullptr) {};
    };
    private:
    Node* root;

    public:
    AVL_tree() : root(nullptr){};

    Node* left_Rotate(Node* y){
        Node* temp = y->right;
        y->right = temp->left;
        temp->right = y;
        return temp;
    }

    Node* right_Rotate(Node* y){
        Node* temp = y->left;
        y->left = temp->right;
        temp->right = y;
        return temp;
    }

    Node* left_right(Node* y){
        Node* temp = right_Rotate(y);
        temp = left_Rotate(temp);
        return temp;
    }
    Node* right_left(Node* y){
        Node*temp = left_Rotate(temp);
        temp = right_Rotate(y);
        return temp;
    }

    void insert(Node* newPtr, bool taller = false){
        if(root == nullptr){
            root = newPtr;
            taller = true;
        }
        else{
            
        }
    }

};


int main(){

}
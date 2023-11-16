#include<iostream>

class Heap{
    class Node{
        public:
        int val;
        Node* left;
        Node* right;
        Node() : val(0), left(nullptr), right(nullptr) {};
        Node(int x) : val(x) , left(nullptr), right(nullptr) {};
        Node(Node* node) : val(node->val), left(node->left), right(node->right);
    };
    private:
        Node* root;
    public:
        Heap() : root(nullptr){}
        Node* createHeap(int*arr, int n){

        }
        
        void reHeapUp(){
            
        }
        void reHeapDown(){

        }
};
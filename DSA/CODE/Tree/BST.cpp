#include<iostream>

using namespace std;


class BST{
    public:
        struct Node
        {
            int data;
            Node *left;
            Node *right;
            Node(int x){
                data = x;
                left = nullptr;
                right = nullptr;
            }
            Node(){
                data = 0;
                left = nullptr;
                right = nullptr;
            }
        };  

    private: 
        Node *root;
    public:
        BST(){
            root = nullptr;
        }
        void insert(int x){
            if(root == nullptr){
                root = new Node(x);
                return;
            }
            Node *cur = root;
            while(cur != nullptr){
                if(cur->data > x){
                    if(cur->left == nullptr){
                        cur->left = new Node(x);
                        return;
                    }
                    cur = cur->left;
                }
                else if(cur->data < x){
                    if(cur->right == nullptr){
                        cur->right = new Node(x);
                        return;
                    }
                    cur = cur->right;
                }
                else return;
            }
        }
        void insertRec(int x){
            root = insertRec(root, x);
        }
        Node* insertRec(Node *cur, int x){
            if(cur == nullptr){
                cur = new Node(x);
                return cur;
            }
            if(cur->data > x){
                cur->left = insertRec(cur->left, x);
            }
            else if(cur->data < x){
                cur->right = insertRec(cur->right, x);
            }
            return cur;
        }
        void PreOrder(){
            PreOrder(root);
        }
        void PreOrder(Node *cur){
            if(cur == nullptr) return;
            cout << cur->data << " ";
            PreOrder(cur->left);
            PreOrder(cur->right);
        }
        void InOrder(){
            InOrder(root);
        }
        void InOrder(Node *cur){
            if(cur == nullptr) return;
            InOrder(cur->left);
            cout << cur->data << " ";
            InOrder(cur->right);
        }



        void PostOrder(){
            PostOrder(root);
        }
        void PostOrder(Node *cur){
            if(cur == nullptr) return;
            PostOrder(cur->left);
            PostOrder(cur->right);
            cout << cur->data << " ";
        }



        void remove(int x){
            root = remove(root, x);
        }
        Node* remove(Node *cur, int x){
            if(cur == nullptr) return cur;
            if(cur->data > x){
                cur->left = remove(cur->left, x);
            }
            else if(cur->data < x){
                cur->right = remove(cur->right, x);
            }
            else{
                if(cur->left == nullptr){
                    Node *temp = cur->right;
                    delete cur;
                    return temp;
                }
                else if(cur->right == nullptr){
                    Node *temp = cur->left;
                    delete cur;
                    return temp;
                }
                else{
                    Node *temp = cur->right;
                    while(temp->left != nullptr){
                        temp = temp->left;
                    }
                    cur->data = temp->data;
                    cur->right = remove(cur->right, temp->data);
                }
            }
            return cur;
        }


        bool search(int x){
            return search(root, x);
        }
        bool search(Node* cur, int x){
            if(cur == nullptr) return false;
            if(cur->data == x) return true;
            if(cur->data > x) return search(cur->left, x);
            return search(cur->right, x);
        }

        int height(){
            return height(root);
        }
        int height(Node *cur){
            if(cur == nullptr) return 0;
            return max(height(cur->left), height(cur->right)) + 1;
        }



        int countNode(){
            return countNode(root);
        }
        int countNode(Node* root){
            if(root == nullptr) return 0;
            return countNode(root->left) + countNode(root->right) + 1;
        }
        

};


int main(){
    int arr[10] = {5, 3, 7, 2, 4, 6, 8, 1, 9, 10};
    BST bst;
    for(int i = 0; i < 10; i++){
        bst.insertRec(arr[i]);
    }
    cout<<"PreOrder: ";
    bst.PreOrder();
    cout<<endl;

    cout<<"InOrder: ";
    bst.InOrder();
    cout<<endl;

    cout<<"PostOrder: ";
    bst.PostOrder();
    cout<<endl;

    cout<<"Height: "<<bst.height()<<endl;

    cout<<"Count Node: "<<bst.countNode()<<endl;

    cout<<"Search 5: "<<bst.search(5)<<endl;

    cout<<"Search 11: "<<bst.search(11)<<endl;  

    bst.remove(5);

    cout<<"PreOrder: ";
    bst.PreOrder();
    cout<<endl;
    
    return 0;

}
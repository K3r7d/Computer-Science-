#include<iostream>
#include<fstream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
    Node(int x, Node* prev) : data{x} , previous{prev}, next{nullptr} {} 
};

class DoublyLinkedList{
    private:
        Node* head = nullptr;
        Node* last = nullptr;
        int len = 0;
    public:
        Node* gethead(){
            return head;
        }
        Node* gettail(){
            return last;
        }
        int length(){
            return len;
        }
        void printLinkedList(){
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void createLinkedList(string file_input){
            ifstream file(file_input);
            int x;
            Node* temp = nullptr;
            while(file>>x){
                if(head == nullptr){
                    head = new Node(x,nullptr);
                    temp = head;
                }
                else {
                    temp->next = new Node(x,temp);
                    temp = temp->next;
                }
                len++;
            }
        }
};

int main(){
    string filename = "input.txt";
    DoublyLinkedList dll;
    dll.createLinkedList(filename);   
    dll.printLinkedList();
    cout<<endl;
    cout<<"length of list"<<dll.length();
    return 0;
}

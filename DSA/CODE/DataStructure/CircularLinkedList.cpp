#include<iostream>
#include<fstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) : data{data}, next(nullptr) {}
};

class CircularLinkedList {
    private:
        Node* head = nullptr;
        int len = 0;
    public:
        int length(){return len;};
        Node* Head(){return head;};
        void create(string filename){
            ifstream file(filename);
            Node* temp = nullptr;
            int x;
            while(file >> x){
                if(head == nullptr){
                    head = new Node(x);
                    temp = head;
                }
                else{
                    temp->next = new Node(x);
                    temp = temp->next;
                }
                len++;
            }
            if(temp != nullptr) 
                temp->next = head;
        }
        void print() {
            if(head == nullptr) {
                cout << "The list is empty." << endl;
                return;
            }
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while(temp != head);
            cout << endl;
        }

 
};

int main(){
    CircularLinkedList cll;
    cll.create("input.txt");
    cll.print();
    return 0;
}
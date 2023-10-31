#include<iostream>
#include "ListADT.h"
using namespace std;

template <class T>
class CircularLinkedList : public ListADT<T>
{
    class Node{
    public:
        T data;
        Node* next;
        
        Node(){
            this->data = 0;
            this->next = NULL;
        }
        Node(T data){
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
            next = NULL;
        }
    };
    private:
        Node* head;
        int count;
    public:
        CircularLinkedList(){
            this->head = new Node();
            this->count = 0;
        }
        ~CircularLinkedList(){
            Node* temp = head->next;
            while (temp != nullptr) {
                Node* t = temp;
                temp = temp->next;
                delete t;
            }
        }
        void insert(T data){
            if(head->next == nullptr){
                head->next = new Node(data);
                head->next->next = head->next;
            }
            else{
                Node* temp = head->next;
                while(temp->next != head->next){
                    temp = temp->next;
                }
                temp->next = new Node(data);
                temp->next->next = head->next;
            }
            count++;
        }
        void insertNode(Node* node){
            if(head->next == nullptr){
                head->next = node;
                head->next->next = head->next;
            }
            else{
                Node* temp = head->next;
                while(temp->next != head->next){
                    temp = temp->next;
                }
                temp->next = node;
                temp->next->next = head->next;
            }
            count++;
        }
        void print(){
            Node* temp = head->next;
            while(temp->next != head->next){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<" ";
            cout<<endl;
        }
        void remove(T data) {
            if(head->next == nullptr) return;
            Node* temp = head->next;
            Node* prev = nullptr;

            while (temp->next != head->next && temp->data != data) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp == head->next) {
                if (temp->next == head->next) {
                    head->next = nullptr;
                }
                else {
                    Node* t = temp->next;
                    while (t->next != head->next) {
                        t = t->next;
                    }
                    head->next = temp->next;
                    t->next = head->next;
                }
            }
            else if (temp->next == head->next) {
                prev->next = head->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            count--;
        }
        bool search(T data){
            Node* temp = head->next;
            while (temp->next!= head->next) {
                if (temp->data == data) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        int size(){return count;}
        bool isEmpty(){return count == 0;}

};

// int main(){
//     int arr[10] = {9, 3, 4, 8, 2, 1, 7, 6, 5, 0};
//     CircularLinkedList<int> list;
//     for(int i = 0;i<10;i++){
//         list.insert(arr[i]);
//     }
//     list.print();
// }
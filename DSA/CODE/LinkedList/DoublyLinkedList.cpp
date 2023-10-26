#include<iostream>
#include "ListADT.h"
using namespace std;

template <class T>
class DoublyLinkedList : public ListADT<T>
{
    class Node{
    public:
        T data;
        Node* next;
        Node* prev;
        
        Node(){
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }
        Node(T data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        ~Node(){
            next = NULL;
            prev = NULL;
        }
    };
    private:
        Node* head;
        int count;
    public:
        DoublyLinkedList(){
            this->head = new Node();
            this->count = 0;
        }
        ~DoublyLinkedList(){
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
            }
            else{
                Node* temp = head->next;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = new Node(data);
                temp->next->prev = temp;
            }
            count++;
        }
        void insertNode(Node* node){
            if(head->next == nullptr){
                head->next = node;
            }
            else{
                Node* temp = head->next;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = node;
                temp->next->prev = temp;
            }
            count++;
        }
        void remove(T data) {
            if(head->next == nullptr) return;
            Node* temp = head->next;
            Node* prev = nullptr;

            while (temp->next != nullptr && temp->data != data) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp == head->next) {
                head->next = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            count--;
        }
        bool search(T data){
            Node* temp = head->next;
            while (temp->next!= nullptr) {
                if (temp->data == data) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        void print(){
            Node* temp = head->next;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        int size(){return count;}
        bool isEmpty(){return count == 0;}
        Node* getHead(){return head;}
        void setHead(Node* head){this->head = head;}
        Node* getTail(){
            Node* temp = head->next;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            return temp;
        }
        void setTail(Node* tail){
            Node* temp = head->next;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = tail;
        }
        void reverse(){
            Node* temp = head->next;
            Node* prev = nullptr;
            Node* next = nullptr;
            while (temp != nullptr) {
                next = temp->next;
                temp->next = prev;
                temp->prev = next;
                prev = temp;
                temp = next;
            }
            head->next = prev;
        }
};

int main(){
    DoublyLinkedList<int> list;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0;i<10;i++){
        list.insert(arr[i]);
    }
    list.print();
    list.reverse();
    list.remove(5);
    list.print();
}
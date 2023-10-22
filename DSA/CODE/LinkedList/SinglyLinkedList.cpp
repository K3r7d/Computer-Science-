#include "ListADT.h"
#include<iostream>
template <class T>


class SinglyLinkedList : public ListADT<T>
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
            delete next;
        }
    };
    private:
        Node* head;
        int count;
    public:
        SinglyLinkedList(){
            this->head = new Node();
            this->count = 0;
        }
        ~SinglyLinkedList(){
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
            }
            count++;
        }
        void remove(T data) {
            if(head->next == nullptr) return;
            Node* temp = head->next;
            Node* prev = nullptr;

            while (temp != nullptr && temp->data != data) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp == head->next) {
                head->next = temp->next;
                delete temp;
                count--;
                return;
            } else {
                if (prev != nullptr) {
                    prev->next = temp->next;
                    delete temp;
                    count--;
                }
            }
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


        int size(){return count;}

        bool isEmpty(){return count == 0;}

        void print(){
            Node* temp = head->next;
            for(int i = 0;i<count-1;i++){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }
};

int main(){
    int arr[9] = {2,34,5,23,1,9,4,3,10};
    SinglyLinkedList<int> sll;
    for(int i = 0;i<9;i++){
        sll.insert(arr[i]);
    }
    sll.print();
    sll.remove(5);
    bool s = sll.search(5);
    std::cout << 5 << (s == 1 ? "In List" : "Not In List");
    sll.print();
    return 0;
}
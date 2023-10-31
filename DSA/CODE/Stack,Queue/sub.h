#ifndef SUB_H
#define SUB_H

#include <iostream>
using namespace std;
template <class T>
class ListADT
{
public:
    virtual void insert(T) = 0;
    virtual void remove(T) = 0;
    virtual bool search(T) = 0;
    virtual void print() = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual ~ListADT() {}
};

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
            next = NULL;
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

            while (temp->next != nullptr && temp->data != data) {
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

        T get(int index){
            if(index >= count) return -1;
            Node* temp = head->next;
            for(int i = 0;i<index;i++){
                temp = temp->next;
            }
            return temp->data;
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


#endif /* SUB_H */
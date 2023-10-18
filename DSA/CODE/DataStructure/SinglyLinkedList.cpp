#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) : data{x}, next{nullptr} {}
};

class LinkedList{
    private:
        int length = 0;
        Node* head = nullptr;
    public:
        void createLinkedList(string file_input){
            ifstream file(file_input);
            Node* temp = nullptr;
            Node* head = nullptr;
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
            }
            this->head = head;
        }
        void print(){
            Node* temp = this->head;
            while(temp !=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
        void reverse(){
            if(this->head == nullptr) return;
            stack<int> st;
            Node* temp = this->head;
            while(temp != nullptr){
                st.push(temp->data);
                temp = temp->next;
            }       
            Node* newhead = new Node(st.top());
            st.pop();
            temp = newhead;     
            while(!st.empty()){
                temp->next = new Node(st.top());
                st.pop();
                temp = temp->next;
            }
            temp = this->head;
            while(temp != nullptr){
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            this->head = newhead;
        }
        Node* getHead(){
            return this->head;
        }
        void setHead(Node*head){
            this->head = head;
        }

};

Node* reverse(Node* head){
    if(head == nullptr) return nullptr;
    stack<Node*> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp);
        temp = temp->next;
    }       
    Node* newhead = st.top();
    st.pop();
    temp = newhead;     
    while(!st.empty()){
        temp->next = st.top();
        st.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
    return newhead;
}




int main(){
    string file_input = "input.txt";
    LinkedList ll;
    ll.createLinkedList(file_input);
    ll.print();
    cout<<endl;
    ll.setHead(reverse(ll.getHead()));
    ll.print();
    return 0;
}


#include"sub.h"

template<typename T> class stack{
    private:
        SinglyLinkedList<T> list;
    public:
        void push(T x){
            list.insert(x);
        }
        void pop(){
            list.remove(list.size());
        }
        T top(){
            return list.get(list.size()-1);
        }
        bool isEmpty(){
            return list.isEmpty();
        }
        int size(){
            return list.size();
        }
        void print(){
            list.print();
        }
};

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout << "top:" ;
    cout << s.top() << endl;
    s.pop();
    s.print();
    cout << "top:" ;
    cout << s.top() << endl;
    cout << "size:" ;
    cout << s.size() << endl;
    return 0;
}
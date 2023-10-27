template <class T>
void SLinkedList<T>::bubbleSort()
{
    if(head==nullptr) return;
    for(int i = 0;i<count;i++){
        Node* t1 = head;
        bool swapped = false;
        for(int j = 0;j<count-i-1;j++){
            if(t1->data > t1->next->data){
                T temp = t1->data;
                t1->data = t1->next->data;
                t1->next->data = temp;
                swapped = true;
            }
        t1 = t1->next;
            
        }
        if(swapped) printList();
        else break;
    }
}
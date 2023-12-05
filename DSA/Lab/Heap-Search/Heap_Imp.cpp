template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return count == 0;
}

template<class T>
T Heap<T>::peek(){
    if(!elements) return -1;
    return elements[0];
}


template<class T>
bool Heap<T>::contains(T item){
    if(!elements) return false;
    for(int i = 0;i<count;i++){
        if(item == elements[i]) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (isEmpty()) {
        return false;
    }
    // Swap the top element with the last element
    std::swap(elements[0], elements[count - 1]);
    // Decrease the count to exclude the last element
    count--;
    // Perform heapify operation to maintain the heap property
    reheapDown(0);
    return true;
}
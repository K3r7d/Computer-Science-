template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count + 1);
        elements[count] = item;
        reheapUp(count);
        count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > capacity) {
            int newCapacity = std::max(2 * capacity, minCapacity);
            T *newElements = new T[newCapacity];

            for (int i = 0; i < count; i++) {
                newElements[i] = elements[i];
            }

            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
}

template<class T>
void Heap<T>::reheapUp(int position){
     int parent = (position - 1) / 2;
        while (position > 0 && elements[position] > elements[parent]) {
            std::swap(elements[position], elements[parent]);
            position = parent;
            parent = (position - 1) / 2;
        }
}
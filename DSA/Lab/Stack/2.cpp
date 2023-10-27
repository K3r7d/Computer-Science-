void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(item);
}

T pop() {
    T topItem = list.get(size() - 1); // Get the top item
    list.removeAt(size() - 1); // Remove it
    return topItem;
}

T top() {
    // TODO: Get value of the element on top of the stack
    return list.get(list.size()-1);
}

bool empty() {
    // TODO: Determine if the stack is empty
    return list.empty();
}

int size() {
    // TODO: Get the size of the stack
    return list.size();
}

void clear() {
    // TODO: Clear all elements of the stack
    while(!empty()){
        pop();
    }
}
#include <iostream>

using namespace std;

void swap(int* x, int* y);

class Heap {
private:
    int* arr;
    int size;
    int capacity;

public:
    Heap(int capacity);

    void MaxHeapify(int i);

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i) + 1; }

    int right(int i) { return (2 * i) + 2; }

    void decreaseKey(int i, int new_val);

    int getMax() { return arr[0]; }

    void deleteKey();

    void insertKey(int val);

    void build_max_heap(int* arr);

    void print();

    void sort();
};

Heap::Heap(int capacity) {
    this->capacity = capacity;
    this->size = 0;  // Initialize size to 0, not capacity
    arr = new int[capacity];
}

void Heap::insertKey(int val) {
    if (size == capacity) {
        cout << "\nOverflow, Could not insert Key!";
        return;
    }

    // Insert the new element at the end of the array
    arr[size] = val;
    size++;

    // Fix the heap property by comparing the element with its parent
    int i = size - 1;
    while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void Heap::decreaseKey(int i, int new_val) {
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] < arr[i]) {  // Corrected comparison operator
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void Heap::MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(largest);
    }
}

void Heap::build_max_heap(int* arr) {
    for (int i = 0; i < capacity; i++) {
        insertKey(arr[i]);
    }
}

void Heap::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Heap::sort() {
    for (int i = size - 1; i > 0; i--) {  // Corrected loop condition
        swap(&arr[0], &arr[i]);
        size--;
        MaxHeapify(0);
    }
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int arr[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    Heap maxheap(10);
    maxheap.build_max_heap(arr);
    maxheap.print();
    return 0;
}


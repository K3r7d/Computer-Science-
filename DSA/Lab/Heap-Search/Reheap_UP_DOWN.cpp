void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int leftChild, rightChild, largerChild;
    while (2 * index + 1 < numberOfElements) {
        leftChild = 2 * index + 1;
        rightChild = leftChild + 1;
        largerChild = leftChild;

        if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[leftChild]) {
            largerChild = rightChild;
        }

        if (maxHeap[index] < maxHeap[largerChild]) {
            std::swap(maxHeap[index], maxHeap[largerChild]);
            index = largerChild;
        } else {
            break;
        }
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    int parent;
    while (index > 0) {
        parent = (index - 1) / 2;
        if (maxHeap[index] > maxHeap[parent]) {
            std::swap(maxHeap[index], maxHeap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

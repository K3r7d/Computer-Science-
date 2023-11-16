
static void merge(T* start, T* middle, T* end) {
    auto l1 = middle - start;
    auto l2 = end - middle + 1;

    T* larr = new T[l1];
    T* rarr = new T[l2];

    for (auto i = 0; i < l1; i++)
        larr[i] = start[i];
    for (auto j = 0; j < l2; j++)
        rarr[j] = middle[j + 1];  // Fixed indexing here

    auto i = 0, j = 0, k = start;
    while (i < l1 && j < l2) {
        if (larr[i] < rarr[j]) {
            *k = larr[i];
            i++;
        } else {
            *k = rarr[j];
            j++;
        }
        k++;
    }

    while (i < l1) {
        *k = larr[i];
        k++;
        i++;
    }

    while (j < l2) {
        *k = rarr[j];
        k++;
        j++;
    }

    delete[] larr;
    delete[] rarr;
}


static void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}


static void InsertionSort(T* start, T* end) {
    int len = end - start;
    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0 && start[j] < start[j - 1]; j--) {
            swap(start[j], start[j - 1]);
        }
    }
}


static void TimSort(T* start, T* end, int min_size) {
    int size = end - start + 1;
    if (size > min_size) {
        T* middle = start + (size / 2);
        merge(start, middle, end);

        // Print the array after using insertion sort
        cout << "Insertion Sort:";
        for (T* ptr = start; ptr <= end; ++ptr) {
            cout << " " << *ptr;
        }
        cout << endl;

        TimSort(start, middle, min_size);
        TimSort(middle + 1, end, min_size);
        merge(start, middle, end);

        // Print the array after calling method merge
        cout << "Merge:";
        for (T* ptr = start; ptr <= end; ++ptr) {
            cout << " " << *ptr;
        }
        cout << endl;
    } else {
        InsertionSort(start, end);
        cout << "Insertion Sort:";
        for (T* ptr = start; ptr <= end; ++ptr) {
            cout << " " << *ptr;
        }
        cout << endl;
    }
}

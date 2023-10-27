// TODO: Write your code here

static void sortSegment(T* start, T* end, int idx, int total) {
        // TODO
        int size = end - start;
        int key, j;
        for (int i = 1; i * total + idx < size; ++i) {
            key = start[i * total + idx];
            j = i - 1;
                
            while (j >= 0 && start[j * total + idx] > key) 
            {  
                start[(j + 1) * total + idx] = start[j * total + idx];  
                j = j - 1;  
            }  
            start[(j + 1) * total + idx] = key;
        }
    }

static void ShellSort(T* start, T* end, int* list, int num) {
        // TODO
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        for (int i = num - 1; i >= 0; --i) {
            for (int segment = 0; segment < list[i]; ++segment) {
                sortSegment(start, end, segment, list[i]);
            } 
            cout << list[i] << " segments: ";
            printArray(start, end);
        }
    }
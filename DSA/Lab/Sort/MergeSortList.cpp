// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode* newHead = new ListNode();
    ListNode* temp = newHead;
    while(a && b) {
        if(a->val <= b->val) {
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    if(!a) {
        temp->next = b;
    }
    if(!b) {
        temp->next = a;
    }
    return newHead->next;
}

// Merge sort for a linked list
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    // Find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr; 

    ListNode* sortedFirstHalf = mergeSortList(head);
    ListNode* sortedSecondHalf = mergeSortList(secondHalf);


    return mergeLists(sortedFirstHalf, sortedSecondHalf);
}

//Helping functions


void add(T value){
    //TODO
    if(!this->root) {root = new Node(value); return;}
    Node* temp = this->root;
    Node* prev = nullptr;
    bool dir = false;
    while(temp != NULL){
        if(value > temp->value){
            dir = true;
            prev = temp;
            temp = temp->pRight;
        }
        else{
            dir = false;
            prev = temp;
            temp = temp->pLeft;
        }
    }
    if(dir) prev->pRight = new Node(value);
    else prev->pLeft = new Node(value);
}

void deleteNode(T value){
    if(!this->root) return;
    Node* temp = root;
    Node* prev = nullptr;
    while(temp && temp->value != value) {
        if(value > temp->value){
            prev = temp;
            temp = temp->pRight;
        }
        else {
            prev = temp;
            temp = temp->pLeft;
        }
    }

    if (!temp) return;  // Node with the given value not found

    // Node with two children
    if(temp->pLeft && temp->pRight){
        Node* succ = temp->pRight;
        Node* succParent = temp;
        while(succ->pLeft){
            succParent = succ;
            succ = succ->pLeft;
        }
        temp->value = succ->value;
        temp = succ;  // Now, temp points to the node we want to delete
        prev = succParent;
    }

    // Node with one or no child
    Node* child = (temp->pLeft) ? temp->pLeft : temp->pRight;
    if(!prev){
        root = child;
    } else if(prev->pLeft == temp){
        prev->pLeft = child;
    } else {
        prev->pRight = child;
    }
    delete temp;
}


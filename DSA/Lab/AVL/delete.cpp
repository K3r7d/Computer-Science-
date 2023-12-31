Node* rightRotate(Node* y)
    {
        Node* x = y->pLeft;
        y->pLeft = x->pRight;
        x->pRight = y;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
    }
    Node* maxValueNode(Node* node)
    {
        Node* current = node;

        /* loop down to find the leftmost leaf */
        while (current->pRight != NULL)
            current = current->pRight;

        return current;
    }

    Node* deleteNode(Node* root, int key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE  
        if (root == NULL)
            return root;
        // If the key to be deleted is smaller  
        // than the root's key, then it lies 
        // in left subtree  
        if (key < root->data)
            root->pLeft = deleteNode(root->pLeft, key);
        // If the key to be deleted is greater  
        // than the root's key, then it lies  
        // in right subtree  
        else if (key > root->data)
            root->pRight = deleteNode(root->pRight, key);

        // if key is same as root's key, then  
        // This is the node to be deleted  
        else
        {
            // node with only one child or no child  
            if ((root->pLeft == NULL) ||
                (root->pRight == NULL))
            {
                Node* temp = root->pLeft ?
                    root->pLeft :
                    root->pRight;

                // No child case  
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else // One child case  
                    *root = *temp; // Copy the contents of  
                                   // the non-empty child  
                free(temp);
            }
            else
            {
                Node* temp = maxValueNode(root->pLeft);
                root->data = temp->data;
                root->pLeft = deleteNode(root->pLeft,
                    temp->data);
            }
        }
        if (root == NULL)
            return root;
        // STEP 3: GET THE BALANCE FACTOR OF  
        // THIS NODE (to check whether this  
        // node became unbalanced)  
        int balance = getBalance(root);

        // If this node becomes unbalanced,  
        // then there are 4 cases  

        // Left Left Case  
        if (balance > 1 && getBalance(root->pLeft) >= 0)
            return rightRotate(root);
        // Left Right Case  
        if (balance > 1 && getBalance(root->pLeft) < 0)
        {
            root->pLeft = leftRotate(root->pLeft);
            return rightRotate(root);
        }

        // Right Right Case  
        if (balance < -1 &&  getBalance(root->pRight) <= 0)
            return leftRotate(root);

        // Right Left Case  
        if (balance < -1 && getBalance(root->pRight) > 0)
        {
            root->pRight = rightRotate(root->pRight);
            return leftRotate(root);
        }

        return root;
    }
    void remove(const T& value)
    {
        // TODO
        this->root = deleteNode(root, value);
    }
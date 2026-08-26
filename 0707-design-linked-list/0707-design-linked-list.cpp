class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        
        Node(int val) {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    
    Node* head;
    Node* tail;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        // Case 1: Invalid index
        if(index < 0 || index >= size) {
            return -1;
        }
        
        Node* curr = head;
        int count = 0;
        
        // Traverse to the index
        while(curr != nullptr && count < index) {
            curr = curr->next;
            count++;
        }
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val);
        
        // Case 1: Empty list
        if(head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        // Case 2: Non-empty list
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* new_node = new Node(val);
        
        // Case 1: Empty list
        if(head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        // Case 2: Non-empty list
        else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        // Case 1: Invalid index
        if(index < 0 || index > size) {
            return;
        }
        
        // Case 2: Insert at head
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        // Case 3: Insert at tail
        if(index == size) {
            addAtTail(val);
            return;
        }
        
        // Case 4: Insert in middle
        Node* curr = head;
        int count = 0;
        
        // Traverse to the node at given index
        while(curr != nullptr && count < index) {
            curr = curr->next;
            count++;
        }
        
        Node* new_node = new Node(val);
        new_node->prev = curr->prev;
        new_node->next = curr;
        curr->prev->next = new_node;
        curr->prev = new_node;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        // Case 1: Invalid index
        if(index < 0 || index >= size) {
            return;
        }
        
        // Case 2: Delete head
        if(index == 0) {
            Node* temp = head;
            head = head->next;
            if(head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            size--;
            return;
        }
        
        // Case 3: Delete tail
        if(index == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
            return;
        }
        
        // Case 4: Delete middle
        Node* curr = head;
        int count = 0;
        
        // Traverse to the node at given index
        while(curr != nullptr && count < index) {
            curr = curr->next;
            count++;
        }
        
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }
};
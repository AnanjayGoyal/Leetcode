class MyCircularDeque {
public:
    vector<int> q;
    int front;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        q.resize(k);
        front = 0;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        q[front] = value;
        size++;

        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;

        int rear = (front + size) % capacity;
        q[rear] = value;
        size++;

        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        size--;

        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;

        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;

        return q[front];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;

        int rear = (front + size - 1) % capacity;
        return q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
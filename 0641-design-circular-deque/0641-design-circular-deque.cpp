class MyCircularDeque {
public:
    vector<int> arr;
    int front, rear;
    int size, capacity;

    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {

        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {

        if (isFull()) return false;

        rear = (rear + 1) % capacity;
        arr[rear] = value;

        if (size == 0)
            front = rear;

        size++;
        return true;
    }

    bool deleteFront() {

        if (isEmpty()) return false;

        if (size == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    bool deleteLast() {

        if (isEmpty()) return false;

        if (size == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return true;
    }

    int getFront() {

        if (isEmpty()) return -1;

        return arr[front];
    }

    int getRear() {

        if (isEmpty()) return -1;

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
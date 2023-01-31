#include <iostream>
#include <array>

class Queue {   // Defining Queue class that uses an array
    public:
        int front;  // Front (index of the first element)
        int back;   // Back (index of the last element)
        std::array<int,100> arr;    //Array to store the elements in queue

        Queue() : front(0), back(0) {}  // Initializing front and back to 0

        void enqueue(int value) {   // Adds a value to the back of queue
            arr[back++] = value;
        } 

        int dequeue() {   // Removes element front the front of queue and returns its value
            if (front == back) return -1;   // If front and back are equal, queue is empty
            return arr[front++];    // Return the element at front and increment the front
        }

        int peek() {    // Returns the value at the front of the queue without removing it
            if (front == back) return -1;
            return arr[front];
        }
};


int main() {
    Queue q;
    q.enqueue(1);
    int value = q.dequeue();    // Test 1: Enqueue and dequeue a single element
    if (value == 1) {
        std::cout << "Test 1 passed" << std::endl;
    } 
    else {
        std::cout << "Test 1 failed" << std::endl;
    }

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    value = q.dequeue();    //Test 2: Enqueue multiple elements and dequeue all
    if (value == 2) {
        value = q.dequeue();
        if (value == 3) {
            value = q.dequeue();
            if (value == 4) {
                std::cout << "Test 2 passed" << std::endl;
            }
            else {
                std::cout << "Test 2 failed" << std::endl;
            }
        }
        else {
            std::cout << "Test 2 failed" << std::endl;
        }
    }
    else {
        std::cout << "Test 2 failed" << std::endl;
    }
    
    
    value = q.dequeue();    // Test 3: Dequeue from an empty queue
    if (value == -1){
        std::cout << "Test 3 passed" << std::endl;
    }
    else {
        std::cout << "Test 3 failed" << std::endl;
    }
    return 0;
}
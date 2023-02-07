#include <iostream>
using namespace std;


// defining Node class
class Node {
    public:
        int key;        // key to identify the node
        int data;       // data stored in the node
        Node* next;     // pointer to next node in the list

        // constructor to initialize the node with default values
        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }

        // parameterized constructor to initialize with the provided values
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

// defining LinkedList class
class LinkedList {
    public:
        Node* head; // pointer to the head node

        // constructor to initiralize the linked list with default values
        LinkedList()
        {
            head = NULL;
        }

        // parametierized constructor to initialize the linked list with the provided head
        LinkedList(Node *n)
        {
            head = n;
        }

        // method that adds a node at the specified position
        void add(int key, int data, int pos) {      // void as it doesn't return any value
            Node *newNode = new Node(key, data);    // creating new node with the parameters given
            if (head == NULL) {     // if linked list is empty
                head = newNode;     // set head to new node
                return;
            }
            if (pos == 0) { 
                newNode->next = head; // set the next node of the new node to the current head
                head = newNode;       // set head to new node
                return;
            }
            Node *current = head;   // initializing pointer to traverse list
            int currentPos = 0;     // to keep track of the current position
            while (current->next != NULL && currentPos < pos - 1) { // while next is not NULL and current position is less than desired position minus 1
                current = current->next;    // moves the current pointer to the next node
                currentPos++;   // increments the current position up
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        
        // method to remove node at the specified position and return it
        int remove(int pos) {
            if (head == NULL) { // if the list is empty return -1
                return -1;
            }
            if (pos == 0) { 
                int removedData = head->data; // storing the data of the head to be removed
                Node *temp = head; // storing the head in a temperary node
                head = head->next; // set head to next node
                delete temp;    // removing the temporary node
                return removedData; // returns the removed data
            }
            Node *current = head;   // initializes pointer to traverse list once again
            int currentPos = 0; // keeping track of the current position
            while (current->next != NULL && currentPos < pos - 1) { // while next is not NULL and current position is less than desired position minus 1
                current = current->next; // moving to the next node
                currentPos++;   // increment current position up
            }
            if (current->next == NULL) { // if the desired position is not in the list return -1
                return -1;
            }
            Node *temp = current->next; // creating temperary node to store the node
            int removedData = temp->data;   // storing the data of the node to be removed
            current->next = temp->next; // set the next node to the currunt node to the next node that will be removed
            delete temp; // deleting temporary node
            return removedData; // reutrning the removed data
        }

        // method to get and return node at the specified location    
        int get(int pos) {
            if (head == NULL) { // check if list is empty and return -1 if so
            return -1;
        }
        Node *current = head;   // initialize pointer to traverse the list
        int currentPos = 0;     // keep track of the current position
        while (current != NULL && currentPos < pos) {   // traversing the list to the desired position
            current = current->next;    // move to next node in list
            currentPos++;   // increment current position up
        }
        if (current == NULL) { // if the position is not in the list return -1
            return -1;
        }
        return current->data; // returns data of the node at desired location
    }
};

int main() {

// Test 1: Adding elements to the linked list and see if the get method returns the correct data and is working correctly
LinkedList list1;
list1.add(1, 10, 0);
list1.add(2, 20, 1);
list1.add(3, 30, 2);

if (list1.get(0) == 10 && list1.get(1) == 20 && list1.get(2) == 30) {
    cout << "Test 1 passed" << endl;
} else {
    cout << "Test 1 failed" << endl;
}

// Test 2: Adding elements to the linked list and see if the remove method returs the correct data and is working correctly
LinkedList list2;
list2.add(1, 10, 0);
list2.add(2, 20, 1);
list2.add(3, 30, 2);

if (list2.remove(1) == 20) {
    cout << "Test 2 passed" << endl;
} else {
    cout << "Test 2 failed" << endl;
}

    return 0;
};


#include <iostream>

using namespace std;

class ArraySortedList {
public:
    int arr[100];   // array based list
    int size;       // int to store number of elements

    ArraySortedList() { // contructor initializing to 0
        size = 0;
    }

    // Insert method to place value in correct position based on ascending order
    void insert(int value) {
        int index = size;   // initialize index where the value will be inserted
        for (int i = 0; i < size; i++) {
            if (arr[i] > value) { // If element > value is found, update index tp current pos
                index = i;
                break;
            }
        }
        for (int i = size; i > index; i--) { // shift elements to the right after the index
            arr[i] = arr[i-1];
        }
        arr[index] = value; // Insert value at index
        size++; // increment size by 1
    }

    // Binary search method to efficiently search for elements
    bool search(int value) {
        int left = 0; // setting both left and right indices for search
        int right = size - 1;
        while (left <= right) { // loop until left index > right index
            int mid = left + (right - left) / 2; // calculate mid index
            if (arr[mid] == value) { // if mid value equals desired value, returns true
                return true;
            } else if (arr[mid] < value) { // if mid value is less than desired value
                left = mid + 1; // update left index to middle index +1
            } else {    // if mid value is greater than desired value,
                right = mid - 1;    // update right index to mid index -1
            }
        }
        return false;   // value not found returns false
    }
};

int main() {
    ArraySortedList list; // Creating list and adding 10 values
    list.insert(5);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.insert(4);
    list.insert(7);
    list.insert(11);
    list.insert(8);
    list.insert(9);
    list.insert(15);

    // Test 1: Check if list contains the inserted values
    cout << "Test 1: List contains 5: " << list.search(5) << endl;
    cout << "Test 1: List contains 6: " << list.search(11) << endl;

    // Test 2: Check if the values were inserted in ascending order
    cout << "Test 2: List elements: ";
    for (int i = 0; i < list.size; i++) {
        cout << list.arr[i] << " ";
    }

    return 0;
}
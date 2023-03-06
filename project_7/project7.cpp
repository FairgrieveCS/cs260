#include <iostream>

const int TABLE_SIZE = 10;  //defining the table size as a constant

// defining hashtable class
class HashTable {
private:

    int table[TABLE_SIZE];  // defining table as an array of integers

    // defining hash method
    int hash(int key) {
        return key % TABLE_SIZE;  // returns key modulo of the table size
    }

public:

    // defining constructor
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;  // initializes all slots in table to -1
        }
    }

    // defining insert method
    void insert(int key) {
        int hashValue = hash(key);  // acquiring hash value for the key
        table[hashValue] = key;     // inserting key into the table at the hash value
    }

    // defining contains method
    bool contains(int key) {
        int hashValue = hash(key);  // getting the hash value for the key
        return table[hashValue] == key; // if the value at the hash val is equal to the key, the key is in the table
    }

    // defining remove method
    int remove(int key) {
        int hashValue = hash(key);  // getting the hash value for the key once again
        int value = table[hashValue]; // get the value at the hash value
        table[hashValue] = -1;  // setting the value at the hash value to -1 to indicate that the slot is now empty
        return value; // returning removed value
    }
};

int main() {
    // creating the hashtable object
    HashTable hashTable;

    // inserting keys into the hash table
    hashTable.insert(8);
    hashTable.insert(13);
    hashTable.insert(34);

    // test for the contains function
    std::cout << "Contains 8: " << hashTable.contains(8) << " (We expect: 1)\n";
    std::cout << "Contains 10: " << hashTable.contains(10) << " (We expect: 0)\n";

    // test for the remove function
    int value = hashTable.remove(13);
    std::cout << "Removed value: " << value << " (We expect: 13)\n";
    std::cout << "Contains 13: " << hashTable.contains(13) << " (We expect: 0)\n";

    // test for the insert function
    hashTable.insert(34);
    std::cout << "Contains 34: " << hashTable.contains(34) << " (We expect: 1)\n";


  return 0;
}
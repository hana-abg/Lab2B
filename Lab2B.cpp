#include <iostream>
using namespace std;

// ============================================================
// Node class
// ============================================================
class Node { //node is one item(it was made not built in) and it stores data and the next?? next is a pointer
public:
    int data;
    Node* next;
    Node(int value) { data = value; next = nullptr; }
};

// ============================================================
// LinkedList class
// ============================================================
class LinkedList {
public:
    Node* head; //this points to the first node

    LinkedList() { head = nullptr; }

    ~LinkedList() { // clean up the nodes when the list is destroyed
        Node* current = head; //start from the first node

        while (current != nullptr) { //keep going until there are no nodes left
            Node* nextNode = current->next; //save the next node before deleting current
            delete current; //delete the current node from memory
            current = nextNode; //move to the next node
        }
        head = nullptr; //list is now empty
    }

    void insertAtHead(int value) {
        // TODO, give value/data at beginning of list
        Node* newNode = new Node(value); //newNode is pointer,
        newNode->next = head; //connects the new node to the old first node
        head = newNode; //makes the new node the first node. So head changes here.
    }

    void insertAtTail(int value) { // add node at end
        // TODO
        Node* newNode = new Node(value);
        if (head == nullptr) { //is list empty
            head = newNode; //if list is empty then make head point to the node we just made otherwise leave condition
            return;
        }
        Node* current = head; //current is a pointer were gonna use to go through the whole list
        while (current->next != nullptr) {
            current = current->next; // this just moves the currnt as if its a count+1
        }
        current->next = newNode; //this is what actually makes it point to 40/last thing
    }

    bool deleteValue(int value) { // remove node thats this value, return whether it was found
        if (head == nullptr) { //if the list is empty theres nothing to delete
            return false;
        }

        if (head->data == value) { //check if the first node is the one we want to delete
            Node* temp = head; //save the old head so we can delete it
            head = head->next; //make head point to the second node
            delete temp; //delete the old first node
            return true; //we found and deleted the value
        }

        Node* current = head; //start from the first node

        while (current->next != nullptr) { //keep checking until we reach the last node
            if (current->next->data == value) { //check if the next node has the value
                Node* temp = current->next; //save the node we want to delete
                current->next = temp->next; //skip the node and connect to the one after it
                delete temp; //delete the node from memory
                return true; //value was found and deleted
            }
            current = current->next; //move to the next node
        }
        return false; //value wasnt found in the list
    }

    bool search(int value) { // check if certain value exists
        Node* current = head; //start from the first node

        while (current != nullptr) { //go through the list until the end
            if (current->data == value) { //check if this node has the value
                return true; //we found it
            }
            current = current->next; //move to the next node
        }
        return false; //we reached the end and didnt find it
    }

    int length() { // return number of nodes
        int count = 0; //start counting from zero
        Node* current = head; //start from the first node

        while (current != nullptr) { //keep going until the end
            count++; //count this node
            current = current->next; //move to the next node
        }
        return count; //return total number of nodes
    }

    void reverse() { // make the links go in reverse
        Node* previous = nullptr; //there is no node before the first one
        Node* current = head; //start from the first node
        Node* nextNode = nullptr; //we use this to save the next node

        while (current != nullptr) { //keep going until the end
            nextNode = current->next; //save where the next node is
            current->next = previous; //make current point backwards instead of forwards
            previous = current; //move previous one step forward
            current = nextNode; //move current to the next node
        }
        head = previous; //the old last node is now the first node
    }

    void print() {
        // TODO: print in format: 10 -> 20 -> null
        Node* current = head; //starts at the beginning og the list
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next; //+1
        }
        cout << "null" << endl;
    }
};


// ---- Do NOT modify below this line ----
// [paste main() from Section 2 here]
#include <iostream>
#include <cassert>
using namespace std;

// --- paste your Node and LinkedList classes above main ---
int main() { //starts at main(). LinkedList L; creates a list named L, onstructor runs, making L.head = nullptr
    LinkedList L;                       // then we start inserting

    // TC1: insertAtHead (builds list in reverse order)
    L.insertAtHead(30);
    L.insertAtHead(20);
    L.insertAtHead(10);
    cout << "TC1: "; L.print();

    // TC2: insertAtTail
    L.insertAtTail(40);
    L.insertAtTail(50);
    cout << "TC2: "; L.print();

    // TC3: length
    cout << "TC3: length = " << L.length() << endl;

    // TC4: search
    cout << "TC4: search(30)=" << L.search(30)
    << " search(99)=" << L.search(99) << endl;

    // TC5: delete head
    L.deleteValue(10);
    cout << "TC5: "; L.print();

    // TC6: delete tail
    L.deleteValue(50);
    cout << "TC6: "; L.print();

    // TC7: delete middle
    L.deleteValue(30);
    cout << "TC7: "; L.print();

    // TC8: delete non-existent
    bool r = L.deleteValue(99);
    cout << "TC8: deleteValue(99)=" << r << endl;

    // TC9: reverse
    LinkedList L2;
    L2.insertAtTail(1); L2.insertAtTail(2); L2.insertAtTail(3);
    L2.reverse();
    cout << "TC9: "; L2.print();

    // TC10: empty list edge cases
    LinkedList L3;
    cout << "TC10: length=" << L3.length()
        << " search=" << L3.search(5)
        << " delete=" << L3.deleteValue(5) << endl;

    return 0;
}
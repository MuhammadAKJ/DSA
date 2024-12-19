#include<iostream>
using namespace std;

struct Node
{
    int data; /* data */

    Node* next; // Pointer to the next node

    //Constructor to initialize a node
    Node(int value){
        data = value;
        next = nullptr;
    }
};

//singly linked list class
class SinglyLinkedClass {
    private:
        Node* head;

    public:
        //Constructor
        SinglyLinkedClass(){
            head = nullptr;
        }

        //Function to insert a new node at the end
        void append(int value){
            Node* newNode = new Node(value);

            if (head == nullptr){
                head = newNode; //if the list is empty, make the new node the head
            } else {
                Node* temp = head;
                while (temp->next != nullptr){
                    temp = temp->next; // traverse to the end of the list
                }
                temp->next = newNode; // link the last to the new node
            }
        }

        //Function to display the list
        void display() {
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }

        // Function to delete a node by value
        void deleteNode(int value) {
            if (head == nullptr){
                cout << "List is empty!" << endl;
                return;
            }
            //if the head node needs to be deleted
            if (head->data == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            // Traverse to the node to delete
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data != value) {
                temp = temp->next;
            }
            if (temp->next == nullptr){
                cout << "Value not found in the list!" << endl;
            } else {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }

        }

        // Destructor to free memory
        ~SinglyLinkedClass() {
            Node* temp = head;
            while (temp != nullptr) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }    
};


//Main Function to demonstrate the singly linked list
int main(){
    SinglyLinkedClass list;

    //insert some nodes
    list.append(10);
    list.append(20);
    list.append(30);

    //display list
    cout << "Linked list: ";
    list.display();

    //delete node
    cout << "Deleting 20...";
    list.deleteNode(20);
    cout << "Linked list: ";
    list.display();

    return 0;
}

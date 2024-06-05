#include <iostream>
using namespace std;


// Making Node for making Linked List
class Node {
public:
  int data;
  Node *prev;
  Node *next;

  Node() {
    this->data = 0;
    this->prev = NULL;
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
};

// Function for printing the whole of Linked List
void print(Node *&head) {
  Node *temp = head;
  cout << "Printing the Linked List : " << endl;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}
// Function for finding the length of a Linked List
int findlen(Node *&head) {
  int length = 0;
  Node *temp = head;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }
  return length;
}

// Function for adding a node right at the tail or to the the right of tail
void insertAtTail(Node *&head, Node *&tail, int data) {
  // Checking if LL is empty or not
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }
  // Step 1 : Make a new Node
  Node *newNode = new Node(data);
  // Step 2 : Make new Node's prev is equal to tail
  newNode->prev = tail;
  // Step 3 : Make tail's next equal to new Node
  tail->next = newNode;
  // Step 4 : Make tail equal to new node
  tail = newNode;
}

int main() {

  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  first->next = second;
  second->prev = first;
  second->next = third;
  third->prev = second;

  //Inserting at tail
  insertAtTail(first, third, 200);
  insertAtTail(first, third, 300);
  insertAtTail(first, third, 400);
//Printing modified Linked List
  print(first);
}
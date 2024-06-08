#include <iostream>
using namespace std;




class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};




class LinkedList {
public:
	Node* head;
	LinkedList() { head = NULL; }
	void InsertAfterNode(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) head = newNode;
		else {
			Node* current = head;
			while (current->next != NULL ) current = current->next;
			current->next = newNode;
		}
	}



	Node* ReverseLinkedList() {
		Node* current = head;
		Node* prev = NULL;
		Node* nextN = NULL;
		while (current != NULL) {
			nextN = current->next;
			current->next = prev;
			prev = current;
			current = nextN;
		}
		return prev;
	}


	void DisplayLinkedList() {
		Node* current = head;
		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	LinkedList l = LinkedList();
	LinkedList l1 = LinkedList();
	bool isPalindrome = true;
	l.InsertAfterNode(1);
	l.InsertAfterNode(2);
	l.InsertAfterNode(1);
	l.InsertAfterNode(1);
	l1.head = &*l.ReverseLinkedList();
	Node* current = &*l.head;
	Node* rev = &*l1.head;
	while (current != NULL) {
		cout << current->data << "   ";
		current = current->next;
	}
	return 0;
	
}
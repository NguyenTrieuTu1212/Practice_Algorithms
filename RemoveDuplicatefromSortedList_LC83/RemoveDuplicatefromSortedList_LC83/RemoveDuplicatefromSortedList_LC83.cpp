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
	LinkedList() {
		head == NULL;
	}

	void InsertBeforeNode(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) head = newNode;
		else {
			Node* currentNode = head;
			while (currentNode->next != NULL) {
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
	}


	void DisplayLinkedList() {
		Node* currentNode = head;
		while (currentNode != NULL) {
			cout << currentNode->data << "->";
			currentNode = currentNode->next;
		}
		cout <<"NULL"<< endl;
	}

	void DeleteDuplicateNode() {
		Node* current = head;
		Node* prev = current;
		while (current != NULL) {
			if (prev->data == current->data) {
				prev->next = current->next;
			}
			else {
				prev = current;
			}
			current = current->next;
		}
	}
};


void main() {
	LinkedList l = LinkedList();
	l.InsertBeforeNode(1);
	l.InsertBeforeNode(1);
	l.InsertBeforeNode(1);
	l.InsertBeforeNode(2);
	l.DisplayLinkedList();
	l.DeleteDuplicateNode();
	l.DisplayLinkedList();
	return;
}
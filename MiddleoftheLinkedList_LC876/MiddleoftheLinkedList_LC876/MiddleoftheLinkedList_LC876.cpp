

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
		head = NULL;
	}


	void InsertBeforeNode(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) head = newNode;
		else {
			Node* current = head;
			while (current->next != NULL) current = current->next;
			current->next = newNode;
		}

	}

	int FindMidleNode() {
		Node* slow = head;
		Node* fast = head;
		while (slow != NULL && fast != NULL) {
			if (fast->next == NULL) return slow->data;
			slow = slow->next;
			fast = fast->next->next;
		}
		return head->data;
	}


	void DisplayLinkedList() {
		Node* current = head;
		while (current != NULL) {

			cout << current->data << "->";
			current = current->next;
		}

		cout <<"NULL"<< endl;
	}

};

void main() {
	LinkedList l = LinkedList();
	l.InsertBeforeNode(1);
	l.InsertBeforeNode(2);
	l.InsertBeforeNode(3);
	l.InsertBeforeNode(4);
	l.DisplayLinkedList();
	cout << "==> Phan tu o gia la: " << l.FindMidleNode() << endl;
	l.DisplayLinkedList();
}
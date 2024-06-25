#include <iostream>
using namespace std;
class Node {
	public:
    int data;
    Node* next;
    Node(int newData){
    	data=newData;
    	next=nullptr;
	}
};
class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}
    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    void insert() {
    	int newData;
    	cout<<"Enter the element you want to enter : ";
    	cin>>newData;
        Node* newNode = new Node(newData);

        if (head == nullptr || head->data >= newData) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < newData) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    void deleteElement() {
    	int key;
    	cout<<"Enter the element you want to delete: \n";
    	cin>>key;
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Given element  not found in the list.\n";
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "data deleted successfully.\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        cout << "LinkedList: \n";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SortedLinkedList m; 
    int choice;
    do{
    	cout<<"1.Insert in ascending\n";
    	cout<<"2.Display\n";
    	cout<<"3.Delete the given element\n";
    	cout<<"4.Exit\n";
    	cin>>choice;
    	switch(choice){
    		case 1:{
    			m.insert();
				break;
			}
			case 2:{
				m.display();
				break;
			}
			case 3:{
				m.deleteElement();
				break;
			}
			case 4:{
				cout<<"Thank uhh";	
				break;
			}
    			
		}
	}while(choice!=4);
}

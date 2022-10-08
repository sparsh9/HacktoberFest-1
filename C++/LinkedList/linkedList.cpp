#include <iostream>
#include <vector>
using namespace std;


class Node{
    public:
    int val;
    Node* next;

    Node(int d) {
        val = d;
        next = NULL;

    }

    void insertAtBeg(Node* &head, int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insertAtLast(Node* &head, int data) {
        Node* new_node = new Node(data);
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // void reverse(Node* head) {
    //     //code
    // }

    void print(Node* &head){ 
        while(head!=NULL){
            cout<<head->val<<" -> ";
            head = head->next;
        }
        cout<<"null";
    }

};





int main(){
    Node* head = new Node(1);
    head->insertAtLast(head, 2);
    head->insertAtLast(head, 3);
    head->insertAtLast(head, 4);
    head->print(head);

    return 0;
}
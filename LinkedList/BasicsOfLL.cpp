#include <iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(Node*&head, int data){
    Node * temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertAtEnd(Node *&head, int data){
    Node * temp = new Node(data);
    Node * curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = temp;
}
Node * findMiddle(Node * head){
    if(!head || !head->next)
    return head;

    Node * slow = head ;
    Node * fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void insertAtMiddle(Node *&head , int data){
    Node * temp = new Node(data);
    Node * curr = head;
    Node * middle = findMiddle(head);
    while(curr != middle){
        curr = curr->next;
    }
    Node * NNext = curr->next;
    curr->next = temp;
    temp->next = NNext;
    
}
void printLL(Node * head){
    while(head){
        cout << head->data << " -> ";
        head = head->next;
    }
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    // head->next->next->next = new Node (4);
    insertAtMiddle(head,10);
    printLL(head);-
    return 0;
}
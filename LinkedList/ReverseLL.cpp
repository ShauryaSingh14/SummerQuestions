#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void printSLL(Node * head){
    while(head){
        cout << head->data<<" -> ";
        head = head->next;
    }
    cout << endl;
}
void RevserseLL(Node *& head){
    if(!head || !head->next)
    return ;
    else{
        Node * curr = head;
        Node * prev = NULL;
        while(curr){
            Node * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }
}
int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
     printSLL(head);
    RevserseLL(head);
    printSLL(head);

    return 0;
}
   
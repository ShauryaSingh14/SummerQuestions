#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
    
};
Node * reverseUtil(Node* curr, Node* prev)
{   if (!curr) 
        return prev;
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    reverseUtil(next, curr);
}
 void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);
    head1->next->next->next->next->next->next->next = new Node(8);
    cout << "Given linked list\n";
    printlist(head1);
    head1 = reverseUtil(head1, NULL);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}
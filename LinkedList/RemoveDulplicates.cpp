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
void removeDuplicates(Node *&head)
{ Node * curr = head;
while( curr && curr->next){
    if(curr->data==curr->next->data){
        Node * temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
    }
    else{
        curr = curr->next;
    }
}
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
    head1->next->next->next = new Node(3);
    head1->next->next->next->next = new Node(3);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);
    head1->next->next->next->next->next->next->next = new Node(8);
    cout << "Given linked list\n";
    printlist(head1);
    removeDuplicates(head1);
    cout << "\nReversed linked list\n";
    printlist(head1);
    return 0;
}
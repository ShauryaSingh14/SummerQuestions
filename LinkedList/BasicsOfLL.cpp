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
    cout << endl;
}
void deletionFromHead(Node *&head){
    Node * temp = head;
    head = head->next;
    delete(temp);
}
void deletionfromEnd(Node *&head){
    Node * curr = head;
    while(head->next->next)
        head = head ->next;
    delete(head->next);
    head->next = NULL;
}
void deleteFromMiddle(Node *&head){
    Node * curr = head;
    Node * middle = findMiddle(head);
    while(curr->next != middle)
        curr = curr->next;
    curr->next = curr->next->next;
    delete(middle);    
}

void sortLL(Node *& head){
    Node * curr = head;
    
    for(Node * i = head; i ; i= i->next){
        for(Node * j = i->next ; j ; j=j->next){
            if(j->data < i->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node (2);
    insertAtMiddle(head,10);
    printLL(head);
    deleteFromMiddle(head);
    printLL(head);
    sortLL(head);
    printLL(head);
    return 0;
}
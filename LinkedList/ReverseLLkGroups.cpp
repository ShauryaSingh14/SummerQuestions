#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode * next;
};
ListNode* reverseLL(ListNode * head,int k){
	ListNode* curr = head;
	ListNode* prev = NULL;
	int i =1;
	while(i!=k){
		ListNode* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr=temp;
		i++;
	}
	return prev;
}
ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode * curr = head;
	while(curr){
		curr=reverseLL(curr,k)->next;
	}
    return head;
}
int main(){
    return 0;
}
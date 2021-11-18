// create a linked list & perform operations such as insert, delete,
 //update, reverse in the linked list.
#include <iostream>
using namespace std;
//the linked list node structure
struct Node
{
   int data;
   struct Node *next;
};
 
//insert new node after a given node
void insertAfter(struct Node* previous_node, int node_data)
{
if (previous_node == NULL)
{
   cout<<"the given previous node is required,cannot be NULL"; return; } 
   struct Node* newNode =new Node; 
   newNode->data = node_data;
   newNode->next = previous_node->next;
    previous_node->next = newNode;
}
 
/* insert new node at the end of the linked list */
void append(struct Node** head, int node_data) // head points to the first node of the linked list
{
struct Node* newNode = new Node;
struct Node *last = *head; 
newNode->data = node_data;
newNode->next = NULL;
 

if (*head == NULL)
{
*head = newNode;
return;
}
 

while (last->next != NULL)
last = last->next;
 
last->next = newNode;
return;
}
 
// for  displaying linked list contents
void displayList(struct Node *node)
{
   //traverse the list to display each node
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }

if(node== NULL)
cout<<"null"; 
} 

//for deleting  node in the linked list
Node* deleteNode(struct Node* head, int value)
{
   if (head == NULL)
   return NULL;
 
   Node * temp = head;
   Node * previous = NULL;
   while(temp != NULL && temp->data != value){
       previous = temp;
       temp = temp->next;
   }
   if(temp == head){
       head = head->next;
       cout<<head->data<<endl;
      delete temp;
       return head;
   }
   previous->next = temp->next;
   delete temp;
 
   return head;
}

Node* updateNode(Node * head, int oldValue,int newValue){
    Node * temp = head;
    while(temp != NULL && temp->data != oldValue){
        temp = temp->next;
    }
    temp->data = newValue;
    return head;
}
Node * reverseLinkedList(Node * head){
    Node * temp = head;
    Node * previous = NULL;
    Node * next = NULL;
    while(temp != NULL){
        next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    head = previous;
    return head;
}
/* main program for linked list*/
int main() 
{ 
struct Node* head = NULL; 
int choice,value,position,newValue;
append(&head, 1);
append(&head, 2);
append(&head, 3);
append(&head, 4);
append(&head, 5);

while(choice != 5){
cout<<endl<<"Select a operation to perform: "<<endl<<"1.Insert"<<endl<<"2.Delete"<<endl<<"3.Update"<<endl<<"4.Reverse"<<endl<<"5.Quit"<<endl;
cout<<"Current linked list: "<<endl;
displayList(head);
cout<<endl;
cout<<"Your Choice: ";
cin>>choice;
switch(choice){
    case 1:
    {
        cout<<"Enter the value after which you want to insert the value: ";
        cin>>position;
        Node * cur = head;
        while(cur->data != position)cur = cur->next;
        cout<<"Enter the value: ";
        cin>>value;
        insertAfter(cur,value);
        break;
    }
    case 2:
        cout<<"Enter value to delete: ";
        cin>>value;
        head = deleteNode(head,value);
        break;
    case 3:
        cout<<"Enter value which you want to update: ";
        cin>>value;
        cout<<"Enter new value: ";
        cin>>newValue;
        updateNode(head,value,newValue);
        break;
    case 4:
        cout<<"Reversing the linked list..."<<endl;
        head = reverseLinkedList(head);
        break;
    case 5:
        break;
    default:
        cout<<"Enter a valid choice..."<<endl;
        break;
}
}
return 0;
}

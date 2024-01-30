#include <iostream>

//set the linked list up
struct Node{
    int data;
    Node* next;
};

//push means insert at the top/front
void push(Node**head,int num){
    Node* newNode=new Node;
    newNode->data=num;
    newNode->next=*head;
    *head=newNode;
}

//insert means insert at the end
void insert(Node**node,int num){
    Node* newNode=new Node;
    Node* last=*node;
    newNode->data=num;
    newNode->next=NULL;
    if(*node==NULL){
        *node=newNode;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
}

//insert after a given node
void insertAfter(Node* prev,int num){
    Node* newNode=new Node;
    if(prev==NULL){
        std::cout<<"your list is empty"<<std::endl;
        return;
    }
    newNode->data=num;
    newNode->next=prev->next;
    prev->next=newNode;
}

void del(Node* node,int num){
    Node* nodePtr, *previousNode;
    if (node==NULL){
        return;        
    }
    if (node->data==num){
        nodePtr=node->next;
        delete node;
        node=nodePtr;
    }else{
        nodePtr=node;
        while (nodePtr!=NULL && nodePtr->data!=num){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

void display(Node* node){
    if(node==NULL){
        std::cout<<"your list is empty"<<std::endl;
    }    
    while(node!=NULL){
        std::cout<<node->data<<std::endl;
        node=node->next;
    }
}

int main() {

    Node* head=NULL; //initialize your list;
    
    push(&head,69);
    push(&head->next,420);
    insert(&head,911);
    insert(&head,16);
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insertAfter(head->next->next,20); //insert after 911
    del(head,16);
    display(head);


    return 0;
}
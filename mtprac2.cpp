#include <iostream>
#include <string>


// INITIALIZE LINKED LIST
struct Node{
    int data;
    Node* next;
};


// DISPLAY THE LINKE LIST AND THE NUMBER OF NODES
void display(Node *node,int counter){
    if(node==NULL){
        std::cout<<"your list is empty";
        return;
    }while(node!=NULL){
        std::cout<<node->data<<" ";
        node=node->next;
    }
    std::cout<<std::endl;
    std::cout<<"the total number of nodes are: "<<counter<<std::endl;
}


// DELETE A SPECIFIC NODE
void del(Node* node,int num,int &counter){
    Node* nodeptr,*prev;
    if(node==NULL){
        return;
    }
    if(node->data==num){
        nodeptr=node->next;
        delete node;
        node=nodeptr;
        counter--;
    }else{
        nodeptr=node;
        while(nodeptr->next!=NULL && nodeptr->data!=num){
            prev=nodeptr;
            nodeptr=nodeptr->next;
        }
        prev->next=nodeptr->next;
        delete nodeptr;
        counter--;
    }
}


// INSERT A NODE AT THE FRONT OR TOP WITH COUNTER
void push(Node**node,int num,int &counter){
    Node* newnode=new Node;
    newnode->next=*node;
    newnode->data=num;
    *node=newnode;
    counter++;
}


// INSERT A NODE AT THE END OR BOTTOM WITH COUNTER
void insert(Node**node,int num,int &counter){
    Node* newnode=new Node;
    Node* last=*node;
    newnode->data=num;
    newnode->next=NULL;
    if(*node==NULL){
        *node=newnode;
        counter++;
        return;
    }while(last->next!=NULL){
        last=last->next;
    }
    counter++;
    last->next=newnode;
}

// REVERSE THE LINKED LIST
void reverse(Node* &node){
    Node* nodeptr=node;
    Node* prev=NULL;
    Node* next=NULL;
    while(nodeptr!=NULL){
        next=nodeptr->next;
        nodeptr->next=prev;
        prev=nodeptr;
        nodeptr=next;
    }
    node=prev;
}


// FIND A SPECIFIC NODE
void find(Node* node,int num){
    bool found=false;
    while(node!=NULL){
        if(node->data==num){
            std::cout<<"node found: "<<node->data<<std::endl;
            found=true;
        }
        node=node->next;
    }
    if(found==false){
        std::cout<<"node not found"<<std::endl;
    }

}


int main(){
    
    Node* head=NULL;
    int counter=0;
    // original(unreveresed) output is 69 420 911 16 69420
    insert(&head,20,counter);
    insert(&head,16,counter);
    push(&head,69,counter);
    push(&head->next,420,counter);
    push(&head->next->next,911,counter);
    insert(&head,69420,counter);
    del(head,20,counter);
    reverse(head);
    display(head,counter);
    find(head,20);
    /* OUTPUT SHOULD BE:  
        69420 16 911 420 69 
        the total number of nodes are: 5
        node not found            
    */

    return 0;
}


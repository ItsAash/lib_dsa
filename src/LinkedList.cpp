/*
    LETS FIRST SEE WHAT IS THE REASON BEHIND THE FORMATION OF NEW DATA STRUCTURE THAT IS LINKED LIST
        WHAT MADE CODERS TO USE LINKED LIST

            ARRAYS ADT                              LINKED LIST
        ->  CONTIGOUS MEMORY LOCATION (in c++)  => MAY BE NON CONTIGOUS AND ALWAYS IN HEAP
        =>  INSERTION AND DELETION              => TRAVERSING IS 
            COSTLY                                 COSTLY


            ==>BOTH ARE EQUALLY IMPORTANT AND CANNOT BE COMPARED ON THE BASIS OF WHICH ONE IS TH BEST ONE

        NOTES:
            1.  ARRAYS ARE USEFUL WHENEVER WE KNOW THE SIZE OR FOR THE STATIC DATA;
            2.  LINKED LIST IS USEFUL WHENEVER INSERTION OR DELETION IS TO BE DONE

            3. SEARCHING IS FASTER IN ARRAY THAN IN LINKED LIST
            4. BINARY SEARCH IS NOT AVAILABLE ON LINKED LIST

            #INTRESTING FACT
                ARRAY DOESNOT TAKE CONTIGOUS MEMORY IN JAVA ONLY.

*/
/* *********************LETS CODE***************************** */

#include<iostream>
using namespace std;

struct node{
    int data;
        struct node *next;


}*head=NULL;

//  CREATE LINKED LIST FROM ARRAY
void create(int a[],int size){
    struct node *last,*Getinstance;
    head=new node();
        head->data=a[0];
        head->next=NULL;
        last=head;

        for(int i=1; i<size; i++){
            Getinstance=new node();
                Getinstance->data=a[i];
                Getinstance->next=NULL;
                last->next=Getinstance;
                last=Getinstance;
        }
}
//  TRAVERSING THROUGHOUT THE LINKED LIST
void display(struct node * head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

//COUNTING NODES
int count_Nodes(struct node * head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

// INSERTION IN LINKED LIST

void insert_Linkedlist(int index,int data){
        struct node *new_node;
        struct node *new_node1;
        int size;
    
        if(index==0){
            new_node=new node();
                new_node->data=data;
                    new_node->next=head;

                    head=new_node;
        }else if(index>0){
            new_node1=head;

            for ( int i = 0; i < index-1; i++)
            {
                new_node1=new_node1->next;
            }

            if (new_node1)
            {
                new_node=new node();
                new_node->data=data;
                new_node->next=new_node1->next;
                new_node1->next=new_node;
            }
            
            
        }
}
//Reversing an Linked List

void ReverseLinkedListUSingsliding(struct node *head){
    struct node *p=NULL;
    struct node *q=NULL;
    struct node *first=head;

    while (head!=NULL)
    {
        p=q;
        q=first;
        first=head->next;

        q->next=p;
        first->next=q;
        head=head->next;

    }
        
}

//Deleting a index

void delete_Link(int position){
    struct node *p,*q;
    p=head;
    q=NULL;
    if(position==1){
        head=head->next;
    }
    else if(position>1){

    for (int  i = 0; i < position-1; i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    p->next=NULL;
    delete(p);
    }
    
}


//MAIN FUNCTION
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int count=0;
    for(auto n:a){
        count++;
    }
    cout<<"Counts:"<<count<<endl;
    create(a,count);
    display(head);
    cout<<"Number of Nodes :"<<count_Nodes(head)<<endl;
    insert_Linkedlist(10,5);
    display(head);
    cout<<endl<<endl;
    delete_Link(1);
    display(head);
    return 0;
}

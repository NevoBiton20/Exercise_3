#include "StrList.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>


//-----------------------------
//Node implementaion
//-----------------------------
typedef struct _node {
    char* data;
    struct _node * next;
}Node;

Node* Node_alloc(char* data, Node* next)
{
    Node* p= (Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("memory allocation failed\n");
        exit(0);
    }
    p->data = data;//remember
    p->next = next;
    return p;
}

void Node_free(Node* node)
{
    free(node);
}
//--------------
//End Node implementaion
//--------------


//--------------
//List implementaion
//--------------

struct _StrList
{
    Node *head;
    size_t size;
};

StrList* StrList_alloc()
{
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if(newList==NULL)
    {
        printf("Memory allocation falied\n");
        return;
    }
    newList->head = NULL;
    newList->size= 0;
    return newList;
}

void StrList_free(StrList* StrList)
{
    if(StrList==NULL)
    {
        return;
    }
    Node* current = StrList->head;
    Node* temp;
    while(current)
    {
        temp = current;
        current = current->next;
        Node_free(temp);
    }
}

size_t StrList_size(const StrList* StrList)
{
    if(StrList==NULL)
    {
        printf("Null Exepction\n");
        return;
    }
    return StrList->size;
}

void StrList_insertLast(StrList* StrList, const char* data)
{
    if(StrList==NULL)
    {
        printf("Null Exepction\n");
        return;
    }
    if(StrList->head==NULL)
    {
        StrList->head = Node_alloc(data,StrList->head);
        ++(StrList->size);
        return;
    }

    Node* current = StrList->head;
    while(current->next)
    {

        current = current->next;
    }
    current->next = Node_alloc(data,NULL);
    ++(StrList->size);
}


void StrList_insertAt(StrList* StrList, const char* data,int index)
{
    if(StrList==NULL)
    {
        printf("Null Exepction\n");
        return;
    }

    if(StrList->head==NULL)
    {
        StrList->head = Node_alloc(strdup(data),StrList->head);
        ++(StrList->size);
        return;
    }


    if(index<0) //Negative Index Exepction
    {
        printf("Error not an index\n");
        return;
    }

    if(index==0)
    {
        Node* first = Node_alloc(strdup(data),StrList->head);
        StrList->head = first;
        ++(StrList->size);
        return;
    }

    Node* newNode;
    Node *current = StrList->head;
    while(current && index>1)
    {
        index--;
        current = current->next;
    }
    if(!current)
    {
        printf("Index: %d out of bounds of the list\n", index);
        return;
    }
    newNode = Node_alloc(strdup(data),current->next);
    current->next=newNode;
    ++(StrList->size);
}

char* StrList_firstData(const StrList* StrList)
{
    return StrList->head->data;
}


void StrList_print(const StrList* StrList)
{
    if(!StrList||!StrList->head||StrList->size==0)
    {
        printf("\n");
        return;
    }
    const Node* temp = StrList->head;
    while(temp)
    {
        printf("%s",temp->data);
        temp=temp->next;
        if(temp)
        {
            printf(" ");
        }
    }
    printf("\n");
}


void StrList_printAt(const StrList* StrList,int index)
{
    if(StrList==NULL)
    {
        printf("Null Exepction\n");
        return;
    }

    if(StrList->head==NULL)
    {
        printf("Empty List");
        return;
    }


    if(index<0) //Negative Index Exepction
    {
        printf("Error not an index\n");
        return;
    }

    Node *current = StrList->head;
    while(current && index>0)
    {
        index--;
        current = current->next;
    }
    if(!current)
    {
        printf("Index: %d out of bounds of the list\n", index);
        return;
    }
    printf("%s\n", current->data);
}


int StrList_printLen(const StrList* Strlist)
{
    int list_Len = 0;
    Node *current = Strlist->head;
    while(current)
    {
        char* word;
        for(word=current->data; *word !='\0';word++)
        {
            list_Len++;
        }
        current=current->next;
    }
    return list_Len;

}


int StrList_count(StrList* StrList, const char* data)
{
    int count=0;
    Node* current =StrList->head;
    while(current)
    {
        if(strcmp(current->data,data)==0)
        {
            count++;
        }
        current=current->next;
    }
    return count;
}


void StrList_remove(StrList* StrList, const char* data)
{
    Node *current=NULL;
    if(!StrList)
    {
        printf("Null Exepction\n");
        return;
    }
    
    while(StrList->head && strcmp(StrList->head->data,data)==0)
    {
        current = StrList->head;
        StrList->head = current->next;
        free(current);
        --(StrList->size);

    }
    
    if(!StrList->head)
    {
        return;
    }
    current = StrList->head;
    Node*temp = NULL;
    
    while(current->next)
    {
        if(strcmp(current->next->data,data)==0)
        {
            temp = current->next;
            current->next= current->next->next;
            free(temp);
            --(StrList->size);
        }
        else
        {
            current=current->next;
        }
    }
    
}


void StrList_removeAt(StrList* StrList, int index)
{
    if(!StrList)
    {
        printf("Null Exepction\n");
        return;
    }
    if(!StrList->head)
    {
        return;
    }
    if(index<0) //Negative Index Exepction
    {
        printf("Error not an index\n");
        return;
    }
    Node *current = StrList->head;
    if(index==0)
    {
        StrList->head=StrList->head->next;
        free(current);
        --(StrList->size);
        return;
    }
    while(index>1)
    {
        index--;
        current = current->next;
    }
    if(!current ||!current->next)
    {
        printf("Index out of bounds of list\n");
        return;
    }
    Node *temp=current->next;
    current->next = current->next->next;
    free(temp);
    --(StrList->size);
}


int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    Node *current1=StrList1->head;
    Node *current2=StrList2->head;
    if(StrList1->size != StrList2->size)
    {
        return 0;
    }
    if(!StrList1 || !StrList2)
    {
        printf("NULL Exeption\n");
        return 0;
    }
    while(current1 && current2)
    {
        if(strcmp(current1->data,current2->data)!=0)
        {
            return 0;
        }
        current1=current1->next;
        current2=current2->next;
    }
    return 1;
}

StrList* StrList_clone(const StrList* StrList)
{
    struct _StrList *clone = StrList_alloc();
    if(StrList->head==NULL)
    {
        return clone;   
    }
    Node *current = StrList->head;

    while(!current)
    {
        StrList_insertLast(clone,current->data);
        current = current->next;
    }
    return clone;
}


void StrList_reverse( StrList* StrList)
{
    if(!StrList)
    {
        printf("NULL Exepction");
        return;
    }
    if(!StrList->head || (StrList->size==1))
    {
        return;
    }
    
    Node* current =StrList->head;
    Node* prev =NULL;
    Node* next = NULL;

    while(current)
    {
        next=current->next;
        current->next = prev;
        prev=current;
        current=next;
    } 
    StrList->head = prev;     
}

void swap( Node* p1, Node* p2)
{
    char* temp = p1->data;
    p1->data=strdup(p2->data);
    p2->data=strdup(temp);
}

void StrList_sort( StrList* StrList)
{
    size_t i,j,n=StrList->size;
    int swapped;
    Node* current=StrList->head;
    for(i=0;i<n-1;i++)
    {
        swapped=0;
        current=StrList->head;
        for(j=0;j<n-i-1;j++)
        {
            if(strcmp(current->data,current->next->data)>0)
            {
                swap(current,current->next);
                swapped=1;
            }
            current = current->next;
        }

        if(swapped == 0)
        {
            break;
        }
    }
}

int StrList_isSorted(StrList* StrList)
{
    Node* current = StrList->head;
    while(current->next)
    {
        if(strcmp(current->data,current->next->data)>0)
        {
            return 0;
        }
        current=current->next;
    }
    return 1;
}





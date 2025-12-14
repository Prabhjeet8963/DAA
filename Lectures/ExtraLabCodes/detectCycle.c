#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; 
}Node;

Node* CreateNode(int input_data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = input_data;
    NewNode->next = NULL;
    return NewNode;
}

int detectCycle(Node* startNode,int n);

int main()
{
    int n = 0;
    Node* startNode = CreateNode(1);
    startNode->next = CreateNode(2);
    startNode->next->next = CreateNode(3);
    n = 3;

    int cycle = detectCycle(startNode,n);
    printf("cycle detected:%d\n",cycle);

    startNode->next->next->next = startNode;
    printf("\n");

    cycle = detectCycle(startNode,n);
    printf("cycle detected:%d\n",cycle);

    return 0;
}

int detectCycle(Node* startNode,int n)
{
    int i = 0;
    Node* temp = startNode;
    printf("LINKED LIST:\n");
    while(i<n+5 && temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
    if(startNode == NULL || startNode->next == NULL)
    {
        return 0;
    }
    Node* slowPoint = startNode;
    Node* fastPoint = startNode;
    while(fastPoint!= NULL && fastPoint->next != NULL)
    {
        slowPoint = slowPoint->next;        //moves 1 step at a time
        fastPoint = fastPoint->next->next;  //moves 2 steps at a time
        if(slowPoint == fastPoint)
        {
            return 1;
        }
    }
    return 0;
}

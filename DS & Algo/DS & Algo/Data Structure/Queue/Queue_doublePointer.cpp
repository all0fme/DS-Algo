#include<iostream>
using namespace std;
//this form of queue has disadvantage that a space cannot be reused.
//Also there may be a situation when the queue is full as well as empty
struct Queue
{
    int size_q;
    int rear_pointer;
    int front_pointer;
    int *arr;

};

void createQueue(struct Queue *Q,int size_q)
{
    Q->size_q=size_q;
    Q->rear_pointer=-1;
    Q->front_pointer=-1;
    Q->arr= new int[size_q];
}
bool isFull(struct Queue *Q)
{
    return (Q->rear_pointer==Q->size_q-1);
}
bool isEmpty(struct Queue *Q)
{
    return (Q->rear_pointer==Q->front_pointer);
}
void enQueue(struct Queue *Q,int x)
{
    if(isFull(Q)){
        cout<<"Queue is Full\n";
        return;}
    Q->arr[++Q->rear_pointer]=x;

}
int deQueue(struct Queue *Q)
{
    int x=-1;
    if(isEmpty(Q))
    {
        cout<<"Queue is Empty\n";
    }
    else
    {
        x=Q->arr[++Q->front_pointer];
        //shifting to the front_pointer place is not involved so it takes O(1) for deletion


    }
    return x;
}
void display(struct Queue *Q)
{
    if(isEmpty(Q))
    {
        cout<<"Nothing to display,Queue is Empty\n";
        return;
    }
    for(int i=Q->front_pointer+1;i<=Q->rear_pointer;i++)
    {
        cout<<Q->arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{

    struct Queue qu;
    createQueue(&qu,10);
    enQueue(&qu,2);
    enQueue(&qu,4);
    enQueue(&qu,6);
    enQueue(&qu,8);
    display(&qu);

    deQueue(&qu);
    display(&qu);
    deQueue(&qu);
    display(&qu);
    deQueue(&qu);
    display(&qu);
    deQueue(&qu);
    display(&qu);

     enQueue(&qu,2);
    enQueue(&qu,4);
    enQueue(&qu,6);
    enQueue(&qu,8);
    enQueue(&qu,2);
    enQueue(&qu,4);
    enQueue(&qu,6);
    enQueue(&qu,8);
    enQueue(&qu,2);
    enQueue(&qu,4);
    enQueue(&qu,6);
    enQueue(&qu,8);
    display(&qu);
    return 0;
}

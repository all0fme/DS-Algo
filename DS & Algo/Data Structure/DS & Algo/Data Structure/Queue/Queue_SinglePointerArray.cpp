#include<iostream>
using namespace std;

struct Queue
{
    int size_q;
    int rear;
    int *arr;

};

void createQueue(struct Queue *Q,int size_q)
{
    Q->size_q=size_q;
    Q->rear=-1;
    Q->arr= new int[size_q];
}
bool isFull(struct Queue *Q)
{
    return (Q->rear==Q->size_q-1);
}
bool isEmpty(struct Queue *Q)
{
    return (Q->rear==-1);
}
void enQueue(struct Queue *Q,int x)
{
    if(isFull(Q))
        cout<<"Queue is Full\n";
    else
    Q->arr[++Q->rear]=x;

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
        x=Q->arr[0];
        //shifting to the first place is involved so it takes O(n) for deletion
        for(int i=0;i<Q->rear;i++)
        {
            Q->arr[i]=Q->arr[i+1];
        }
        Q->rear--;
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
    for(int i=0;i<=Q->rear;i++)
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
    cout<<deQueue(&qu)<<endl;
    display(&qu);

    return 0;
}

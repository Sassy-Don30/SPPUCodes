/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.*/

#include <bits/stdc++.h>
#define MAX 5
using namespace std;

class Node{
    int data[MAX];
    int start, rear;
    friend class Queue;
};

class Queue{

private:
    Node q;

public:
    Queue(){
        q.start = q.rear = -1;
    }

    int IsEmpty(){
        return (q.start == q.rear) ? 1 : 0;
    }

    int IsFull(){
        return (q.rear == MAX-1) ? 1 : 0;
    }

    void AddQueue(int x){
        q.data[++q.rear] = x;
    }

    int DelQueue(){
        return q.data[++q.start];
    }

    void DisplayQueue(){
        for(int i=q.start+1;i<=q.rear;i++)
            cout<<q.data[i]<<" ";
    }

};

int main(){
    Queue obj;
    int ch, x;

    do{
        cout<<"\nMenu: \n1.Insert job \n2.Delete job \n3.Display jobs \n0.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                if(!obj.IsFull()){
                    cout<<"Enter data:";
                    cin>>x;
                    obj.AddQueue(x);
                }
                else
                    cout<<"Queue overflow!!!!";
                break;

            case 2:
                if(!obj.IsEmpty())
                    cout<<"\nDeleted job is: "<<obj.DelQueue();
                else
                    cout<<"\nQueue underflow!!!!";
                break;

            case 3:
                if(!obj.IsEmpty()){
                    cout<<"Jobs present in the queue are:"<<endl;
                    obj.DisplayQueue();
                }
                else
                    cout<<"\nQueue is empty!!!!";
                break;

            case 0:
                cout<<"Byeeeee";
                break;

            default:
                cout<<"Enter appropriate value!";
                break;
        }
    } while(ch != 0);
    return 0;
}

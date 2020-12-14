//Sassy_Don30

#include <bits/stdc++.h>
#define SIZE 7
using namespace std;

class Dequeue{
    int arr[SIZE], start, rear, total; // ek array usme start aur end

public:
    Dequeue(){
        start = -1; // contructor me sabko default values di
        rear = -1;
        total = 0;
    }

    void AddAtFront(int data){
        if(start == -1){ // agar pehla element hai toh
            start++; // start aur rear ko kiya 0
            rear++;
            arr[rear] = data; // aur value de di waha pe
            total++; // number of items increment
        }
        else if(rear >= SIZE - 1) // agar size ke bahar ja raha toh overflow
            cout<<"Overflow!!"<<endl;

        else{ // agar first bhi nahi aur overflow bhi nahi
            int i;
            for(i=total;i>=0;i--) // toh saare elements me ghoome
                arr[i] = arr[i-1]; // current wale ko pichle wali ki value, total hamesha rear se ek jada hoga because of 0 indexing
            arr[i] = data; // aur first element jo sabse aage hoga usme value de di
            total++; // total aur rear increase
            rear++;
        }
    }

    void AddAtEnd(int data){ // agar piche dalna hai toh
        if(start == -1){ // empty hai toh normal way me increment fir allot
            start++;
            rear++;
            arr[rear] = data;
            total++;
        }
        else if(rear >= SIZE - 1) // overflow hai toh exception
            cout<<"Overflow!!"<<endl;

        else
            arr[++rear] = data; // normally rear increase kiya fir allot kiya
    }

    void DisplayQ(){ // first se last tak jayenge aur print
        for(int i=start;i<=rear;i++)
            cout<<arr[i]<<" ";
    }

    void DeleteStart(){
        if(start == -1)
            cout<<"Underflow!!"<<endl; // empty pe underflow
        else{
            if(start == rear){ // agar ek element hai toh
                start = rear = -1; // wapas se dono ko -1 kar diya
                //return;
            }
            cout<<"Deleted data is: "<<arr[start]<<endl; // yaha print kiya
            start += 1; // aur aage kar diya start ko
        }
    }

    void DeleteEnd(){
        if(start == -1){ // empty pe kuch nahi
            cout<<"Underflow!!"<<endl;
            return;
        }
        else {
            if(start == rear) // agar pehla hai toh dono ko -1
                start = rear = -1;
            cout<<"Deleted data is: "<<arr[rear]<<endl; // piche ka element show
            rear -= 1; // rear ko ek kam kiya
        }
    }
};

int main(){
    int ch, item;
    Dequeue deq;

    do{ // simple menu banaya
        cout<<"\nMenu: \n1.Insert at start \n2.Insert at end \n3.Display \n4.Delete from start \n5.Delete from end \n0.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter element to add at front: ";
                cin>>item;
                deq.AddAtFront(item);
                break;

            case 2:
                cout<<"Enter element to add at end: ";
                cin>>item;
                deq.AddAtEnd(item);
                break;

            case 3:
                deq.DisplayQ();
                break;

            case 4:
                deq.DeleteStart();
                break;

            case 5:
                deq.DeleteEnd();
                break;

            case 0:
                cout<<"Byeee!!"<<endl;

            default:
                cout<<"Enter appropriate value!!"<<endl;
        }
    } while(ch != 0);
    return 0;
}

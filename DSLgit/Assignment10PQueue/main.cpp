//Sassy_Don30

#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int priority; // priority aur id node me hoga aur uske sath next pointer
    int id;
    Node* next;

public:
    Node(){
        priority = 0;
        id = 0;
        next = nullptr;
    }

    void GetData(){ // id aur priority input lega yaha pe
        cout<<"\nInput job id: ";
        cin>>id;
        cout<<"\nEnter priority: ";
        cin>>priority;
    }

    friend class PQueue;
};

class PQueue{
private:
    Node* start, dataHub; // head node hoga ye

public:
    PQueue(){
        start = nullptr; // next ko null kiya
        //start->id = 0; // ye dono lines dalo toh run nahi rahe doubt hai!!!!
        //start->priority = 100;
        dataHub.id=0; // garbage value taken if not alloted
    }

    void InsertData(){
        Node *temp, *q;
        temp = new Node;
        temp->GetData(); // jo input lenge voh store kiya
        if(dataHub.id>5){
            cout<<"Overflow!!"<<endl;
            return;
        }

        if(start == nullptr || temp->priority < start->priority){ // agar head null hai ya fir iski priority max hai
            temp->next = start; // temp jisko point karega voh originally head jisko kar raha tha usko karega
            start = temp; // aur ab start ko temp ke equal kar diya
        }
        else{ // agar first nahi hai, beech me ya end me hai
            q = start; // iterate karne ke liye
            while(q->next != nullptr && q->next->priority <= temp->priority) // jab tak end nahi aata aur priority order ma nahi pohochte
                q = q->next;
            temp->next = q->next; // temp ka pointer q ke next ko
            q->next = temp; // aur isko firse reset
        }
        dataHub.id++;
    }

    void DeleteData(){
        Node* temp;
        if(start == nullptr)
            cout<<"Underflow!!"<<endl;
        else{
            temp = start; // sabse aage wala item delete
            cout<<"Deleted item is: "<<temp->id<<endl;
            start = start->next; // aage bad jayenge
            dataHub.id--;
        }
    }

    void DisplayQ(){
        Node* temp;
        temp = start;
        if(start == nullptr)
            cout<<"Queue is empty!!";
        else{
            cout<<"There are "<<dataHub.id<<" elements!"<<endl;
            cout<<"Queue is :\n";
            cout<<"Priority\tItem\n";
            while(temp != nullptr){ // jab tak queue end nahi hota
                cout<<temp->priority<<"\t\t"<<temp->id<<endl; // priority aur id print karega ye
                temp = temp->next;
            }
        }
    }

};


int main(){
    int ch;
    PQueue pq;

    do{
        cout<<"\nMenu: \n1.Insert \n2.Display \n3.Delete \n0.Exit"; // simple menu hai
        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                pq.InsertData();
                break;
            case 2:
                pq.DisplayQ();
                break;
            case 3:
                pq.DeleteData();
                break;
            case 0:
                cout<<"Byeeee!"<<endl;
                break;
            default:
                cout<<"\nEnter appropriate value!!";
                break;
        }
    } while(ch != 0);
    return 0;
}

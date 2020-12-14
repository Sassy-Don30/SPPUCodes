/*
Second year Computer Engineering class, set A of students like
Vanilla Ice-cream and set B of students like butterscotch ice-cream.
Write C/C++ program to store two sets using linked list. compute and display
1. Set of students who like both vanilla and butterscotch
2. Set of students who like only vanilla or butterscotch but not both
3. Number of students who like neither vanilla nor butterscotch.
*/

#include <bits/stdc++.h>

using namespace std;

class Student{

    int rollNo; //roll number student ka aur sath me next item ke liye pointer
    Student *nextPtr;

public:
    Student(){ //empty constructor banaya jisme random values jayengi
        rollNo = 0;
        nextPtr = nullptr;
    }

    Student(int roll){ //parameter wala banaya roll number ke liye
        rollNo = roll;
        nextPtr = nullptr; //pointer ko null rakha taaki error na de
    }

    friend class Set; //jaha saare set operations honge usko friend banaya
};

class Set{

    int total,roll; //friend class me ek total aur roll store karne ke liye
    Student* head; //ye pointer start point batayga singly linked list ka

public:

    Set(){
        head = nullptr; ///start ko initially null diya taaki set kar sake baad me
    }

    void Create(int funRoll){ // create an entry
        Student* ptr = new Student(funRoll); //ptr banaya student ka jo ek new object ko hai parametrized

        if(head==nullptr) head = ptr; //agar ye ekdum first entry hai, toh head me iski value dal denge

        else { //agar first entry nahi hai
            Student *temp = head; //toh student class ka ek ptr jo set class ke head ko point kar raha, kyuki link wahi se start ho raha

            while(temp->nextPtr != nullptr) // aur tab tak aage chal raha jab tak last element na aa jay
                temp = temp->nextPtr; // jaise hi last me pohoch jayenge
            temp->nextPtr = ptr; //waha pe new student jo create kiya uska dal location
        }
    }

    void Insert(){
        cout<<"Enter total number of students:"; // total me jitne students hai voh dalenge
        cin>>total;

        cout<<"Enter all roll numbers:"; // ab saare elements dalenge
        for(int i=0;i<total;i++){
            cin>>roll; //jo roll number add karna hai voh kiya
            Create(roll); //by passing it into the function
        }
    }

    void Display(){
        cout<<"Set is:"<<endl;
        Student* ptr = head;

        while(ptr != nullptr){
            cout<<ptr->rollNo<<"->";
            ptr = ptr->nextPtr;
        }
        cout<<endl;
    }

    void DeleteNode(Student *toDelete){


    }

    Set Intersection(Set doosraSet){
        //cout<<"Students who like both vanilla and butterscotch"<<endl;
        Student* tempPehla = head; //pehle set ko ptr jo head se start karega
        Student* tempDoosra = doosraSet.head; // doosre set ko ptr head se star
        Set intersectionSet; // interstion set name ka object

        //agar tempPehla->nextPtr != nullptr kiya toh voh last wala check hi nahi karega, ek piche ruk jayga
        while(tempPehla != nullptr){ //pehle set me ghoome
            tempDoosra = doosraSet.head;
            while(tempDoosra != nullptr){ // doosre set me ghoome
                if(tempPehla->rollNo == tempDoosra->rollNo){ // agar common mila koi roll number
                    intersectionSet.Create(tempDoosra->rollNo); // toh intersection set me use add kiya
                    break;
                }
                tempDoosra = tempDoosra->nextPtr; // increment operator doosre set ka
            }
            tempPehla = tempPehla->nextPtr; // pehle ka increment
        }
        //intersectionSet.Display();
        return intersectionSet;
    }

    Set UnionSet(Set doosraSet){
        Student* tempPehla = head;
        Set unionSet = doosraSet;
        Student* tempUnion = unionSet.head;
        bool flag;

        while(tempPehla != nullptr){
            tempUnion = unionSet.head;
            flag = false;

            while(tempUnion != nullptr){
                if(tempPehla->rollNo == tempUnion->rollNo){
                    flag = true;
                    break;
                }
                tempUnion = tempUnion->nextPtr;
            }
            if(!flag)
                unionSet.Create(tempPehla->rollNo);

            tempPehla = tempPehla->nextPtr;
        }

        return unionSet;
    }


    // jinhe sirf ek ice cream pasand hai, (union-intersection)
    void OnlyOne(Set doosraSet){
        //Student* tempPehla = head;

        Set intersectionSet = this->Intersection(doosraSet); //intersection ka set banaya
        Student* tempInter = intersectionSet.head;

        Set unionSet = this->UnionSet(doosraSet); //union ka set banaya
        Student* tempUnion = unionSet.head;

        bool flag = false;
        Set onlyOneSet;

        while(tempUnion != nullptr){
            tempInter = intersectionSet.head; //normally jaise common elements jo nahi hai voh alag set me dale
            flag = false;
            while(tempInter != nullptr){
                if(tempUnion->rollNo == tempInter->rollNo){
                    flag = true;
                    break;
                }
                tempInter = tempInter->nextPtr;
            }
            if(!flag)
                onlyOneSet.Create(tempUnion->rollNo);

            tempUnion = tempUnion->nextPtr;
        }

        onlyOneSet.Display(); //fir display kiya
        cout<<endl;
    }

    Set Nothing(Set pehlaSet, Set doosraSet){
        Student* tempTotal = head;
        bool flag;

        Set unionSet = pehlaSet.UnionSet(doosraSet);
        Student* tempUnion = unionSet.head;

        Set nothingSet;
        while(tempTotal != nullptr){
            tempUnion = unionSet.head;
            flag = false;

            while(tempUnion != nullptr){
                if(tempUnion->rollNo == tempTotal->rollNo){
                    flag = true;
                    break;
                }
                tempUnion = tempUnion->nextPtr;
            }
            if(!flag)
                nothingSet.Create(tempTotal->rollNo);

            tempTotal = tempTotal->nextPtr;
        }

        return nothingSet;
    }

};


int main(){
    int choice;
    Set vanillaSet, butterscotchSet, totalStudents;
    cout<<"Total Student Data"<<endl;
    totalStudents.Insert();
    totalStudents.Display();

    cout<<"\nVanilla Data"<<endl;
    vanillaSet.Insert();
    vanillaSet.Display();

    cout<<"\nButterscotch Data"<<endl;
    butterscotchSet.Insert();
    butterscotchSet.Display();

    do{
        cout<<"\nMenu: \n1.Students who like both ice-creams \n2.Students who like only either vanilla or butterscotch but not both \n3.Students who like neither vanilla nor butterscotch \n0.Quit"<<endl;
        cin>>choice;

        switch(choice){
        case 1:{
            cout<<"\nStudents who like both ice-creams:"<<endl;
            Set inter = vanillaSet.Intersection(butterscotchSet);
            inter.Display();
            break;
            }

        case 2:{
            cout<<"\nStudents who like only either vanilla or butterscotch but not both:"<<endl;
            vanillaSet.OnlyOne(butterscotchSet);
            break;
        }

        case 3:{
            cout<<"\nStudents who like neither vanilla nor butterscotch:"<<endl;
            Set noLikes = totalStudents.Nothing(vanillaSet, butterscotchSet);
            noLikes.Display();
            break;
        }

        case 0:
            cout<<"Byee"<<endl;
            break;

        default:
            cout<<"Enter appropriate values\n";
        }

    } while(choice != '0');

    return 0;
}

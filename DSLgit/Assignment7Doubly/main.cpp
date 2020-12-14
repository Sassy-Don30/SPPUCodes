#include <bits/stdc++.h>
using namespace std;

class Node{
    Node* prevPtr; // piche ka pointer
    bool num; // current digit
    Node* nextPtr; // aage ka

public:
    Node(){
        prevPtr = nextPtr = nullptr; // null banaya aage aur piche
    }

    Node(bool bo){
        num = bo; // current ko value di
        prevPtr = nextPtr = nullptr; // null banaya
    }

    friend class Binary; // jaise singly me kiya, yaha bhi same, friend use kiya
};

class Binary{
    Node* head; // start of list ya head jo bhi

public:
    Binary(){
        head = nullptr; // jab start hoga tab null banake hoga
    }

    //start me node add kar rahe
    bool AddStart(bool val){
        Node* tempNode = new Node(val); // pehle naya node banaya aur usko argument wali value di
        if(head == nullptr) // agar head khali hai toh use isse bhara
            head = tempNode;

        else{ // agar head khali nahi hai
            tempNode->nextPtr = head; // toh temp ka next ko head ki value di
            head->prevPtr = tempNode; // head ka prev jo tha usko temp ki taraf
            head = tempNode;
        }

        return true; // true matlab 1, ban gaya start me
    }

    void CreateBinary(int inputNum){
        bool rem; // current ke liye jaise liye waise hi
        Node* temp;

        // ye loop ke bahar kiya taaki head dal sake uske baad normally append to left side
        rem = inputNum%2; // because ya toh 0 ya fir 1 hi hoga hamara binary digit
        head = new Node(rem); // agar 11 dala, toh sabse right me 1 aayga, toh voh hamara head hoga yaha pe
        // aur uske baad hum left ki taraf jaate hue digits dalenge
        inputNum /= 2; // aur fir input number of half karenge taaki next binary digit da pay

        while(inputNum != 0){ // similar toh number ka remainder nikalna
            rem = inputNum%2; // 0 ya 1 nikala
            inputNum /= 2; // number half kiya

            temp = new Node(rem); // new node banaya rem value ka jo head ke left lagana hai
            // temp ko left me add karne ke liye 2 connections kiye
            temp->nextPtr = head; // temp kyuki left me hai, toh uska right/next hua head
            head->prevPtr = temp; // aur head ke piche wale ko kiya temp ki taraf
            head = temp; // dono ko equal kiya
        }
        // jaise 11 dala, toh sabse pehle humne rem 1 ka node sabse right me lagaya aur fir 11/2 = 5
        // fir 5%2 = 1 toh jo pehle se 1 tha uske left me ek aur 1 lagaya, aur 5/2 = 2
        // 2%2 = 0, jo do pehle se 1 hai uske left me ek 0 lagaya uske baad 2/2 = 1
        // 1%2 = 1, toh finally 1 lagaya 011 ke left me jisse ban jayga binary ready because now input num is 0
        // 1011 ready hai for further use

    }


    void DisplayBinary(){
        Node* temp = head; // head ki taraf ek node banaya

        while(temp != nullptr){ // aur end tak leke gaye usko
            cout<<temp->num; // us location ke num jo print kiya, 1 ya 0
            temp = temp->nextPtr; // pointer ko aage leke jao
        }
    }


    void OneComplement(){
        Node* temp = head; // head ki taraf pointer

        while(temp != nullptr){ // iterate karne ke liye end tak

            temp->num = (temp->num == 0 ? 1 : 0); // agar 0 hai toh 1 kiya 1 hai toh 0
            /*
            if(temp->num == 0)
                temp->num = 1;
            else
                temp->num = 0;*/

            temp = temp->nextPtr; // next ki taraf jaane ke liye
        }
    }


    void TwoComplement(){
        OneComplement(); // pehle usko one complement kiya
        bool carry = 1; // one complement karte fir 1 add karte isleye starting se carry 1 hoga

        Node* temp = head; // pointer kiya head ka

        while(temp->nextPtr != nullptr) // usko leke end se ek pehle tak gaye
            temp = temp->nextPtr; // kyuki temp ka next 0 hua toh voh jayga hi nahi loop me aur second last pe stop

        while(temp != nullptr){ // null tak leke jaana hai firse
            if(temp->num == 1 && carry == 1){ // agar 1 + 1 hai toh usko 0 kar do aur carry jo aage jayga voh 1
                temp->num = 0; // num ko 0 kiya
                carry = 1; // carry 1 ho jayga
            }

            else if(temp->num == 0 && carry == 1){ // lekin agar 1+0 hai toh
                temp->num = 1; // num ko 1 kar denge
                carry = 0; // carry ab ruk jayga
            }

            else if(carry == 0) // carry 0 matlab aage wale num pe koi farak nahi padega toh stop
                break;

            temp = temp->prevPtr; // pointer aage leke jaane ke liye
        }
    }


    Binary operator +(Binary num2){ // overload kiya + ko
        Binary sum; // sum ke liye alag se banaya
        Node* tempPehla = head; // 2 pointer to 2 binary num ke head because ekdum left me hai voh
        Node* tempDoosra = num2.head;
        bool carry = false; // false matlab 0

        while(tempPehla != nullptr) // isko last digit tak leke gaye
            tempPehla = tempPehla->nextPtr;

        while(tempDoosra != nullptr) // isko last tak leke gaye, right most tak
            tempDoosra = tempDoosra->nextPtr;

        // ^ basically XOR hai, agar dono digit same hai toh 0 copy karega warna 1 karega
        while(tempPehla != nullptr && tempDoosra != nullptr){ //  jab tak dono khatam nahi hote
            // sum me start kiya add karna
            sum.AddStart((tempPehla->num)^(tempDoosra->num)^carry); // dono binary ke digit compare kiye using XOR
            // agar dono 0 with carry 0 toh 0 aayga, agar dono 1 with carry 1 toh 1 aayga, and so on

            // dono digit ke num ka AND kiya carry ke sath alag se
            // agar dono digit 1 hai toh carry 1 ho jayga, agar ek 1 aur pehle se carry 1 hai toh 1, doosra 1 aur carry 1 toh 1
            // agar koi bhi digit 0 hai aur carry 1, toh carry 0 ho jayga, us digit ko 1 bana denge
            carry = ((tempPehla->num && tempDoosra->num) || (tempPehla->num && carry) || (carry && tempDoosra->num));

            tempPehla = tempPehla->prevPtr; // dono pointer aage leke jaane ke liye
            tempDoosra = tempDoosra->prevPtr;
        }

        //jaise merge wale assignment me kiya tha, agar ek binary doosre se bada hai toh
        // dono ke liye alag se ek loop banayenge
        while(tempPehla != nullptr){ // jab ekdum right me pohoch gaya, toh left tak leke jaana hai fir
            sum.AddStart(tempPehla->num ^ carry); // isko add karte gaye num + carry karke
            tempPehla = tempPehla->prevPtr; // aur left ki taraf jaate gaye toh handle the carry wala part
        }

        while(tempDoosra != nullptr){ // doosre ke liye same
            sum.AddStart(tempDoosra->num ^ carry); // digit aur carry ko add kiya aur sum me add kiya
            tempDoosra = tempDoosra->prevPtr; // left ki taraf
        }

        sum.AddStart(carry); // agar end me carry bach gaya, ekdum left me, toh usko alag se banaya warna 0 aa jayga waha
        return sum;
    }

};



int main(){
    int num1, num2; // input ke liye 2 decimal numbers
    Binary bin1, bin2, bin3; // 2 binary aur ek sum ke liye
    int choice;

    do{
        cout<<"\n\n=========Binary Number Operations========\n"; // menu banyaa
		cout<<"1.Generate binary\n2.One's Complement\n3.Two's Complement\n4. Addition\n0.Exit\nEnter your choice: ";
		cin>>choice;

		switch(choice){ // normal switch case se kiya hai sab yaha pe
        case 1:
            cout<<"\nEnter number in decimal form:"; // decimal number dala
            cin>>num1;
            bin1.CreateBinary(num1); // binary banay
            cout<<"\nBinary representation:";
            bin1.DisplayBinary(); // display
            break;

        case 2:
            cout<<"\nEnter number in decimal form:";
            cin>>num1;
            bin1.CreateBinary(num1);
            cout<<"\nBinary representation:";
            bin1.DisplayBinary();
            cout<<"\nOnes's Complement: ";
            bin1.OneComplement();
            bin1.DisplayBinary();
            break;

        case 3:
            cout<<"\nEnter number in decimanl form: ";
            cin>>num1;
            bin1.CreateBinary(num1);
            cout<<"\nBinary representation: ";
            bin1.DisplayBinary();
            cout<<"\nTwo's Complement: ";
            bin1.TwoComplement();
            bin1.DisplayBinary();
            break;

        case 4:
            cout<<"\nEnter 2 numbers: ";
            cin>>num1>>num2;
            bin1.CreateBinary(num1);
            bin2.CreateBinary(num2);
            bin1.DisplayBinary();
            cout<<"+";
            bin2.DisplayBinary();
            cout<<" = ";
            bin3 = bin1 + bin2;
            bin3.DisplayBinary();

        default:
            cout<<"\nEnter appropriate value!";
            break;
		}
    } while(choice != 0); // khatam yayayaaa

    return 0;
}

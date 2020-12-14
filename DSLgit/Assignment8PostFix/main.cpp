// Sassy_Don30

#include<bits/stdc++.h>
#define MAX 20
using namespace std;

char stk[20]; // ek stack aur 2 top
int top = -1; // ek operands ka ek operator ka
int top1 = -1;

void Push1(char oper){ // isme jo bhi operator hoga jaise + - voh push karenge stack me
    if(top1==MAX-1)
        cout<<"\nStack is full!!!!";

    else{
        //stk[++top] = oper
        top1++;
        stk[top1] = oper;
    }
}


float Pop1(){ //stack me jo sabse upar hoga operand hoga return karte hue pop
    float ch;
    if(top1 == -1) // agar khali hai toh chodo
        cout<<"\nStack is empty!!!!";

    else{
        ch=stk[top1]; // pehle store kia fir nikala
        stk[top1]='\0';
        top1--;
        return(ch);
    }
    return 0;
}


void Push(char oper){ // stack me add karega
    if(top==MAX-1)
        cout<<"stack is full!";

    else{
        // stk[++top] = oper
        top++;
        stk[top]=oper;
    }
}


char Pop(){ // stack me jo bhi operator hua
    char ch;
    if(top==-1)
        cout<<"Stack is empty!";

    else{
        ch=stk[top]; // stack me se sabse upar wala character return karega aur pop karega use
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}


int Priority(char alpha){ // haar operator ki priority ke hisab se
    if(alpha == '+' || alpha =='-') // BODMAS rule use karte hue dekhenge yaha pe
        return(1); // + -  ka 1


    if(alpha == '*' || alpha =='/')
        return(2); // multi divide ka 2

    return 0;
}


string Convert(string infix){
    int i=0;
    string postfix = "";

    while(infix[i]!='\0'){ // infix string ke start se end tak jayenge
        // agar number ya variable hua toh postfix string me directly inbuilt insert use karke aage chalo
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9')){
            postfix.insert(postfix.end(),infix[i]); // syntax of insert: strName(position, value), position ke liye end use kiya
            i++; // next character ki taraf chale
        }

        // agar bracket hua opening toh stack me dalenge use
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='['){
            Push(infix[i]);
            i++;
        }

        // agar closing hua toh stack me jayenge
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']'){
            if(infix[i]==')'){
                while(stk[top]!='(') // us bracket ka corresponding bracket hataya
                    postfix.insert(postfix.end(),Pop()); // string me insert kiya

                Pop(); // pehle laga ki agar kahi store nahi kiya toh kya hoga, lekin kuch nahi hua
                i++;
            }

            if(infix[i]==']'){ // same yaha pe but for different type of bracket
                while(stk[top]!='[')
                    postfix.insert(postfix.end(),Pop());

                Pop();
                i++;
            }

            if(infix[i]=='}'){ // same here nothing new
                while(stk[top]!='{')
                    postfix.insert(postfix.end(),Pop());

                Pop();
                i++;
            }
        }

        // agar na bracket na variable, matlab operator
        else{
            if(top==-1){
                Push(infix[i]); // agar pehle character hai toh push seedha
                i++;
            }

            else if(Priority(infix[i]) <= Priority(stk[top])){ // jo current operator hai usko compare kiya stack se
                postfix.insert(postfix.end(),Pop()); // agar same hua ya kam hua toh voh postfix me aayga

                while(Priority(stk[top]) == Priority(infix[i])){ //jab tak same hai tab tak loop
                    postfix.insert(postfix.end(),Pop()); // insert karte jayenge
                    if(top < 0) // agar empty ho gaya toh break
                        break;
                }

                Push(infix[i]); // end me use stack me dalenge next comparison ke liye
                i++;
            }

            // agar current operator stack wale se jada hai toh use stack me dalenge
            else if(Priority(infix[i]) > Priority(stk[top])) {
                Push(infix[i]);
                i++;
            }
        }
    }
    // ab stack me wapas check karenge ki kya kya bacha hai
    while(top!=-1)
        postfix.insert(postfix.end(),Pop()); // aur pop karte hue dalenge postfix string me

    cout<<"The converted postfix string is: "<<postfix<<endl; //it will print postfix conversion
    return postfix;
}


// ye bas us postfix function ki value nikalega
void Evaluate(string postfix){
    int j = 0;

    while (j < postfix.length()){ // uski length me jayenge
        int e1,e2,e3; // corresponding value check karke push kiya
        if (postfix[j] == '1')
            Push1(1);
        if (postfix[j] == '2')
            Push1(2);
        if (postfix[j] == '3')
            Push1(3);
        if (postfix[j] == '4')
            Push1(4);
        if (postfix[j] == '5')
            Push1(5);
        if (postfix[j] == '6')
            Push1(6);
        if (postfix[j] == '7')
            Push1(7);
        if (postfix[j] == '8')
            Push1(8);
        if (postfix[j] == '9')
            Push1(9);
        if (postfix[j] == '0')
            Push1(0);

        if (postfix[j] == '+'){ // operator aane pe 2 numbers pop kiye aur uska result karke
            e1 = Pop1();
            e2 = Pop1();
            e3 = e2 + e1;
            Push1(e3); // stack me push
        }

        if (postfix[j] == '-'){
            e1 = Pop1();
            e2 = Pop1();
            e3 = e2 - e1;
            Push1(e3);
        }

        if (postfix[j] == '*'){
            e1 = Pop1();
            e2 = Pop1();
            e3 = e2 * e1;
            Push1(e3);
        }

        if (postfix[j] == '/'){
            e1 = Pop1();
            e2 = Pop1();
            e3 = e2 / e1;
            Push1(e3);
        }
        j++;
    }

    cout<<"\nEvaluated value: "; // final value print kar denge
    cout<<Pop1()<<"\n"<<endl;
}

int main(){
    string infix, postfix;
    int choice;

    do{ // simple menu banaya
        cout<<"Enter Choice:\n1.Infix to postfix conversion\n2.Postfix Evaluation\n0.Exit\n";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnter the infix expression: "; //enter the expression
                cin>>infix;
                Convert(infix);
                break;

            case 2:
                cout<<"\nEnter a postfix expression to be evaluated: ";
                cin>>postfix;
                Evaluate(postfix);
                break;

            default:
                cout<<"\nEnter appropriate value!!";
                break;
        }
    } while(choice != 0);
    return 0;
}

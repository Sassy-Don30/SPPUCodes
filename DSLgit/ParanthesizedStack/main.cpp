//Sassy_Don30

#include<bits/stdc++.h>
#define MAX 20
using namespace std;


class Brackets {
	char st[MAX]; // class me ek array aur top
	int top;

public:
	Brackets(){
		top = -1; // new object ka top kiya -1
    }

    void PushData(char a) {
        top++; // object add aur uske baad stack me dala
        st[top] = a;
    }

	void PopData() {
        top--; // directly kam kar diya top ko
    }

	void InputExp(){
        string str;
        int i = 0;
        cout<<"\nEnter the expression: ";
        cin>>str; // ek string input li

        while (i < str.size()){

            if ((str[i] == '{') || (str[i] == '[') || (str[i] == '(')) // opening braces aane pe push data
                PushData(str[i]);

            if (str[i] == '}'){ // agar } closing braces hai toh pop kiya stack me se
                if (st[top] == '{')
                    PopData();
                else
                    cout<<"\nMatching opening brace '{' is not found";
            }

            if (str[i] == ']'){ // agar ] wala hua toh corresponding pop kiya
                if (st[top] == '[')
                    PopData();
                else
                    cout<<"\nMatching brace '[' is not found";
            }

            if (str[i] == ')') { // same here, nothing new
                if (st[top] == '(')
                    PopData();
                else
                    cout<<"\nMatching opening brace '(' is not found";
            }

            i++; // next string char ki taraf jaane ke liye
        }

        if (top == -1){ // agar end me stack empty hua toh sahi hai sab
            //cout<<"\nStack is empty";
            cout<<"\nEXPRESSION IS WELL PARENTHESIZED";
        }

        else { // agar empty nahi hai
            while (top != -1) { // jab tak khali nahi hota
                if (st[top] == '[') { // haar type ke braces pop karenge
                    PopData();
                    cout << "\nMatching closing brace ']' is not found";
                }

                if (st[top] == '{') {
                    PopData();
                    cout << "\nMatching closing brace '}' is not found";
                }

                if (st[top] == '(') {
                    PopData();
                    cout << "\nMatching closing brace ')' is not found";
                }
            }
            cout << "\nEXPRESSION IS NOT WELL PARENTHESIZED"; // aur kyuki corresponding nahi mila toh kharab hai
        }
    }

};

int main(){
	Brackets c; // object banake function use
	c.InputExp();
}

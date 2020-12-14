#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileHandle;
    string pehliLine;
    fileHandle.open("example.txt",ios::out); //iske alawa ofstream use karke kar sakte the but koi na

    cout<<"File created"<<endl;
    cout<<"Write  to file"<<endl;
    cout<<"Enter data:"<<endl;
    fileHandle<<"My name is Shashwat Tandon"<<endl;
    fileHandle<<"I study in PICT CS branch"<<endl;
    cin>>pehliLine;
    fileHandle<<pehliLine<<endl;

    fileHandle.close(); //file band kaam khatam

    fileHandle.open("example.txt",ios::in);
    string str;
    cout<<"Read from file"<<endl;
    cout<<"File content"<<endl;
    while(!fileHandle.eof()){
        cin.ignore();
        getline(fileHandle,str);
        cout<<str;
        cout<<""<<endl;
    }
    fileHandle.close();

    return 0;
}

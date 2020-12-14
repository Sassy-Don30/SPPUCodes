#include <iostream>
using namespace std;

class StudentData{
private:
    string name,cls,blood_group,address;
    int roll_no,div,dob,tele_no,license_no;
    static int count;
public:
    StudentData(){
        cout<<"Default constructor used...."<<endl;
        name = "XYZ";
        roll_no = -4;
        cls = "Second Year";
        div = 1;
        dob=000;
        blood_group = " ";
        address = " ";
        tele_no = 0000;
        license_no = 0;
        count++;
    }

    StudentData(string name , int roll_no,string cls,int div,int dob,string blood_grp,string address,int tele_no,int dr_no){
        cout<<"Parameterized constructor called...."<<endl;
        this->name = name;
        this->roll_no = roll_no;
        this->cls = cls;
        this->div = div;
        this->dob=dob;
        this->blood_group =blood_group;
        this->address = address;
        this->tele_no = tele_no;
        this->license_no = license_no;
        count++;
    }

    StudentData(StudentData &stud){
        name = stud.name;
        roll_no = stud.roll_no;
        cls = stud.cls;
        div = stud.div;
        dob = stud.dob;
        blood_group = stud.blood_group;
        address = stud.address;
        tele_no = stud.tele_no;
        license_no = stud.license_no;
        count++;
    }



    ~StudentData(){
        cout<<"Destroyer has been called"<<endl;
        count--;
    }

    inline void InputData(){
        cout<<"Enter student name:";
        getline(cin,name);
        if(name.size()<3) throw name;

        cout<<"Enter roll no:";
        cin>>roll_no;
        if(roll_no<1000) throw roll_no;

        cout<<"Enter class:";
        cin>>cls;
        if(cls.size()< 2) throw cls;

        cout<<"Enter division:";
        cin>>div;
        if(!(div>=1 && div<=11)) throw div;

        cout<<"Enter date of birth:(ddmmyyyy)";
        cin>>dob;
        if(dob<10000) throw dob;

        cout<<"Enter blood group:";
        cin>>blood_group;
        if(!isalpha(blood_group[0])) throw blood_group;

        cin.ignore();
        cout<<"Enter address:";
        getline(cin,address);
        if(address.size()< 5) throw address;

        cout<<"Enter telephone number:";
        cin>>tele_no;
        if(tele_no<100000000) throw tele_no;

        cout<<"Enter driving license number:";
        cin>>license_no;
        if(license_no<4000) throw license_no;
    }

    static int Student_Count(){
        if(count<=0) throw count;
        return count;
    }

    void PrintData(){
        cout<<"Student's name: "<<name<<endl;
        cout<<"Student's roll no: "<<roll_no<<endl;
        cout<<"Student's class: "<<cls<<endl;
        cout<<"Student's division: "<<div<<endl;
        cout<<"Student's date of birth: "<<dob<<endl;
        cout<<"Student's blood group: "<<blood_group<<endl;
        cout<<"Student's address: "<<address<<endl;
        cout<<"Student's telephone no: "<<tele_no<<endl;
        cout<<"Student's driving license no: "<<license_no<<endl;
    }

    friend class Student;

};

class Student{
public:
    void PrintData(StudentData &s){
        cout<<"Student's name: "<<s.name<<endl;
        cout<<"Student's roll no: "<<s.roll_no<<endl;
        cout<<"Student's class: "<<s.cls<<endl;
        cout<<"Student's division: "<<s.div<<endl;
        cout<<"Student's date of birth: "<<s.dob<<endl;
        cout<<"Student's blood group: "<<s.blood_group<<endl;
        cout<<"Student's address: "<<s.address<<endl;
        cout<<"Student's telephone no: "<<s.tele_no<<endl;
        cout<<"Student's driving license no: "<<s.license_no<<endl;
    }
};


int StudentData::count = 0;

int main()
{
    StudentData* ptrHub[10];
    char repeatChoice = 'y';
    int quantity = 0;
    ptrHub[quantity] = new StudentData("Shashwat",21174,"SE",1,300901,"O+","Vayusena Nagar ,Nagpur",98989898,4444444);
    quantity++;
    while(repeatChoice=='y'){
        try{
            ptrHub[quantity] = new StudentData();
            ptrHub[quantity]->InputData();
            quantity++;
            cout<<"Enter another student?(y/n):";
            cin>>repeatChoice;
        }

        catch(string){
            cout<<"Name or class or blood group or address is wrong!"<<endl;
        }

        catch(int){
            cout<<"Roll number or division or date of birth or telephone number or license is wrong!"<<endl;
        }

        catch(...){
            cout<<"Something else is wrong!"<<endl;
        }
    }

    ptrHub[quantity+1] = ptrHub[quantity];
    quantity++;
    cout<<"Total students are"<<ptrHub[quantity]->Student_Count()<<endl;

    for(int i=0;i<=quantity;i++){
        ptrHub[i]->PrintData();
        delete ptrHub[i];
    }

    return 0;
}

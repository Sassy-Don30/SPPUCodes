#include <iostream>
#include <string>
using namespace std;

class Publication{

protected:
    string title;
    float price;

public:
    Publication(){
        title = "";
        price = 0.0;
    }

    virtual void GetName(){
        cout<<"Enter title: (can't be less than 3) ";
        cin.ignore();
        cin>>title;
        if(title.size() < 3) throw title;

        cout<<"Enter price: (can't be less than 10)";
        cin>>price;
        if(price <= 10.0) throw price;
    }

    virtual void ShowName(){
        cout<<"***********************"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }

    ~Publication(){
        cout<<"Destroy publication"<<endl;
    }

};


class BookPublish: public Publication{

private:
    int pageCount;

public:
    BookPublish(){
        pageCount = 0;
    }

    void GetName(){
        Publication::GetName();
        cout<<"Enter pages: (can't be less than 20) ";cin>>pageCount;
        if(pageCount <= 20) throw pageCount;
    }

    void ShowName(){
        Publication::ShowName();
        cout<<"Pages: "<<pageCount<<endl;
        //cout<<"***********************"<<endl;
    }

    ~BookPublish(){
        cout<<"Destroy book"<<endl;
    }

};


class TapePublish: public Publication{
private:
    float playTime;

public:
        TapePublish(){
            playTime = 0.0;
        }
        void GetName(){
            Publication::GetName();
            cout<<"Enter time: (can't be less than 10)";
            cin>>playTime;
            if(playTime <= 10) throw playTime;
        }

        void ShowName(){
            Publication::ShowName();
            cout<<"Time: "<<playTime<<endl;
            //cout<<"***********************"<<endl;
        }

        ~TapePublish(){
            cout<<"Destroy tape"<<endl;
        }

};

int main()
{
    /*
    Publication *ptrHub[100];
    int n=0;
    char choice;
    do{
        cout<<"Book or Tape?(b/t): ";cin>>choice;
        if(choice=='b'){
            ptrHub[n] = new BookPublish;
            ptrHub[n]-> GetName();
        }
        else {
            ptrHub[n] = new TapePublish;
            ptrHub[n]->GetName();
        }
        n++;
        cout<<"Enter another item?(y/n): ";cin>>choice;
    } while(choice=='y');

    for(int i=0;i<n;i++){
        ptrHub[i]->ShowName();
        cout<<endl;
    }*/
    Publication* ptrArr[10];
    int quantity=0;
    char choice,repeatChoice= 'y';

    while(repeatChoice=='y'){
        try{
            cout<<"Enter book or tape? (b/t):";
            cin>>choice;
            if(choice=='b'){
                ptrArr[quantity] = new BookPublish;
                ptrArr[quantity]->GetName();
            }
            else{
                ptrArr[quantity] = new TapePublish;
                ptrArr[quantity]->GetName();
            }
            quantity++;
            cout<<"Enter another item (y/n):";
            cin>>repeatChoice;
        }

        catch(string &title){
            cout<<"Title galat hai"<<endl;
        }
        catch(float &price){
            cout<<"Price galat hai"<<endl;
        }
        catch(int &pages){
            cout<<"Pages kam hai re"<<endl;
        }
        catch(float &timeTape){
            cout<<"Time galat hai re"<<endl;
        }
        catch(...){
            cout<<"Kuch toh gadbad hai"<<endl;
        }

    }

    for(int i=0;i<quantity;i++) {
        ptrArr[i]->ShowName();
        //ptrArr[i] ->~Publication();
        delete ptrArr[i];
    }


    cout<<"\n Byeeeeeee"<<endl;
    return 0;
}


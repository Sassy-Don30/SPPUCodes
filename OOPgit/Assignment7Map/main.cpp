// Sassy_Don30
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

class Mapper{ // is class me population aur state ke 2 variables honge
    int population;
    string state;

public:
    void GetData(){ // is function me user se input lenge dono datas
        cout<<"\nEnter name of state: ";
        cin>>state;
        cout<<"\nEnter population of state: ";
        cin>>population;
    }

    void DisplayData(vector<Mapper> vec, int len){
        map<string, int, less<string>> mapState; // less string usko alphabet ke according sort kar dega apne aap

        for(int i=0;i<len;i++) // haar state ko map me dala aur fir usko population di
            mapState[vec[i].state] = vec[i].population;

        cout<<"\n----------------------------------------";
        cout<<"\nState\t\tPopulation";
        for(auto const& pair: mapState){
            cout<<"\n"<<pair.first<<"\t\t"<<pair.second;
        }
        cout<<"\n----------------------------------------";
    }

    void Search(vector<Mapper> vec, int len){
        map<string, int, less<string>> mapState; // less string usko alphabet ke according sort kar dega apne aap

        for(int i=0;i<len;i++) // haar state ko map me dala aur fir usko population di
            mapState[vec[i].state] = vec[i].population;

        string findState; // yaha pe state jise dhoondhna hai voh lenge input aur print karenge
        cout<<"\nEnter state: ";
        cin>>findState;

        if(mapState[findState] == 0){ // dictionary in python jaisa hi hai
            cout<<"\nState doesn't exist in database!!";
        }
        else{
            cout<<"\nPopulation is: "<<mapState[findState];
        }
    }
};

int main(){
    vector<Mapper> vec;
    Mapper obj;
    int siz, choice;

    do{
        cout<<"\nMenu: \n1.Create \n2.Display \n3.Search \n0.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnter number of states: ";
                cin>>siz;
                for(int i=0;i<siz;i++){ // objects leke vector me dale
                    obj.GetData();
                    vec.pb(obj);
                }
                break;

            case 2:
                obj.DisplayData(vec, siz);
                break;

            case 3:
                obj.Search(vec, siz);
                break;

            default:
                cout<<"\nEnter appropriate value!!!";
                break;
        }
    } while(choice != 0);

    return 0;
}

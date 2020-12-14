#include <bits/stdc++.h>
using namespace std;

template<class T>
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void SelectionSort(){
    int length;
    cout<<"Enter size of array:";
    cin>>length;
    T arr[length];
    for(int i=0;i<length;i++){
        cout<<"arr["<<i+1<<"] = ";
        cin>>arr[i];
    }

    int minIndex;
    for(int i=0;i<length-1;i++){
        minIndex = i;
        for(int j=i+1;j<length;j++)
            if(arr[j]<arr[minIndex])
                minIndex = j;

        Swap(arr[i], arr[minIndex]);
    }

    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";

}

int main()
{
    cout<<"Integer sort"<<endl;
    SelectionSort<int>();

    cout<<"\nFloat sort"<<endl;
    SelectionSort<float>();

    cout<<"\nChar sort"<<endl;
    SelectionSort<char>();

    return 0;
}

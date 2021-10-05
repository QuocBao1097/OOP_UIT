#include <iostream>
using namespace std;

void print(int a[], int n)
{ 
     for(int i=0; i<10; i++)
     { 
         cout<<a[i]<<"\t";
     }
}
void InsertionSort(int a[], int n)
{ 
    int i=1;
    while(i<n)
    { 
        int x=a[i]; int k;
        for(k=i-1; k>=0 && a[k]>x; k--)
           a[k+1] = a[k];
        a[k+1] = x;
        cout<<"Buoc "<<i<<": ";
        print(a,10);
        cout<<endl;
        i++;
    }
}
int main()
{ 
    int a[10] = {44, 27, 58, 65, 30, 61, 15, 21, 82, 12};
    cout<<"Mang ban dau: ";
    print(a, 10);
    cout<<endl<<endl;
    InsertionSort(a,10);
    cout<<"\nSau khi sap xep"<<endl;
    print(a,10);
    return 1;
}


#include<iostream>
#include<string.h>
using namespace std;
struct HOCSINH
{
    string hoten;
    float toan,van;
};
void nhapTTHS(HOCSINH &x)
{
    cout<<"Ten hoc sinh: ";
    getline(cin,x.hoten);
    cout<<"Diem Toan: ";
    cin>>x.toan;
    cout<<"Diem Van: ";
    cin>>x.van;
}
void xuatTTHS(HOCSINH &x)
{
    cout<<"Ten hoc sinh: "<<x.hoten<<endl;
    cout<<"Diem Toan: "<<x.toan<<endl;
    cout<<"Diem Van: "<<x.van<<endl;
}
double caculate(HOCSINH &x)
{
    float DTB;
    DTB=float(x.toan+x.van)/2*1.0;
    return DTB;
}
int main(){
    HOCSINH x;
    nhapTTHS(x);
    xuatTTHS(x);
    cout<<"DIEM TRUNG BINH: "<<caculate(x);
    return 0;
}

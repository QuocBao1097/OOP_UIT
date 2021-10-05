
#include<iostream>
using namespace std;

class HocSinh
{
private:
    string Hoten;
    float Toan, Van;
public:
    void khoitaotenrong();
    void khoitaohstuyy();
    void Nhap();
    void xuat();
    float DTB();
    void XepLoai();
};
void HocSinh::khoitaotenrong()
{
    this->Toan=this->Van=0;
}
void HocSinh::khoitaohstuyy()
{
    
    cout<<"Ten hoc sinh: DOAN QUOC BAO";
    this->Toan=8;
    this->Van=8.25;
}
void HocSinh::Nhap()
{
    cout<<"Ten hoc sinh: ";
    getline(cin, Hoten);
    do
    {
        cout<<"Nhap diem Toan: "; cin>>Toan;
    } while(Toan<0 || Toan >10);
    do
    {
        cout<<"Nhap diem Van: "; cin>>Van;
    } while(Van<0 || Van >10);
}
void HocSinh::xuat()
{
    cout<<Hoten<<endl;
    cout<<"Diem Toan: "<<Toan<<endl;
    cout<<"Diem Van: "<<Van<<endl;
}
float HocSinh::DTB()
{
    float DIEMTRUNGBINH=(Toan+Van)/2.0;
    return DIEMTRUNGBINH;
}
void HocSinh::XepLoai()
{
    cout<<"DIEM TRUNG BINH: "<<DTB()<<endl;
    cout<<"XEP LOAI: ";
    if(DTB()>=8) cout<<"GIOI "<<endl;
    else
        if(DTB()>=6.5) cout<<"KHA "<<endl;
    else
        if(DTB()>=5) cout<<"TRUNG BINH "<<endl;
    else
        if(DTB()>=3.5) cout<<"YEU "<<endl;
    else
        cout<<"KEM "<<endl;
}
int main()
{
    HocSinh hs;
    //hs.khoitaotenrong();
    hs.Nhap();
    cout<<"-----------------------"<<endl;
    cout<<"   Thong tin hoc sinh "<<endl;
   // hs.khoitaohstuyy();
    hs.xuat();
    hs.XepLoai();
    return 0;
}

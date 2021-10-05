#include<iostream>
#include<string>
using namespace std;
class NHANVIEN
{ 
private:    
    string maso,hoten,phongban;
    int loai;
public:
    NHANVIEN(string="", string="", string="", int=0);
    string Getmaso();
    string gethoten();
    string Getphongban();
    int Getloai();
    void Setmaso(string);
    void Sethoten(string);
    void Setphongban(string);
    virtual void nhap();
    virtual void xuat();
    virtual int Gethesoluong();
    virtual void Sethesoluong(int); 
    virtual int Gethesophucap();
    virtual void Sethesophucap(int);
    virtual long Gettiencong();
    virtual void Settiencong(long);
    virtual int Getsongaycong();
    virtual void Setsongaycong(int);
    virtual int Gethesovuotgio();
    virtual void Sethesovuotgio(int);
    virtual long Tienluong()=0;
};
NHANVIEN::NHANVIEN(string ms, string ht, string pb, int l):maso(ms), hoten(ht), phongban(pb), loai(l){}
int NHANVIEN::Getloai(){ 
    return loai;
}
string NHANVIEN::Getmaso(){ 
    return maso;
}
string NHANVIEN::gethoten() { 
    return hoten;
}
string NHANVIEN::Getphongban() { 
    return phongban;
}
void NHANVIEN::Setmaso(string ms){ 
    maso=ms;
}
void NHANVIEN::Sethoten(string ht){ 
    hoten=ht;
}
void NHANVIEN::Setphongban(string pb){ 
    phongban=pb;
}
int NHANVIEN::Gethesophucap(){
    return -1;
}
int NHANVIEN::Gethesoluong(){
    return -1;
}
int NHANVIEN::Getsongaycong(){
    return -1;
}
long NHANVIEN::Gettiencong(){
    return -1;
}
void NHANVIEN::Sethesoluong(int ){
    return;
}
void NHANVIEN::Sethesophucap(int){ 
    return;
}
void NHANVIEN::Sethesovuotgio(int){ 
    return;
}
void NHANVIEN::Settiencong(long) {
    return ;
}
void NHANVIEN::nhap()
{   
    cin.ignore();
    cout<<"Nhap ma so: ";
    getline(cin, maso);
    cout<<"Nhap Ho Ten: ";
    getline(cin, hoten);
    cout<<"Nhap Phong Ban: ";
    getline(cin, phongban);
}
void NHANVIEN::xuat()
{ 
    cout<<"Ma so: "<<maso<<"\t Ho Ten: "<<hoten<<"\tPhong Ban: "<<phongban<<"\tLoai: "<<(loai==1?"NVBC ":(loai==2?"NCHD":"???"));
}

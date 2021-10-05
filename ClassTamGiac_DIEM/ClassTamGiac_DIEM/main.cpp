#include <iostream>
#include<cmath>
//thuvienDIEM
using namespace std;
class Diem
{
private:
    double x;
    double y;
    static int dem;
public:
    ~Diem();
    Diem ();
    Diem(double);
    Diem (double, double);
    double getX();
    double getY();
    static int Getdem();
    void setX(double);
    void setY(double);
    void setXY(double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double, double);
    bool Ktra2diemtrungnhau(Diem);
    double Khoangcach(Diem);
    Diem   TimDiemDoiXung();
    double TinhChuVi(Diem,Diem);
    double TinhDienTich(Diem, Diem);
    //friend istream & operator>>(istream&, Diem &);
    //friend ostream & operator<<(ostream&, Diem );
};
class TAMGIAC
{
private:
    Diem A,B,C;
    static int dem;
public:
    ~TAMGIAC();
    TAMGIAC();
    TAMGIAC(double,double,double,double,double,double);
    TAMGIAC(Diem, Diem, Diem);
    Diem GetA(Diem);
    Diem GetB(Diem);
    Diem GetC(Diem);
    static int GetDiem();
    void SetA(Diem);
    void SetB(Diem);
    void SetC(Diem);
    void SetABC(Diem, Diem, Diem);
    void Nhap();
    void Xuat();
    double TinhChuVi();
    double TinhDienTich();
    bool KiemTraHopLe();
    bool PhanLoaiTamGiac();
    friend istream & operator>>(istream &, TAMGIAC&);
    friend ostream & operator<<(ostream &, TAMGIAC);
};
int TAMGIAC::dem=0;
bool TAMGIAC:: KiemTraHopLe()
{
    double a=A.Khoangcach(B);
    double b=B.Khoangcach(C);
    double c=C.Khoangcach(A);
    return a>0 && b>0 && c>0 && a<b+c && b<a+c && c<a+b;
}
TAMGIAC :: ~TAMGIAC()
{
    dem--;
}
TAMGIAC ::TAMGIAC()
{
 while(KiemTraHopLe()!=0)
     cin>>*this;
    dem++;
}
TAMGIAC::TAMGIAC(double xA, double yA,double xB,double yB,double xC,double yC) :A(xA, yA),B(xB,yB),C(xC,yC)
{
    while(KiemTraHopLe()!=0)
        cin>>*this;
    dem++;
}
TAMGIAC :: TAMGIAC (Diem AA, Diem BB,Diem CC)
{
    A=AA;
    B=BB;
    C=CC;
    while(KiemTraHopLe()!=0)
        cin>>*this;
    dem++;
}


#include<iostream>
#include<cmath>
using namespace std;

class DIEM3C
{
protected:
    double x,y,z;
public:
    ~DIEM3C();
    DIEM3C(double =0, double =0, double =0);
    double getX();
    double getY();
    double getZ();
    void setX(double);
    void setY(double);
    void setZ(double);
    void setXYZ(double, double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double, double, double);
    bool Ktra2diemtrungnhau(DIEM3C);
    double Khoangcach(DIEM3C);
    DIEM3C   TimDiemDoiXung();
    double TinhChuVi(DIEM3C, DIEM3C);
    double TinhDienTich(DIEM3C, DIEM3C);
    friend istream & operator>>(istream&is, DIEM3C &);
    friend ostream & operator<<(ostream& os, DIEM3C );
};
DIEM3C ::~DIEM3C(){}
DIEM3C::DIEM3C(double xx, double yy, double zz) :x(xx), y(yy), z(zz){};
void DIEM3C::setZ(double zz)
{
    z=zz;
}
double DIEM3C::getZ()
{
    return z;
}
void DIEM3C::setX(double xx)
{ 
    x=xx;
}
double DIEM3C::getX()
{ 
    return x;
}
void DIEM3C::setY(double yy)
{ 
    y=yy;
}
double DIEM3C::getY()
{ 
    return y;
}
void DIEM3C::setXYZ(double xx, double yy, double zz)
{
    x=xx;
    y=yy;
    z=zz;
}
void DIEM3C::Nhap()
{
    cout<<"Hoanh do: "; cin>>x;
    cout<<"Tung do: "; cin>>y;
    cout<<"Cao do: ";  cin>>z;
}
void DIEM3C::Xuat(){
    cout<<"("<<x<<","<<y<<","<<z<<")";
}
istream&operator>>(istream & is, DIEM3C &d)
{
  
    cout<<"Hoanh do: "; is>>d.x;
    cout<<"Tung do: "; is>>d.y;
    cout<<"Cao do: ";  is>>d.z;
    return is;
}
ostream&operator<<(ostream &os, DIEM3C d)
{
    os<<"("<<d.x<<","<<d.y<<","<<d.z<<")";
    return os;
}
void DIEM3C::Dichuyen(double dx, double dy, double dz)
{
    x+=dx;
    y+=dy;
    z+=dz;
}
bool DIEM3C::Ktra2diemtrungnhau(DIEM3C dd)
{
    return x==dd.x && z==dd.z && y==dd.y;
}
double DIEM3C::Khoangcach(DIEM3C dd)
{
    return sqrt(pow(x-dd.x,2)+pow(y-dd.y,2)+pow(z-dd.z,2));
}
DIEM3C DIEM3C::TimDiemDoiXung()
{
    DIEM3C ddx(x==0?0:-x, y==0?0:-y, z==0?0:-z);
    return ddx;
}
double DIEM3C::TinhChuVi(DIEM3C d1, DIEM3C d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    return a+b+c;
}
double DIEM3C:: TinhDienTich(DIEM3C d1, DIEM3C d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}


class Mau
{ 
protected: 
    int mau;
public:
    ~Mau();
    Mau(int =0);
    void setmau(int);
    int getmau();
    void nhap();
    void xuat();
    bool kiemtraMAUtrung(Mau &d)
    { 
        return mau==d.mau;
    }
    friend istream &operator>>(istream &is, Mau&);
    friend ostream &operator<<(ostream &os, Mau); 
};
Mau::~Mau(){};
Mau::Mau(int mau)
{ 
    setmau(mau);
}
int Mau::getmau()
{ 
    return mau;
}
void Mau::setmau(int m)
{ 
    mau=m;
}
void Mau::nhap()
{ 
    do{ 
        cout<<"Nhap MAU tu (0-255): "; cin>>mau;
    } while(mau<0 || mau>255);
}
void Mau::xuat()
{ 
    cout<<" -Mau: "<<mau;
}
istream &operator>>(istream &is, Mau& m)
{ 
    do{ 
        cout<<"Nhap mau tu 0-255: "; cin>>m.mau;
    } while(m.mau<0 || m.mau>255);
    return is;
} 
ostream &operator<<(ostream &os, Mau m)
{ 
    os<<" -Mau: "<<m.mau;
    return os;
}


class DIEMMAU3C:public Mau, public DIEM3C
{ 
private:
    int mau;
public:
    ~DIEMMAU3C();
    DIEMMAU3C(double=0, double=0,double=0, int=0);
    void nhap();
    void xuat();
    void setmau( int);
    double getmau();
    bool kiemtratrung(DIEMMAU3C);
    friend istream &operator >> (istream &is, DIEMMAU3C &);
    friend ostream &operator <<(ostream &os, DIEMMAU3C);
};
DIEMMAU3C :: ~DIEMMAU3C(){};
DIEMMAU3C ::DIEMMAU3C(double xx, double yy, double zz, int m): DIEM3C(xx,yy,zz), Mau(m){}
void DIEMMAU3C::setmau(int m)
{ 
    mau=m;
}
double DIEMMAU3C::getmau()
{ 
    return mau;
}
void DIEMMAU3C::nhap(){ 
    DIEM3C::Nhap();
    Mau::nhap();
}
void DIEMMAU3C::xuat() { 
    DIEM3C::Xuat();
    Mau::xuat();
}
bool DIEMMAU3C::kiemtratrung(DIEMMAU3C d) { 
    return (x==d.x && y==d.y && mau==d.mau);
}
istream&operator >>(istream&is, DIEMMAU3C &d)
{ 
    d.DIEM3C::Nhap();
    d.Mau::nhap();
    return is;
}
ostream&operator <<(ostream&os, DIEMMAU3C d)
{ 
    d.DIEM3C::Xuat();
    d.Mau::xuat();
    return os;
}

int main()
{ 
    DIEMMAU3C A, B(3,-3,8), C(-7,8,3.7,99);
     cout<<"DIEM A"<<A<<endl;
     cout<<"DIEM B"<<B<<endl;
     cout<<"DIEM C"<<C<<endl;
     cout<<"+Nhap Diem A moi: "<<endl; A.nhap();
     cout<<"-->A'"<<A;
     B.Dichuyen(1,3,3);
     cout<<"\nDi chuyen B(3,-3,8) theo don vi (1,3,3)->"; B.xuat();
     DIEM3C D=C.TimDiemDoiXung();
     cout<<"\nDiem Doi Xung C la C'"; D.Xuat();
     cout<<"\nChu vi: "<<A.TinhChuVi(B,C);
     cout<<"\nDien Tich: "<<A.TinhDienTich(B,C);
     if(B.kiemtratrung(C)) cout<<"\nB&C trung nhau"<<endl;
     else cout<<"\nB&C Khong trung nhau"<<endl;
     return 0;
}
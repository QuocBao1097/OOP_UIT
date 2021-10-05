#include <iostream>
#include <cmath>

using namespace std;
class DIEM2C
{ 
  protected: 
    double x, y;
 public:
    ~DIEM2C();
    DIEM2C(double =0, double =0);
    double getX();
    double getY();
    void setX(double);
    void setY(double);
    void setXY(double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double, double);
    bool Ktra2diemtrungnhau(DIEM2C);
    double Khoangcach(DIEM2C);
    DIEM2C   TimDiemDoiXung();
    double TinhChuVi(DIEM2C,DIEM2C);
    double TinhDienTich(DIEM2C, DIEM2C);
    friend istream & operator>>(istream&, DIEM2C &);
    friend ostream & operator<<(ostream&, DIEM2C );
};
DIEM2C::~DIEM2C(){};
DIEM2C ::DIEM2C(double xx, double yy):x(xx), y(yy){}
double DIEM2C::getX()
{ 
    return x;
}
double DIEM2C::getY()
{ 
     return y;
}
void DIEM2C::setX(double xx)
{ 
    x=xx;
}
void DIEM2C::setY(double yy)
{ 
    y=yy;
}
void DIEM2C::setXY(double xx, double yy)
{ 
    x=xx;
    y=yy;
}
void DIEM2C::Nhap()
{ 
    cout<<"Hoanh do x= "; cin>>x;
    cout<<"Tung do  y= "; cin>>y;
}
void DIEM2C::Xuat()
{ 
    cout<<"("<<x<<","<<y<<")";
}
void DIEM2C::Dichuyen(double dx, double dy) { 
    x+=dx;
    y+=dy;
}
bool DIEM2C::Ktra2diemtrungnhau(DIEM2C d){ 
    return (x==d.x && y==d.y); 
}
double DIEM2C::Khoangcach(DIEM2C d) 
{ 
    return sqrt(pow(x-d.x,2)+pow(y-d.y, 2));
}
DIEM2C DIEM2C::TimDiemDoiXung() { 
    DIEM2C d(-x,-y);
    return d;
}
double DIEM2C::TinhChuVi(DIEM2C d1, DIEM2C d2) { 
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    return a+b+c;
}
double DIEM2C::TinhDienTich(DIEM2C d1, DIEM2C d2) { 
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
istream&operator>>(istream & is,DIEM2C &d)
{ 
    cout<<"Hoanh do: ";  is>>d.x;
    cout<<"Tung do:";   is>>d.y;
    return is;
}
ostream &operator <<(ostream & os, DIEM2C d)
{ 
    os<<"("<<d.x<<","<<d.y<<")";
    return os;
}

//class Mau
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

//class DIEMMAU 2 Chieu
class DIEM2CMAU:public DIEM2C, public Mau
{ 
protected:
    int mau;
public: 
    ~DIEM2CMAU();
    DIEM2CMAU(double=0, double=0, int=0);
    void nhap();
    void xuat();
    void setmau( int);
    double getmau();
    bool kiemtratrung(DIEM2CMAU);
    friend istream &operator >> (istream &is, DIEM2CMAU &);
    friend ostream &operator <<(ostream &os, DIEM2CMAU);
};
DIEM2CMAU :: ~DIEM2CMAU(){};
DIEM2CMAU ::DIEM2CMAU(double xx, double yy, int m):DIEM2C(xx,yy), Mau(m){}
void DIEM2CMAU::setmau(int m)
{ 
    mau=m;
}
double DIEM2CMAU::getmau()
{ 
    return mau;
}
void DIEM2CMAU::nhap(){ 
    DIEM2C::Nhap();
    Mau::nhap();
}
void DIEM2CMAU::xuat() { 
    DIEM2C::Xuat();
    Mau::xuat();
}
bool DIEM2CMAU::kiemtratrung(DIEM2CMAU d) { 
    return (x==d.x && y==d.y && mau==d.mau);
}
istream&operator >>(istream&is, DIEM2CMAU &d)
{ 
    d.DIEM2C::Nhap();
    d.Mau::nhap();
    return is;
}
ostream&operator <<(ostream&os, DIEM2CMAU d)
{ 
    d.DIEM2C::Xuat();
    d.Mau::xuat();
    return os;
}

 int main()
 { 
     DIEM2CMAU A, B(3,9,124), C(11,-5,77);
     cout<<"DIEM A"<<A<<endl;
     cout<<"DIEM B"<<B<<endl;
     cout<<"DIEM C"<<C<<endl;
     cout<<"+Nhap Diem A moi: "<<endl; A.nhap();
     cout<<"->A'"<<A;
     B.Dichuyen(1,3);
     cout<<"\nDi chuyen B(3,9,mau: 124) theo don vi (1,3)->"; B.xuat();
     DIEM2C D=C.TimDiemDoiXung();
     cout<<"\nDiem Doi Xung C la C'"; D.Xuat();
     cout<<"\nChu vi: "<<A.TinhChuVi(B,C);
     cout<<"\nDien Tich: "<<A.TinhDienTich(B,C);
     return 0;
 }


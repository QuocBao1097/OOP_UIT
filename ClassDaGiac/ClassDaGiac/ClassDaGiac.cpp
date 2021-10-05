
#include <iostream>
#include<cmath>
#define PI 3.1416

using namespace std;

class Diem
{
private:
    double x;
    double y;
public:
    ~Diem(){};
    Diem ();
    Diem(double);
    Diem (double, double);
    double getX();
    double getY();
    void setX(double);
    void setY(double);
    void setXY(double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double , double );
    friend istream & operator>>(istream&, Diem &A);
    friend ostream & operator<<(ostream&, Diem &);
};
Diem::Diem()
{
    setXY(0, 0);
}
Diem::Diem(double xx)
{
    setXY(xx, 0);
}
Diem::Diem(double xx, double yy)
{
    setXY(xx, yy);
}
double Diem::getX()
{
    return x;
}
double Diem::getY()
{
    return y;
}
void Diem::setX(double xx)
{
    x=xx;
}
void Diem::setY(double yy)
{
    y=yy;
}
void Diem::setXY(double xx, double yy)
{
    x=xx;
    y=yy;
}
void Diem::Nhap()
{
    cout<<"x = "; cin>>x;
    cout<<"y = "; cin>>y;
}
void Diem::Xuat()
{
    cout<<"("<<x<<","<<y<<")";
}

void Diem::Dichuyen(double dx, double dy)
{
    x=x+dx;
    y=y+dy;
}
ostream & operator <<(ostream &os, Diem &A)
{
    os<<"("<<A.getX()<<","<<A.getX()<<")";
    return os;
}

istream &operator >>(istream &is, Diem &A)
{
    cout<<"\nx = ";
    is>>A.x;
    cout<<"y =  ";
    is>>A.y;
    return is;
}


class DAGIAC
{
private:
    Diem *A;
    int sodiem;
public:
    DAGIAC(int sodiem);
    void zoomDagiac(double k);
    void quaydagiac(double goc);
    void Dichuyendagiac(double dx, double dy);
    void nhapdagiac();
    friend ostream& operator <<(ostream & os, DAGIAC & x);
    ~DAGIAC();
};

DAGIAC::DAGIAC (int n)
{
    sodiem=n;
    A=new Diem[sodiem];
    for(int i=0; i<sodiem; i++){
        A[i].setX(0);
        A[i].setY(0);
    }
}
void DAGIAC::zoomDagiac(double k)
{
    for(int i=0; i<sodiem; i++)
    {
        A[i].setX(A[i].getX()*k);
        A[i].setY(A[i].getY()*k);
    }
}

void DAGIAC::quaydagiac(double goc)
{
    goc=goc*PI/180;
    for(int i=0; i<sodiem; i++)
    {
        int  a=A[i].getX();
        int  b=A[i].getY();
        A[i].setX(a*cos(goc)-b*sin(goc));
        A[i].setY(a*sin(goc)+b*cos(goc));
        
    }
}
void DAGIAC::Dichuyendagiac(double dx, double dy)
{
    for(int i=0; i<sodiem; i++)
    {
        A[i].Dichuyen(dx, dy);
    }
}
void DAGIAC::nhapdagiac()
{
    cout<<"("<<sodiem<<"): "<<endl;
    for(int i=0; i<sodiem; i++)
    {
        cout<<"Diem so "<<i+1<<": ";
        cin>>A[i];
    }
}
ostream &operator<<(ostream & os, DAGIAC& dagiac)
{
    for(int i=0; i<dagiac.sodiem; i++)
    {
        os<<dagiac.A[i]<<" ";
    }
    return os;
}
DAGIAC::~DAGIAC()
{
    sodiem=0;
    delete []A;
}
int main()
{
    DAGIAC DAGIAC1 (3);
    DAGIAC DAGIAC2 (4);
    cout<<"Hien thi da giac 1: "<<DAGIAC1<<endl;
    cout<<"Hien thi da giac 2: "<<DAGIAC2<<endl;
    cout<<"Thiet lap da giac 1: ";
    DAGIAC1.nhapdagiac();
    cout<<"--Di chuyen Da giac 2 (3, 6) "<<endl;
    DAGIAC2.Dichuyendagiac(3, 6);
    cout<<"Hien thi da giac 2 (sau khi Di chuyen (3,6) "<<DAGIAC2<<endl;
    cout<<"--Zoom Da Giac 1 len 7 lan: "<<endl;
    DAGIAC1.zoomDagiac(7);
    cout<<"Hien thi DA GIAC 1 (sau khi zoom 7) "<<DAGIAC1<<endl;
    cout<<"--Quay Da Giac 2 goc 40 do "<<endl;
    DAGIAC2.quaydagiac(40);
    cout<<"Hien thi DA GIAC 2 (sau khi quay 40 do)\n"<<DAGIAC2<<endl;
    return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
class Diem
{
private:
    double x;
    double y;
public:
    Diem ();
    Diem(double);
    Diem (double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double, double);
    bool Ktra2diemtrungnhau(Diem);
    double Khoangcach(Diem);
    Diem TimDiemDoiXung();
    double TinhChuVi(Diem,Diem);
    double TinhDienTich(Diem, Diem);
};
Diem ::Diem()
{
    this->x=this->y=0;
}
Diem ::Diem(double x)
{
    this->x=x;
    this->y=0;
}
Diem ::Diem (double xx, double yy)
{
    x=xx;
    y=yy;
}
void Diem::Nhap()
{
    cout<<"Nhap Hoanh Do: ";
    cin>>x;
    cout<<"Nhap Tung Do: ";
    cin>>y;
}
void Diem::Xuat()
{
    cout<<"("<<x<<";"<<y<<")";
}
void Diem::Dichuyen(double dx, double dy)
{
    x+=dx;
    y+=dy;
}
bool Diem::Ktra2diemtrungnhau(Diem dd)
{
    return (x==dd.x&&y==dd.y);
}
double Diem:: Khoangcach(Diem dd)
{
    return sqrt(pow(x-dd.x,2)+pow(y-dd.y,2));
}
Diem Diem::TimDiemDoiXung()
{
    Diem ddx(-this->x,-this->y);
    return ddx;
}
double Diem::TinhChuVi(Diem d1, Diem d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    Diem d1; Diem d2(-3); Diem d3(8,9.5);
    cout<<"Toa do diem d1"; d1.Xuat(); cout<<endl;
    cout<<"Toa do diem d2"; d2.Xuat(); cout<<endl;
    cout<<"Toa do diem d3"; d3.Xuat(); cout<<endl;
    cout<<"Nhap lai tao do diem d1 "<<endl; d1.Nhap();
    cout<<"Toa do diem d1: "; d1.Xuat(); cout<<endl;
    d1.Dichuyen(-1, 4);
    cout<<"Toa do diem d1 sau khi di chuyen: "; d1.Xuat(); cout<<endl;
    if(d1.Ktra2diemtrungnhau(d2))
        cout<<"Toa do hai diem d1 & d2 trung nhau"<<endl;
    else
        cout<<"toa do hai diem d1 & d2 KHONG trung nhau"<<endl;
    cout<<"Khoang cach hai diem d1 & d2 "<<d1.Khoangcach(d2)<<endl;
    Diem d4=d1.TimDiemDoiXung();
    cout<<"Diem d4 la diem doi xung voi d1: "; d4.Xuat();cout<<endl;
    cout<<"Chu vi cua tam giac di qua 3 Diem: "<<d1.TinhChuVi(d2, d3)<<endl;
    cout<<"Dien tich cua tam giac di qua 3 Diem: "<<d1.TinhDienTich(d2, d3)<<endl;
    return 0;
}


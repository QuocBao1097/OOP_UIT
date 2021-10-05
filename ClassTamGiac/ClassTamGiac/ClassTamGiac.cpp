
#include <iostream>
#include<cmath>

using namespace std;
class TamGiac
{
private:
    double a, b, c;
public:
    void KhoiTao(double, double, double);
    void NhapTamGiac();
    void XuatTamGiac();
    bool KiemTra3canhTamGiac(double, double, double);
    void PhanLoaiTamGiac();
    double TinhChuVi();
    double TinhDientich();
};
void TamGiac::KhoiTao(double a, double b, double c)
{
    this->a=a;
    this->b=b;
    this->c=c;
}
void TamGiac::NhapTamGiac()
{
    cout<<"Nhap 3 canh cua Tam Giac: "<<endl;
    cin>>a>>b>>c;
}
bool TamGiac::KiemTra3canhTamGiac(double a, double b, double c)
{
    if(a<b+c||b<a+c||c<b+a) return 1;
    else
        return 0;
}
void TamGiac:: PhanLoaiTamGiac(){
    if(KiemTra3canhTamGiac(a, b, c)==1)
    {
    if( a*a==b*b+c*c || b*b==a*a+c*c || c*c== a*a+b*b)
        cout<<"Day la tam giac vuong";
    else if(a==b && b==c)
        cout<<"Day la tam giac deu";
    else if(a==b || a==c || b==c)
        cout<<"Day la tam giac can";
    else if(a*a > b*b+c*c || b*b > a*a+c*c || c*c > a*a+b*b)
        cout<<"Day la tam giac tu";
    else
        cout<<"Day la tam giac nhon";
}
    else
        cout<<"Ba canh a, b, c khong phai la ba canh cua mot tam giac";
}
double TamGiac::TinhChuVi()
{
    double chuvi=a+b+c;
    return chuvi;
}
double TamGiac::TinhDientich()
{
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
void TamGiac:: XuatTamGiac()
{
    if(KiemTra3canhTamGiac(a, b, c)==1) cout<<"Ba canh tam giac nay hop le";
    else
        cout<<"Ba canh cua tam giac khong hop le";
}
int main()
{
    TamGiac x;
    x.KhoiTao(4.8, 2, 5);
    x.NhapTamGiac();
    x.XuatTamGiac(); cout<<endl;
    x.PhanLoaiTamGiac();cout<<endl;
    cout<<"Chu vi cua tam giac = ";
    cout<<x.TinhChuVi(); cout<<endl;
    cout<<"Dien tich cua tam giac = ";
    cout<<x.TinhDientich()<<endl;
    return 0;
}

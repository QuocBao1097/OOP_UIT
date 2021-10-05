
#include <iostream>
using namespace std;
class GiaiPTBac1
{
private:
    double a, b;
public:
    void KhoiTao();
    void KhoiTao(double);
    void KhoiTao(double, double);
    void NhapHeSo();
    void XuLi();
};
void GiaiPTBac1::KhoiTao()
{
    this->a=this->b=0;
}
void GiaiPTBac1:: KhoiTao(double b)
{
    this->a=0;
    this->b=b;
}
void GiaiPTBac1::KhoiTao(double a, double b)
{
    this->a=a;
    this->b=b;
}
void GiaiPTBac1:: NhapHeSo()
{
    cout<<"Nhap a= "; cin>>a;
    cout<<"Nhap b= "; cin>>b; cout<<endl;
}
void GiaiPTBac1:: XuLi()
{
    if(a==0)
    {
        if(b==0) cout<<"PTVSN"<<endl;
        else
            cout<<"PTVN"<<endl;
    }
    else
    {
        if(b==0) cout<<"x = "<<0<<endl;
        else
            cout<<"x = "<<(double)-b/a<<endl;
    }
}
int main()
{
    GiaiPTBac1 x;
    x.KhoiTao();
    x.KhoiTao(5); x.XuLi();
    x.KhoiTao(2, -3); x.XuLi();
    x.NhapHeSo();
    cout<<"Nghiem cua PT bac 1 la: ";
    x.XuLi();
}

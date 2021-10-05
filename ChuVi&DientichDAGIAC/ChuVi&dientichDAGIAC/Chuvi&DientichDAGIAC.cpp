/*#include<iostream>
#include"phanso.hpp"
int main()
{
PHANSO  ps1, ps2, psmax, pstong, pshieu, pstich, psthuong;
int chon;
bool danhapPS=false;
do{ 
    cout<<"----MENU----"<<endl;
    cout<<"1.Nhap 2 phan so"<<endl;
    cout<<"2.Tim phan so lon hon trong 2 phan so"<<endl;
    cout<<"3.tong hai phan so"<<endl;
    cout<<"4.hieu hai phan so"<<endl;
    cout<<"5.Tich hai phan so"<<endl;
    cout<<"6.thuong hai phan so"<<endl;
    cout<<"0.Thoat..."<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Ban chon"; cin>>chon;
    switch(chon){
        case 0:
            cout<<"Thoat CHUONG TRINH...";
            break;
        case 1:
            nhaphaiphanso(ps1, ps2);
            danhapPS=true;
        case 2:
            kiemtranhaphaiphanso(danhapPS, ps1, ps2);
            psmax=timphansolonnhat(ps1, ps2);
            cout<<"Phan so lon la:";
            xuatphanso(psmax); break;
        case 3:
            kiemtranhaphaiphanso(danhapPS,ps1, ps2);
            pstong=tong(ps1, ps2);
            xuatphanso(ps1); cout<<"+"; xuatphanso(ps2);
            cout<<"="; xuatphanso(pstong); cout<<endl;
            break;
        case 4:
            kiemtranhaphaiphanso(danhapPS,ps1, ps2);
            pshieu=hieu(ps1, ps2);
            xuatphanso(ps1); cout<<"+"; xuatphanso(ps2);
            cout<<"="; xuatphanso(pshieu); cout<<endl;
            break;
        case 5:
            kiemtranhaphaiphanso(danhapPS,ps1, ps2);
            pstich=tich(ps1, ps2);
            xuatphanso(ps1); cout<<"+"; xuatphanso(ps2);
            cout<<"="; xuatphanso(pstich); cout<<endl;
            break;
        case 6:
            kiemtranhaphaiphanso(danhapPS,ps1, ps2);
            psthuong=thuong(ps1, ps2);
            xuatphanso(ps1); cout<<"+"; xuatphanso(ps2);
            cout<<"="; xuatphanso(psthuong); cout<<endl;
            break;
        default:
            cout<<"Ban chon sai.Moi ban nhap lai:"; break;
    }
}while(chon!=0);
    return 0;
}
*/

/*#include <iostream>
using namespace std;
const int MAX=50;
void NhapMang(int a[], int &n)
{
    do{
        cout<<"Nhap so phan tu n=";
        cin>>n;
        
    }while(n<1 || n>MAX);
    
    for(int i=0; i<n; i++)
    {
        cout<<"Nhap a["<<i<<"]= ";
        cin>>a[i];
    }
}
bool Ktradoixung(int A[], int n){
    int dem=0;
    for(int i=0; i<n/2; i++){
        if(A[i]!=A[n-i-1])
            dem++;
            }
    if(dem==0)
            return true;
    return false;
}
void ArrayIncrease(int A[], int n)
{
    for(int i=0; i<n/2; i++)
        {
            
        }
}
int main(){
    int n;int a[MAX];
    NhapMang(a, n);
    if(Ktradoixung(a, n)==1) cout<<"Mang doi xung"<<endl;
    else
        cout<<"Mang khong doi xung\n";
    return 0;
}
*/

#include<iostream>
#include<math.h>
using namespace std;
struct point
{
    int x,y;
};
void chuvi(point a[], int n)
{
    a[n]=a[0];
    double d,s=0;
    for (int i=0; i<n; i++)
    {
        d=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y));
        s=s+d;
    }
    cout<<s;
}
void dientich(point a[], int n)
{
    a[n]=a[0];
    double s=0;
    for(int i=0; i<n; i++)
    {
        s=s+(a[i].x-a[i+1].x)*(a[i].y+a[i+1].y);
    }
    s=abs(s/2);
    cout<<s;
}
int main(){
    point a[22];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    cout<<"CHu vi cua da giac la:";
    chuvi(a, n);
    cout<<"\nDien tich cua da giac la:";
    dientich(a, n);
    return 0;
}

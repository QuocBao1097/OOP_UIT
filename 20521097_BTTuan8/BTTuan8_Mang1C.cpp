

#include <iostream>
#include<cmath>
using namespace std;
class MANG1C
{
private:
    int n;
    int *A;
public:
    MANG1C();
    MANG1C(int nn);
    MANG1C(MANG1C &u);
    void Nhap();
    void Xuat();
    void LietKe_SNT();
    void Dem_SCP();
    int Tong_SHT();
    double TBCong_Doixung();
    bool KiemTraLe();
    int TimChan_Min();
    void SortTang();
    void XoaBatKi();
    void Themvitribatki();
    int Timkiem();
    ~MANG1C();
};
MANG1C ::~MANG1C()
{
    cout<<"\nGoi Ham Huy ~Mang1C" ;
    delete []A;
    A=NULL;
}

MANG1C::MANG1C()
{
    cout<<"Goi Ham Thiet Lap (Khong doi so)\n";
    n=0;
    A=NULL;
}
MANG1C ::MANG1C(MANG1C &u)
{
    n=u.n;
    A=new int [n];
    for(int i =0 ; i<n; i++)
        A[i]=u.A[i];
}
MANG1C::MANG1C(int nn)
{
    cout<<"\nThiet lap co doi so: "<<endl;
    n=nn;
    A = new int [n];// cap phat vung nho dong chua n phan tu
}

void MANG1C::Nhap()
{
    if(A==NULL)
    {
        cout<<"Nhap so luong phan tu Mang1C: ";
        cin>>n;
        A=new int [n];
    }
        for(int i = 0 ; i < n; i++)
        {
            cout<<"A["<<i<<"]= ";
            cin>>A[i];
        }
}

void MANG1C::Xuat()
{
    cout<<"\nXuat MANG1C: "<<endl;
    for(int i = 0; i<n; i++)
    cout<<A[i]<<"\t";
}
int ktra(int &n)
{
    if(n<2) return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void MANG1C::LietKe_SNT()
{
    cout<<"\nLiet ke SNT: ";
    for(int i=0; i<n; i++)
    {
        if(ktra(A[i]))
        {
            cout<<A[i]<<"\t";
        }
    }
}
int ktraspc(int &n)
{
    for(int i = 0; i<=n; i++){
        if(i*i==n) return 1;
    }
    return 0;
}
void MANG1C::Dem_SCP()
{
    int dem=0;
    for(int i = 0; i < n; i++)
    {
        if(ktraspc(A[i]))
            dem++;
    }
    if(dem==0) cout<<"-Khong co SCP"<<endl;
    else
        cout<<"\n-Co "<<dem<<" SCP\n";
}
bool MANG1C::KiemTraLe()
{
    int dem=0;
    for(int i=0; i<n; i++){
        if(A[i]%2!=0)
            dem++;
    }
    if(dem==n)
            return 1;
    return 0;
}
int ktrasohoanthien(int &n)
{
    int s=0;
    for(int i=1; i<=n/2; i++)
    {
        if(n%i==0)
            s=s+i;
    }
    if(s==n) return 1;
    return 0;
}
int MANG1C::Tong_SHT()
{
    int tong=0;
    for(int i=0; i<n; i++)
    {
        if(ktrasohoanthien(A[i]))
        tong=tong+A[i];
    }
    return tong;
}
int MANG1C::TimChan_Min()
{
        int min=A[0];
        for(int i=0; i<n; i++)
        {
            if(min>A[i] && A[i]%2==0)
            {
                min=A[i];
            }
        }
    if(min==A[0])
    {
        if(A[0]%2!=0)
            return 0;
    }
    return min;
}
void MANG1C::SortTang()
{
    for(int i=0; i<n-1 ;i++)
        for(int j=i+1; j<n; j++)
        {
            if(A[i]>A[j]){
                int temb=A[i];
                A[i]=A[j];
                A[j]=temb;
            }
        }
    cout<<"\nMang sau Khi Sap xep: ";
     for(int i=0; i<n ;i++)
         cout<<A[i]<<"\t";
}
int MANG1C::Timkiem()
{
    int x; int k=-1;
    cout<<"\nGia tri can tim Kiem la: "; cin>>x;
    for(int i=0; i<n; i++)
    {
        if(A[i]==x)
        {
            k=i;
            cout<<"Tim thay "<<x<<" tai vi tri i= "<<k<<endl;
            break;
        }
    }
      return k;
}
void MANG1C::Themvitribatki()
{
    n++;
    int k; int x;
    cout<<"\nNhap gia tri can chen: "; cin>>x;
    cout<<"\nVi tri can chen: "; cin>>k;
    for(int i=n; i>k; i--)
        A[i]=A[i-1];
        A[k]=x;
    cout<<"Mang sau khi them: ";
    for(int i=0; i<n; i++)
        cout<<A[i]<<"\t";
}
void MANG1C::XoaBatKi()
{
    int x;
    cout<<"\nNhap vi tri can xoa: "; cin>>x;
    for(int i=x; i<=n-2; i++)
        A[i]=A[i+1];
    n--;
    cout<<"\nMang sau khi xoa: ";
    for(int i=0; i<n; i++)
        cout<<A[i]<<"\t";
}
int DaoNguoc(int number) {
    int res = 0;
    while (number > 0) {
        res = res * 10 + number % 10;
        number /= 10;
    }
    return res;
}
bool KiemTraDoiXung(int number) {
    if (number == DaoNguoc(number))
        return true;
    return false;
}
double MANG1C::TBCong_Doixung()
{
    int tong=0;
    int dem=0;
    for(int i=0; i<n; i++){
        if(KiemTraDoiXung(A[i])==true)
        {
              tong+=A[i];
            dem++;
        }
        
    }
    return tong/dem;
}
int main()
{
    MANG1C x;
    x.Nhap();
    x.Xuat();
    MANG1C y(5);
    y.Nhap();
    y.Xuat();
    MANG1C z=y;
    cout<<"\nMang Z sau khi da sao chep: ";
    z.Xuat();
    z.LietKe_SNT();
    z.Dem_SCP();
    cout<<"\nTong SHT= "<<z.Tong_SHT();
    cout<<"\nTBC so doi xung= "<<z.TBCong_Doixung();
    if(z.KiemTraLe()) cout<<"\nMang toan le"<<endl;
    else
        cout<<"\nMang khong toan le";
    if(z.TimChan_Min()==0) cout<<"Khong co Min_Chan"<<endl;
    else
        cout<<"\nGia tri Min_Chan: "<<z.TimChan_Min();
    if(z.Timkiem()==-1)  cout<<"-Khong tim thay: "<<endl;
    z.SortTang();
    z.Themvitribatki();
    z.XoaBatKi();
    z.TimChan_Min();
    return 0;
}

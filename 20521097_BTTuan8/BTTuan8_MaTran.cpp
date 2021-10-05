#include<iostream>
#include<cmath>
using namespace std;
class MATRAN
{
private:
    int sd;
    int sc;
    int **p;
public:
    MATRAN();
    MATRAN(int sd, int sc);
    MATRAN(MATRAN &x);
    ~MATRAN();
    void NhapMaTran();
    void XuatMaTran();
    void LietKe_SNT();
    void DemSCP();
    int Tong_SHT();
    double Tinh_TBC_SoDoiXung();
    void SapXepTangTheoDong();
};

MATRAN ::MATRAN()
{
    cout<<"Ham Thiet Lap(Khong doi so): "<<endl;
    sd=sc=0;
    p=NULL;
}
MATRAN::~MATRAN()
{
    cout<<"Goi ham huy: "<<endl;
    for(int i=0; i<sd; i++)
        delete []p[i];
    delete []p;
    p=NULL;
}
MATRAN ::MATRAN(int sodong, int socot)
{
    cout<<"Thiet lap (co doi so): "<<endl;
    sd=sodong;
    sc=socot;
    p=new int*[sd*sc];
}
MATRAN::MATRAN(MATRAN &x)
{
    sd=x.sd;
    sc=x.sc;
    p=new int *[sd];
    for(int i = 0; i<sd; i++)
         p[i]=new int[sc];
     for(int i = 0; i<sd; i++)
        for(int j=0; j<sc; j++)
            p[i][j]=x.p[i][j];
}
void MATRAN::NhapMaTran()
{
    if(p==NULL){
        cout<<"Nhap so dong va so cot:"<<endl;
        cin>>sd>>sc;
        p=new int *[sd];
    }
        for(int i = 0; i<sd; i++)
            p[i]=new int[sc];
        for(int i=0; i<sd; i++)
            for(int j=0; j<sc; j++){
                cout<<"P["<<i<<"]["<<j<<"]=";
                cin>>p[i][j];
            }
}
void MATRAN::XuatMaTran()
{
    cout<<"Xuat ma tran:"<<endl;;
    for(int i=0; i<sd; i++){
        for(int j=0; j<sc; j++){
            cout<<p[i][j]<<"\t";
        }
          cout<<endl;
    }
}
int ktraSNT(int &n)
{
    if(n<2) return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void MATRAN::LietKe_SNT()
{
    cout<<"Cac phan tu la SNT: ";
    for(int i=0; i<sd; i++)
        for(int j=0; j<sc;j++){
            if(ktraSNT(p[i][j]))
                cout<<p[i][j]<<"\t";
        }
}
int ktraspc(int &n)
{
    for(int i = 0; i<=n; i++){
        if(i*i==n) return 1;
    }
    return 0;
}
void MATRAN::DemSCP()
{
    int dem=0;
    for(int i=0; i<sd; i++)
        for(int j=0; j<sc; j++)
        {
            if(ktraspc(p[i][j]))
                dem++;
        }
    cout<<"\nMa Tran co "<<dem<<" SCP"<<endl;
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
int MATRAN::Tong_SHT()
{
    int tong=0;
    for(int i=0; i<sd; i++)
        for(int j=0; j<sc; j++){
            if(ktrasohoanthien(p[i][j]))
                tong+=p[i][j];
        }
    return tong;
}
void swap(int &a, int &b)
{
    int temb=a;
    a=b;
    b=temb;
}
void MATRAN::SapXepTangTheoDong()
{
    int k=1;
    cout<<"\nDong can sap xep: ";
    cin>>k;
    if (sd == 0)
        return;
    for(int i = 0; i < sc; i++)
        for(int j = 1; j < sc; j++)
            if (p[k][i] > p[k][j])
                swap(p[k][i], p[k][j]);
    cout<<"Ma tran sau khi sap xep: "<<endl;
    for(int i=0; i<sd; i++){
        for(int j=0; j<sc; j++){
            cout<<p[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    MATRAN a;
    a.NhapMaTran();
    a.XuatMaTran();
    MATRAN b(3,3);
    b.NhapMaTran();
    b.XuatMaTran();
    MATRAN z=b;// sao chep
    z.XuatMaTran();
    z.LietKe_SNT();
    z.DemSCP();
    cout<<"Tong SHT= "<<z.Tong_SHT();
    z.SapXepTangTheoDong();
    return 0;
}

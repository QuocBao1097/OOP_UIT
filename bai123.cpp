#include <iostream>
#include <math.h>
using namespace std;
struct PHANSO
{
    int tu,mau;
};
void nhapphanso(PHANSO &ps)
{
    cout<<"Nhap tu so: ";
    cin>>ps.tu;
    do{
        cout<<"Nhap mau so: ";
        cin>>ps.mau;
    }while(ps.mau==0);
}
int UCLN(int a, int b)
{
    if(b==0) return a;
    if(a%b==0) return b;
    return UCLN(b,a%b);
}
void rutgon(PHANSO &ps)
{
    int ucln=UCLN(ps.tu,ps.mau);
    ps.tu/=ucln;
    ps.mau/=ucln;
}
void xuatphanso(PHANSO ps)
{
    if(ps.mau==1) cout<<ps.tu;
    else if (ps.mau==-1) cout<<-(ps.tu);
    else if (ps.mau<0) cout<<-abs(ps.tu)<<"/"<<-(ps.mau);
    else
        cout<<ps.tu<<"/"<<ps.mau;
}
void nhaphaiphanso(PHANSO &ps1, PHANSO &ps2)
{
    cout<<" nhap tu so cua phan so 1 "; cin>>ps1.tu;
    
    do {
        cout<<" nhap mau so cua phan so 1 ";
        cin>>ps1.mau;
    } while (ps1.mau==0);
    
    cout<<" nhap tu so cua phan so 2 "; cin>>ps2.tu;
    do {
        cout<<" nhap mau so cua phan so 2 ";
        cin>>ps2.mau;
    } while (ps2.mau==0);
}
void timphansolonhon(PHANSO ps1,PHANSO ps2)
{
    float temb1=(float) ps1.tu/ps1.mau;
    float temb2=(float) ps2.tu/ps2.mau;
    if(temb1>temb2)
    {
        if(ps1.mau==1) cout<<ps1.tu;
    else
        if (ps1.mau==-1) cout<<-(ps1.tu);
    else
        if (ps1.mau<0) cout<<-abs(ps1.tu)<<"/"<<-(ps1.mau);
    else
        cout<<ps1.tu<<"/"<<ps1.mau;
    }
    if(temb1<temb2)
    {
        if(ps2.mau==1) cout<<ps2.tu;
        else
            if (ps2.mau==-1) cout<<-(ps2.tu);
            else
                if (ps2.mau<0) cout<<-abs(ps2.tu)<<"/"<<-(ps2.mau);
                else
                    cout<<ps2.tu<<"/"<<ps2.mau;
    }
}
void tong(PHANSO ps1, PHANSO ps2)
{
    PHANSO temb;
    temb.tu=(ps1.tu*ps2.mau+ps2.tu*ps1.mau);
    temb.mau=ps1.mau*ps2.mau;
    rutgon(temb);
    if(temb.mau==1) cout<<temb.tu;
    else
        if (temb.mau==-1) cout<<-(temb.tu);
        else
            if (temb.mau<0) cout<<-abs(temb.tu)<<"/"<<-(temb.mau);
            else
                cout<<temb.tu<<"/"<<temb.mau;
}
void hieu(PHANSO ps1, PHANSO ps2)
{
    PHANSO temb;
    temb.tu=(ps1.tu*ps2.mau-ps2.tu*ps1.mau);
    temb.mau=ps1.mau*ps2.mau;
    rutgon(temb);
    if(temb.mau==1) cout<<temb.tu;
    else
        if (temb.mau==-1) cout<<-(temb.tu);
        else
            if (temb.mau<0) cout<<-abs(temb.tu)<<"/"<<-(temb.mau);
            else
                cout<<temb.tu<<"/"<<temb.mau;
}
void tich(PHANSO ps1, PHANSO ps2)
{
    PHANSO temb;
    temb.tu=ps1.tu*ps2.tu;
    temb.mau=ps1.mau*ps2.mau;
    rutgon(temb);
    if(temb.mau==1) cout<<temb.tu;
    else
        if (temb.mau==-1) cout<<-(temb.tu);
        else
            if (temb.mau<0) cout<<-abs(temb.tu)<<"/"<<-(temb.mau);
            else
                cout<<temb.tu<<"/"<<temb.mau;
}
void thuong(PHANSO ps1, PHANSO ps2)
{
    PHANSO temb;
    temb.tu=ps1.tu*ps2.mau;
    temb.mau=ps1.mau*ps2.tu;
    rutgon(temb);
    if(temb.mau==1) cout<<temb.tu;
    else
        if (temb.mau==-1) cout<<-(temb.tu);
        else
            if (temb.mau<0) cout<<-abs(temb.tu)<<"/"<<-(temb.mau);
            else
                cout<<temb.tu<<"/"<<temb.mau;
}
void giatrithuc(PHANSO ps)
{
    cout<<static_cast<float>(ps.tu)/static_cast<float>(ps.mau)<<endl;
}
void MENU()
{
    cout<<"----MENU----"<<endl;
    cout<<"1.Nhap 1 phan so"<<endl;
    cout<<"2.Rut gon 1 phan so"<<endl;
    cout<<"3.Xuat 1 phan so"<<endl;
    cout<<"4.Nhap hai phan so"<<endl;
    cout<<"5.Tim phan so lon hon trong 2 phan so"<<endl;
    cout<<"6.Tinh tong hai phan so"<<endl;
    cout<<"7.Tinh hieu hai phan so"<<endl;
    cout<<"8.Tinh tich hai phan so"<<endl;
    cout<<"9.Tinh thuong hai phan so"<<endl;
    cout<<"0.Thoat"<<endl;
    cout<<endl;
}
void xuli(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    int x,k;
    do{
        cout<<"Nhap MENU so: ";
        cin>>x;
    } while((x!=4) && (x!=1));
    if(x==1)
    {
        nhapphanso(ps);
        cout<<endl;
        do{
            cout<<" Chon cach xu li 1 phan so:";
            cin>>k;
            switch (k) {
                case 2:
                {
                    cout<<"Phan So da rut gon la: ";rutgon(ps);
                    cout<<endl;
                    break;
                }
                case 3:
                {
                    cout<<"Phan So da nhap la: ";nhapphanso(ps); cout<<endl;
                    break;
                }
                case 10:
                {
                    cout<<"Gia tri thuc cua phan so la: ";giatrithuc(ps); cout<<endl;
                    break;
                }
            }
        }while(k!=0);
        cout<<" Thoat...";
    }
    else
    {
        nhaphaiphanso(ps1, ps2);
        do{
            cout<<"Chon cach xu ly voi 2 phan so:";
            cin>>k;
            switch (k){
                case 5:
                {
                    cout<<"Phan so lon hon trong 2 phan so la:";
                    timphansolonhon(ps1, ps2);
                    cout<<endl;
                    break;
                }
                case 6:
                {
                    cout<<"Tong 2 phan so la:";
                    tong(ps1, ps2);
                    cout<<endl;
                    break;
                }
                case 7:
                {
                    cout<<"Hieu 2 phan so la:";
                    hieu(ps1, ps2);
                    cout<<endl;
                    break;
                }
                case 8:
                {
                    cout<<"Tich 2 phan so la:";
                    tich(ps1, ps2); cout<<endl;
                    break;
                }
                case 9:
                {
                    cout<<"Thuong 2 phan so la:";
                    thuong(ps1, ps2);
                    cout<<endl;
                    break;
                }
            }
        } while(k!=0);
        cout<<"Thoat...";
    }
}
int main()
{
    PHANSO ps1, ps2;
    MENU();
    xuli(ps1, ps2);
    return 0;
}

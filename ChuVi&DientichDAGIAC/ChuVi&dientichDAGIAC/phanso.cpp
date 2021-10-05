//
//  phanso.cpp
//  Group9
//
//  Created by Nguyen Thao Hien on 3/19/21.
//  Copyright © 2021 Bảo IT. All rights reserved.
//
#include<iostream>
#include "phanso.hpp"

void nhapphanso(PHANSO &ps)
{
    cout<<"Nhap tu so: ";
    cin>>ps.tu;
    do{
        cout<<"Nhap mau so khac 0:";
        cin>>ps.mau;
    }while (ps.mau==0);
}
int UCLN(int a, int b)
{
    if(b==0) return a;
    if(a%b==0) return b;
    return UCLN(b,a%b);
}
void rutgon(PHANSO &ps)
{
    int ucln=UCLN(ps.tu, ps.mau);
    ps.tu/=ucln;
    ps.mau/=ucln;
}
void xuatphanso(PHANSO ps)
{
    if(ps.mau==1) cout<<ps.tu;
    else
        if (ps.mau==-1) cout<<-(ps.tu);
        else
            if (ps.mau<0) cout<<-abs(ps.tu)<<"/"<<-(ps.mau);
            else
                cout<<ps.tu<<"/"<<ps.mau;
}
void nhaphaiphanso(PHANSO &ps1, PHANSO &ps2)
{
    cout<<"nhap tu so cua phan so 1 "<<endl;
    nhapphanso(ps1);
    cout<<" nhap tu so cua phan so 2 "<<endl;
    nhapphanso(ps2);
}
PHANSO timphansolonhon(PHANSO ps1, PHANSO ps2)
{
    double gtri_ps1=(double)ps1.tu/ps1.mau;
    double gtri_ps2=(double)ps2.tu/ps2.mau;
    return (gtri_ps1>gtri_ps2 ? ps1:ps2);
}
PHANSO tong(PHANSO ps1, PHANSO ps2)
{
    PHANSO pstong;
    pstong.tu=ps1.tu*ps2.mau+ps2.tu*ps1.mau;
    pstong.mau=ps1.mau*ps2.mau;
    rutgon(pstong);
    return pstong;
}
PHANSO hieu(PHANSO ps1, PHANSO ps2)
{
    PHANSO pshieu;
    pshieu.tu=ps1.tu*ps2.mau-ps2.tu*ps1.mau;
    pshieu.mau=ps1.mau*ps2.mau;
    rutgon(pshieu);
    return pshieu;
}
PHANSO tich(PHANSO ps1, PHANSO ps2)
{
    PHANSO pstich;
    pstich.tu=ps1.tu*ps2.tu;
    pstich.mau=ps1.mau*ps2.mau;
    rutgon(pstich);
    return pstich;
}
PHANSO thuong(PHANSO ps1, PHANSO ps2)
{
    PHANSO psthuong;
    psthuong.tu=ps1.tu*ps2.mau;
    psthuong.mau=ps1.mau*ps2.tu;
    rutgon(psthuong);
    return psthuong;
}
void kiemtranhaphaiphanso(bool &danhapPS, PHANSO &ps1, PHANSO &ps2)
{
    if(!danhapPS)
    {
        nhaphaiphanso(ps1, ps2);
        rutgon(ps1);
        rutgon(ps2);
        danhapPS=true;
    }
}

//
//  main.cpp
//  HinhTron_ThayKhang
//
//  Created by Nguyen Thao Hien on 5/17/21.
//  Copyright © 2021 Bảo IT. All rights reserved.
//

#include <iostream>
using namespace std;
struct diem
{
    float x,y;
};
typedef struct diem DIEM;
struct hinhtron
{
    DIEM I;
    float R;
};
typedef struct hinhtron HINHTRON;

void nhap(DIEM &p)
{
    cout<<"\nx= "; cin>>p.x;
    cout<<"y= "; cin>>p.y;
}
void xuat(DIEM &p)
{
    cout<<"("<<p.x<<","<<p.y<<")";
}
void nhap(HINHTRON &c)
{
    cout<<"Nhap Diem: ";
    nhap(c.I);
    cout<<"Nhap Ban Kinh R:";
    cin>>c.R;
}
float dientinh(HINHTRON &c)
{
    return 3.14*c.R*c.R;
}
float chuvi(HINHTRON &c)
{
    return 2*3.14*c.R;
}
int main()
{
    HINHTRON c;
    nhap(c);
    xuat(c.I);
    cout<<"\nBan kinh: "<<c.R;
    cout<<"\nDien tich: "; cout<<dientinh(c);
    cout<<"\nChu vi: "; cout<<chuvi(c);
    return 1;
}


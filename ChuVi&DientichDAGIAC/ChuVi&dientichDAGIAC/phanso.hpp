//
//  phanso.hpp
//  Group9
//
//  Created by Nguyen Thao Hien on 3/19/21.
//  Copyright © 2021 Bảo IT. All rights reserved.
//

#ifndef phanso_hpp
#define phanso_hpp

#include <stdio.h>
using namespace std;
struct PHANSO
{
    int tu,mau;
};
void nhapphanso(PHANSO&);
void nhaphaiphanso(PHANSO&, PHANSO&);
int UCLN(int, int);
void rutgon(PHANSO &);
void xuatphanso(PHANSO);
PHANSO timphansolonnhat(PHANSO&, PHANSO&);
PHANSO tong(PHANSO, PHANSO);
PHANSO hieu(PHANSO, PHANSO);
PHANSO tich(PHANSO, PHANSO);
PHANSO thuong(PHANSO, PHANSO);
void kiemtranhaphaiphanso(bool &, PHANSO&, PHANSO&);
#endif /* phanso_hpp */

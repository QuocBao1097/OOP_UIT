#include<iostream>
#include<string>
using namespace std;

class DTXS
{
protected:
   string maso, hoten, khoa;
   int loai;// 1:GV, 2:SV, 3: NV
public:
   DTXS(string ="",string ="",string ="", int =0);
   string GetMaSo();
   string GetHoTen();
   string GetKhoa();
   int Getloai();
   void SetHoTen(string);
   void SetKhoa(string);
   virtual void nhap();
   virtual void xuat();
   virtual long TinhTienLuong()=0;
   virtual void SetSoBB(int)=0;
   virtual double GetDTB()=0;
   virtual double GetDRL()=0;
   virtual int GetSoBB()=0;
   virtual int GetSoSK()=0;
   virtual void SetDTB(double)=0;
   virtual void SetDRL(double)=0;
   virtual void SetSoSK(int)=0;
};
DTXS::DTXS(string ms, string ht, string khoa, int l ): maso(ms), hoten(ht), khoa(khoa), loai(l) {}

int DTXS::Getloai(){
   return loai;
}
string DTXS::GetMaSo() {
   return maso;
}
string DTXS::GetHoTen() {
   return hoten;
}
string DTXS::GetKhoa() {
   return khoa;
}
void DTXS::SetHoTen(string ht) {
   hoten=ht;
}
void DTXS::SetKhoa(string kh) {
   khoa=kh;
}
void DTXS::nhap()
{
   cin.ignore();
   cout<<"Ma so: ";
   getline(cin, maso);
   cout<<"Ho Ten: ";
   getline(cin, hoten);
   cout<<"Khoa: ";
   getline(cin, khoa);
}
void DTXS::xuat()
{
   cout<<"MS: "<<maso<<"\t"<<"Ho Ten: "<<hoten<<"\t"<<"Khoa: "<<khoa<<"\t"<<"Loai: "<<(loai==1?"GV ":(loai==2?"SV ":(loai==3?"NV ":"???")));
}

//-------------------------
class GV:public DTXS
{
private:
   int sobb;
public:
   GV(string ="",string ="",string ="", int =0);
   void nhap();
   void xuat();
   int GetSoBB();
   void SetSoBB(int);
   long TinhTienLuong();
   double GetDRL();
   double GetDTB();
   int GetSoSK();
   void SetSoSK(int);
   void SetDTB(double);
   void SetDRL(double);
};
GV::GV(string ms, string ht, string khoa, int sobb):DTXS(ms, ht, khoa, 1), sobb(0){}
int GV::GetSoBB() {
   return sobb;
}
void GV::SetSoBB(int bb) {
   while(bb<0) {
       cout<<"Nhap so bai bao: "; cin>>bb;
   }
   sobb=bb;
}
void GV::SetSoSK(int sk) {}
void GV::SetDTB(double tb) {}
void GV::SetDRL(double rl) {}

void GV::nhap()
{
   loai=1;
   DTXS::nhap();
   do{
       cout<<"So luong Bai Bao: "; cin>>sobb;
   }while(sobb<0);
}
void GV::xuat()
{
   DTXS::xuat();
   cout<<"So bai bao: "<<sobb<<" Tien thuong: "<<TinhTienLuong()<<endl;
}
long GV::TinhTienLuong()
{
   long thuong, them;
   thuong= sobb*20000000;
   them= (sobb>6? 15000000: (sobb>3?1000000:0));
   return them+thuong;
}
double GV::GetDRL() {
   return -1;// khong xac dinh
}
double GV::GetDTB() {
   return -1;// khong xac dinh
}
int GV::GetSoSK() {
   return -1;// khong xac dinh
}
//-----------------------
class SV: public DTXS
{
private:
   double DTB, DRL;
public:
   SV(string ="",string ="",string ="", double =0, double =0);
   void nhap();
   void xuat();
   long TinhTienLuong();
   double GetDRL();
   double GetDTB();
   int GetSoBB();
   int GetSoSK();
   void SetSoBB(int);
   void SetSoSK(int);
   void SetDTB(double);
   void SetDRL(double);
};
SV::SV(string ms, string ht, string khoa, double DTB, double DRL): DTXS(ms, ht, khoa, 2), DTB(DTB), DRL(DRL) {}

double SV::GetDRL(){
   return DRL;
}
double SV::GetDTB(){
   return DTB;
}
void SV::SetDTB(double tb)
{
   while(tb<0 || tb>10) {
       cout<<"Nhap DTB: "; cin>>tb;
   }
   DTB=tb;
}
void SV::SetDRL(double rl)
{
   while(rl<0 || rl>100) {
       cout<<"Nhap DRL: "; cin>>rl;
   }
   DRL=rl;
}
void SV::nhap()
{
   loai=2;
   DTXS::nhap();
   do{
       cout<<"Nhap DTB: "; cin>>DTB;
   }while(DTB<0 || DTB>10);
   do{
       cout<<"Nhap DRL: "; cin>>DRL;
   }while(DRL<0 || DRL >100);
}
void SV::xuat()
{
   DTXS::xuat();
   cout<<"DTB: "<<DTB<<"\t"<<"DRL: "<<DRL<<"\t"<<"Tien Thuong: "<<TinhTienLuong()<<endl;
}
long SV::TinhTienLuong()
{
   long thuong = 0;
   if(DRL >= 85)
       thuong = (DTB >9 ? 7000000: (DTB > 8.5?5000000:0));
   return thuong;
}
int SV::GetSoBB() {
   return -1;// khong xac dinh
}
int SV::GetSoSK() {
   return -1;// khong xac dinh
}
void SV::SetSoBB(int bb){}
void SV::SetSoSK(int sk){}

//------------------------
class NV: public DTXS
{
private:
   int sosk;
public:
   NV(string ="",string ="",string ="", int =0);
   void nhap();
   void xuat();
   long TinhTienLuong();
   double GetDRL();
   double GetDTB();
   void SetDTB(double);
   void SetDRL(double);
   int GetSoBB();
   void SetSoBB(int);
   int GetSoSK();
   void SetSoSK(int);
};
NV::NV(string ms, string ht, string khoa, int sosk): DTXS(ms, ht, khoa, 3), sosk(sosk) {}
int NV::GetSoSK() {
   return sosk;
}
void NV::SetSoSK(int sk) {
   while(sk<0)
   {
       cout<<"Nhap so SK: ";
       cin>>sk;
   }
   sosk=sk;
}
void NV::nhap(){
   loai= 3;
   DTXS::nhap();
   do {
       cout<<"Nhap So sang kien: "; cin>>this->sosk;
   }while(sosk<0);
}
void NV::xuat()
{
   DTXS::xuat();
   cout<<"So sk: "<<sosk<<" Tien thuong: "<<TinhTienLuong()<<endl;
}
long NV::TinhTienLuong()
{
   long luong= sosk *3000000;
   if(sosk >=3 )
       luong= sosk *1.2;
   return luong;
}
int NV::GetSoBB(){
   return -1;// khong xac dinh
}
double NV::GetDTB() {
   return -1;// khong xac dinh
}
double NV::GetDRL() {
   return -1;// khong xac dinh
}
void NV::SetDRL(double rl){}
void NV::SetDTB(double tb){}
void NV::SetSoBB(int bb){}
//--------------------

class TRUONGDH
{
private:
   DTXS** pdtxs;
   int sl;
public:
   TRUONGDH();
   ~TRUONGDH();
   int GetSL();
   void nhap();
   void xuat();
   void LietKeGVcoTu5BB();
   int DemSVcoDRLToiDa();
   long TinhTongTienNVco3SKKNTroLen();
   double TinhDTBCuaSVCoDRLDuoi50();
   int KiemTraGVChuaCoBaiBao();
   void TimNVCoSKKNNhieuNhat();
   string DoiChuoiInHoa(string);
   string DoiChuoiInThuong(string);
   void SapXepMaSoTangDan();
   void TimDTXSTheoTungKhoa(string);
   void CapNhapThongTinTheoMaSo(string);
};

TRUONGDH::TRUONGDH()
{
   pdtxs=NULL;
   sl=0;
}
//TRUONGDH::~TRUONGDH()
//{
//    if(sl>0)
//    {
//    for(int i=0; i<sl; i++)
//            delete pdtxs [i];
//            delete[]pdtxs;
//            pdtxs=NULL;
//            sl=0;
//    }
//}
TRUONGDH ::~TRUONGDH()
{
   delete[]pdtxs;
   pdtxs=NULL;
   sl=0;
}
int TRUONGDH::GetSL(){
   return sl;
}
void TRUONGDH::nhap()
{
   int l;// loai DTXS
   do{
       cout<<"Nhap So Luong DTXS: ";
       cin>>sl;
   }while(sl<1);
   pdtxs=new DTXS*[sl];
   for(int i=0; i<sl; i++)
   {
       cout<<"\n--------------------------\n";
       cout<<"Nhap Thong Tin DTXS thu "<<i+1<<":\n";
       do {
           cout<<"Nhap Loai(1:GV, 2:SV, 3: NV): ";
           cin>>l;
       }while(l<1|| l>3);
       if(l==1)
               pdtxs[i]= new GV;
       else if (l==2)
               pdtxs[i]= new SV;
           else
               pdtxs[i]= new NV;
       pdtxs[i]->nhap();
   }
}
void TRUONGDH::xuat()
{
   for(int i=0; i<sl; i++)
       pdtxs[i]->xuat();
}
void TRUONGDH::LietKeGVcoTu5BB()
{
   int dem=0;
   for(int i=0; i<sl; i++)
       if(pdtxs[i]->Getloai()==1 && pdtxs[i]->GetSoBB()>=5)
       {
           pdtxs[i]->xuat();
           dem++;
       }
   if(dem==0)
       cout<<"Khong co GV nao co tu 5 bai bao tro len\n";
}
int TRUONGDH::DemSVcoDRLToiDa()
{
   int dem=0;
   for(int i=0; i<sl; i++)
       if(pdtxs[i]->Getloai() && pdtxs[i]->GetDRL()==100)
           dem++;
   return dem;
}
long TRUONGDH::TinhTongTienNVco3SKKNTroLen()
{
   long sum=0;
   for(int i=0; i<sl; i++)
       if(pdtxs[i]->Getloai()==3 && pdtxs[i]->GetSoSK()>=3)
           sum+=pdtxs[i]->TinhTienLuong();
   return sum;
}
double TRUONGDH::TinhDTBCuaSVCoDRLDuoi50()
{
   double tongdtb=0;
   int dem=0;
   for(int i=0; i<sl; i++)
       if(pdtxs[i]->Getloai()==2 && pdtxs[i]->GetDRL() <50)
       {
           tongdtb+=pdtxs[i]->GetDTB();
           dem++;
       }
   return dem>0 ? tongdtb/dem:0;
}

int TRUONGDH::KiemTraGVChuaCoBaiBao()
{
   int kt=1;
   for(int i=0; i<sl; i++)
       if(pdtxs[i]->Getloai()==1)
       {
           if(pdtxs[i]->GetSoBB()==0)
           {
               kt=2;
               break;
           }
           else
               kt=3;
       }
   return kt;
}

void TRUONGDH::TimNVCoSKKNNhieuNhat()
{
   int skmax=-1, vt=-1;
   for(int i=0; i<sl; i++)
       if(pdtxs[i]->Getloai()==3)
       {
           vt=i;
           skmax=pdtxs[i]->GetSoSK();
           break;
       }
   if(vt!=-1)
   {
       for(int i=vt+1; i<sl; i++)
           if(pdtxs[i]->Getloai()==3 && pdtxs[i]->GetSoSK()>skmax)
               skmax=pdtxs[i]->GetSoSK();
       for(int i=0; i<sl; i++)
           if(pdtxs[i]->Getloai()==3 && pdtxs[i]->GetSoSK()==skmax)
               pdtxs[i]->xuat();
   }
   else
       cout<<"Truong Khong Co NV";
}
string TRUONGDH::DoiChuoiInHoa(string str)
{
   for(int i=0; i<str.length(); i++)
       str[i]=toupper(str[i]);
   return str;
}
string TRUONGDH::DoiChuoiInThuong(string str)
{
   for(int i=0; i<str.length(); i++)
       str[i]=tolower(str[i]);
   return str;
}
void TRUONGDH::SapXepMaSoTangDan()
{
   for(int i=0; i<sl-1; i++)
       for(int j=i+1; j<sl; j++)
           if(DoiChuoiInHoa(pdtxs[i]->GetMaSo())>DoiChuoiInHoa(pdtxs[j]->GetMaSo()))
           {
               DTXS*temb=pdtxs[i];
               pdtxs[i]=pdtxs[j];
               pdtxs[j]=temb;
           }
}
void TRUONGDH::TimDTXSTheoTungKhoa(string kh)
{
   int dem=0;
   for(int i=0; i<sl; i++)
       if(DoiChuoiInHoa(pdtxs[i]->GetKhoa())==DoiChuoiInHoa(kh))
       {
           pdtxs[i]->xuat();
           dem++;
       }
   if(dem==0)
       cout<<"Khong co DTXS thuoc Khoa "<<kh<<endl;
}
void TRUONGDH::CapNhapThongTinTheoMaSo(string ms)
{
   int timthay=-1;
   for(int i=0; i<sl; i++)
       if(DoiChuoiInHoa(pdtxs[i]->GetMaSo())==DoiChuoiInHoa(ms))
       {
           timthay=1;
           string ht, kh;
           cin.ignore();
           cout<<"Nhap Ho Ten: ";
           getline(cin, ht);
           pdtxs[i]->SetHoTen(ht);
           cout<<"Nhap Khoa: ";
           getline(cin, kh);
           pdtxs[i]->SetKhoa(kh);
           if(pdtxs[i]->Getloai()==1)
           {
               int bb;
               cout<<"Nhap So Bai Bao: ";
               cin>>bb;
               pdtxs[i]->SetSoBB(bb);
           }
           else if(pdtxs[i]->Getloai()==2)
           {
               double tb, rl;
               cout<<"Nhap DTB: ";
               cin>>tb;
               pdtxs[i]->SetDTB(tb);
               cout<<"Nhap DRL: ";
               cin>>rl;
               pdtxs[i]->SetDRL(rl);
           }
           else
           {
               int sk;
               cout<<"Nhap So SKKN: ";
               cin>>sk;
               pdtxs[i]->SetSoSK(sk);
           }
           cout<<"Da Cap Nhat Thong Tin DTXS co Ma So la: "<<ms<<endl;
           xuat();
           break;
       }
   if(timthay==-1)
       cout<<"Khong tim thay DTXS co Ma So la "<<ms<<endl;
}

int main()
{
   TRUONGDH trg;
   int chon;
   do {
       cout<<"======CHUONG TRINH QUAN LY DOI TUONG XUAT SAC CUA TRUONG======\n";
       cout<<"1. Nhap D/S DTXS\n";
       cout<<"2. Xuat D/S DTXS\n";
       cout<<"3. liet Ke D/S GV co tu 5 bai bao KH tro len\n";
       cout<<"4. Dem SV co DRL toi da\n";
       cout<<"5. Tinh Tong tien tuong Cua NV co 3 SKKN tro len\n";
       cout<<"6. Tinh DTB cua SV co DRL Duoi 50\n";
       cout<<"7. Kiem Tra GV Chua co Bai Bao Khoa Hoc\n";
       cout<<"8. Tim NV co SKKN nhieu nhat\n";
       cout<<"9. Sap Xep D/S DTXS tang dan\n";
       cout<<"10. Tim DTXS theo Khoa\n";
       cout<<"11. Cap nhap Thong Tin DTXS co MA SO tuy y\n";
       cout<<"0. Thoat Chuong Trinh...\n";
       cout<<"---------------------------\n";
       cout<<"Xin Moi Ban Chon: ";
       cin>>chon;
       switch(chon){
           case 1:
           {
               if(trg.GetSL()>0)
                   trg.~TRUONGDH();
               trg.nhap();
               break;
           }
           case 2:
           {
               if(trg.GetSL()>0)
                   trg.xuat();
               else
                   cout<<"Chua nhap Thong Tin\n";
               break;
           }
           case 3:
           {
               if(trg.GetSL()>0)
                   trg.LietKeGVcoTu5BB();
               else
                   cout<<"Chua Nhap Thong Tin\n";
               break;
           }
           case 4:
           {
               int dem;
               if(trg.GetSL()>0) {
                   dem=trg.DemSVcoDRLToiDa();
                   if(dem > 0)
                       cout<<"Co "<<dem<<" SV co DRL toi da\n";
                   else
                       cout<<"Khong co SV co DRL toi da\n";
               }
               else
                   cout<<"Chua cap nhat thong tin\n";
               break;
           }
           case 5:
           {
               if(trg.GetSL()>0) {
                   long tongtien=trg.TinhTongTienNVco3SKKNTroLen();
                   if(tongtien>0)
                       cout<<"Tong tien thuong cap cho NV co 3 SKKN tro len la: "<<tongtien<<endl;
                   else
                       cout<<"Khong co NV co 3 SKKN tro len\n";
               }
               else
                   cout<<"Chua cap nhat thong tin\n";
               break;
           }
           case 6:
           {
               if(trg.GetSL()>0)
                   cout<<"DTB cua SV DRL duoi 50 la: "<<trg.TinhDTBCuaSVCoDRLDuoi50()<<endl;
               else
                   cout<<"Chua cap nhat thong tin\n";
               break;
           }
           case 7:
           {
               if(trg.GetSL()>0) {
                   int kt=trg.KiemTraGVChuaCoBaiBao();
                   if(kt==1)
                       cout<<"Truong Khong co GV\n";
                   else if (kt==2)
                       cout<<"Truong co GV chua co Bai Bao\n";
                   else
                       cout<<"Cac GV deu co Bai Bao\n";
               }
               else
                   cout<<"Chua cap nhat thong tin\n";
               break;
           }
           case 8:
           {
               if(trg.GetSL()>0)
                   trg.TimNVCoSKKNNhieuNhat();
               else
                   cout<<"Chua cap nhat thong tin\n";
               break;
           }
           case 9:
           {
               if(trg.GetSL()>0) {
                   trg.SapXepMaSoTangDan();
                   trg.xuat();
               }
               else
                   cout<<"Chua cap nhat thong tin\n";
               break;
           }
           case 10:
           {
               if(trg.GetSL()>0) {
                   string kh;
                   cin.ignore();
                   cout<<"Nhap Khoa Can tim: ";
                   getline(cin, kh);
                   trg.TimDTXSTheoTungKhoa(kh);
               }
               else
                   cout<<"Chua Cap Nhap Thong Tin\n";
               break;
           }
           case 11:
           {
               if(trg.GetSL()>0) {
                   string ms;
                   cin.ignore();
                   cout<<"Nhap Ma So: ";
                   getline(cin, ms);
                   trg.CapNhapThongTinTheoMaSo(ms);
               }
               else
                   cout<<"Chua Cap Nhap Thong Tin\n";
               break;
           default:
               cout<<"Ban Chon sai. Moi chon lai.\n";
               break;
           }
       }
   }while(chon!=0);
   cout<<"Thoat Chuong Trinh..."<<endl;
   return 0;
}

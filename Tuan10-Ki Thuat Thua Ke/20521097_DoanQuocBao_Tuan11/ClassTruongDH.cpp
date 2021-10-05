
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class DTXS
{
protected:
   string maso, hoten, khoa;
   int loai;
public:
   DTXS(string ="",string ="",string ="", int =0);
   string GetMaSo();
   string GetHoTen();
   string GetKhoa();
   int Getloai();
   void SetHoTen(string);
   void SetKhoa(string);
   //cac ham ao
   virtual void nhap();
   virtual void xuat();
   virtual void SetSoBB(int);
   virtual double GetDTB();
   virtual double GetDRL();
   virtual int GetSoBB();
   virtual int GetSoSK();
   virtual void SetDTB(double);
   virtual void SetDRL(double);
   virtual void SetSoSK(int);
   // cac ham ao thuan tuy
   virtual long TinhTienThuong()=0;
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
int DTXS::GetSoBB() {
   return -1;
}
double DTXS::GetDTB(){
   return -1;
}
double DTXS::GetDRL(){
   return -1;
}
int DTXS::GetSoSK() {
   return -1;
}
void DTXS::SetSoBB(int bb) {
   return;
}
void DTXS::SetDTB(double tb) {
   return;
}
void DTXS::SetDRL(double rl){
   return;
}
void DTXS::SetSoSK(int sk){
   return;
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
   long TinhTienThuong();
};
GV::GV(string ms, string ht, string khoa, int sobb):DTXS(ms, ht, khoa, 1), sobb(0){}

int GV::GetSoBB() {
   return sobb;
}
void GV::SetSoBB(int bb) {
   while(bb<0) {
       cout<<"Nhap so bai bao: ";
       cin>>bb;
   }
   sobb=bb;
}
void GV::nhap()
{
   loai=1;
   DTXS::nhap();
   do{
       cout<<"So luong Bai Bao: ";
       cin>>sobb;
   }while(sobb<0);
}
void GV::xuat()
{
   DTXS::xuat();
   cout<<"So bai bao: "<<sobb<<" Tien thuong: "<<TinhTienThuong()<<endl;
}
long GV::TinhTienThuong()
{
   long thuong, them;
   thuong= sobb*20000000;
   them= (sobb>6? 15000000: (sobb>3?1000000:0));
   return them+thuong;
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
   double GetDRL();
   double GetDTB();
   void SetDTB(double);
   void SetDRL(double);
   long TinhTienThuong();
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
   cout<<"\t"<<"DTB: "<<DTB<<"\t"<<"DRL: "<<DRL<<"\t"<<"Tien Thuong: "<<TinhTienThuong()<<endl;
}
long SV::TinhTienThuong()
{
   long thuong = 0;
   if(DRL >= 85)
       thuong = (DTB >9 ? 7000000: (DTB > 8.5?5000000:0));
   return thuong;
}
//------------------------
class NV: public DTXS
{
private:
   int sosk;
public:
   NV(string ="",string ="",string ="", int =0);
   void nhap();
   void xuat();
   long TinhTienThuong();
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
   cout<<"So sk: "<<sosk<<" Tien thuong: "<<TinhTienThuong()<<endl;
}
long NV::TinhTienThuong()
{
   long luong= sosk *3000000;
   if(sosk >=3 )
       luong= sosk *1.2;
   return luong;
}
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
   DTXS *Nhap1();
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
   void Them(DTXS*, int);
   int xoa(string);
   void GhiFile(string);
   void DocFile(string);
   void DocFileDTXS(string);
   void GhiFileDTXS(string);
};

TRUONGDH::TRUONGDH()
{
   pdtxs=NULL;
   sl=0;
}
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
   int l;
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
DTXS *TRUONGDH::Nhap1()
{
   int l;
   DTXS *pdt;
   do {
       cout<<"Nhap loai (1: GV, 2:SV, 3:NV): ";
       cin>>l;
   }while(l<1 || l>3);
   if(l==1)
       pdt=new GV;
   else if (l==2)
       pdt=new SV;
   else
       pdt=new NV;
   pdt->nhap();
   return pdt;
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
           sum+=pdtxs[i]->TinhTienThuong();
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
       // liet ke d/s cac NV co so SKKN max
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

void TRUONGDH::Them(DTXS*pdt, int vt)
{
   DTXS** pnew =new DTXS*[sl+1];
   for(int i=0; i< vt-1; i++)
       pnew[i]= pdtxs[i];
   pnew[vt-1]= pdt;
   for(int i=vt; i<sl+1; i++)
       pnew[i]= pdtxs[i-1];
   delete[]pdtxs;
   pdtxs = pnew;
   sl++;
}

int TRUONGDH::xoa(string ms)
{
   int vt=-1;
   for(int i=0; i<sl; i++)
       if(DoiChuoiInHoa(pdtxs[i]->GetMaSo())== DoiChuoiInHoa(ms))
   {
       vt = i;
       break;
   }
   if(vt!=-1)
   {
       DTXS**pnew=new DTXS*[sl-1];
       for(int i=0; i<vt; i++)
           pnew[i]=pdtxs[i];
       for(int i=vt; i<sl-1; i++)
           pnew[i]= pdtxs[i+1];
       delete[]pdtxs;
       pdtxs=pnew;
       sl--;
   }
   else
       cout<<"Khong tim thay DTXS co Ma So "<<ms<<endl;
   return vt;
}
void TRUONGDH::GhiFile(string tenfile)
{
   string nd;
   ofstream outputFile(tenfile);
   if(!outputFile.fail())
   {
       cout<<"Nhap ND File(bam ~ de ket thuc): ";
       while(1)
       {
           getline(cin, nd);
           if(nd.back()!='~')
               outputFile<<nd<<endl;
           else
           {
               nd.back()='\0';
               outputFile<<nd;
               break;
           }
       }
       outputFile.close();
       cout<<"Da ghi File thanh cong\n";
   }
   else
       cout<<"Loi tao File\n";
}

void TRUONGDH::DocFile(string tenfile)
{
   string nd;
   ifstream inputFile(tenfile);
   if(!inputFile.fail())
   {
       while(getline(inputFile, nd))
           cout<<nd<<endl;
       inputFile.close();
       cout<<"Da doc file thanh cong\n";
   }
   else
       cout<<"Loi doc file\n";
}
void TRUONGDH::DocFileDTXS(string tenfile)
{
   ifstream inputFile(tenfile);
   if(!inputFile.fail())
   {
       inputFile>>sl;
       if(sl>0)
       {
           pdtxs=new DTXS*[sl];
           string ms, ht, kh;
           int l, bb, sk;
           double tb,rl;
           long tt;
           for(int i=0;i<sl; i++)
           {
               inputFile>>ms;
               inputFile>>ht;
               inputFile>>kh;
               inputFile>>l;
               if(l==1)
               {
                   inputFile>>bb;
                   pdtxs[i]=new GV(ms, ht, kh, bb);
               }
               else if(l==2)
               {
                   inputFile>>tb;
                   inputFile>>rl;
                   pdtxs[i]= new SV(ms, ht, kh, tb, rl);
               }
               else
               {
                   inputFile>>sk;
                   pdtxs[i]= new NV(ms, ht, kh, sk);
               }
               inputFile>>tt;
           }
           cout<<"Da doc file va luu D/S DTXS thanh cong\n";
       }
       else
           cout<<"So luong DTXS phai > 0\n";
       inputFile.close();
   }
   else
       cout<<"Loi doc File\n";
}
void TRUONGDH::GhiFileDTXS(string tenfile)
{
   ofstream outputFile(tenfile);
   if(!outputFile.fail())
   {
       outputFile<<sl<<endl;
       for(int i=0; i<sl; i++)
       {
           outputFile<<pdtxs[i]->GetMaSo()<<"\t"<<pdtxs[i]->GetHoTen()<<"\t"<<pdtxs[i]->GetKhoa()<<"\t"<<pdtxs[i]->Getloai()<<"\t";
           if(pdtxs[i]->Getloai()==1)
               outputFile<<pdtxs[i]->GetSoBB()<<"\t";
           else if(pdtxs[i]->Getloai()==2)
               outputFile<<pdtxs[i]->GetDTB()<<"\t"<<pdtxs[i]->GetDRL()<<"\t";
           else
               outputFile<<pdtxs[i]->GetSoSK()<<"\t";
           outputFile<<pdtxs[i]->TinhTienThuong()<<"\t";
       }
       outputFile.close();
       cout<<"Da ghi File thanh cong\n";
   }
   else
       cout<<"Loi Ghi File\n";
}
int main()
{
   TRUONGDH trg;
   int chon;
   do {
       cout<<"\n======CHUONG TRINH QUAN LY DOI TUONG XUAT SAC CUA TRUONG======\n";
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
       cout<<"12. Them DTXS moi tai vi tri bat ki\n";
       cout<<"13. Xoa DTXS co ma so tuy y\n";
       cout<<"14. Xoa D/S DTXS\n";
       cout<<"15. Tao File\n";
       cout<<"16. Doc File\n";
       cout<<"17. Doc File va luu D/S DTXS\n";
       cout<<"18. Luu File D/S DTXS\n";
       cout<<"19. Kiem tra khong duoc trung ma so khi nhap lieu\n";
       cout<<"20. Doc-ghi file nhi phan de ma hoa du lieu\n";
       cout<<"0. Thoat Chuong Trinh...\n";
       cout<<"--------------------------------------------------------------\n";
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
               if(trg.GetSL()>0)
               {
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
               if(trg.GetSL()>0)
               {
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
               if(trg.GetSL()>0)
               {
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
               if(trg.GetSL()>0)
               {
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
               if(trg.GetSL()>0)
               {
                   string ms;
                   cin.ignore();
                   cout<<"Nhap Ma So: ";
                   getline(cin, ms);
                   trg.CapNhapThongTinTheoMaSo(ms);
               }
               else
                   cout<<"Chua Cap Nhap Thong Tin\n";
               break;
           }
           case 12:
           {
               DTXS*pdt;
               int vt=1;
               pdt=trg.Nhap1();
               if(trg.GetSL()>0)
               {
                   do {
                       cout<<"Nhap vi tri muon them DTXS tu 1 den "<<trg.GetSL()+1<<": ";
                       cin>>vt;
                   }while(vt<1||vt>trg.GetSL()+1);
               }
               trg.Them(pdt, vt);
               cout<<"D/s DTXS sau khi them DTXS moi tai vi tri thu "<<vt<<" la:\n";
               trg.xuat();
               break;
           }
           case 13:
           {
               if(trg.GetSL()>0)
               {
                   string ms;
                   cout<<"Nhap ma so DTXS muon xoa: ";
                   cin>>ms;
                   int kq=trg.xoa(ms);
                   if(kq!=-1){
                       if(trg.GetSL()>0) {
                           cout<<"D/S STXS sau khi xoa DTXS co ma so "<<ms<<" la\n";
                           trg.xuat();
                       }
                       else
                           cout<<"D/S DTXS rong\n";
                   }
               }
               else
                   cout<<"Chua nhap thong tin\n";
               break;
           }
           case 14:
           {
               if(trg.GetSL()>0) {
                   trg.~TRUONGDH();
                   cout<<"Da xoa toan bo D/S DTXS\n";
               }
               else
                   cout<<"Chua nhap thong tin\n";
               break;
           }
           case 15:
           {
               string tenfile;
               cin.ignore();
               cout<<"Nhap ten File:  ";
               getline(cin, tenfile);
               trg.GhiFile(tenfile);
               break;
           }
           case 16:
           {
               string tenfile;
               cin.ignore();
               cout<<"Nhap ten File: ";
               trg.DocFile(tenfile);
               break;
           }
           case 17:
           {
               string tenfile;
               cin.ignore();
               cout<<"Nhap ten file: ";
               getline(cin, tenfile);
               trg.DocFileDTXS(tenfile);
               break;
           }
           case 18:
           {
               if(trg.GetSL()>0)
               {
                   string tenfile;
                   cin.ignore();
                   cout<<"Nhap ten File: ";
                   getline(cin, tenfile);
                   trg.GhiFileDTXS(tenfile);
               }
               else
                   cout<<"Chua nhap thong tin\n";
               break;
           }
           case 19:
           {
               //Em chua lam duoc
               break;
           }
           case 20:
           {
            // Em chua lam duoc
               break;
           }
       }
   }while(chon!=0);
   cout<<"Thoat Chuong Trinh..."<<endl;
   return 0;
}
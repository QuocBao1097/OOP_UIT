
#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *left;
    TNode *right;
};
typedef TNode *TREE;
void createTree(TREE &T)
{
    T = NULL;
}
TNode *createTNode(int x)
{
    TNode *p = new TNode;
    if(p==NULL) exit(1);
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int InsertNode(TREE &T, int x)
{
    if(T){
        if(T->key==x) return 0;
        if(x<T->key) 
            return InsertNode(T->left, x);
        return InsertNode(T->right, x);
    } 
    T=createTNode(x);
    return 1;
}
// tinh chieu cao cua TREE
int ChieuCao(TREE T)
{
    if(T==NULL)
        return 0;
    int a = ChieuCao(T->left);
    int b = ChieuCao(T->right);
    if(a>b)
        return (a+1);
    return (b+1);
}
//xuat theo tang k
void xuattheotangk(TREE T, int k)
{   
    if(T!=NULL)
    {   
        k--;
        if(T->left!=NULL)
        xuattheotangk(T->left, k);
        if(k==0)
        {
            cout<<T->key<<"\t";
        }
        if(T->right!=NULL)
        xuattheotangk(T->right, k);       
    } 
}
// dem tang thu k
int DemTangThuk(TREE T, int k)
{
    if (T!=NULL)
    {
        k--;
        int a = DemTangThuk(T->left,k);
        int b = DemTangThuk(T->right,k);
        if (k==0)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

int TongTangThuK(TREE T, int k)
{   
    if(T)
    {   
        k--;
        int a=TongTangThuK(T->left, k);
        int b=TongTangThuK(T->right, k);
        if(k==0)
            return a+b+T->key;
        return a+b; 
    }  
    return 0;
}
// xuat theo thu tu tu 0-> h-1
void XuatTheoThuTu(TREE T)
{   
    int h= ChieuCao(T);
    cout<<"\nChieu cao cua cay la:  "<<h<<endl;
    for(int i =0 ; i<= h-1; i++)
    {  
        cout<<"\nGia tri Node tang thu "<<i<<" la: "; xuattheotangk(T, i+1);
        cout<<"\n-So luong: "<<DemTangThuk(T,i+1);
        cout<<"\n-Tong: "<<TongTangThuK(T, i+1);
    }
}
// duyet theo NLR
void NLR(TREE T)
{
     if(T)
     {
         cout<<T->key<<"\t";
         NLR(T->left);
         NLR(T->right);
     }
}

int main()
{
   int A[20]={25,10,3,1,6,5,18,12,13,20,37,29,35,32,50,41};// duyet NLR
   TREE T; 
   createTree(T);
   for(int i=0; i<16; i++)
   InsertNode(T, A[i]);
   cout<<"-Duyet theo NLR: ";NLR(T);
   cout<<"\n=======================";
   XuatTheoThuTu(T);
return 0;
}

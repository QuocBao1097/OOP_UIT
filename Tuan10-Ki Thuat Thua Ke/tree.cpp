
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

void xuattheotangk(TREE T, int k)
{   
    if(T!=NULL)
    {   
        k--;
        if(T->left!=NULL)
        xuattheotangk(T->left, k);
        if(k==0)
            cout<<T->key<<"\t";
        if(T->right!=NULL)
        xuattheotangk(T->right, k);       
    } 
}

void XuatThuTu(TREE T)
{   
    int h= ChieuCao(T);
    cout<<"\nChieu cao cua cay: "<<h<<endl;
    for(int i =0 ; i<= h-1; i++)
    {  
        cout<<"\nTang thu "<<i<<": ";
        xuattheotangk(T, i+1);
    }

}
void LNR(TREE T)
{
     if(T)
     {
         LNR(T->left);
         cout<<T->key<<"\t";
         LNR(T->right);
     }
}
int main()
{
   int A[20]={30, 12, 17, 49, 22, 65, 51, 50, 70, 68};
   TREE T; 
   createTree(T);
   for(int i=0; i<10; i++)
   InsertNode(T, A[i]);
   cout<<"-Duyet theo LNR: ";
   LNR(T);
   cout<<endl;
   XuatThuTu(T);
   //printLevelOrder(T);
return 0;
}

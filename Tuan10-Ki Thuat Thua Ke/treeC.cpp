#include <iostream>
using namespace std;
struct Node
{
	Node* pLeft;
	Node* pRight;
	int iX;
};
typedef Node* Tree;
Node* TaoNode(int X)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->pLeft = NULL;
	p->pRight = NULL;
	p->iX=X;
	return p;
}
void ThemNodeVaoCay(Node* p, Tree &c)
{
	if (c == NULL)//nếu cây rỗng
		c = p;
	else //cây khác rỗng
	{
		if (p->iX < c->iX)
			ThemNodeVaoCay(p,c->pLeft);
		else if (p->iX > c->iX)
			ThemNodeVaoCay(p,c->pRight);
		else
			return;
	}
}

void Nhap(Tree &c)
{
	
		int x;
		int A[50]={30, 12, 17, 49, 22, 65, 51, 50, 70, 68};
    	for(int i=0; i<10; i++)
		{ 
		Node* p = TaoNode(A[i]);
		ThemNodeVaoCay(p, c);
		}
}
// void Nhap(Tree &c)
// {
// 		int x;
// 		cout<<"Nhap cay NKTK: "<<endl;
//     	for(int i=0; i<10; i++)
// 		{
// 		scanf("%d",&x);
// 		Node* p = TaoNode(x);
// 		ThemNodeVaoCay(p,c);
// 		}
// }
//875* Viết hàm xuất các nút trên cây theo thứ tự tầng 0 đến tầng h-1 của cây (với h là chiều cao của cây)
int ChieuCaoCay(Tree c)
{
	if (c == NULL)
		return 0;
	int a = ChieuCaoCay(c->pLeft);
	int b = ChieuCaoCay(c->pRight);
	int max = (a>b)?a:b;
	return 1 + max;
}

void XuatTheoTangK(Tree c, int k)
{
	if (c!=NULL)
	{
		k--;
		if (c->pLeft != NULL)
			XuatTheoTangK(c->pLeft,k);
		if (k==0)
			printf("%4d", c->iX);
		if (c->pRight != NULL)
			XuatTheoTangK(c->pRight,k);
	}
}
void Xuat(Tree c)
{
	int h = ChieuCaoCay(c);
	printf ("\nChieu cao cay: %d",h);
	for (int i=0; i<=h-1; i++)
	{
		printf("\n tang %d :", i);
		XuatTheoTangK(c,i+1);
	}
}
int main()
{
	Tree c = NULL;
	Nhap(c);
	printf("\nXuat cac gia tri theo thu tu tang 0 -> h-1: ");
    Xuat(c);
	return 0;
}
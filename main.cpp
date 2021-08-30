#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct NODE
{
	int key;
	NODE* pLeft;
	NODE* pRight;
};
typedef NODE* TREE;
void KhoiTaoTree(TREE& t);
void ThemNODE(TREE& t, int x);
void NLR(TREE t);
void RanDomARR(int* A, int n);
bool SNT(int x);
void InSNT(TREE t);
void InSNTMax(TREE t, int& max);
void InNODEMucK(TREE t, int k);
void TongChanCayConTrai(TREE t, int& s);
void MinCayConPhai(TREE t, int& x);
void MaxCayConTrai(TREE t, int& x);
int DemNodeNhoHonX(TREE t, int x);
int DemNodeLonHonXNhoHonY(TREE t, int x, int y);
void menu(TREE& t);
int main()
{
	TREE t;
	KhoiTaoTree(t);
	menu(t);
}
void KhoiTaoTree(TREE& t)
{
	t = NULL;
}
void ThemNODE(TREE& t, int x)
{
	if (t == NULL)
	{
		NODE* p = new NODE;
		p->key = x;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x < t->key)
			ThemNODE(t->pLeft, x);
		if (x > t->key)
			ThemNODE(t->pRight, x);

	}
}
void NLR(TREE t)
{
	if (t != NULL)
	{

		cout << t->key << " ";
		NLR(t->pLeft);
		NLR(t->pRight);

	}
}
void RanDomARR(int* A, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 + 1;

		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] != A[j])
				continue;
			else
			{
				A[i] = rand() % 100;
				j = i;
			}
		}
	}
}
bool SNT(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
void InSNT(TREE t)
{
	if (t != NULL)
	{
		if (SNT(t->key))
			cout << t->key << " ";
		InSNT(t->pLeft);
		InSNT(t->pRight);
	}
}
void InSNTMax(TREE t, int& max)
{
	if (t != NULL)
	{
		if ((SNT(t->key) == true) && (t->key > max))
			max = t->key;
		InSNTMax(t->pLeft, max);
		InSNTMax(t->pRight, max);
	}
}
void InNODEMucK(TREE t, int k)
{
	if (t == NULL)
		return;
	if (k == 1)
		cout << t->key << " ";
	else
	{
		InNODEMucK(t->pLeft, k - 1);
		InNODEMucK(t->pRight, k - 1);
	}
}
void TongChanCayConTrai(TREE t, int& s)
{
	if (t == NULL)
		return;
	else
	{
		if ((t->key % 2) == 0)
			s = s + t->key;
		TongChanCayConTrai(t->pLeft, s);
		TongChanCayConTrai(t->pRight, s);
	}
}
void MinCayConPhai(TREE t, int& x)
{
	if (t == NULL)
		return;
	else
	{
		if (t->key < x)
			x = t->key;
		MinCayConPhai(t->pLeft, x);
	}
}
void MaxCayConTrai(TREE t, int& x)
{
	if (t == NULL)
		return;
	else
	{
		if (t->key > x)
			x = t->key;
		MaxCayConTrai(t->pRight, x);
	}
}
int DemNodeNhoHonX(TREE t, int x)
{
	if (t == NULL)
		return 0;
	else
	{
		if (t->key < x)
			return 1 + DemNodeNhoHonX(t->pLeft, x) + DemNodeNhoHonX(t->pRight, x);
		return DemNodeNhoHonX(t->pLeft, x) + DemNodeNhoHonX(t->pRight, x);
	}
}
int DemNodeLonHonXNhoHonY(TREE t, int x, int y)
{
	if (t == NULL)
		return 0;
	else
	{
		if ((t->key > x) && (t->key < y))
			return 1 + DemNodeLonHonXNhoHonY(t->pLeft, x, y) + DemNodeLonHonXNhoHonY(t->pRight, x, y);
		return DemNodeLonHonXNhoHonY(t->pLeft, x, y) + DemNodeLonHonXNhoHonY(t->pRight, x, y);
	}
}
void menu(TREE& t)
{
	while (true)
	{
		cout << "\n\t==========MENU==========";
		cout << "\n\t1.Nhap vao BST bang mang phat sinh ngau nhien va duyet cay theo dang NLR";
		cout << "\n\t2.In cac so nguyen to trong cay";
		cout << "\n\t3.In ra so nguyen to lon nhat tren cay";
		cout << "\n\t4.In ra node o muc K nhap tu ban phim";
		cout << "\n\t5.Tinh tong cac node chan cay con trai";
		cout << "\n\t6.In ra phan tu nho nhat cay con phai";
		cout << "\n\t7.In ra phan tu lon nhat cay con trai";
		cout << "\n\t8.Dem so node co gia tri nho hon x";
		cout << "\n\t9.Dem so node co gia tri lon hon x va nho hon y";
		cout << "\n\t0.Thoat";
		cout << "\n\t==========END==========";
		int lc;
		cout << "\nNhap lua chon : ";
		cin >> lc;
		if (lc == 1)
		{
			int n;
			cout << "Nhap so luong phan tu : ";
			cin >> n;
			int* A = new int[n];
			RanDomARR(A, n);
			cout << "Mang ban dau : ";
			for (int i = 0; i < n; i++)
				cout << A[i] << " ";

			for (int i = 0; i < n; i++)
				ThemNODE(t, A[i]);
			cout << "\nDuyet NLR : ";
			NLR(t);
			system("pause");
		}
		if (lc == 2)
		{
			InSNT(t);
		}
		if (lc == 3)
		{
			int mx = -1;
			InSNTMax(t, mx);
			if (mx == -1)
				cout << "Khong co SNT";
			else cout << "So Nguyen To lon nhat trong cay : " << mx;

		}
		if (lc == 4)
		{
			int k;
			cout << "Nhap muc k : ";
			cin >> k;
			cout << "Cac node o muc k : "; InNODEMucK(t, k);
		}
		if (lc == 5)
		{
			int s = 0;
			TongChanCayConTrai(t->pLeft, s);
			cout << "Tong cac node chan ben cay con trai : " << s;
		}
		if (lc == 6)
		{
			int MinRight = (t->pRight)->key;
			MinCayConPhai(t->pRight, MinRight);
			cout << "Phan tu nho nhat cay con phai : " << MinRight;
		}
		if (lc == 7)
		{
			int MaxLeft = (t->pLeft)->key;
			MaxCayConTrai(t->pLeft, MaxLeft);
			cout << "Phan tu lon nhat cay con trai : " << MaxLeft;
		}
		if (lc == 8)
		{
			int count = 0;
			int x;
			cout << "Nhap gia tri x : ";
			cin >> x;
			count = DemNodeNhoHonX(t, x);
			cout << "So node co gia tri nho hon x : " << count;
		}
		if (lc == 9)
		{
			int count = 0;
			int x, y;
			cout << "Nhap gia tri x : ";
			cin >> x;
			cout << "Nhap gia tri y : ";
			cin >> y;
			count = DemNodeLonHonXNhoHonY(t, x, y);
			cout << "So node co gia tri lon hon x va nho hon y : " << count;
		}
		if (lc == 0)
			break;
	}
}
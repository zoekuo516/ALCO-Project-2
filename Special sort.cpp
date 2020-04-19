#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int odd(int num) 
{
	if (abs(num % 2) == 1)//判斷基數且防止餘數為負
	{
		return num;
	}
}
bool cmp(int a, int b) 
{
	if (a % m != b % m)
	{
		return a % m < b % m; //n%m的值小的在前大的在後
	}
	if (odd(a) != odd(b))
	{
		return odd(a); //餘數相同奇數在前偶數在後
	}
	if (odd(a))
	{
		return a > b; //都是奇數大的在前小的在後
	}
	return a < b; //剩下的都是偶數小的在前大的在後
}
int main() {
	int a[10001];
	while (cin >> n >> m) 
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}
	}
	system("pause");
	return 0;
}

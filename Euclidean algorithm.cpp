#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int num1, num2, result;
	while (cin >> num1 >> num2)
	{
		while (num1 != 0 && num2 != 0)
		{
			if (num1 >= num2)
				num1 = num1 % num2;
			else if (num2 > num1)
				num2 = num2 % num1;
		}
		if (num1 >= num2)
			cout << num1 << endl;
		else
			cout << num2 << endl;
	}
	system("pause");
	return 0;
}

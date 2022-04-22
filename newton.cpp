#include <iostream>
#include <math.h>
using namespace std;
double function(int array[], int size, int x)
{
	int sum = 0, temp = 1;
	for (int i = 0; i <= size - 1; i++)
	{
		for (int j = 1; j <= size - 1 - i; j++)
		{
			temp = temp * x;
		}
		sum = sum + temp * array[i];
		temp = 1;
	}
	return sum;
}
int main()
{
	system("chcp 65001");
	int Len = 0, F[100], f[100];
	double X[100];
	while (true)
	{
		cout << "輸入最高次數:";
		cin >> Len;
		Len++;
		for (int i = 0; i <= Len - 1; i++)
		{
			f[i] = 1;
		}
		for (int i = 0; i <= Len - 1; i++)
		{
			cout << Len - i - 1 << "次方之係數:";
			cin >> F[i];
		}
		for (int i = Len - 1, I = 0; i >= 0; i--, I++)
		{
			f[I] = F[I] * i;
		}
		X[0] = 5;
		int counter = 0;
		for (int i = 0; i <= 100; i++)
		{
			if (function(F, Len, X[i]) != 0)
			{
				X[i + 1] = X[i] - (function(F, Len, X[i]) / function(f, Len - 1, X[i]));
				counter++;
			}
			else
			{
				break;
			}
		}
		cout << X[counter] << endl;
		cout << "如果想重新請輸入1,結束輸入2" << endl;
		int a;
		cin >> a;
		if (a == 1)
		{
			continue;
		}
		else if (a == 2)
		{
			break;
		}
	}
}

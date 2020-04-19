#include<iostream>
using namespace std;

int matrix[50][50];
void max(int vertex)
{
	int max_num = 0;
	int count[vertex] = { 0 };
	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex; j++)
		{
			if (matrix[i][j] == 1)
			{
				count[i]++;
			}
		}
	}
	for (int i = 0; i < vertex; i++)
	{
		if (count[i] > max_num)
		{
			max_num = count[i];
		}
	}
	cout<<max_num<<endl;
}

void edge_value(int x,int y)
{   
	matrix[x][y] = matrix[y][x] = 1;
	;
}

int main(){
	int vertex, edge;
	cin >> vertex >> edge;
	int a[edge], b[edge];
	for (int i = 0; i < edge; i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < edge; i++)
	{
		edge_value(a[i], b[i]);
	}
	max(vertex);
	
	system("pause");
	return 0;
} 

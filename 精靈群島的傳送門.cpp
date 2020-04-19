#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

/*
有N個島嶼
建造足夠的傳送門使得這N個島嶼可以通過傳送門相互連通
---
魔法設備的等級(為正整數)。
使用魔法設備等級為t，則島嶼i與j的傳送門成本為C(i,j)/t
---
魔法設備
等級為1的設備成本為X,等級為t的設備的成本為t*X。
等級上限為T。
一台魔法設備可以用來建造所有的傳送門。
---
建造的總成本
[魔法設備成本t*X]+[建造傳送門的成本總和C(i,j)/t]
---
應投資等級多高的魔法設備?
在那些島嶼與島嶼之間建造傳送門?
>>最低的成本達成讓N個島嶼能通過傳送門相互連通<<
*/

int find(vector<int> vec, int target) {//看vertex裡面有沒有target這個值，如果有的畫就回傳他的index
	vector<int>::iterator begin = vec.begin();
	vector<int>::iterator end = vec.end();
	vector<int>::iterator it;
	for (it = begin; it != end; it++) {
		if (*it == target)
			return it - begin;
	}
	return -1;
}

struct Edge//有三個變數的結構
{
	int A;
	int B;
	int C;
};

int main() {
	vector<int> Vertex;
	vector<Edge> Ans;

	//N = 島嶼的數量
	//M = 可建造傳送門的組合總數
	//T = 魔法設備的等級上限
	//X = 等級一魔法設備之價格
	int N, M, T, X;
	cin >> N >> M >> T >> X;

	int** map;//哪些地方可以蓋橋，N*N的大小
	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[M];

	/*int** m_;
	m_ = new int* [N];
	for (int i = 0; i < N; i++)
		m_[i] = new int[M];
	*/
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = 0;

	//接下來的M行，每一行有三個整數i, j, C(i,j)
	//表示島嶼i與j之間可建造傳送門，建造的基礎成本為C(i,j)
	for (int i = 0; i < M; i++) {
		int tempA, tempB, tempC;
		cin >> tempA>> tempB;
		if (find(Vertex, tempA) == -1)//裡面存的是所有島的編號
			Vertex.push_back(tempA);
		if (find(Vertex, tempB) == -1)
			Vertex.push_back(tempB);
		cin >> tempC;
		if (tempA == 0 || tempB == 0|| tempC == 0) {
			cout << "輸入不能有0!!!這個程式會壞掉" << endl;
			return 0;
		}

		map[find(Vertex, tempA)][find(Vertex, tempB)] = map[find(Vertex, tempB)][find(Vertex, tempA)]=tempC;

	}

	/* * * *	Prim's Algorithm	* * * */
	vector<int> Vert_A, Vert_B;
	int sum = 0;

	//Pick a singleton V'屬於V arbitrarily
	Vert_B.push_back(0);//看現在哪座島是通的
	for(int i=1;i<Vertex.size();i++)
		Vert_A.push_back(i);//看那些島還沒走過

	//while V!=V' do
	while(Vertex.size()!= Vert_B.size()) {//如果走到的點還不是全部的點的話那我就繼續做
		//Pick minimize w(u,v)
		int minimize=-1;
		int minW_xy[2];
		for (int j = 0; j < Vert_B.size(); j++) {//從走過的點中去看還沒走到的點，找出最輕的值
			for (int k = 0; k < Vert_A.size(); k++) {
				if (Vert_A[k] == -1)//這個點已經被走過了
					continue;
				if (minimize == -1 ||(minimize > map[Vert_B[j]][Vert_A[k]])) {//如果有比現在的值還小的話那我就存
					minimize = map[Vert_B[j]][Vert_A[k]];
					minW_xy[0] = Vert_B[j];
					minW_xy[1] = Vert_A[k];
				}
			}
		}
		Vert_B.push_back(minW_xy[1]);
		Vert_A[minW_xy[0]] = -1;
		Edge temp;//把剛剛做的是先存到這裡
		temp.A = minW_xy[0];
		temp.B = minW_xy[1];
		temp.C = map[minW_xy[0]][minW_xy[1]];
		sum += map[minW_xy[0]][minW_xy[1]];
		Ans.push_back(temp);
	}

	/*
	所求，根據算幾不等式
	[ t*X + C(i,j)/t ] >= 2* [t * X*C(i,j)/t]^(1/2) = 2* [X*C(i,j)]^(1/2)
	等號成立時 t*X = C(i,j)/t
	所以 t = [C(i,j)/X]^(1/2)
	*/
	cout << sqrt(sum / X) << endl << Ans.size()<<endl;

	for (int i = 0; i < Ans.size(); i++) {
		cout << Vertex[Ans[i].A] << " " << Vertex[Ans[i].B] << endl;
	}

	/*
	**輸出說明:**
	第一行一個整數t>>投資的魔法設備等級t。
	第二行一個整數m>>總共建造的傳送門數目m。
	接下來m行每一行包含兩個數字i, j，表示要在島嶼i與j之間建立傳送門
	*/

	delete[] map;

	system("pause");
	return 0;
}

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX=30000;
ofstream f;
int m[MAX];
int num=MAX;
void solves()
{
	for(int i=1;i<=MAX;i++){
	m[i]=i;
	}
	
	while(num--){
		int ans = rand() % num + 1;
		cout<<m[ans]<<" ";
		int tmp =  m[ans];
		m[ans] = m[num];
		m[num] = tmp;
		num--;
	}
}
//int mangrand()
//{
//	//srand(time(NULL));
//	int a = rand() % n ;
//    int t=m[a];
//    m[a]=m[MAX-1];
//	m[MAX-1]=t;
//    n--;
//    
//    return t;
//}
int main()
{
	
	ofstream f;
	f.open("matcngaunhien.txt",ios::out);
	f<<MAX<<"\n";
solves();
	for(int i=1;i<=MAX;i++)
	{
	
	f<<m[i]<<"  ";
	}
	f.close();
}


#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>   
#include <queue> 
using namespace std;

int processInter(int n){
	int arr[100]={0};
	arr[1]=1;arr[2]=2;
	for (int i=3;i <= n;i++) //̨�׵�һ��Ϊ1�֣��ڶ���Ϊ2�֣�����nȡ�Ⱥ�.
	{ arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n];
}

int array[100]={0};//�ݹ�� ȫ������
int processRecur(int n){
	if (n == 1) return array[1]=1;//�Ƚ�ֵ�������飬�ٷ��ء�
	if (n == 2) return array[2]=2;
	if (array[n] != 0) return array[n];
	return array[n]=processRecur( n-1)+processRecur( n-2);
}

int  main(){
	int maxStep=10;
	cout<< "������processInter(10)="<< processInter(maxStep)<<endl;
	cout<< "�ݹ��processRecur(10)="<<processRecur(maxStep) <<endl;
	system("pause");
}
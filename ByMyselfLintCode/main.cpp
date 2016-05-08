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
	for (int i=3;i <= n;i++) //台阶第一步为1种，第二步为2种，所以n取等号.
	{ arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n];
}

int array[100]={0};//递归版 全局数组
int processRecur(int n){
	if (n == 1) return array[1]=1;//先将值赋给数组，再返回。
	if (n == 2) return array[2]=2;
	if (array[n] != 0) return array[n];
	return array[n]=processRecur( n-1)+processRecur( n-2);
}

int  main(){
	int maxStep=10;
	cout<< "迭代版processInter(10)="<< processInter(maxStep)<<endl;
	cout<< "递归版processRecur(10)="<<processRecur(maxStep) <<endl;
	system("pause");
}
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

int getMidIndex(vector<int> &nums,int low,int high){
	int tmp=nums[low];
	while(low<high){
		while(low<high&&nums[high]>=tmp){
			high--;
		}
		nums[low]=nums[high];

		while(low<high&&nums[low]<tmp){
			low++;
		}
		nums[high]=nums[low];
	}
	nums[low]=tmp;// 中轴元素归位,
	return low; // 返回中轴的位置
}

void quickSort(vector<int> &nums,int low,int high){
	if(low<high){
		int mid=getMidIndex(nums,low,high); 
		quickSort(nums,low,mid);
		quickSort(nums,mid+1,high);
	}
} 

int median(vector<int> &nums) {
	int len=nums.size();
	if(len==0) return 0;
	quickSort(nums,0,len-1);
	return nums[(len-1)/2];
}


int  main(){
	int arr[]={4,5,1,2,3};
	int num=sizeof(arr)/sizeof(arr[0]);
	vector<int> nums(arr,arr+num);
	cout<< "median(nums)="<< median(nums)<<endl;
	system("pause");
}
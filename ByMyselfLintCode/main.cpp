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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int val){
		this->val=val;
		this->left = this->right=this->next = NULL;
	}
};

int GetDepth(TreeNode *pRoot)  {   //求二叉树的深度  
	if (pRoot == NULL)  return 0;  
	int leftDepth=GetDepth(pRoot->left);
	int rightDepth=GetDepth(pRoot->right);
	return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);  
}  

int GetWidth(TreeNode *pRoot)  {   //求二叉树的宽度,定义为具有最多结点数的层中包含的结点数.
	if (pRoot == NULL)    return 0;  

	queue<TreeNode *> myQueue;//队列，层次遍历的思路  
	myQueue.push(pRoot);//将根节点入队列  
	TreeNode *pCur = NULL;  //while内层循环 取出队列头元素 

	int nLastLevelWidth = 1;//记录上一层的宽度//已加入根节点  
	int nTempLastLevelWidth = 1;//用于跳出while内层循环//已加入根节点
	int nCurLevelWidth = 0;//记录当前层的宽度//后面有myQueue.size();   
	int nWidth = 1;//二叉树的宽度,1用于max函数初始比较//空树返回0，单根节点返回1,

	while (!myQueue.empty())  {//队列不空  
		nTempLastLevelWidth = nLastLevelWidth;  
		while (nTempLastLevelWidth != 0)  	{ //用于跳出while内层循环//已加入根节点 
			pCur = myQueue.front();//取出队列头元素  
			myQueue.pop();//将队列头元素出对  
			nTempLastLevelWidth--; 

			if (pCur->left != NULL)  myQueue.push(pCur->left);  
			if (pCur->right != NULL)  myQueue.push(pCur->right);   
		}  

		nCurLevelWidth = myQueue.size();  
		nWidth = max(nCurLevelWidth , nWidth);//当前层最多的节点数
		nLastLevelWidth = nCurLevelWidth;//进行下层求宽度  
	}  

	return nWidth;  
}  

int  main(){
	TreeNode* root=new TreeNode(0);//test1
	root->left=new TreeNode(1);
	root->right=new TreeNode(2);

	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);

	root->right->left=new TreeNode(5);
	// root->right->right=new TreeNode(6);

	root->left->left->right=new TreeNode(7);//3->right=7
	root->left->left->right->right=new TreeNode(11);//7->right=11
	root->left->right->right=new TreeNode(8);//4->right=8
	root->left->right->right->right=new TreeNode(9);//8->right=9
	root->left->right->right->right->right=new TreeNode(10);//9->right=10
	cout<< "深度GetDepth(root)="<< GetDepth(root) <<endl;
	cout<< "宽度GetWidth(root)="<< GetWidth(root) <<endl;
	system("pause");
}
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

int GetDepth(TreeNode *pRoot)  {   //������������  
	if (pRoot == NULL)  return 0;  
	int leftDepth=GetDepth(pRoot->left);
	int rightDepth=GetDepth(pRoot->right);
	return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);  
}  

int GetWidth(TreeNode *pRoot)  {   //��������Ŀ��,����Ϊ������������Ĳ��а����Ľ����.
	if (pRoot == NULL)    return 0;  

	queue<TreeNode *> myQueue;//���У���α�����˼·  
	myQueue.push(pRoot);//�����ڵ������  
	TreeNode *pCur = NULL;  //while�ڲ�ѭ�� ȡ������ͷԪ�� 

	int nLastLevelWidth = 1;//��¼��һ��Ŀ��//�Ѽ�����ڵ�  
	int nTempLastLevelWidth = 1;//��������while�ڲ�ѭ��//�Ѽ�����ڵ�
	int nCurLevelWidth = 0;//��¼��ǰ��Ŀ��//������myQueue.size();   
	int nWidth = 1;//�������Ŀ��,1����max������ʼ�Ƚ�//��������0�������ڵ㷵��1,

	while (!myQueue.empty())  {//���в���  
		nTempLastLevelWidth = nLastLevelWidth;  
		while (nTempLastLevelWidth != 0)  	{ //��������while�ڲ�ѭ��//�Ѽ�����ڵ� 
			pCur = myQueue.front();//ȡ������ͷԪ��  
			myQueue.pop();//������ͷԪ�س���  
			nTempLastLevelWidth--; 

			if (pCur->left != NULL)  myQueue.push(pCur->left);  
			if (pCur->right != NULL)  myQueue.push(pCur->right);   
		}  

		nCurLevelWidth = myQueue.size();  
		nWidth = max(nCurLevelWidth , nWidth);//��ǰ�����Ľڵ���
		nLastLevelWidth = nCurLevelWidth;//�����²�����  
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
	cout<< "���GetDepth(root)="<< GetDepth(root) <<endl;
	cout<< "���GetWidth(root)="<< GetWidth(root) <<endl;
	system("pause");
}
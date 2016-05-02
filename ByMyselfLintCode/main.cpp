#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
#include <stack> 
#include <iostream>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
int maxPathSum(TreeNode *root){
	if(root == NULL) return 0;
	int rootVal=root->val;
	int maxleft=maxPathSum(root->left);
	int maxright=maxPathSum(root->right);

	if(rootVal>0){//加上正数rootVal
		if(maxleft>maxright){
			return  maxleft>=0 ? (rootVal + maxleft) : maxleft;//单点{+1}AC
		}else{
			return maxright>=0 ? (rootVal + maxright) :maxright;
		} 
	}else{//不加上负数rootVal
		if(maxleft>maxright){
			return  maxleft<=0 ? (rootVal + maxleft) : maxleft;//单点{-1}AC
		}else{
			return maxright<=0 ? (rootVal + maxright) :maxright;
		} 
	}


}

int  main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(3);

	cout<< "maxPathSum(root)="<<maxPathSum(root)<<endl;
	system("pause");
}
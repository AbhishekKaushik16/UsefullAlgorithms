#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node* left = NULL;
	Node* right = NULL;
};
struct Node* newNode(int x){
	struct Node* temp = new Node();
	temp->val = x;
	return temp;
}
struct Node* insert(struct Node* root,int x){
	if(root == NULL)
		root = newNode(x);
	else if(root->val > x)
		root->left = insert(root->left,x);
	else 
		root->right = insert(root->right,x);
	return root;
}
void inorder(struct Node* root){
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}
void inorderS(struct Node* root,vector<int> &arr){
	if(root == NULL)
		return ;
	inorderS(root->left,arr);
	arr.push_back(root->val);
	inorderS(root->right,arr);
}
bool searchBST(struct Node* root,int x){
	if(root==NULL || root->val == x){
		return root;
	}
	if(root->val > x)
		return searchBST(root->left,x);
	return searchBST(root->right,x);
}
void isThere(struct Node* root,int x){
	if(searchBST(root,x))
		printf("%d is present in the BST\n",x);
	else if(root==NULL)
		printf("BST is empty\n"); 
	else 
		printf("%d is not present in the BST\n",x);
}
void printArray(vector<int> arr){
	for(auto it = arr.begin();it!=arr.end();++it)
		printf("%d ",*it);
	cout<<"!\n";
}
struct Node* minValue(struct Node* root){
	struct Node* curr = root;
	while(curr && curr->left !=NULL)
		curr= curr->left;
	return curr;
}
struct Node* deleteNode(struct Node* root,int x){
	if(root == NULL)
		return root;
	if(root->val > x)
		root->left = deleteNode(root->left,x);
	else if(root->val < x) 
		root->right = deleteNode(root->right,x);
	else{
		if(root->left==NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* succ = minValue(root->right);
		root->val = succ->val;
		root->right = deleteNode(root->right,succ->val);
	}
	return root;
}
int main(){
	struct Node* root1 = newNode(50);
	insert(root1,20);
	insert(root1,100);
	insert(root1,80);
	insert(root1,20);
	insert(root1,30);
	insert(root1,70);
	insert(root1,10);
	inorder(root1);
	deleteNode(root1,100);
	//isThere(root1,70);
	vector<int> sorted ;
	inorderS(root1,sorted);
	printArray(sorted);
	return 0;
	
}

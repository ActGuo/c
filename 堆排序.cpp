#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}BTNode;
BTNode *CreatTree(){
	int n,t,i;
	BTNode *root=NULL,*p,*q;
	printf("请输入一组数的长度：");
	scanf("%d",&n);
	int a[n];
	printf("请输入一组数：");
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[i]=t;
	}
	for(i=0;i<n;i++){
		p=(BTNode*)malloc(sizeof(BTNode));
		p->data=a[i];
		p->left=NULL;
		p->right=NULL;
		if(!root){
			root=p;
		}
		else{
			if(!p->left)
			p=p->left;
			else
			p=p->right;
			}
			
		}
	}
int main(){
	BTNode*h;
	h=CreatTree();
	
}

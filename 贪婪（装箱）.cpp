#include<stdio.h>
#include<stdlib.h>
#define v 40
typedef struct{
	int gnumber;
	int gv;
}ElemG;
typedef struct node{
	int gnumber;
	struct node *link;
}GoodsLink;
typedef struct box{
	int surplus;
	GoodsLink*hg;
	struct box* next;
}BoxLink;
ElemG*Puton(int n){
	int vol,c=0;
	ElemG*h,t;
		h=(ElemG*)malloc(n*sizeof(ElemG));
	for(int i=0;i<n;i++){
		h[i].gnumber=i+1;
		printf("请输入第%d个物品的体积",++c);
		scanf("%d",&vol);
		h[i].gv=vol;
	} 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(h[i].gv<h[j].gv){
				t=h[i];
				h[i]=h[j];
				h[j]=t;
			}
		}
	}
	return h;
} 
BoxLink*Putbox(ElemG*g,int n){
	BoxLink *hbox=NULL,*p,*hg,*tail;
	GoodsLink*newg,*q;
	for(int i=0;i<n;i++){
		for(p=hbox;p&&p->surplus<g[i].gv;p=p->next);
		if(!p){
			p=(BoxLink*)malloc(sizeof(BoxLink));
			p->next=NULL;
			p->hg=NULL;
			p->surplus=v;
			if(!hbox)
				hbox=tail=p;
			else
				tail=tail->next=p;
		}
		p->surplus-=g[i].gv;
		newg=(GoodsLink*)malloc(sizeof(GoodsLink));
		newg->gnumber=g[i].gnumber;
		if(!p->hg){
			q=p->hg=newg;
			q->link=NULL;
		}
		else
		q=q->link=newg;
		q->link=NULL;
	}
	return hbox;
}
void print(BoxLink*h){
	int i=0;
	BoxLink*p;
	GoodsLink*q;
	for(p=h;p;p=p->next){
		printf("这是第%d个箱子，它中放的物品编号为：",++i);
		for(q=p->hg;q;q=q->link){
			printf("%d",q->gnumber);
		}
	}
}
int main(){
	int n;
	ElemG*g;
	BoxLink*h;
	printf("请输入物品的个数：");
	scanf("%d",&n);
	g=Puton(n);
	h=Putbox(g,n);
	print(h);	
}

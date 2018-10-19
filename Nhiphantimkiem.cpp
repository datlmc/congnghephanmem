#include<stdio.h>
#include<conio.h>
#define MAX 20
//#define inputfile1 "C:/Users/Administrator/Downloads/Programs/LTDT/Graph/DFS.txt"
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
int DocMaTranKe(GRAPH &g){
	FILE* f;
	f=fopen("Open.txt","rt");
	if(f==NULL){
		printf("/nKhong mo duoc file/n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i=0; i<g.n; i++)
		for(j=0; j<g.n; j++){
			fscanf(f, "%d", &g.a[i][j]);
		}
	fclose(f);
	return 1;
}
void XuatMaTranKe(GRAPH g){
	printf("so dinh cua ma tran la %d\n",g.n);
	printf("Ten cac dinh lan luot tu 0 den %d\n", g.n-1);
	printf("Ma tran ke cua do thi nay la:\n");
	for(int i=0; i<g.n; i++){
		printf("\t");
		for(int j=0; j<g.n; j++){
			printf("%3d", g.a[i][j]);
		}
	printf("\n");
	}		
}
int LuuVet[MAX];
int ChuaXet[MAX];
void DFS(int v, GRAPH g){	//ham xet tai dinh v cua do thi g
	ChuaXet[v] = 1;	//gan gia tri dinh v trong mang ChuaXet la 1
	printf("%3d", v);
	int u;
	for(u=0; u<g.n; u++){
		if(g.a[v][u] != 0 && ChuaXet[u] == 0){
		//Xem xet co canh nao noi tu dinh v den dinh u trong do thi khong va dinh u da xet duyet hay chua
		//Neu co canh noi tu dinh v den dinh u va dinh u chua duoc xet hay duyet den thi tien hanh duyet dinh u
			LuuVet[u] =v;
			DFS(u,g);	//tien hanh nhay den dinh u va xet duyet dinh u
		}
	}
}
void duyetTheoDFS(int S, int F, GRAPH g){
	int i;
	FILE* fout;
	fout = fopen("Closed.txt", "w");
	for(i=0;i<g.n;i++){
		ChuaXet[i]=0;
		LuuVet[i]=-1;
	}
	printf("DFS: ");
	DFS(S,g);
	if(ChuaXet[F]==1){
		fprintf(fout, "Duong di tu dinh %d den dinh %d duyet theo chieu sau la: \n", S, F);
		i=F;
		fprintf(fout, "%d",F);
		while(i != S){
			i=LuuVet[i];
			fprintf(fout, " <- %3d ",i);		
		}
		printf("\nDa xu ly xong!\nMoi ban kiem file Closed.txt o cung vi tri voi file *.cpp!");
	}
	else printf("\nKhong co duong di tu dinh %d den dinh %d",S,F);
}
int main(){
	DOTHI g;
	int a, b;	//Khai bao 2 bien, a la ten dinh dau, b la ten dinh cuoi
	if(DocMaTranKe(g)==1){
		printf("\nDuoc file thanh cong\n");		
		XuatMaTranKe(g);
		do{
			printf("Nhap dinh dau: ");	scanf("%d", &a);	//nhap ten dinh dau
		}while(a<0 || a>=g.n);
		do{
			printf("Nhap dinh cuoi: ");	scanf("%d", &b);	//nhap ten dinh cuoi
		}while(b<0 || b>=g.n);
		duyetTheoDFS(a, b, g);
		printf("\n");
	}
	return 0;
}

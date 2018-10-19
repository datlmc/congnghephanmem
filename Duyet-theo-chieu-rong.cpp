#include<stdio.h>
#include<conio.h>
#define MAX 20
typedef	struct	GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;
struct	QUEUE{
	int size;
	int array[MAX];
};
int	DocMaTranKe(GRAPH &g){
	FILE* f;
	f=fopen("Open.txt", "rt");
	if(f==NULL){
		printf("Khong mo duoc file!/n");
		return 0;
	}
	fscanf(f,"%d", &g.n);
	int i,j;
	for(i=0; i<g.n; i++)
		for(j=0; j<g.n; j++){
			fscanf(f, "%d", &g.a[i][j]);
		}
	fclose(f);
	return 1;
}
void	XuatMaTranKe(GRAPH g){		//Xuat ma tran
	printf("So dinh cua ma tran la: %d\n", g.n);
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
void	KhoiTaoQueue(QUEUE &Q){		//Khoi tao Queue
	Q.size = 0;
}
int DayGiaTriVaoQueue(QUEUE &Q, int value){
	if(Q.size + 1 >= 100)
		return 0;
	Q.array[Q.size]= value;
	Q.size ++;
	return 1;
}
int LayGiaTriRaKhoiQueue(QUEUE &Q, int &value){
	if(Q.size <= 0)
		return 0;
	value = Q.array[0];
	for(int i=0; i<Q.size -1; i++ )
		Q.array[i]=Q.array[i+1];
	Q.size--;
	return 1;
}
int KiemTraQueueRong(QUEUE Q){
	if(Q.size <= 0)
		return 1;
	return 0;
}
void BFS(int v, GRAPH g){
	QUEUE Q;
	KhoiTaoQueue(Q);
	DayGiaTriVaoQueue(Q,v);
	while(!KiemTraQueueRong(Q)){
		LayGiaTriRaKhoiQueue(Q, v);
		for(int u=0; u<g.n; u++){
			if(g.a[v][u] != 0 && ChuaXet[u] == 0){
				DayGiaTriVaoQueue(Q, u);// no se day cac dinh lien quan toi v vao
				if(LuuVet[u] == -1){
					LuuVet[u]=v;// ghi vao luu vet
					ChuaXet[u]=1;// va danh giau da di qua
				}
			}
		}
		printf("%3d", v);
	}
}
void duyetTheoBFS(int S, int F, GRAPH g){
	int i;
	FILE* fout;
	fout = fopen("Close.txt", "w");
	for(i=0; i<g.n; i++){
		ChuaXet[i]=0;
		LuuVet[i]=-1;
	}
	printf("\nBFS: ");
	BFS(S,g);
	printf("\nLuu vet:");
	for(int i=0; i<g.n; i++)
		printf("%3d",LuuVet[i]);
	if(ChuaXet[F] == 1){
		fprintf(fout, "Duong di tu dinh %d den dinh %d la: \n", S, F);
		i=F;
		fprintf(fout, "%d", F);
		while(i != S){
			i=LuuVet[i];
			fprintf(fout, " <- %2d ", i);
		}
		printf("\nDa xu ly xong!\nMoi ban kiem file Close.txt o cung vi tri voi file *.cpp!");
	}
	else printf("\nKhong co duong di tu dinh %d den dinh %d \n", S, F);
	
}
int	main(){
	DOTHI g;
	int a, b;	//Khai bao 2 bien, a la ten dinh dau, b la ten dinh cuoi
	if(DocMaTranKe(g)==1){
		printf("Doc file thanh cong\n");		
		XuatMaTranKe(g);
		printf("Nhap dinh dau: ");	scanf("%d", &a);	//nhap ten dinh dau
		printf("Nhap dinh cuoi: ");	scanf("%d", &b);	//nhap ten dinh cuoi
		duyetTheoBFS(a, b, g);
	}
	printf("\n");
	return 0;
}

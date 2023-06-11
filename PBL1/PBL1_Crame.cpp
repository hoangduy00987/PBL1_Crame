#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
float a[100][100],b[100][100],x[100][100];
int m,n,d,k,c;
char tt;

void xuatmt(float a[][100],int n);
void doc_file();
void xuatmt1(float a[][100],int m,int n);
void XoaDong(float a[][100],int m,int &n);
void matrancon(float a[][100],float b[][100],int n,int k);
float dt(float x[][100],int n);
float nghiem(float a[][100],float b[][100],int m,int n);
float in_kq(float a[][100],float b[][100],int m,int n);
void setcolor(int backgound_color, int text_color);

main() {
	int mn;
	int danhap=0;
	FILE *f;
	do{
	   	setcolor(0,6);
		printf("\t\t\t\t===================================================\n");
		setcolor(0,6);                                              
		printf("\t\t\t\t|\t    Truong Dai hoc Bach Khoa Da Nang      |  \n"); 
		printf("\t\t\t\t|\t       Khoa Cong Nghe Thong Tin           |\n"); 
		printf("\t\t\t\t|                   ___________                   |\n");
		printf("\t\t\t\t|\t                                          |\n");
		printf("\t\t\t\t|PBL1:     DO  AN  LAP  TRINH  TINH  TOAN         |\n");
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t|De tai: 206-Phuong Phap Cramer                   |\n");
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t|GVHD: Do Thi Tuyet Hoa                           |\n");
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t|SVTH: Hoang Khuong Duy - Nguyen Thanh Hung       |\n");
		printf("\t\t\t\t|                                                 |\n");
		printf("\t\t\t\t|Nhom: 5                                          |\n");
		printf("\t\t\t\t|                                                 |\n");
		setcolor(0,6);
		printf("\t\t\t\t===================================================\n\n\n\n");
		setcolor(0,7);
		printf("1--Doc file ma tran\n");
		printf("2--Xoa dong giua cua ma tran\n");
		printf("3--Dua ve ma tran tam giac va tinh det\n");
		printf("4--Ghi ket qua vao file\n");
		printf("5--Dung chuong trinh\n");		
		printf("\nNhap lua chon: "); scanf("%d",&mn);
		switch(mn) {
			case 1:
			doc_file();
			danhap=1;
			break;
			case 2:
			if(danhap==1) {
				XoaDong(a,m,n);	
				danhap=2;			
			} else {
				printf("\nVui long thuc hien B1 truoc khi chon B2\n");
			}
			break;
			case 3:
			if(danhap==2) {
				nghiem(a,b,m,n);
				danhap=3;
			} else {
				printf("\nVui long thuc hien B2 truoc khi chon B3\n");
			}
			break;
			case 4:
				if( danhap==2 || danhap==3 ) {
				in_kq(a,b,m,n);						
				} else {
				printf("\nVui long thuc hien B2 truoc khi chon B4\n");					
				}		
			break;
			case 5: 
				printf("\nKet thuc chuong trinh\n");
				exit(1);
			default:
				printf("Vui long nhap trong khoang tu 1 den 5\n");
			}
			printf("\nNhap phim bat ki de tiep tuc!");
			getch();
			system("cls");
	}	while(mn!=5);
}

void xuatmt(float a[][100],int n) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%.3f\t",a[i][j]);
		} printf("\n");
	}
}

void doc_file() {
	char st[100];
	FILE *f;
	int milk=0;
	printf("\nNhap ten file: "); 
	fflush(stdin);	
	gets(st);
	strcat(st,".txt");
	f=fopen(st,"r");
	if(f!=NULL) {
			fscanf(f,"%d",&n);
			if(n==0) {
			printf("\nFile trong");
			} else {
			printf("\nMa tran vuong cap: %d\n\n",n);		
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(!feof(f)) {
					fscanf(f,"%f",&a[i][j]);	
					milk=1;					
					}				
			 		else {
					milk=2;
					}					
				}				
			}
			fclose(f);
			if(milk==1)	
			xuatmt(a,n);
			else printf("\nDu lieu khong hop le\n");				
			} 			
	} else {
		printf("\nFile khong ton tai");	
	}	
}

void xuatmt1(float a[][100],int m,int n) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			printf("%.2f\t",a[i][j]);
		} printf("\n");
	}
}

void XoaDong(float a[][100],int m,int &n) {
	m=n;	
	for(int i=(n+1)/2;i<=n;i++) {
 		for(int j=1;j<=m;j++) {
 			a[i][j]=a[i+1][j];
 		}		
	} 
	n--; 
	xuatmt1(a,m,n);	
}

void matrancon(float a[][100],float b[][100],int n,int k) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(j==k) b[i][j]=a[i][n+1];
			else b[i][j]=a[i][j];
		}
	}
}

float dt(float x[][100],int n) {
	float m,g=1;
	int k,h,i,j,c=0;	
	for(int i=1;i<=n+1;i++) {
        if (x[i][i] == 0) {
            for (int j = i+1; j <= n+1; j++) {
                if (x[j][i] != 0) {
                    for (int k = i; k <= n+1; k++) {
                        float t = x[i][k];
                        x[i][k] = x[j][k];
                        x[j][k] = t;
                    }
                    break;
                } else {
                	c++;
                	if(c==n) break;
                	else continue;
				}
            }
        }
	for(int j=i+1;j<=n;j++) {
			m=-x[j][i]/x[i][i];
			for(int k=i;k<=n+1;k++)
				x[j][k]+=x[i][k]*m;
		}		
	}
	if(c==n) {
		g=0;
		return g;
	} else {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==j) {
				g*=x[i][j];
				}
			}	
		} 
		return g;	
	}						
}

float nghiem(float a[][100],float b[][100],int m,int n) {	
	float x[100];
	printf("\nMa tran A: \n");	
	xuatmt(a,n);	
	printf("\nMa tran B: \n");
	for(int i=1;i<=n;i++) {
		matrancon(a,b,n,i);
		printf("\n(+)Ma tran B%d:\n",i);
		xuatmt(b,n);
		printf("\n");
	}
	float D=dt(a,n);
	int t=0; 
	if(D==0) { 			
		for(int i=1;i<=n;i++) {
			matrancon(a,b,n,i);	
			x[i]=dt(b,n);						
			if(x[i]==0) t+=x[i];
			else t++;							
		}
		if(t!=0) {
		printf("\nHe phuong trinh vo nghiem\n"); 	
		} 
		else {
		printf("\nHe phuong trinh co vo so nghiem\n"); 	
		}
	}
	else {
		printf("\nMa tran tam giac cua A: \n");
		xuatmt(a,n);
		printf("\n-->det(A)= %8.3f\n",dt(a,n));
		for(int i=1;i<=n;i++) {
			printf("\n(+) Ma tran tam giac B%d: \n",i);
			matrancon(a,b,n,i);
			if(b[i][i]!=0) {	
			dt(b,n);
			xuatmt(b,n);
			printf("\n-->det(%d)=%8.3f\n",i,dt(b,n));							
			} else 	xuatmt(b,n);
			x[i]=dt(b,n)/D;
			if(x[i]==-0.000) {
				x[i]*=-1;
			}
		}
		printf("\nNghiem cua he phuong trinh la: \n");
		for(int i=1;i<=n;i++){
		printf("x[%d] = %8.3f\n", i,x[i]);
		}	
	}
}

float in_kq(float a[][100],float b[][100],int m,int n) {
	FILE *f;
	char p[20];
	printf("Nhap ten file can luu ket qua: ");
	fflush(stdin);
	gets(p);
	strcat(p,".txt");
	f=fopen(p,"w");		
	float x[100];	
	for(int i=1;i<=n;i++) {
		matrancon(a,b,n,i);
	}
	float D=dt(a,n);
	int t=0; 
	if(D==0) { 			
		for(int i=1;i<=n;i++) {
			matrancon(a,b,n,i);	
			x[i]=dt(b,n);						
			if(x[i]==0) t+=x[i];
			else t++;							
		}
		if(t!=0) {
		fprintf(f,"He phuong trinh vo nghiem");	
		} 
		else { 
		fprintf(f,"He phuong trinh co vo so nghiem");	
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			matrancon(a,b,n,i);
			x[i]=dt(b,n)/D;
			if(x[i]==-0.000){
				x[i]*=-1;
			}
		}
		fprintf(f,"Nghiem cua he phuong trinh la: \n");
		for(int i=1;i<=n;i++){
		fprintf(f,"x[%d] = %8.3f\n", i,x[i]); 
		}	
	}
	fclose(f);
}
void setcolor(int backgound_color, int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<unistd.h>
//deklarasi variable global
int pil;

//deklarasi tipe bentukan
typedef struct 
{
	char nama[100];
	int harga;
	int jml;
	int tot;
}struk;

typedef struk
tabstruk[100];

tabstruk str;

//deklarasi array
char menu[100][100] = {"Nasi Putih","Kerupuk","Ayam Goreng","Ayam Bakar","Ayam Sayur","Ayam Balado","Capcay Kering","Orek Tempe","Tahu Goreng","Telur Dadar","Mie Goreng","Bihun Goreng"};
int harga[100]= {3000,1000,7000,7000,7000,7000,4000,3000,2000,2000,3000,3000};
int stok[100]= {100,12,3,13,5,6,9,8,23,12,32,5};

//prosedur
void tampilmenu(){
	int i;
	printf("NO\t|Menu\t\t|Harga\t|Stok\n");
	for(i=0;i<12;i++){
		printf("%d.\t|%s\t|%d\t|%d porsi\n",i+1,menu[i],harga[i],stok[i]);
	}
}

void menuutama(){
	printf("WARTEG SUMBER BERKAH HEGA AGUNG\n");
	printf("_________________________________\n");
	printf("MENU UTAMA\n");
	printf("_________________________________\n");
	printf("1. Tambah Stok\n");
	printf("2. Transaksi\n");
	printf("3. Exit\n\n");
	printf("Pilih Menu = ");
	scanf("%d",&pil);
}

void tambahstok(){
	int p,q;
	tampilmenu();
	printf("Masukan ID Makanan = ");
	scanf("%d",&p);
	printf("Masukan Stok tambahan = ");
	scanf("%d",&q);
	stok[p-1] = stok[p-1]+q;
	system("cls");
	tampilmenu();
	printf("press any key to continue...\n\n");
	getch();
}

void tampilstruk(){
	int i;
	system("cls");
	printf("NO\t|Menu\t\t|Harga\t|Jumlah\t|Total\n");
	for(i=0;i<=sizeof(tabstruk);i++){
		printf("%d\t|%d\t|%d\t|%d\t|%d\n",i+1,str[i].nama,str[i].harga,str[i].jml,str[i].tot);
	}
}

void transaksi(){
	int i=0;
	int l,m,n;
	do{
		system("cls");
		tampilmenu();
		printf("Pilih Menu = ");
		scanf("%d",&m);
		m = m-1;
		printf("Jumlah = ");
		scanf("%d",&n);
		if(n>stok[m]){
			printf("Jumlah Terlalu Banyak\n");
		}else{
			strcpy(str[i].nama,menu[m]);
			str[i].harga = harga[m];
			str[i].jml = n;
			str[i].tot = harga[m]*n;
			stok[m] = stok[m]-n;
			i++;
			printf("Data terinput!\n");
		}
		printf("Input Lagi?(1/0)");
		scanf("%d",&l);
	}while(l==1);
	tampilstruk();
}
//fungsi


//program main
main(){
	int k = 1;
	do{
		system("cls");
		menuutama();
		switch(pil){
			case 1 :
				tambahstok();
				printf("Kembali ke menu utama? (1/0)");
				scanf("%d",&k);
				break;
			case 2 :
				transaksi();
				getch();
				break;
		}
		
	}while(k == 1);
}

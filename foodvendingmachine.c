#include <stdio.h>
#include <stdlib.h>

/*Kasaya giriş için para girişine 7319 yazılması lazım, otomatta ayrı olarak admin girişi diye bir yer yok, normal kullanıcıların göremeyeceği şekilde sadece yetkililerin bilgisiyle girilebilir*/

float kasa=0;
float urun[7][2]={{7,1},{7,3},{7,1.75},{7,0.75},{7,2},{7,1.50},{7,1.25}};

int sor();
int menu();
int adminmenu();
int gunceldurum();
void islem(float miktar, int *birlira, int *ellikurus, int *yirmibeskurus, int *onkurus, float *beskurus);

void islem(float miktar, int *birlira, int *ellikurus, int *yirmibeskurus, int *onkurus, float *beskurus){ 
	
	*birlira=miktar/1.00;
	*ellikurus=(miktar-(*birlira*1.00))/0.50;
	*yirmibeskurus=(miktar-(*birlira*1.00)-(*ellikurus*0.50))/0.25;
	*onkurus=(miktar-(*birlira*1.00)-(*ellikurus*0.50)-(*yirmibeskurus*0.25))/0.10;
	*beskurus=(miktar-(*birlira*1.00)-(*ellikurus*0.50)-(*yirmibeskurus*0.25)-(*onkurus*0.10))/0.05;
	
}
int main() {
	
	system("color 4f");
	system("cls"); 
	menu();
	
	return 0;
}	
int sor(){
	
	char cevap,enter;
	printf("\n\t\t\tBaska bir islem yapmak istiyor musunuz?(E/H): ");
	scanf("%c%c",&enter,&cevap);
	
	if(cevap=='E' || cevap=='e'){
		
		main();
		
	}else if(cevap=='H' || cevap=='h'){
		
		printf("\n\t\t\tYine bekleriz!");
		
	}else{
		
		printf("\n\t\t\tLutfen gecerli bir karakter girin!\n");
		sor();
		
	}
	
}
int adminpanel(){
	
	system("cls");
	int tercih, secim, yeniadet;
	float yenifiyat;
	gunceldurum();
	printf("\n\t\t\tKasadaki para: %.2f\n\n\t\t\t1-Para Cek\n\t\t\t2-Urun Adedi Guncelle\n\t\t\t3-Urun Fiyati Guncelle\n\t\t\t\n\t\t\t0-Cikis\n\n\t\t\tYapmak istediginiz islemi seciniz: ",kasa);
	scanf("%d",&tercih);
	
	if(tercih==1){
		
		float paracek;
		printf("\t\t\tCekmek istediginiz miktari giriniz: ");
		scanf("%f",&paracek);
		
		if(paracek>kasa){
			
		printf("\n\t\t\tLutfen kasayi tekrar kontrol ediniz!\n");
		adminpanel();
			
		}else{
			
		kasa=kasa-paracek;
		printf("\n\t\t\tIslem basarili!\n");
		printf("\n\t\t\tKasadaki para: %.2f\n",kasa);
		sor();
			
		}
		}else if(tercih==2){
			
		printf("\n\t\t\tAdedini guncellemek istediginiz urunu seciniz: ");
		scanf("%d",&secim);
		printf("\t\t\tEklemek istediginiz urun miktarini giriniz: ");
		scanf("%d",&yeniadet);
		
	if(secim>=1 && secim<=7){
		
		if(secim==1 && yeniadet>0){
			
			urun[0][0]=urun[0][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==1 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}if(secim==2 && yeniadet>0){
			
			urun[1][0]=urun[1][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==2 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}if(secim==3 && yeniadet>0){
			
			urun[2][0]=urun[2][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==3 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}if(secim==4 && yeniadet>0){
			
			urun[3][0]=urun[3][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==4 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}if(secim==5 && yeniadet>0){
			
			urun[4][0]=urun[4][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==5 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}if(secim==6 && yeniadet>0){
			
			urun[5][0]=urun[5][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==6 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}if(secim==7 && yeniadet>0){
			
			urun[6][0]=urun[6][0]+yeniadet;
			gunceldurum();
			sor();
			
	}else if(secim==7 && yeniadet<=0){
		
		printf("\n\t\t\tAdet miktari sifirdan buyuk olmalidir!");
		sleep(3);
		adminpanel();
		
	}		
	}
	else{
		
		printf("\n\t\t\tLutfen seciminizi kontrol ediniz!\n");
		sleep(3);
		adminpanel();
	
	}
	}else if(tercih==3){
		
		printf("\n\t\t\tFiyatini guncellemek istediginiz urunu seciniz: ");
		scanf("%d",&secim);
		printf("\t\t\tYeni fiyat miktarini giriniz: ");
		scanf("%f",&yenifiyat);
		
		if(secim>=1 && secim<=7){
		
		if(secim==1 && yenifiyat>0){
			
			urun[0][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==1 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}if(secim==2 && yenifiyat>0){
			
			urun[1][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==2 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}if(secim==3 && yenifiyat>0){
			
			urun[2][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==3 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}if(secim==4 && yenifiyat>0){
			
			urun[3][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==4 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}if(secim==5 && yenifiyat>0){
			
			urun[4][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==5 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}if(secim==6 && yenifiyat>0){
			
			urun[5][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==6 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}if(secim==7 && yenifiyat>0){
			
			urun[6][1]=yenifiyat;
			gunceldurum();
			sor();
			
	}else if(secim==7 && yenifiyat<=0){
		
		printf("\n\t\t\tBedavaya sattirmiyoruz!");
		sleep(3);
		adminpanel();
		
	}		
	}
	else{
		
		printf("\n\t\t\tLutfen seciminizi kontrol ediniz!\n");
		sleep(3);
		adminpanel();
	
	}
	}else if(tercih==0){
		
		exit(0);
		
	}else{
		
		printf("\n\t\t\tLutfen seciminizi kontrol ediniz!\n");
		sleep(3);
		adminpanel();
	
	}		
}
int menu(){
	
	gunceldurum();
	
	float girilenpara, miktar, beskurus;
	int secim, birlira, ellikurus, yirmibeskurus, onkurus;
	
		printf("\n\t\t\tPara girisi: ");
		scanf("%f",&girilenpara); 
		
		if(girilenpara==7319){
			
			adminpanel();
			
		}else{
	
		printf("\t\t\tSeciminizi yapiniz: ");
		scanf("%d",&secim);	

	if(secim>=1 && secim<=7){
		
		if(secim==1 && girilenpara>=urun[0][1] && urun[0][0]>0){
			
			miktar=girilenpara-urun[0][1];
			kasa=kasa+urun[0][1];
			urun[0][0]=urun[0][0]-1;
			
	}else if(girilenpara<urun[0][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();

	}else if(secim==1 && urun[0][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
		
	}else if(secim==2 && girilenpara>=urun[1][1] && urun[1][0]>0){
	
			miktar=girilenpara-urun[1][1];
			kasa=kasa+urun[1][1];
			urun[1][0]=urun[1][0]-1;
			
	}else if(girilenpara<urun[1][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}else if(secim==2 && urun[1][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();

	}else if(secim==3 && girilenpara>=urun[2][1] && urun[2][0]>0){
   	
			miktar=girilenpara-urun[2][1];
			kasa=kasa+urun[2][1];
			urun[2][0]=urun[2][0]-1;
	
	}else if(girilenpara<urun[2][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}else if(secim==3 && urun[2][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();

	 }else if(secim==4 && girilenpara>=urun[3][1] && urun[3][0]>0){
		
			miktar=girilenpara-urun[3][1];
			kasa=kasa+urun[3][1];
			urun[3][0]=urun[3][0]-1;
			
	}else if(girilenpara<urun[3][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}else if(secim==4 && urun[3][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();

	}else if(secim==5 && girilenpara>=urun[4][1] && urun[4][0]>0){
		
			miktar=girilenpara-urun[4][1];
			kasa=kasa+urun[4][1];
			urun[4][0]=urun[4][0]-1;
			
	}else if(girilenpara<urun[4][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}else if(secim==5 && urun[4][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();

	}else if(secim==6 && girilenpara>=urun[5][1] && urun[5][0]>0){
	
			miktar=girilenpara-urun[5][1];
			kasa=kasa+urun[5][1];
			urun[5][0]=urun[5][0]-1;
			
	}else if(girilenpara<urun[5][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}else if(secim==6 && urun[5][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();

	}else if(secim==7 && girilenpara>=urun[6][1] && urun[6][0]>0){
	
			miktar=girilenpara-urun[6][1];
			kasa=kasa+urun[6][1];
			urun[6][0]=urun[6][0]-1;
				
	}else if(girilenpara<urun[6][1]){

	printf("\t\t\tYetersiz para girisi yapildi!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}else if(secim==7 && urun[6][0]==0){

	printf("\n\t\t\tUrunumuz tukenmistir!\n\t\t\tIade edilen para: %.2fTL\n", girilenpara);
	sor();
	
	}
	islem(miktar, &birlira, &ellikurus, &yirmibeskurus, &onkurus, &beskurus);
		
		if(miktar==0){
			
			printf("\t\t\tAfiyet olsun!\n");
			sor();
			
		}else{
			
			printf("\n\t\t\tPara ustu: %.2fTL \n\t\t\t%d adet bir lira \n\t\t\t%d adet elli kurus \n\t\t\t%d adet yirmibes kurus \n\t\t\t%d adet on kurus \n\t\t\t%.f adet bes kurus\n",miktar, birlira,ellikurus,yirmibeskurus,onkurus,beskurus);
			sor();
		
		}
	}
}if(secim>7){
		
		printf("\t\t\tLutfen seciminizi kontrol ediniz!\n");
		printf("\t\t\tIade edilen para: %.2fTL\n", girilenpara);
		sleep(3);
		main();
		
	}
}
int gunceldurum(){
		system("cls");
		printf("\n\t\t\t\t         OTOMAT     \t\n");	
		printf("\t\t\t|\t\t  MENU");
		printf("\t\t\t|\n");
		printf("\t\t\t|---------------------------------------|\n");
		printf("\t\t\t|1-Su	        [Kalan %.f] (%.2fTL) ",urun[0][0],urun[0][1]);
		printf("\t|\n");
		printf("\t\t\t|2-Kola	        [Kalan %.f] (%.2fTL) ",urun[1][0],urun[1][1]); 
		printf("\t|\n");
		printf("\t\t\t|3-Meyve Suyu   [Kalan %.f] (%.2fTL)",urun[2][0],urun[2][1]);
		printf("\t|\n");
		printf("\t\t\t|4-Cubuk Kraker [Kalan %.f] (%.2fTL)",urun[3][0],urun[3][1]);
		printf("\t|\n");
		printf("\t\t\t|5-Biskuvi      [Kalan %.f] (%.2fTL)",urun[4][0],urun[4][1]);
		printf("\t|\n");
		printf("\t\t\t|6-Cikolata     [Kalan %.f] (%.2fTL)",urun[5][0],urun[5][1]);
		printf("\t|\n");
		printf("\t\t\t|7-Gofret       [Kalan %.f] (%.2fTL)",urun[6][0],urun[6][1]);
		printf("\t|\n");
		printf("\t\t\t|---------------------------------------|\n");
}

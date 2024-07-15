#include "Dosya.h"

Dosya DosyaOlustur(){
	Dosya this;
	this=(Dosya)malloc(sizeof(struct DOSYA));
	
	this->yoket=&DosyaYokEt;
	this->bilgi=&dosyaBilgiAl;
	this->adet=&adetBilgiAl;
	return this;
}

void DosyaYokEt(const Dosya this){
	if(this==NULL) 
		return;		
    free(this);
}

void dosyaBilgiAl(const char *dosyaAdi, int *satirSayisi, int *sutunSayisi) {
    FILE *dosya = fopen(dosyaAdi, "r");	
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }
    int satirSayac = 0;
    int sutunSayac = 0;
    int sayac=0;
    char karakter;
	char oncekikarakter=' ';
	
    while ((karakter = fgetc(dosya)) != EOF) {
        if(sayac ==0 && satirSayac== 0 && karakter =='\n')
			continue;
		if(karakter == '\n' && oncekikarakter == '\n')
			continue;
		if(karakter == ' ' && oncekikarakter == '\n')
			continue;
		if(karakter == '\n' && oncekikarakter == ' ' && satirSayac==0)
			sutunSayac--;
        if (karakter == '\n') {
			
            satirSayac++;
            if (satirSayac == 1) {
				sutunSayac++;
                *sutunSayisi = sutunSayac;
            }
        } 
		else if (karakter == ' ' && oncekikarakter != ' ') {         
            sutunSayac++;
        }
		oncekikarakter=karakter;
		sayac++;		
    }   
    fclose(dosya);
    if (satirSayac == 0) {
		satirSayac++;
		*sutunSayisi = sutunSayac;
    } 
	if(oncekikarakter != '\n'){
		satirSayac++;
	}
	
    *satirSayisi = satirSayac;
}

void adetBilgiAl(const char *dosyaAdi,int satir, int sutun, int* bitkisayisi , int* boceksayisi ,int* sineksayisi ,int* piresayisi){	
	FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }
	int bitkisayac=0;
	int boceksayac =0;	
	int sineksayac=0;
	int piresayac=0;	
    int okunansayi;
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            fscanf(dosya, "%d", &okunansayi);
            
            if (okunansayi >= 1 && okunansayi <= 9) {
                bitkisayac++;
            }
			else if (okunansayi >= 10 && okunansayi <= 20) {
                boceksayac++;
            } 
			else if (okunansayi >= 21 && okunansayi <= 50) {
                sineksayac++;
            }
			else if (okunansayi >= 51 && okunansayi <= 99) {
                piresayac++;
            }			
        }
    }	
    fclose(dosya);
	
	*bitkisayisi=bitkisayac;
	*boceksayisi = boceksayac;	
	*sineksayisi=sineksayac;
	*piresayisi=piresayac;	
}
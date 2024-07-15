#include "Habitat.h"

Habitat HabitatOlustur(int satirsayisi,int sutunsayisi, int bitkiadet, int bocekadet,int sinekadet,int pireadet){	
	Habitat this;
	this=(Habitat)malloc(sizeof(struct HABITAT));
	
	this->satirsayisi = satirsayisi;
    this->sutunsayisi = sutunsayisi;
	this->bitkisayisi = bitkiadet;
	this->boceksayisi = bocekadet;	
	this->sineksayisi = sinekadet;
	this->piresayisi = pireadet;	
	this->toplam = satirsayisi*sutunsayisi;
	this->doldur = &habitatDoldur;
	this->yazdir=&habitatYazdir;
	this->yeme=&habitatSavas;
	this->son = &habitatSonyaz;
	this->yoket= &HabitatYokEt;
	
	this->bitkidizisi = (Bitki *)malloc(bitkiadet * sizeof(Bitki));
	this->bocekdizisi = (Bocek *)malloc(bocekadet * sizeof(Bocek));	
	this->sinekdizisi = (Sinek *)malloc(sinekadet * sizeof(Sinek));
	this->piredizisi = (Pire *)malloc(pireadet * sizeof(Pire));
	
	this->matris = (Canli **)malloc(satirsayisi * sizeof(Canli *));
    if (this->matris == NULL) {
        printf("Hafiza ayirma basarisiz.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < satirsayisi; i++) {
        this->matris[i] = (Canli *)malloc(sutunsayisi * sizeof(Canli));
        if (this->matris[i] == NULL) {
            printf("Hafiza ayirma basarisiz.\n");
            exit(EXIT_FAILURE);
        }
    }
    return this;	
}

void habitatDoldur(const Habitat this, const char *dosyaadi) {
    FILE *dosya = fopen(dosyaadi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }
	int bitkisayaci =0;
	int boceksayaci =0;
	int sineksayaci=0;
	int piresayaci=0;
    int sayi;
    for (int i = 0; i < this->satirsayisi; i++) {
        for (int j = 0; j < this->sutunsayisi; j++) {
            fscanf(dosya, "%d", &sayi);
            
            if (sayi >= 1 && sayi <= 9) {
                Bitki bitki = BitkiOlustur("B", sayi);
                this->matris[i][j] = bitki->super;
				this->bitkidizisi[bitkisayaci]=bitki;
				bitkisayaci++;
            } 
			else if (sayi >= 10 && sayi <= 20) {
                Bocek bocek = BocekOlustur("C", sayi);
                this->matris[i][j] = bocek->super;
				this->bocekdizisi[boceksayaci]=bocek;
				boceksayaci++;
            } 
			else if (sayi >= 21 && sayi <= 50) {
                Sinek sinek = SinekOlustur("S", sayi);
                this->matris[i][j] = sinek->super->super;
				this->sinekdizisi[sineksayaci]=sinek;
				sineksayaci++;
            } 
			else if (sayi >= 51 && sayi <= 99) {
                Pire pire = PireOlustur("P", sayi);
                this->matris[i][j] = pire->super->super;
				this->piredizisi[piresayaci]=pire;
				piresayaci++;
            } 
			else {
                this->matris[i][j] = NULL;
            }
        }
    }
    fclose(dosya);
}

void habitatYazdir(const Habitat this) {
	printf("\n");
	system("cls");
    for (int i = 0; i < this->satirsayisi; i++) {
        for (int j = 0; j < this->sutunsayisi; j++) {
            if (this->matris[i][j] != NULL && (this->matris[i][j]->tur == "C"||this->matris[i][j]->tur == "B"||this->matris[i][j]->tur == "P"||this->matris[i][j]->tur == "S")) {
                printf("%s ", this->matris[i][j]->gorunum(this->matris[i][j]));
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}
void habitatSavas(const Habitat this){
	
	int satir = this->satirsayisi;
    int sutun = this->sutunsayisi;
    	
	while(this->toplam > 1){
		for (int i = 0; i < satir; i++) {
			for (int j = 0; j < sutun; j++) {
							
				if (this->matris[i][j] != NULL && (this->matris[i][j]->tur == "C"||this->matris[i][j]->tur == "B"||this->matris[i][j]->tur == "P"||this->matris[i][j]->tur == "S")) {
					Canli avci = this->matris[i][j];
					
					for (int k = 0; k < satir; k++) {
						for (int l = 0; l < sutun; l++) {
							
							if (this->matris[k][l] != NULL && !(i == k && j == l) && (this->matris[k][l]->tur == "C"||this->matris[k][l]->tur == "B"||this->matris[k][l]->tur == "P"||this->matris[k][l]->tur == "S")) {								
								Canli av = this->matris[k][l];
															
								if(avci->tur == "C" && av->tur == "B"){
									av->tur = "x";												
									this->toplam -= 1;
									habitatYazdir(this);
								}
								else if(avci->tur == "C" && av->tur == "P"){									
									av->tur = "x";								
									this->toplam -= 1;
									habitatYazdir(this);
								}
								else if(avci->tur == "C" && av->tur == "S"){
									avci->tur = "x";								
									this->toplam -= 1;
									habitatYazdir(this);
								}
								else if(avci->tur == "C" && av->tur == "C"){
									
									if(avci->sayi > av->sayi){								
										av->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}										
									else if(avci->sayi < av->sayi){										
										avci->tur = "x";										
										this->toplam -= 1;
										habitatYazdir(this);
									}																			
									else{										
										av->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}										
								}								
								else if(avci->tur == "B" && av->tur == "C"){
									avci->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "B" && av->tur == "P"){
									av->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "B" && av->tur == "S"){
									av->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "B" && av->tur == "B"){
									
									if(avci->sayi > av->sayi){										
										av->tur = "x";										
										this->toplam -= 1;
										habitatYazdir(this);
									}										
									else if(avci->sayi < av->sayi){									
										avci->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}																			
									else{										
										av->tur = "x";										
										this->toplam -= 1;
										habitatYazdir(this);
									}
								}
								else if(avci->tur == "P" && av->tur == "B"){
									avci->tur = "x";								
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "P" && av->tur == "C"){
									avci->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "P" && av->tur == "S"){
									avci->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "P" && av->tur == "P"){
									
									if(avci->sayi > av->sayi){										
										av->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}										
									else if(avci->sayi < av->sayi){										
										avci->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);										
									}																			
									else{										
										av->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}
								}
								else if(avci->tur == "S" && av->tur == "B"){
									avci->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);						
								}
								else if(avci->tur == "S" && av->tur == "C"){
									av->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "S" && av->tur == "P"){
									av->tur = "x";									
									this->toplam -= 1;
									habitatYazdir(this);									
								}
								else if(avci->tur == "S" && av->tur == "S"){
									
									if(avci->sayi > av->sayi){										
										av->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}										
									else if(avci->sayi < av->sayi){										
										avci->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}																			
									else{										
										av->tur = "x";
										this->toplam -= 1;
										habitatYazdir(this);
									}
								}							
							}							
						}
					}
				}                
			}
		}
	}		
}

void habitatSonyaz(const Habitat this){
	
	int satir = this->satirsayisi;
    int sutun = this->sutunsayisi;
	
	for (int i = 0; i < satir; i++) {			
		for (int j = 0; j < sutun; j++) {
				
			if(this->matris[i][j] != NULL && (this->matris[i][j]->tur == "C"||this->matris[i][j]->tur == "B"||this->matris[i][j]->tur == "P"||this->matris[i][j]->tur == "S")){
					
				printf("\n");
				system("cls");
				printf("Kazanan: %s : (%d,%d)", this->matris[i][j]->gorunum(this->matris[i][j]),i,j );	
			}
		}										
	}
}

void HabitatYokEt(const Habitat this){
	
	if (this != NULL) {			
		for (int i = 0; i < this->bitkisayisi; i++) {			
			this->bitkidizisi[i]->yoket(this->bitkidizisi[i]);			
		}
		free(this->bitkidizisi);
			
		for (int i = 0; i < this->boceksayisi; i++) {
			this->bocekdizisi[i]->yoket(this->bocekdizisi[i]);
		}
		free(this->bocekdizisi);
			
		for (int i = 0; i < this->sineksayisi; i++) {
			this->sinekdizisi[i]->yoket(this->sinekdizisi[i]);
		}
		free(this->sinekdizisi);
		
		for (int i = 0; i < this->piresayisi; i++) {
			this->piredizisi[i]->yoket(this->piredizisi[i]);
		}
		free(this->piredizisi);
				
        if (this->matris != NULL) {
            for (int i = 0; i < this->satirsayisi; i++) {
                free(this->matris[i]);
            }
            free(this->matris);
        }
        free(this);				
    }
}
#include "Pire.h"

Pire PireOlustur(char* tur,int sayi){
	Pire this;
	this=(Pire)malloc(sizeof(struct PIRE));	
	
	this->super=BocekOlustur(tur,sayi);
	this->super->super->gorunum=&PireGorunum;
	this->gorunum=&PireGorunum;
	this->yoket=&PireYokEt;
	return this;
}

char* PireGorunum(const Canli this) {
	return this->tur;
}

void PireYokEt(const Pire this){
	if(this==NULL) 
		return;			
    this->super->yoket(this->super); 
    free(this);	
}
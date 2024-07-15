#include "Sinek.h"

Sinek SinekOlustur(char* tur, int sayi){
	Sinek this;
	this=(Sinek)malloc(sizeof(struct SINEK));
	
	this->super=BocekOlustur(tur,sayi);
	this->super->super->gorunum=&SinekGorunum;
	this->gorunum=&SinekGorunum;
	this->yoket=&SinekYokEt;
	return this;
}

char* SinekGorunum(const Canli this) {
	return this->tur;
}

void SinekYokEt(const Sinek this){
	if(this==NULL) 
		return;		
	this->super->yoket(this->super); 
    free(this);	
}
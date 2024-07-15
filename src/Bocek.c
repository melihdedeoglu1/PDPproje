#include "Bocek.h"

Bocek BocekOlustur(char* tur,int sayi){
	Bocek this;
	this=(Bocek)malloc(sizeof(struct BOCEK));
	
	this->super = CanliOlustur(tur,sayi);
	this->super->gorunum=&BocekGorunum;
	this->gorunum=&BocekGorunum;
	this->yoket=&BocekYokEt;
	return this;
}

char* BocekGorunum(const Canli this) {
    return this->tur;
}

void BocekYokEt(const Bocek this) {
	if(this==NULL)
		return;	
    this->super->yoket(this->super); 
    free(this);	
}
#include "Bitki.h"

Bitki BitkiOlustur(char* tur, int sayi){
	Bitki this;
	this=(Bitki)malloc(sizeof(struct BITKI));
		
	this->super = CanliOlustur(tur,sayi);
	this->super->gorunum=&BitkiGorunum;
	this->gorunum=&BitkiGorunum;
	this->yoket=&BitkiYokEt;
	return this;
}

char* BitkiGorunum(const Canli this){
	return this->tur;
}

void BitkiYokEt(const Bitki this){
	if(this==NULL) 
		return;	
    this->super->yoket(this->super); 
    free(this);	
}
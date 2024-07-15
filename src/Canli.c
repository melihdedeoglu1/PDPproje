#include "Canli.h"

Canli CanliOlustur(char* tur,int sayi){
	Canli this;
	this=(Canli)malloc(sizeof(struct CANLI));	
	
	this->sayi=sayi;	
	this->tur=tur;	
	this->yoket= &CanliYokEt;
	return this;
}

void CanliYokEt(const Canli this){
	if(this==NULL) 
		return;
	free(this);		
}
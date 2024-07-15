#ifndef HABITAT_H
#define HABITAT_H

#include "stdio.h"
#include "stdlib.h"
#include "Canli.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"
#include "Bitki.h"

struct HABITAT{
	Canli **matris;
	Bitki *bitkidizisi;
	Bocek *bocekdizisi;	
	Sinek *sinekdizisi;
	Pire *piredizisi;
	int boceksayisi;
	int bitkisayisi;
	int sineksayisi;
	int piresayisi;	
	int satirsayisi;
    int sutunsayisi;
	int toplam;	
	void (*doldur)(struct HABITAT*,const char*);
	void (*yazdir)(struct HABITAT*);
	void (*yoket)(struct HABITAT*);
	void (*yeme)(struct HABITAT*);
	void (*son)(struct HABITAT*);
};
typedef struct HABITAT* Habitat;

Habitat HabitatOlustur(int,int,int,int,int,int);
void habitatDoldur(const Habitat, const char*);
void habitatYazdir(const Habitat) ;
void habitatSavas(const Habitat);
void habitatSonyaz(const Habitat);
void HabitatYokEt(const Habitat);

#endif
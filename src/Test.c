#include "stdio.h"
#include "Dosya.h"
#include "Habitat.h"

int main(){	
		int satir;
		int sutun;
		int bitkiadeti;
		int bocekadeti;		
		int sinekadeti;
		int pireadeti;
		
		Dosya dosya=DosyaOlustur();				
		dosya->bilgi("Veri.txt", &satir, &sutun);		
		dosya->adet("Veri.txt", satir, sutun, &bitkiadeti, &bocekadeti, &sinekadeti, &pireadeti);						
		dosya->yoket(dosya);
		
		Habitat habitat = HabitatOlustur(satir, sutun, bitkiadeti,bocekadeti,sinekadeti,pireadeti);		
		habitat->doldur(habitat, "Veri.txt");
		habitat->yazdir(habitat);
		printf("\nEnter tusuna basiniz.\n");
		getchar();
		printf("\n");
		habitat->yeme(habitat);
		habitat->yazdir(habitat);
		habitat->son(habitat);
		habitat->yoket(habitat);
		
		return 0;
}


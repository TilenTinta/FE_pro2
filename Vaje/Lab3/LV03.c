/*
 * Interaktivni vmesnik za izris fraktalov
 * Tretja vaja za Programiranje II
 * Nejc Bertoncelj, 4/2020
 *
 * *** POZOR ***
 *  Program uporablja ANSI ubežne sekvence, da premika kurzor
 *  po terminalu. To deluje v Linux in Mac okoljih, Windows
 *  pa jih ne podpira (vsaj privzeto ne). Zaželjeno izvajanje
 *  na operacijskih sistemih, ki izvirajo iz UNIX-a :)
 *
 * Tudi ta program je postal malo bolj 'razširjen'. Mogoče pa
 * karantena le ne vpliva tako slabo na nas...
 */

#include <stdio.h>
#include <math.h>
#include "bitmap.c"

#define DIM_PRIVZETA 1024           // Privzeta dimenzija slike, maksimum
#define INT_PRIVZETA 5              // Privzeta intenziteta fraktala
#define DATOTEKA     "fraktal.bmp"  // Ime izhodne datoteke

// Glavni strukt kompleksnih števil z dvema komponentama
typedef struct kom_st {
	float re;
	float im;
} kom_st;

// Deklaracije funkcij (opisi nad posameznimi funkcijami)
unsigned char doloci_barvo  (struct kom_st z, struct kom_st c);
float         absv          (struct kom_st z);
struct        kom_st vsota  (struct kom_st z, struct kom_st w);
struct        kom_st produkt(struct kom_st z, struct kom_st w);

// Dimenzija izhodne slike
int DIM = DIM_PRIVZETA;

// Uporabniški vnos prek scanf
int up_vnos;

// Izbrana cifra fraktala (iz tabele)
int n_frak = 0;

// Intenziteta barv izrisa
int intenz_barv = 5;

// Odtenek podlage (0 - črno/1 - belo)
char odtenek_pod = 0;

// Število vrstic za interaktiven izbris podatkov v terminalu
char n_vrstic;

// Stanje zapisnika
char zapisnik = -1;

int main() {
	// Kompleksni števili enačbe f(z) = z^2 + c
	// Uporabnik iz spodnje tabele izbere 'c', 'z' se izračuna v programu
	struct kom_st z, c;

	// Ravnina, iz katere se generira slika
	unsigned char ravnina[DIM][DIM];

	// Tabela fraktalov. Ne pozabi ohraniti čuvaja (42.0)
	float fraktali[][2] = {
		{ 0.000, 1.000},
		{-1.350, 0.000},
		{-0.550, 0.500},
		{ 0.310, 0.500},
		{ 0.285, 0.001},
		{-0.400, 0.600},
		{-0.800, 0.156},
		{42.000, 42.00}};
	
	// Privzeta nastavitev iz zgornje tabele (določena s spremenljivko 'n_frak')
	c.re = fraktali[n_frak][0];
	c.im = fraktali[n_frak][1];
	
	for(;;) {
		// Izpis ukazov
		printf("[H[2J\n");
		printf("  [0;32mUKAZI[0m            \n");
	        printf("  1   Izris fraktala            \n");
	        printf("  2   Izbira fraktala      [%4i]  %+.3f%+.3fi\n", n_frak, fraktali[n_frak][0], fraktali[n_frak][1]);
	        printf("  3   Dimenzija            [%4i]\n", DIM);
	        printf("  4   Intenziteta barv (*) [%4i]\n", intenz_barv);
	        printf("  5   Odtenek podlage      %s   \n", odtenek_pod ? "svetel" : " temen");
	        printf("  6   Zapusti program                             \n\n");
		printf("  *   Večja intenziteta pomeni manjšno natančnost.\n\n");
	
		// Izpis zapisnika (vedno zasede dve vrstici)
		printf("  [1;32mZAPISNIK[0m\n  ");
		switch(zapisnik) {
			case -1: // Pozdravno sporočilo
				printf("Pozdravljeni! Vnesite ukaz.\n\n");
				break;
			case 1:  // Neveljavno število
				printf("[0;31mPOZOR:[0m To število ni veljavno. Nastavljam na privzeto vrednost.\n\n");
				break;
			case 2:  // Generiranje uspešno
				printf("[0;33mOPOMBA:[0m Fraktal uspešno generiran.\n\n");
				break;
			case 3:  // Nastavi na maksimum
				printf("[0;31mPOZOR:[0m To število ni veljavno. Nastavljam na največjo vrednost.\n\n");
				break;
			case 9:  // Neznan ukaz
				printf("[0;31mPOZOR:[0m Ta ukaz ni prepoznan!\n\n");
				break;
			default: // Praznina
				printf("--\n\n");
				break;
		}
	
		// Zapisnik se vsakič ponastavi
		zapisnik = 0;

		// Uporabnik je morda že izbral fraktal, nastavi komponenti
		c.re = fraktali[n_frak][0];
		c.im = fraktali[n_frak][1];

		// Ukazna vrstica
		printf("[4mVaša izbira?[0m [1..6]: ");
		scanf("%d", &up_vnos);

		// To zaporedje izbriše terminal in vrne kurzor na (0,0) - deluje le na ANSI
		// terminalih.
		printf("[1A[K");

		switch(up_vnos) {
			case 1:  // Izračun fraktala, zapis v datoteko
				printf("Računam za %.3lf%+.3lfi  ", c.re, c.im);
				for(int x_os = 0; x_os < DIM; x_os++){
					for(int y_os = 0; y_os < DIM; y_os++){
						z.re = ((float)x_os / DIM) * 3.4 - 1.699;
						z.im = ((float)y_os / DIM) * 3.4 - 1.699;
						ravnina[x_os][y_os] = doloci_barvo(z, c);
					}
					if(x_os % 20 == 0){
						printf("[1D=>");
						fflush(stdout);
					}
				}
				printf("Zapisujem datoteko");
				shraniBMP(ravnina, DIM, DIM, DATOTEKA);
				zapisnik = 2;
				break;

			case 2:  // Izbira fraktala
				printf("Na voljo je:\n");
				int j = 0;
				for(j; fraktali[j][0] != 42.0; j++) {
					if(j == n_frak) {
						printf(" -> %i  %+.3f%+.3fi\n", j, fraktali[j][0], fraktali[j][1]);
					}
					else {
						printf("    %i  %+.3f%+.3fi\n", j, fraktali[j][0], fraktali[j][1]);
					}
				}
				printf("\nVaš izbor? ");
				scanf("%i", &n_frak);

				n_vrstic = j + 2;

				if(n_frak > j || n_frak < 0) {
					n_frak = 0;
					n_vrstic = n_vrstic + 2;
					zapisnik = 1;
				}

				// Izbriši toliko vrstic, kolikor je bilo izbir
				for(int k = 0; k <= n_vrstic; k++)
					printf("[1A[K");

				break;

			case 3:  // Nastavitev dimenzij
				printf("Dimenzija fraktala: ");
				scanf("%i", &DIM);

				if(DIM > DIM_PRIVZETA || DIM < 1) {
					DIM = DIM_PRIVZETA;
					zapisnik = 3;
				}
				break;
				
			case 4:  // Nastavitev intenzitete
				printf("Intenziteta barv (med 1 in 20): ");
				scanf("%i", &intenz_barv);

				if(intenz_barv > 20 || intenz_barv < 1) {
					intenz_barv = INT_PRIVZETA;
					zapisnik = 1;
				}
				break;

			case 5:  // Sprememba odtenka
				odtenek_pod = !odtenek_pod;
				break;

			case 6:  // Izhod
				printf("Zaključujem program.\n\n");
				return 0;
				break;

			default: // Neznan ukaz
				zapisnik = 9;
				break;
		}
	}
}

// Funkcija za določitev barve posameznega piksla. Vzame dve kompleksni števili,
// jih izračuna prek formule f(z) = z^2 + c in, ko absolutna vrednost izračuna
// preseže 2, vrne barvo piksla v intervalu (0, 255). Zraven še preveri 
// spremenljivko 'odtenek_pod(lage)', ki določi, ali bo ozadje črno ali belo.
unsigned char doloci_barvo(kom_st z, kom_st c) {
	int i = 0;
	for(i; i < 256; i = i + intenz_barv) {
		z = vsota(produkt(z, z), c);
		if(absv(z) > 2)
			break;
	}

	return odtenek_pod ? 255 - i : i;
}

// Absolutna vrednost kompleksnega števila
float absv(kom_st z) {
	return sqrt(pow(z.re, 2) + pow(z.im, 2));
}

// Izračun kompleksne vsote
struct kom_st vsota(kom_st z, kom_st w) {
	kom_st k;
	k.re = z.re + w.re;
	k.im = z.im + w.im;
	return k;
}

// Izračun kompleksnega produkta
struct kom_st produkt(kom_st z, kom_st w) {
	kom_st k;
	k.re = (z.re * w.re) - (z.im * w.im);
	k.im = (z.re * w.im) + (w.re * z.im);
	return k;
}

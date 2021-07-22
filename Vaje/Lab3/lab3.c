#include <math.h>
#include <stdio.h>
#include "bitmap.c"
#define DIM 2300

struct kompleksna_st
{
    double real;
    double imag;
};
struct kompleksna_st Vsota(struct kompleksna_st x, struct kompleksna_st y);
struct kompleksna_st Produkt(struct kompleksna_st x, struct kompleksna_st y);
unsigned char setBarva(struct kompleksna_st z, struct kompleksna_st c);

int main()
{
    /*
    struct kompleksna_st z, c;
    int dimx = 10;
    int dimy = 30;
    double z_real = (((float)dimx / (DIM -1))* 3.4);
    double z_imag = (((float)dimy / (DIM -1))* 3.4);
    printf("%lf-%lf\n", z_real, z_imag);
    z.real = (z_real - 1.6999);
    z.imag = (z_imag - 1.6999);
    printf("%lf-%lf\n", z, c);

    */
    unsigned char ravnina[DIM][DIM];
    int dimx;
    int dimy;
    char i; // itak ga ne rabim
    struct kompleksna_st z, c;

    //Vnos števila
    //c.real = 0;
    //c.imag = 0;
    i = 0;
    printf("Vnesi kompleksno število:\n");
    scanf("%lf%lf%c", &c.real, &c.imag, &i);
    //printf("%lf %lf\n", real, imag);

    for (dimx = 0; dimx < DIM; dimx++)
    {
        for (dimy = 0; dimy < DIM; dimy++)
        {
            z.real = ((((float)dimx / DIM) * 3.4) - 1.6999);
            z.imag = ((((float)dimy / DIM) * 3.4) - 1.6999);
            //printf("%lf-%lf\n", z, c);
            ravnina[dimy][dimx] = setBarva(z, c);
        }
    }

    shraniBMP(ravnina, DIM, DIM, "kricekrace.bmp");

    return 0;
}

unsigned char setBarva(struct kompleksna_st z_barva, struct kompleksna_st c)
{
    int i = 0;
    double z;

    while (i < 256)
    {
        z_barva = Vsota(Produkt(z_barva, z_barva), c);
        double vrednost = sqrt((z_barva.real * z_barva.real) + (z_barva.imag * z_barva.imag));
        if (vrednost > 2)
        {
            break;
        }
        i=i+3;
    }
    //printf("%d", i);
    return i; //255-barva (bela podlaga)
}

// PRERAČUN PRODUKTA
struct kompleksna_st Produkt(struct kompleksna_st x, struct kompleksna_st y)
{
    struct kompleksna_st zmnozek;
    zmnozek.real = (x.real * y.real) - (x.imag * y.imag);
    zmnozek.imag = (y.imag * x.real) + (x.imag * y.real);
    return zmnozek;
};

//PRERAČUN VSOTE
struct kompleksna_st Vsota(struct kompleksna_st x, struct kompleksna_st y)
{
    struct kompleksna_st sestevek;
    sestevek.real = x.real + y.real;
    sestevek.imag = x.imag + y.imag;
    return sestevek;
}
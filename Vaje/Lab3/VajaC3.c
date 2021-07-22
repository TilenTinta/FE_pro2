#include <math.h>
#include <stdio.h>
#include "bitmap.c"
#define DIM 1000

struct kompleks{
    double real;
    double imag;
};
struct kompleks Vsota(struct kompleks x, struct kompleks y);
struct kompleks Produkt(struct kompleks x, struct kompleks y);
unsigned char setBarva(struct kompleks a, struct kompleks b);

int main(){
 
    unsigned char plane[DIM][DIM];
    int dimx;
    int dimy;
    char q;
    struct kompleks a, b;

    q = 0;
    printf("Vnesi kompleksno stevilo:\n");
    scanf("%lf%lf%c", &b.real, &b.imag, &q);

    for (dimx = 0; dimx < DIM; dimx++){
        for (dimy = 0; dimy < DIM; dimy++){
            a.real = ((((float)dimx / DIM) * 3.4) - 1.6999);
            a.imag = ((((float)dimy / DIM) * 3.4) - 1.6999);
            plane[dimy][dimx] = setBarva(a, b);
        }
    }

    shraniBMP(plane, DIM, DIM, "skribli.bmp");

    return 0;
}

unsigned char setBarva(struct kompleks z_barva, struct kompleks b){
    int q = 0;
    double a;

    while (q < 256){
        z_barva = Vsota(Produkt(z_barva, z_barva), b);
        double vrednost = sqrt((z_barva.real * z_barva.real) + (z_barva.imag * z_barva.imag));
        if (vrednost > 2){
            break;
        }
            q=q+5;
    }
    return q;
}

struct kompleks Produkt(struct kompleks x, struct kompleks y){
    struct kompleks zmnozek;
    zmnozek.real = (x.real * y.real) - (x.imag * y.imag);
    zmnozek.imag = (y.imag * x.real) + (x.imag * y.real);
    return zmnozek;
};


struct kompleks Vsota(struct kompleks x, struct kompleks y){
    struct kompleks sestevek;
    sestevek.real = x.real + y.real;
    sestevek.imag = x.imag + y.imag;
    return sestevek;
}
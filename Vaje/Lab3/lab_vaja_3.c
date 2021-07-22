#include <math.h>
#include <stdio.h>
#include "bitmap.c"
#define dim 500

struct kompleksno_stevilo{
    double realni;
    double imaginarni;
};

struct kompleksno_stevilo Vsota(struct kompleksno_stevilo x, struct kompleksno_stevilo y);
struct kompleksno_stevilo Produkt(struct kompleksno_stevilo x, struct kompleksno_stevilo y);
unsigned char setcolour(struct kompleksno_stevilo z, struct kompleksno_stevilo c);

int main(){

    unsigned char plane[dim][dim];
    int x;
    int y;
    struct kompleksno_stevilo z,c;
    char i;

    printf("Insert complex number:\n");
    scanf("%lf%lf%c",&c.realni,&c.imaginarni,&i);
    //printf("%lf %lf\n", realni, imaginarni); 

    for(y=0;y<dim;y++){
        for(x=0;x<dim;x++){
            z.realni=((((float)x/dim)*3.4)-1.6999); //pobrano z yt
            z.imaginarni=((((float)y/dim)*3.4)-1.6999);

            plane[x][y]=setcolour(z,c);
        }
    }

shraniBMP(plane,dim,dim, "upam_de_dela.bmp");

    return 0;
}

unsigned char setcolour(struct kompleksno_stevilo z_colour, struct kompleksno_stevilo c){
    int i=0;
    double z;

    while(i<256)
    {
        z_colour=Vsota(Produkt(z_colour,z_colour),c);
        double meja=sqrt((z_colour.realni*z_colour.realni)+(z_colour.imaginarni*z_colour.imaginarni));

        if(meja>2){
            break;
        }
        i=i+5;
    }
    return i;
}

//Produkt
struct kompleksno_stevilo Produkt(struct kompleksno_stevilo a, struct kompleksno_stevilo b){
    struct kompleksno_stevilo mnozenje;
    mnozenje.realni=(a.realni*b.realni)-(a.imaginarni*b.imaginarni);
    mnozenje.imaginarni=(b.imaginarni*a.realni)+(a.imaginarni*b.realni);
    return mnozenje;
};

//Vsota

struct kompleksno_stevilo Vsota(struct kompleksno_stevilo a, struct kompleksno_stevilo b){
    struct kompleksno_stevilo sestevanje;
    sestevanje.realni=a.realni+b.realni;
    sestevanje.imaginarni=a.imaginarni+b.imaginarni;
    
    return sestevanje;
}



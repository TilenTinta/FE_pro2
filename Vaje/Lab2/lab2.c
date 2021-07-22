#include <math.h>
#include <stdio.h>

// Vsota
int Vsota(float real1,float  real2, float imag1, float imag2,char i1)
{
   int vsota1 = 0;
   int vsota2 = 0;
   vsota1 = real1 + real2;
   vsota2 = imag1 + imag2;
         printf("%f %f\n", real1, imag1);
         printf("%f %f\n", real2, imag2);
   if (vsota2 >= 0)
   {
      printf("Vsota števil je: %d%+d%c\n", vsota1, vsota2, i1);
   }
   else
   {
      printf("Vsota števil je: %d%d%c\n", vsota1, vsota2, i1);
   }
   return 0;
}
// Razlika
int Razlika(float real1,float  real2, float imag1, float imag2,char i1)
{
   int razlika1 = 0;
   int razlika2 = 0;
   razlika1 = real1 - real2;
   razlika2 = imag1 - imag2;
   if (razlika2 >= 0)
   {
      printf("Razlika števil je: %d+%d%c\n", razlika1, razlika2, i1);
   }
   else
   {
      printf("Razlika števil je: %d%d%c\n", razlika1, razlika2, i1);
   }
   return 0;
}

// Produkt
int Produkt(float real1,float  real2, float imag1, float imag2,char i1)
{

   int produkt1 = 0;
   int produkt2 = 0;
   produkt1 = (real1 * real2) - (imag1 * imag2);
   produkt2 = (imag1 * real2) + (imag2 * real1);
   if (produkt2 >= 0)
   {
      printf("Produkt števil je: %d+%d%c\n", produkt1, produkt2, i1);
   }
   else
   {
      printf("Produkt števil je: %d%d%c\n", produkt1, produkt2, i1);
   }
   return 0;
}

// Kvocient
int Kvocient(float real1,float  real2, float imag1, float imag2,char i1)
{
   float kvocient1 = 0;
   float kvocient2 = 0;
   kvocient1 = ((real1 * real2) + (imag1 * imag2)) / ((real2 * real2) + (imag2 * imag2));
   kvocient2 = ((imag1 * real2) - (imag2 * real1)) / ((real2 * real2) + (imag2 * imag2));
   if (kvocient2 >= 0)
   {
      printf("Kvocient števil je: %.2f+%.2f%c\n", kvocient1, kvocient2, i1);
   }
   else
   {
      printf("Kvocient števil je: %.2f%.2f%c\n", kvocient1, kvocient2, i1);
   }
   return 0;
}

int main()
{
   float real1 = 0;
   float imag1 = 0;
   float real2 = 0;
   float imag2 = 0;
   char i1 = 0;
   char i2 = 0;
   // Operacija
   int izbira = 0;
   char enter;

   while (izbira != 6)
   {
      // Vnos števil
      printf("Izberi željeno operacijo:\n");
      printf("(1) Vnos\n");
      printf("(2) Vsota\n");
      printf("(3) Razlika\n");
      printf("(4) Produkt\n");
      printf("(5) Kvocient\n");
      printf("(6) Exit\n");
      // Try - Catch block po C-jevo
      if(scanf("%d%c", &izbira, &enter) != 2 || enter != '\n'){
         izbira = 0;
      }else{
         scanf("%d", &izbira);
         //printf("%d\n", izbira);
      }

      if (izbira == 1)
      {
         printf("Vnašanje kompleksnih števili:\n");
         printf("Vnesi prvo kompleksno število:\n");
         scanf("%f%f%c", &real1, &imag1, &i1);
         printf("Vnesi drugo kompleksno število:\n");
         scanf("%f%f%c", &real2, &imag2, &i2);
         //printf("%f %f\n", real1, imag1);
         //printf("%f %f\n", real2, imag2);
      }

      switch (izbira)
      {
      case 2:
         Vsota(real1,real2, imag1, imag2, i1);
         break;
      case 3:
         Razlika(real1,real2, imag1, imag2, i1);
         break;
      case 4:
         Produkt(real1,real2, imag1, imag2, i1);
         break;
      case 5:
         Kvocient(real1,real2, imag1, imag2, i1);
         break;
      default:
         break;
      }
   }
   if (izbira == 6)
   {
      printf("PROGRAM KONČAN!!!\n");
   }
}




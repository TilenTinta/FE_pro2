#include <math.h>
#include <stdio.h>
int main()
{
   float real1 = 0;
   float imag1 = 0;
   float real2 = 0;
   float imag2 = 0;
   int vsota1 = 0;
   int vsota2 = 0;
   int razlika1 = 0;
   int razlika2 = 0;
   int produkt1 = 0;
   int produkt2 = 0;
   float kvocient1 = 0;
   float kvocient2 = 0;
   char i1 = 0;
   char i2 = 0;
   // Vnos števil
   printf("Lab1\n");
   printf("Vnesi prvo kompleksno število:\n");
   scanf("%f%f%c", &real1, &imag1, &i1);
   printf("Vnesi drugo kompleksno število:\n");
   scanf("%f%f%c", &real2, &imag2, &i2);
   //printf("%d %d\n", real1,imag1);
   //printf("%d %d\n", real2,imag2);

   // Vsota
   vsota1 = real1 + real2;
   vsota2 = imag1 + imag2;
   if (vsota2 >= 0)
   {
      printf("Vsota števil je: %d%+d%c\n", vsota1, vsota2, i1);
   }
   else
   {
      printf("Vsota števil je: %d%d%c\n", vsota1, vsota2, i1);
   }

   // Razlika
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

   // Produkt
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
   //Kvocient
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

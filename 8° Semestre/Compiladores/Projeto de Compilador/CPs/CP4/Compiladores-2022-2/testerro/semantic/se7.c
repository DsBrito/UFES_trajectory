#include <stdio.h>
#include <math.h>
 
int main(void)
{
   float fX, fY, fZ;
   printf("\nEntre com os valores dos 3 lados:");
   scanf("%f%f%f", &fX, &fY, &fZ);
 
   /* condição de existência de um triângulo */
   if( (fabsf(fY-fZ) < fX) && (fX < (fY+fZ)) )
   {
      if( (fX == fY) && (fX == fZ) )
      {
         printf("\nTriangulo equilatero!");
      }
      else
      {
         if( (fX != fY) && (fX != fZ) )
         {
            printf("\nTriangulo escaleno!");
         }
         else
         {
            printf("\nTriangulo isosceles!");
         }
      }
   }
   else
   {
      printf("\nAs medidas nao formam um triangulo!");
   }
   return 0;
}

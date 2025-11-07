#include <stdio.h>

int main() {

   typedef unsigned long int ULONG;
   typedef short int SHORT;

   typedef union myunion {
      char a;
      int b;
      double c;
   } UNTYPE;

   UNTYPE u1;
   u1.c = 65.50;

   typedef UNTYPE * UNPTR;
   UNPTR ptr = &u1;

   printf("a:%c b: %d c: %lf \n", u1.a, u1.b, u1.c);
   printf("a:%c b: %d c: %lf \n", ptr->a, ptr->b, ptr->c);

   return 0;
}

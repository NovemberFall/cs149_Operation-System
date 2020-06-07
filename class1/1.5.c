#include <stdio.h>

int main(void) {
   int baseInt;
   int headInt;
   
   scanf("%d%d", &baseInt, &headInt);
   printf("    ");
   printf("%d\n", headInt);
   printf("    ");
   printf("%d%d\n", headInt, headInt);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", baseInt);
        }
        if (i == 0 || i == 2) {
            printf("%d%d%d\n", headInt, headInt, headInt);
        } else {
            printf("%d%d%d%d\n", headInt, headInt, headInt, headInt);
        }
    }
   printf("    ");
   printf("%d%d\n", headInt, headInt);
   printf("    ");
   printf("%d\n", headInt);
   
   return 0;
}
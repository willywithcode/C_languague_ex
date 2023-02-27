#include<stdio.h>
#include <string.h>

int main() {
   char string[50] = "Hello world";
   // Extract the first token
   char * token = strtok(string, " ");
   printf( " %s\n", token ); //printing the token
   return 0;
}

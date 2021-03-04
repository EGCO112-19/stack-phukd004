#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j,check=0;
  char n;

  Stack s;
  s.size = 0;
  s.top = NULL;

  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
       switch( argv[i][j] ){
         case '{':
          push(&s,'{');
          break;
         
         case '}':
          push(&s,'[');
          break;
         
         case ']':
          n = pop(&s);
          if( n!='[' ){
            check = 1;
          }
          break;

         case '}':
          n = pop(&s);
          if( n!='{' ){
            check=1;
          }
          break;

       }
       if( check!=0 ) {
         break;
       }  
     }

     printf("\n The size is : %d and check : %d\n",s.size,check);
     if(s.size >0 || check!=0){
       printf("The parentheses do not match for '%s'\n",argv[i]);
     }
     else{
       printf("The parentheses match successfully for '%s'\n",argv[i]);
     }
     check =0;
     s.size =0;
     pop_all(&s);
  }
   return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void main(){
char operators[] = "+-*/%=<>";
char buffer[100];
char keyword[10][10]={"int","if","float","char","printf","while"};
int bindex = 0;
FILE* f;
f=fopen("lex.txt","r");
fgets(buffer, sizeof(buffer),f);
printf("the content of file is: %s\n",buffer);
bzero(buffer,100);
fclose(f);
f=fopen("lex.txt","r");
printf("Output:\n");
while(1){
 char c=fgetc(f);
 if(feof(f))
 break;
 if(isalnum(c)){
 buffer[bindex++]=(char)c;
 while(isalnum(c=fgetc(f))) {
 buffer[bindex++]=(char)c;
 }
 buffer[bindex] = '\0';
 ungetc(c, f);
 int is_key=0;
 for(int i=0;i<10;i++){
 if (strcmp(buffer, keyword[i]) == 0){
 printf("%s is a keyword\n", buffer);
 is_key = 1;
 break;
 } }
 if(!is_key){
 printf("%s is an identifier\n",buffer);
 }
 bindex=0;
 }
 else if (strchr(operators, c)) {
 printf("%c is an operator\n", c);
 }
 else if (isspace(c)) {
 continue;
 }
 else{
 printf("%c is a special symbol\n",c);
 }
} }
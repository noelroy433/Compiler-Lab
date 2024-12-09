#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_EXPR_LENGTH 100
#define MAX_TEMP 10
int temp_count = 0;
char* new_temp() {
char* temp = malloc(4 * sizeof(char));
if (temp == NULL) {
fprintf(stderr, "Memory allocation failed\n");
exit(1);}
snprintf(temp, 4, "t%d", temp_count++);
return temp;}
int is_operator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/');}
int precedence(char op) {
switch(op) {
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
default:
return 0;}}
void generate_code(const char* expr) {
char stack[MAX_EXPR_LENGTH];
int top = -1;
char output[MAX_EXPR_LENGTH * 2] = {0};
int out_idx = 0;
for (int i = 0; expr[i] != '\0'; i++) {
if (isalnum(expr[i])) {
output[out_idx++] = expr[i];
output[out_idx++] = ' ';
} else if (expr[i] == '(') {
stack[++top] = expr[i];
} else if (expr[i] == ')') {
while (top > -1 && stack[top] != '(') {
output[out_idx++] = stack[top--];
output[out_idx++] = ' ';}
if (top > -1 && stack[top] == '(') {
top--;}
} else if (is_operator(expr[i])) {
while (top > -1 && precedence(stack[top]) >= precedence(expr[i])) {
output[out_idx++] = stack[top--];
output[out_idx++] = ' ';}
stack[++top] = expr[i];}}
while (top > -1) {
output[out_idx++] = stack[top--];
output[out_idx++] = ' ';}
output[out_idx] = '\0';
char* token = strtok(output, " ");
char* operand_stack[MAX_TEMP];
int operand_top = -1;
while (token != NULL) {
if (isalnum(token[0])) {
operand_stack[++operand_top] = strdup(token);
} else if (is_operator(token[0])) {
char* result = new_temp();
printf("%s = %s %c %s\n", result, operand_stack[operand_top-1], token[0],
operand_stack[operand_top]);
free(operand_stack[operand_top]);
free(operand_stack[operand_top-1]);
operand_top--;
operand_stack[operand_top] = result;}
token = strtok(NULL, " ");}
while (operand_top >= 0) {
free(operand_stack[operand_top--]);}}
int main() {
char expr[MAX_EXPR_LENGTH];
printf("Enter an expression: ");
if (fgets(expr, sizeof(expr), stdin) == NULL) {
fprintf(stderr, "Error reading input\n");
return 1;}
expr[strcspn(expr, "\n")] = 0;
printf("Intermediate Code:\n");
generate_code(expr);
return 0;
}
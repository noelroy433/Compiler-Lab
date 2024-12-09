#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100
void process_line(char *line, FILE *output) {
char op[10], arg1[10], arg2[10], result[10];
sscanf(line, "%s %s %s %s", op, arg1, arg2, result);
if (strcmp(op, "+") == 0) {
fprintf(output, "MOV R0,%s\n", arg1);
fprintf(output, "ADD R0,%s\n", arg2);
fprintf(output, "MOV %s,R0\n", result);
} else if (strcmp(op, "*") == 0) {
fprintf(output, "MOV R0,%s\n", arg1);
fprintf(output, "MUL R0,%s\n", arg2);
fprintf(output, "MOV %s,R0\n", result);
} else if (strcmp(op, "-") == 0) {
fprintf(output, "MOV R0,%s\n", arg1);
fprintf(output, "SUB R0,%s\n", arg2);
fprintf(output, "MOV %s,R0\n", result);
} else if (strcmp(op, "=") == 0) {
fprintf(output, "MOV R0,%s\n", arg1);
fprintf(output, "MOV %s,R0\n", result);}}
int main() {
char input_filename[100];
char line[MAX_LINE];
FILE *input_file, *output_file;
printf("Enter input file name: ");
scanf("%s", input_filename);
input_file = fopen(input_filename, "r");
if (input_file == NULL) {
printf("Error opening input file.\n");
return 1;}
output_file = fopen("output.txt", "w");
if (output_file == NULL) {
printf("Error creating output file.\n");
fclose(input_file);
return 1;}
while (fgets(line, MAX_LINE, input_file) != NULL) {
process_line(line, output_file);}
fclose(input_file);
fclose(output_file);
printf("Output has been written to output.txt\n");
return 0;
}

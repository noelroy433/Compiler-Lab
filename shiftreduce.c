#include <stdio.h>
#include <string.h>

int c = 0, i = 0, j = 0, k = 0, z = 0;
char a[15], acr[15], stk[20], acs[15];

void check();

int main() {
    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id \n");
    puts("Enter the input string: ");
    scanf("%s", a);
    c = strlen(a);
    strcpy(acs, "SHIFT->");
    puts("STACK\tINPUT\tACTION");

    for (i = 0, j = 0; j < c; i++, j++, k++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stk, a, acs);
            check();
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%s", stk, a, acs);
            check();
        }
    }

    return 0;
}

void check() {
    strcpy(acr, "REDUCE TO E");

    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, acr);
            j++;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, acr);
            i = i - 2;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, acr);
            i = i - 2;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, acr);
            i = i - 2;
        }
    }
}

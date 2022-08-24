#include <stdio.h>

int table1[2][2][2];
int table2[2][2][2];

int at_(int a, int k){
    return (a>>k) & 1;
}

int main(){
    table1[0][0][0] = 0;
    table1[1][0][0] = table1[0][1][0] = table1[0][0][1] = 1;
    table1[1][1][0] = table1[1][0][1] = table1[0][1][1] = 0;
    table1[1][1][1] = 1;

    table2[0][0][0] = 0;
    table2[1][0][0] = table2[0][1][0] = table2[0][0][1] = 0;
    table2[1][1][0] = table2[1][0][1] = table2[0][1][1] = 1;
    table2[1][1][1] = 1;

    int a, b;
    scanf("%d %d", &a, &b);
    int c = 0;

    int carryin = 0;
    for(int i=0; i<=31; i++){
        int a_ = at_(a, i), b_ = at_(b, i);

        int c_ = table1[a_][b_][carryin];
        carryin = table2[a_][b_][carryin];

        c |= (c_ << i);
    }

    printf("%d", c);
}

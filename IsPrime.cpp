#include <iostream>              // HW04-Q5_7111056228
#include <ctgmath>
#include <cstdlib>

void IsPrime(int num) {
    if (num <= 1)
        printf("EXCEPTION\n");
    else if (((num % 2 == 0) || (num % 3 == 0)) && num != 2 )
        printf("composite\n");
    else {
        int i = 2, counter = 0;
        while (i < sqrt(num)) {
            if (num % i == 0) {
                printf("composite\n");
                return;
            }
            i += 1;
            counter += 1;
        }
        if (num == 2 || num == 3 || num == 5 || num == 7)
            counter += 1;
        printf("prime %d\n", counter);
    }
}

int main() {
    FILE *bench;
    char str[10];
    int n;
    bench = fopen("testbench.txt", "r");

    if (bench != NULL) {
        while (!feof(bench)) {
            fgets(str, 10, bench);
            n = atoi(str);
            IsPrime(n);
        }
    }
    return 0;
}

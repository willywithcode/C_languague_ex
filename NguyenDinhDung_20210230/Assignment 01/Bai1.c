#include <stdio.h>
#include <math.h>

long long C(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    return res;
}

int main() {
    int n, k;
    FILE *in = fopen("TOHOP.INP", "r");
    FILE *out = fopen("TOHOP.OUT", "w");
    while (fscanf(in, "%d%d", &n, &k) == 2) {
        fprintf(out, "%lld\n", C(n, k));
    }
    fclose(in);
    fclose(out);
    return 0;
}

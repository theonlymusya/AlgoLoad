int n = 3;
int m = 4;
for (int i = 1; i <= pow(n, 2); i++) {
    for (int j = 0; j < m; ++j) {
        A[i][j] = x[i];
    }
    B[i] = y[i];
}
int l = n + m;
for (int i = 0; i <= n; i++) {
    for (int j = 0; j < m && l > 4; j++) {
        D[pow(i, 2)][j] = B[i] + A[i * j][j];
    }
    l = l - 1;
}

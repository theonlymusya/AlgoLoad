int n = 5;
int m = 4;
for (int i = 0; i < n; ++i) {
    A[i] = x[i];
    B[i] = y[i];
}

for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        C[i][j] = A[i] + B[j];
    }
}

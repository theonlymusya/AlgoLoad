int n = 3;
int m = 4;
int l = 2;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < l; ++k) {
            A[i][j][k] = x[i] + y[j];
        }
    }
}
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < l; ++k) {
            B[i][j][k] = A[i][j][k];
        }
    }
}
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        C[i][j] = A[i][j][0] + B[i][j][0];
        for (int k = 0; k < l; ++k) {
            D[i][j][k] = A[i][j][k] + C[i][j];
        }
    }
}

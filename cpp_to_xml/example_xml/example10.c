int n = 3;
int m = 4;
int main() {
    int i = 0;
    for (; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = x[i];
        }
        B[i] = y[i];
        for (int j = 0; j < m;) {
            C[i][j] = A[i][j] + B[i];
            j += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        D[i][0] = B[i] + C[i][0];
    }
}

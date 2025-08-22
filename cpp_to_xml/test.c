int n = 3;
int m = 4;
int l = 2;
int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = x[i];
        }
        B[i] = y[i];
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i];
            l += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        D[i][0] = B[i] + C[i][0];
    }
}

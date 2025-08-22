int n = 3;
int m = 4;
int l = 2;
int main() {
    for (int i = 0; i < n; i = i + 1) {
        for (int j = 0; j < m; j = j + 1) {
            A[i][j] = x[i];
        }
        B[i] = y[i];
        for (int j = 0; j < m; j = j + 1) {
            C[i][j] = A[i][j] + B[i];
            l = l + 1;
        }
    }
    for (int i = 0; i < n; i = i + 1) {
        D[i][0] = B[i] + C[i][0];
    }
}

int N = 3;
for (int j = 0; j < N; j++) {
    for (int i = N - 1; i > j; i--) {
        double denom = sqrt(A[i - 1][j] * A[i - 1][j] + A[i][j] * A[i][j]);
        for (int k = 0; k < N; k++) {
            double a = A[i - 1][k];
            double b = A[i][k];
            A[i - 1][k] = (A[i - 1][j] * a + A[i][j] * b) / denom;
            A[i][k] = (-A[i][j] * a + A[i - 1][j] * b) / denom;
        }
    }
}

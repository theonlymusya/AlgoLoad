int i;
int N = 5;
for (i = 0; i < N - 1; i++) {
    A[i + 1][i] = A[i + 1][i] / A[i][i];
    A[i + 1][i + 1] = A[i + 1][i + 1] - A[i + 1][i] * A[i][i + 1];
}

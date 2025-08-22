int n = 4;
int m = 5;
int l = 6;
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        matrix_out[i][j] = 0;
        for (int k = 0; k < l; k++)
            matrix_out[i][j] += matrix_1[i][k] * matrix_2[k][j];
    }

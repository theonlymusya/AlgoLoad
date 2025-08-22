int size = 5;
for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
        vec_out[i] += matrix[i][j] * vec_in[j];

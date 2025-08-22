int h = 3;
int arr_size = 8;
for (int i = 1; i <= h; i++)
    for (int j = 0; j < arr_size; j++)
        if (j < (arr_size / (pow(2, i))))
            arr[j] = arr[j * 2] + arr[2 * j + 1];

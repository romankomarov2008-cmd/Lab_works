#include <stdio.h>


// Далі йде ваш основний код:

int main() {
    FILE *temp = fopen("F.bin", "wb");
    if (temp != NULL) {
        int numbers[] = {10, 20, -5, -15};
        fwrite(numbers, sizeof(int), 4, temp);
        fclose(temp);
    }

    FILE *f = fopen("F.bin", "rb");
    if (f == NULL) {
        printf("Error opening file F.bin\n");
        return 1;
    }

    int num;
    int pos_count = 0;
    int neg_count = 0;
    int zero_count = 0;

    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (num > 0) {
            pos_count++;
        } else if (num < 0) {
            neg_count++;
        } else {
            zero_count++;
        }
    }

    if (pos_count != neg_count || zero_count > 0 || pos_count == 0) {
        printf("Error: number of positive and negative numbers isn't equal (file is empty).\n");
        fclose(f);
        return 0;
    }

    FILE *h = fopen("H.bin", "wb+");
    if (h == NULL) {
        printf("Error creating file H.bin\n");
        fclose(f);
        return 1;
    }

    rewind(f);
    while (fread(&num, sizeof(int), 1, f) == 1) {
        if (num < 0) {
            fwrite(&num, sizeof(int), 1, h);
        }
    }

    FILE *g = fopen("G.bin", "wb");
    if (g == NULL) {
        printf("Error creating G.bin\n");
        fclose(f);
        fclose(h);
        return 1;
    }

    rewind(f);
    rewind(h);

    int pos_num, neg_num;
    for (int i = 0; i < pos_count; i++) {
        while (fread(&pos_num, sizeof(int), 1, f) == 1) {
            if (pos_num > 0) {
                fwrite(&pos_num, sizeof(int), 1, g);
                break;
            }
        }
        if (fread(&neg_num, sizeof(int), 1, h) == 1) {
            fwrite(&neg_num, sizeof(int), 1, g);
        }
    }

    printf("File G successfully created.\n");

    fclose(f);
    fclose(h);
    fclose(g);

    return 0;
}


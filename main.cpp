#include <iostream>
#include <stdio.h>

using namespace std;

struct Parallelepiped {
    double a;
    double b;
    double h;
};

int main() {

    FILE* file;
    if (fopen_s(&file, "./result.txt", "w") != 0) {
        printf("File no exist\n");
        return 1;
    }

    Parallelepiped parallelepipeds[100];
    int i = 0;
    double a, b, h;

    do {
        printf("Enter side a: ");
        scanf_s("%lf", &a);

        printf("Enter side b: ");
        scanf_s("%lf", &b);

        printf("Enter side h: ");
        scanf_s("%lf", &h);
        parallelepipeds[i++] = { a, b, h };
    } while (a != 0 || b != 0 || h != 0);

    for (int j = 0; j < i; ++j) {
        fprintf(file, "V = %.2lf * %.2lf * %.2lf\n", parallelepipeds[j].a, parallelepipeds[j].b, parallelepipeds[j].h);
    }

    fclose(file);
    return 0;
}

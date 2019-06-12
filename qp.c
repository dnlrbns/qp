#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (int argc, char *argv[])
{   
    float x_vals[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    float y_vals[10];
    if (argc != 3)
    {
        printf("please input 2 arguments: qp w.x y.z\n");
    }
    float m = atof(argv[1]);
    printf("%f\n",m);
    float b = atof(argv[2]);
    printf("%f\n",b);

    for (int i = 0; i < 10; i++)
    {
        y_vals[i] = m*x_vals[i] + b;
        printf("%f\n", y_vals[i]);
    }

}

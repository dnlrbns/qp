#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "qp.h"

int main (int argc, char *argv[])
{   
    float x_vals[] = DEFAULT_XVALS;
    float y_vals[DEFAULT_LEN];
    if (argc != 3)
    {
        printf("please input 2 arguments: qp w.x y.z\n");
    }
    float m = atof(argv[1]);
    //printf("m value is %f\n",m);
    float b = atof(argv[2]);
    //printf("b value is %f\n",b);

    for (int i = 0; i < 10; i++)
    {
        y_vals[i] = function(m,b,x_vals[i]);
       // printf("%f\n", y_vals[i]);
    }
    
    uint8_t ax[10][26] = { 0 };
    
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ax[j][i] = '0';
        }       
    }
        
    for (int i = 0; i < 10; i++)
    {
        ax[ (int) x_vals[i] ][ (int) y_vals[i] ] = '1';
    }
    
    FILE *fp;
    fp = fopen("print.pmm","w");
    fprintf(fp,"P1\n# this is the picture file\n10 26\n");

    for (int i = 26-1; i > 0-1; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            putc(ax[j][i], fp);
            putc(' ', fp);
            //printf("%c",ax[j][i]);
        }       
        putc('\n',fp);
        //printf("\n");
    }

    fclose(fp);
}

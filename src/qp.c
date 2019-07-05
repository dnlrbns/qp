#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "qp.h"

#define ROWS 10
#define COLS 30
#define LINEBUFF 100

int qp(char *pscreen);

int main (int argc, char *argv[])
{   
    // set up structure for holding a point
    //  we will declare an array of these 
    //  for dumping a 2 value csv into
    struct point {
        float x;
        float y;
    };

    // declare array to hold picture
    char *screen = calloc(sizeof(*screen) * COLS * ROWS,sizeof(*screen)); 

    // declare struct for holding 5 points
    // this should be dynamic in the future
    struct point *pt = malloc(5 * sizeof(struct point)); 

    // tell user arguments are ignored
    if (argc != 1)
    {
        printf("arguments ignored. Not yet supported");
    }

    // make some buffer for reading the first line of stdin
    char line[LINEBUFF];

    // control loop that reads each line of data and dumps
    // the result as a float into point struct
    int i=0;
    char * pch;
    while(fgets(line, LINEBUFF, stdin)!=NULL)
    {
        pch = strtok(line, ",");

        pt[i].x = atof(pch);
        pch = strtok(NULL, ",\n");
        pt[i].y = atof(pch);

        printf("%f and %f\n",pt[i].x, pt[i].y);

        i++;
    }
    qp(screen);
}
int qp(char *pscreen)
{
    for (int i; i<ROWS;i++)
    {   
        putchar('>');
        for (int j; j<COLS;j++)
        {
            if(*pscreen == 0)
            {
                putchar('*');
            }
        }
        putchar('\n');
    }
    return 0;
}

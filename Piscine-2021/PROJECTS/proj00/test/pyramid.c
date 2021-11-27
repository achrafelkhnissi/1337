#include <stdio.h>

int main(void) 
{
    int rows = 10;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= (rows*2) - 1; j++)
        {
//            if (j >= rows - (i - 1) && j <= rows + (i - 1))
//            {
            printf("*");
    //        }
      //      else
        //    {
          //      printf(" ");
            //}
        }
        printf("\n");
    }

    return 0;
}
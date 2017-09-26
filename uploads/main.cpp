#include "jsoncppheader.h"
#include <string>
#include <string.h>
char string1[110] = "AGGTAB";
char string2[110] = "GXTXAYB";
int m = strlen(string1);
int n = strlen(string2);
int A[110][110];
Array1DTracer tracer1 = Array1DTracer ( "String 1").setData ( string1, 6);
Array1DTracer tracer2 = Array1DTracer ( "String 2").setData ( string2, 7);
Array2DTracer tracer3 = Array2DTracer ( "Memo Table").setData ( A[0], 110, m, n);
LogTracer logger = LogTracer ();
int i,j;
int main()
{
     
    return 0;
}

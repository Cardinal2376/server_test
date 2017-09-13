#include "jsoncppheader.h"
#include <string>
int main()
{
    //freopen("E:\\HTML5Learning\\test\\1.txt", "w", stdout);
    int N = 5;
    int A[100];
    for (int i = N; i >= 0; i--) {
        A[i] = 0;
    }
    Array1DTracer tracer = Array1DTracer("Catalan Numbers")._setData(A, N);
    LogTracer logger = LogTracer();
    A[0] = 1;
    tracer._notify(0, A[0])._wait(1);
    tracer._denotify(0);
    A[1] = 1;
    tracer._notify(1, A[1])._wait(1);
    tracer._denotify(1);
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            A[i] += A[j] * A[i - j - 1];
            tracer._select(j)._wait(1);
            tracer._select( i - j -1 )._wait(1);
            tracer._notify( i, A[i])._wait(1);
            tracer._deselect( j );
            tracer._deselect( i - j - 1 );
            tracer._denotify( i );
        }
    }
    logger._print("wtf\n");
    tracer._select(N)._wait(1);
    return 0;
}

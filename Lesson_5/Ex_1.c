#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_code;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) if (exception_code == (x)) printf("%s\n", error_code);
#define THROW(x, ERROR_CODE) do {error_code = #ERROR_CODE; longjmp(buf, (x));} while(0) // oke

double divide(int a, int b) {
    if (b == 0) THROW (1, Error: Divide by 0!); 
    if (a*b < 0) THROW (2, Error: Quotient is less than 0!);  
    return (double) a/b;
}

int main() {
    int a = 31; int b = -12;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result is %f\n", result);
    } CATCH(exception_code); 
    return 0;
}

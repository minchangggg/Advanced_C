#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code; 
char *error_code;
enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x) 
#define THROW(x, ERROR_CODE) do {error_code = #ERROR_CODE; longjmp(buf, x);} while(0) 

void readFile() {
    printf("readFile...\n");
    THROW(FILE_ERROR, WARNING: FILE_ERROR);
}
    
void networkOperation() {
    printf("networkOperation...\n");
    THROW(NETWORK_ERROR, WARNING: NETWORK_ERROR);
}
    
void calculateData() {
    printf("calculateData...\n");
    THROW(CALCULATION_ERROR, WARNING: CALCULATION_ERROR);
}

int main() {
    TRY {
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) {
        printf("%s\n", error_code);
    } 
    CATCH(NETWORK_ERROR) {
        printf("%s\n", error_code);
    }
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_code);
    }
}

    

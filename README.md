# Lesson 1: COMPILER and MACRO
### A. COMPILER
> https://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/

**1, How do we compile and run a C program?**

-> Step 1: Creating a C Source File

-> Step 2: Compiling using GCC compiler

-> Step 3: Executing the program

**2, What is the compilation?**

The compilation is the process of converting the source code of the C language into machine code. 

C is a mid-level language, it needs a compiler to convert it into an executable code so that the program can be run on our machine.

**3, What goes inside the compilation process?**

<img width="600" alt="image" src="https://github.com/minchangggg/AdvancedC/assets/125820144/bce15492-bcab-4c06-aae9-b77140e00075">

**a, Preprocessor**

<img width="200" alt="image" src="https://github.com/minchangggg/AdvancedC/assets/125820144/7f77b474-8ea0-43d6-875a-65d38ccfc701">


<img width="500" alt="image" src="https://github.com/minchangggg/AdvancedC/assets/125820144/0e3464b8-1928-46bb-87ef-f719093c721d">

<img width="700" alt="image" src="https://github.com/minchangggg/AdvancedC/assets/125820144/c4392f1b-c42e-4fb6-ad13-514f92181ba2">


**b, Compiler** 

The compiler takes the preprocessed file and uses it to generate corresponding assembly code. 

<img width="200" alt="image" src="https://github.com/minchangggg/AdvancedC/assets/125820144/cba3c714-7fb1-4289-bf20-b31dedd5950d">

<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/572bbb3e-4c88-46aa-87b0-b83096c05db3">

=> This file is in assembly-level instructions.

**c, Assembler**

Assembles the code into object code 

< Where assembly code represents a correspondence between program and machine code, object code represents pure machine code (ie. binary) >

<img width="200" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d5cc0269-704f-47e2-8836-8be945268cd6"> => This file contains machine-level instructions.

<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d3b1bed3-c128-4302-98ca-402b2cf02bbf">


**d, Linker**

<img width="200" alt="image" src="https://github.com/minchangggg/AdvancedC/assets/125820144/7d3880db-b0b7-46e9-8c31-21035966c67e">


<img width="250" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/973c3ae7-18ae-4786-939b-11fa524098ec">

### B. MACRO

> https://www.programiz.com/c-programming/c-preprocessor-macros

There are devided into 3 main groups: 
+ Including Header Files: #include
+ Macros using #define (Function like Macros...)
+ Conditional Compilation: #ifdef, #if, #defined, #else and #elif

a, How to include files with the #include directive
            
            #include <stdio.h>
            #include "myfile.h"
      
            int main() {
            	printf(message);
            	return 0;
            }

b, How to define a macro with #define

            #include <stdio.h>
            
            #define MESSAGE "Hello World" // macro definition
            #define TRUE 1 // macro definition
            #define FALSE 0 // macro definition
            #define SUM (3 + 5) // macro definition
            
            int main() {
                printf("String: %s\n", MESSAGE);
                printf("Custom boolean TRUE: %d\n", TRUE);
                printf("Custom boolean FALSE: %d\n", FALSE);
                printf("Arithmetic: 3+5=%d\n", SUM);
                return 0;
            }

c, How to undefine a macro with #undef

=> We can remove, or redefine, a macro that we set up previously with the #undef directive.
Macro definition is typically done at the top of the document, but macro undefining and redefining is done inside the rest of the document.

            #include <stdio.h>
            
            #define MESSAGE "Hello World"
            
            int main() {
                printf("String: %s\n", MESSAGE);
                #undef MESSAGE // remove macro
                #define MESSAGE "Hello there" // redefine macro
                printf("String: %s\n", MESSAGE);
                return 0;
            }
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 2: STDARG and ASSERT
### A. C Library - <stdarg.h>
*The stdarg.h header defines a variable type va_list and three macros which can be used to get the arguments in a function when the number of arguments are not known i.e. variable number of arguments.*

**1, Library Variables**
	
<img width="300" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/4cd3fc83-555d-4b23-b9d7-b6ac2b99a1e5">

**2, Library Macros**

<img width="350" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d7d6df93-5ca0-4d23-866c-ddbd1fd3a475">


**3, Example**

Example 1:

	#include <stdio.h>
	#include <stdarg.h>
	
	int sum(int count, ...) {
	    va_list args; // args là 1 con trỏ, dùng để các lưu địa chỉ các tham số truyền vào
	    va_start(args, count);  // va_start () tạo vùng nhớ, địa chỉ đầu tiên của nó là địa chỉ biến count đc lưu trong args
	
	    int result = 0;
	    for (int i = 0; i < count; i++) {
		result += va_arg(args, int); // va_arg () dịch chuyển đến địa chỉ tiếp theo, và lấy giá trị tại địa chỉ đó
	    }
	
	    va_end(args); // va_ end () giải phóng vùng nhớ 
	
	    return result;
	}
	
	int main() {
	    printf("Sum: %d\n", sum(4, 1, 2, 3, 4));
	    return 0;
	}

Example 2:

            #include <stdio.h>
            #include <stdarg.h>
            
            typedef enum {
                TEMPERATURE_SENSOR,
                PRESSURE_SENSOR
            } SensorType;
            
            void processSensorData(SensorType type, ...) {
                va_list args;
                va_start(args, type);
            
                switch (type) {
                    case TEMPERATURE_SENSOR: {
                        int numArgs = va_arg(args, int);
                        int sensorId = va_arg(args, int);
                        float temperature = va_arg(args, double); // float được promote thành double
                        printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);
                        if (numArgs > 2) {
                            // Xử lý thêm tham số nếu có
                            char* additionalInfo = va_arg(args, char*);
                            printf("Additional Info: %s\n", additionalInfo);
                        }
                        break;
                    }
                    case PRESSURE_SENSOR: {
                        int numArgs = va_arg(args, int);
                        int sensorId = va_arg(args, int);
                        int pressure = va_arg(args, int);
                        printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);
                        if (numArgs > 2) {
                            // Xử lý thêm tham số nếu có
                            char* unit = va_arg(args, char*);
                            printf("Unit: %s\n", unit);
                        }
                        break;
                    }
                }
            
                va_end(args);
            }
            
            int main() {
                processSensorData(TEMPERATURE_SENSOR, 3, 1, 36.5, "Room Temperature");
                processSensorData(PRESSURE_SENSOR, 2, 2, 101325);
                return 0;
            }

### B. C Library - <assert.h>

> - Provides a macro called assert
> 
> - This macro can be used to verify assumptions made by the program. 
> 
> - If this assumption is false, nothing happens and the program continues to execute.
> 
> - If this assumption is false, The program stops to execute and print a diagnostic message.
> 
> - Using for debugging, use #define NDEBUG to turn off debug mode.

Ex:

<img width="800" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/ec805091-04c8-4347-9e39-b5b9be87acf6">

**Macro is used for debugging**

		#define LOG(condition, cmd) assert(condition && #cmd);

Ex1: 

		#include <assert.h>
		#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))
		
		void setLevel(int level) {
		    ASSERT_IN_RANGE(level, 1, 10);
		    // Thiết lập cấp độ
		}

Ex2:  

		#include <assert.h>
		#include <stdint.h>
		
		#define ASSERT_SIZE(type, size) assert(sizeof(type) == (size))
		
		void checkTypeSizes() {
		    ASSERT_SIZE(uint32_t, 4);
		    ASSERT_SIZE(uint16_t, 2);
		    // Kiểm tra các kích thước kiểu dữ liệu khác
		}
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 3: POINTER
### A. Function Pointer

### B. Void Pointer

### C. Pointer to Constant

### D. Constant Pointer

### E. Pointer to Pointer

### F. NULL Pointer
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 4: EXTERN - STATIC - VOLATILE - REGISTER
### A. Extern

### B. Static

### C. Volatile

### D. Register
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 5: GOTO - setjmp.h
### A. Goto
**Ex1**

<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/6fcf16fd-b6a3-4a34-b1ab-e45f070bf5ad">

**Ex2**

<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/a4a25f0f-f5c9-4816-bba3-a9f5896e5817">

**Ex3**

<img width="600" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/80e7ef78-3e98-4e04-b7d8-012615790033">


		#include <stdio.h>
		
		void delay() {
		    double start;
		    while (start < 60000000) start++;
		}
		
		char letter = 'A';
		char first_sentence[] = "HELLO";
		char second_sentence[] = "FASHION COTHES";
		char third_sentence[] = "SUITABLE PRICE";
		
		int letter_A[8][8] = {  {0,0,1,0,0,0,0,0},
		                        {0,1,0,1,0,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,1,1,1,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},  };
		
		int letter_H[8][8] = {  {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,1,1,1,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},
		                        {1,0,0,0,1,0,0,0},  };
		
		int letter_L[8][8] = {  {1,0,0,0,0,0,0,0},
		                        {1,0,0,0,0,0,0,0},
		                        {1,0,0,0,0,0,0,0},
		                        {1,0,0,0,0,0,0,0},
		                        {1,0,0,0,0,0,0,0},
		                        {1,0,0,0,0,0,0,0},
		                        {1,0,0,0,0,0,0,0},
		                        {1,1,1,1,1,0,0,0},  };
		
		
		// H, e, l,o, F, a, ....
		
		int button = 0;
		
		typedef enum {
		    FIRST,
		    SECOND,
		    THIRD
		}   Sentence;
		
		int main() {
		    Sentence sentence = FIRST;
		
		    while(1) {
		        switch (sentence) {
		            case FIRST:
		                for (int index = 0; index < sizeof(first_sentence); index++) {
		                    if (first_sentence[index] == 'H') {
		                        for (int i = 0; i < 8; i++) {    
		                            for (int j = 0; j < 8; j++) {
		                                if (letter_H[i][j] == 1) {
		                                    printf("Turn on led at [%d][%d]\n", i,j);
		                                    if (button == 1) { goto exit_loops; }
		                                }
		                            }
		                            // tat den
		                        }
		                    }
		                    if (first_sentence[index] == 'e') {
		                        // in ra chu e
		                    }
		                }
		                printf("first sentence is done\n");
		                delay();
		                goto logic;
		
		            case SECOND:
		                for (int index = 0; index < sizeof(second_sentence); index++) {
		                    if (second_sentence[index] == 'A') {
		                        for (int i = 0; i < 8; i++) {    
		                            for (int j = 0; j < 8; j++) {
		                                if (letter_A[i][j] == 1) {
		                                    printf("Turn on led at [%d][%d]\n", i,j);
		                                    if (button == 1) { goto exit_loops; }
		                                }
		                            }
		                            // tat den led
		                        }
		                    }
		                    if (second_sentence[index] == 'F') {
		                        // in ra chu F
		                    }
		                }
		                printf("second sentence is done\n");
		                delay();
		                goto logic;
		
		            case THIRD:
		                for (int index = 0; index < sizeof(third_sentence); index++) {
		                    if (third_sentence[index] == 'L') {
		                        for (int i = 0; i < 8; i++) {    
		                            for (int j = 0; j < 8; j++) {
		                                if (letter_L[i][j] == 1) {
		                                    printf("Turn on led at [%d][%d]\n", i,j);
		                                    if (button == 1) { goto exit_loops; }   
		                                }
		                            }
		                            // tat den led
		                        }
		                    }
		                    if (third_sentence[index] == 'E') {
		                        // in ra chu H
		                    }
		                }
		                printf("third sentence is done\n");
		                delay();
		                //button = 1; 
		                goto logic;
		        }
		
		        logic:
		            if (sentence == FIRST) { sentence = SECOND; }
		            else if (sentence == SECOND) { sentence = THIRD; }
		            else if (sentence == THIRD) { sentence = FIRST; }
		            goto exit;
		            
		        exit_loops:
		            printf("Stop!\n");
		            break;
		        
		        exit:;
		        
		    }
		    return 0;
		}

### B. C Library - <setjmp.h>
 
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 6: BITMASK

<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d7d9f1a0-b842-4d91-b95f-5efdeed6f534">
<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/84a5abe2-3eae-4f1c-b7ef-74cfe5805bac">

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 7: Struct - Union
### A. Struct

### B. Union
_________________________________________________________________________________________________________________________________________________________________________
# Lesson 8: Memory layout

<img width="385" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/0adf350d-f3aa-4fb0-b846-c3e45045d90b">

[<img src="https://github.com/minchangggg/Basic_C/assets/125820144/444853d4-ceb8-415a-b050-bd8f9b3bc0a9" alt="hehe" width="20" />] How C program structure the memory area?   https://www.scaler.com/topics/c/memory-layout-in-c/
<img width="600" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/f1df255f-ed94-47f5-8850-9ea39d21bd94">


<img width="275" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/022c1cb6-ae90-482b-9e93-9e0205e7169e">

+ Contains executable instructions 
+ Sharable                         
+ Read-only                        

<img width="275" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/83b76c76-3a89-465b-a3ad-efa4f64a7c28">

| Global variables & Static variables | Initialized (≠0) by programmer |

Ex:
<img width="555" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/879a182d-4990-42d1-9b13-51686eca892d">


<img width="275" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/9b7a668f-bdf8-4ef4-aee0-c54fe0713601">

| Global variables & Static variables | Uninitialized or Initialized (=0) by programmer |

Ex:
<img width="556" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/300dcabf-ad5f-42fa-b261-cbae175fc4ce">

                                                                                                                                 
<img width="275" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/41ca0f62-4f37-4a2e-8954-a2656ab66d00"> ***-> Dynamic Memory Allocation***

+ malloc/ calloc/ realloc/ free
+ new/ delete
> Forget to deallocate memory in Heap -> cause Memory leak

Ex 1

		#include <stdlib.h>
		int main() {
		    int *arr_malloc, *arr_calloc;
		    size_t size = 5;
		
		    arr_malloc = (int*)malloc(size * sizeof(int)); // Sử dụng malloc
		    arr_calloc = (int*)calloc(size, sizeof(int)); // Sử dụng calloc
		    // ...
		
		    // Giải phóng bộ nhớ
		    free(arr_malloc);
		    free(arr_calloc);
		    return 0;
		}
Ex 2

		#include <stdio.h>
		#include <stdlib.h>
		
		int main(int argc, char const *argv[]) {  
		    int soluongkytu = 0;
		    char* ten = (char*) malloc(sizeof(char) * soluongkytu);
		
		    for (int i = 0; i < 3; i++) {
		        printf("Nhap so luong ky tu trong ten: \n");
		        scanf("%d", &soluongkytu);
		        ten = realloc(ten, sizeof(char) * soluongkytu);
		        printf("Nhap ten cua ban: \n");
		        scanf("%s", ten);
		
		        printf("Hello %s\n", ten);
		    }
		    return 0;
		}

  Ex 3
		#include <stdio.h>
		#include <stdlib.h>
		
		void test1() {
		    int array[3];
		    for (int i = 0; i < 3; i++) {
		        printf("address of array[%d]: %p\n", i, (array+i));
		    }
		    printf("----------------------\n");
		}
		
		void test2() {
		    int *array = (int*)malloc(3*sizeof(int));
		    for (int i = 0; i < 3; i++) {
		        printf("address of array[%d]: %p\n", i, (array+i));
		    }
		    printf("----------------------\n");
		    //free(array);
		}
		
		int main(int argc, char const *argv[]) {  
		    test1(); test1();
		    test2(); test2();
		    return 0;
		}

<img width="275" alt="image" src="https://github.com/minchangggg/Basic_C/assets/125820144/dfab2f7c-6509-497c-939f-5e68f43566af"> ***-> Automatic Variable Storage***

<img src="https://scaler.com/topics/images/stack-segment.webp" alt="meme" width="300" /> 

| LIFO structure (Last In First Out) 

| Grows in the direction opposite to heap

| Function frame  


**CONCLUSION**

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 9: JSON


__________________________________________________________________________________________________________________________________________________________________________
# Lesson 10: Linked List


__________________________________________________________________________________________________________________________________________________________________________

  





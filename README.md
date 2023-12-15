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
# Lesson 2: STDARG and ASSERT
### A. CC Library - <stdarg.h>
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

		#include <stdio.h>
		#include <assert.h>
		
		int main() {
		    int x = 5;
		    assert(x == 5);  // Chương trình sẽ tiếp tục thực thi nếu điều kiện x = 5 là đúng.
		    printf("X is: %d", x);
		    return 0;
		}

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

  

		


  





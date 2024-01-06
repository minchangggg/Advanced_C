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

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 9: JSON

+ JSON stands for JavaScript Object Notation
+ JSON is a text format for storing and transporting data
+ JSON is "self-describing" and easy to understand
		
		#include <stdio.h>
		#include <string.h>
		#include <stdlib.h>
		#include <stddef.h>
		#include <ctype.h>
		#include <stdbool.h>
		
		typedef enum {
		    JSON_NULL,
		    JSON_BOOLEAN,
		    JSON_NUMBER,
		    JSON_STRING,
		    JSON_ARRAY,
		    JSON_OBJECT
		} JsonType;
		
		typedef struct JsonValue {
		    JsonType type;
		    union {
		        int boolean; double number; char *string;
		        struct {
		            struct JsonValue *values;
		            size_t count;
		        } array;
		        struct {
		            char **keys;
		            struct JsonValue *values;
		            size_t count;
		        } object;
		    } value;
		} JsonValue;
		
		JsonValue *parse_json(const char **json);
		
		void free_json_value(JsonValue *json_value);
		
		static void skip_whitespace(const char **json) {
		    while (isspace(**json)) {
		        (*json)++;
		    }
		}
		
		JsonValue *parse_null(const char **json) {
		    skip_whitespace(json);
		    if (strncmp(*json, "null", 4) == 0) {
		        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
		        value->type = JSON_NULL;
		        *json += 4;
		        return value;
		    }
		    return NULL;
		}
		
		JsonValue *parse_boolean(const char **json) {
		    skip_whitespace(json);
		    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
		    if (strncmp(*json, "true", 4) == 0) {
		        value->type = JSON_BOOLEAN;
		        value->value.boolean = true;
		        *json += 4;
		    } else if (strncmp(*json, "false", 5) == 0) {
		        value->type = JSON_BOOLEAN;
		        value->value.boolean = false;
		        *json += 5;
		    } else {
		        free(value);
		        return NULL;
		    }
		    return value;
		}
		
		JsonValue *parse_number(const char **json) {
		    skip_whitespace(json);
		    char *end;
		
		    double num = strtod(*json, &end);
		    if (end != *json) {
		        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
		        value->type = JSON_NUMBER;
		        value->value.number = num;
		        *json = end;
		        return value;
		    }
		    return NULL;
		}
		
		JsonValue *parse_string(const char **json) {
		    skip_whitespace(json);
		
		    if (**json == '\"') {
		        (*json)++;
		        const char *start = *json;
		        while (**json != '\"' && **json != '\0') {
		            (*json)++;
		        }
		        if (**json == '\"') {
		            size_t length = *json - start; // 3
		            char *str = (char *) malloc((length + 1) * sizeof(char));
		            strncpy(str, start, length);
		            str[length] = '\0';
		
		            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
		            value->type = JSON_STRING;
		            value->value.string = str;
		            (*json)++;
		            return value;
		        }
		    }
		    return NULL;
		}
		
		JsonValue *parse_array(const char **json) {
		    skip_whitespace(json);
		    if (**json == '[') {
		        (*json)++;
		        skip_whitespace(json);
		
		        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
		        array_value->type = JSON_ARRAY;
		        array_value->value.array.count = 0;
		        array_value->value.array.values = NULL;
		
		        /*
		        double arr[2] = {};
		        arr[0] = 30;
		        arr[1] = 70;
		        */
		
		        while (**json != ']' && **json != '\0') {
		            JsonValue *element = parse_json(json); // 70
		            if (element) {
		                array_value->value.array.count++;
		                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
		                array_value->value.array.values[array_value->value.array.count - 1] = *element;
		                free(element);
		            } else {
		                break;
		            }
		            skip_whitespace(json);
		            if (**json == ',') {
		                (*json)++;
		            }
		        }
		        if (**json == ']') {
		            (*json)++;
		            return array_value;
		        } else {
		            free_json_value(array_value);
		            return NULL;
		        }
		    }
		    return NULL;
		}
		
		JsonValue *parse_object(const char **json) {
		    skip_whitespace(json);
		    if (**json == '{') {
		        (*json)++;
		        skip_whitespace(json);
		
		        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
		        object_value->type = JSON_OBJECT;
		        object_value->value.object.count = 0;
		        object_value->value.object.keys = NULL;
		        object_value->value.object.values = NULL;
		
		        while (**json != '}' && **json != '\0') {
		            JsonValue *key = parse_string(json);
		            if (key) {
		                skip_whitespace(json);
		                if (**json == ':') {
		                    (*json)++;
		                    JsonValue *value = parse_json(json);
		                    if (value) {
		                        object_value->value.object.count++;
		                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
		                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;
		
		                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
		                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
		                        free(value);
		                    } else {
		                        free_json_value(key);
		                        break;
		                    }
		                } else {
		                    free_json_value(key);
		                    break;
		                }
		            } else {
		                break;
		            }
		            skip_whitespace(json);
		            if (**json == ',') {
		                (*json)++;
		            }
		        }
		        if (**json == '}') {
		            (*json)++;
		            return object_value;
		        } else {
		            free_json_value(object_value);
		            return NULL;
		        }
		    }
		    return NULL;
		}
		
		JsonValue *parse_json(const char **json) { 
		    while (isspace(**json)) {
		        (*json)++;
		    }
		
		    switch (**json) {
		        case 'n':
		            return parse_null(json);
		        case 't':
		        case 'f':
		            return parse_boolean(json);
		        case '\"':
		            return parse_string(json);
		        case '[':
		            return parse_array(json);
		        case '{':
		            return parse_object(json);
		        default:
		            if (isdigit(**json) || **json == '-') return parse_number(json);
		            else return NULL; // Lỗi phân tích cú pháp
		    }
		}
		
		void free_json_value(JsonValue *json_value) {
		    if (json_value == NULL) return;
		    
		    switch (json_value->type) {
		        case JSON_STRING:
		            free(json_value->value.string);
		            break;
		        case JSON_ARRAY:
		            for (size_t i = 0; i < json_value->value.array.count; i++) {
		                free_json_value(&json_value->value.array.values[i]);
		            }
		            free(json_value->value.array.values);
		            break;
		        case JSON_OBJECT:
		            for (size_t i = 0; i < json_value->value.object.count; i++) {
		                free(json_value->value.object.keys[i]);
		                free_json_value(&json_value->value.object.values[i]);
		            }
		            free(json_value->value.object.keys);
		            free(json_value->value.object.values);
		            break;
		        default:
		            break;
		    }
		}
		
		void test(JsonValue* json_value){
		    if (json_value != NULL && json_value->type == JSON_OBJECT) {
		        // Truy cập giá trị của các trường trong đối tượng JSON
		        size_t num_fields = json_value->value.object.count;
		        size_t num_fields2 = json_value->value.object.values->value.object.count;
		        for (size_t i = 0; i < num_fields; ++i) {
		
		            char* key = json_value->value.object.keys[i];
		            JsonValue* value = &json_value->value.object.values[i];
		
		            JsonType type = (int)(json_value->value.object.values[i].type);
		
		            if(type == JSON_STRING) printf("%s: %s\n", key, value->value.string);
		        
		            if(type == JSON_NUMBER) printf("%s: %f\n", key, value->value.number);
		        
		            if(type == JSON_BOOLEAN) printf("%s: %s\n", key, value->value.boolean ? "True":"False");
		
		            if(type == JSON_OBJECT){
		                printf("%s: \n", key);
		                test(value);
		            }
		
		            if(type == JSON_ARRAY){
		                printf("%s: ", key);
		                for (int i = 0; i < value->value.array.count; i++) {
		                   test(value->value.array.values + i);
		                } 
		                printf("\n");
		            }
		        }
		    } else {
			    if(json_value->type == JSON_STRING) printf("%s ", json_value->value.string);
			    
			    if(json_value->type == JSON_NUMBER) printf("%f ", json_value->value.number);
			
			    if(json_value->type == JSON_BOOLEAN) printf("%s ", json_value->value.boolean ? "True":"False");
			
			    if(json_value->type == JSON_OBJECT){
				printf("%s: \n", json_value->value.object.keys);
				test(json_value->value.object.values);          
		            }
		      }
		}
		
		int main(int argc, char const *argv[]) {
		     
		     // Chuỗi JSON đầu vào
		    const char* json_str = "{"
		                        "\"1001\":{"
		                          "\"SoPhong\":3,"
		                          "\"NguoiThue\":{"
		                            "\"Ten\":\"Nguyen Van A\","
		                            "\"CCCD\":\"1920517781\","
		                            "\"Tuoi\":26,"
		                            "\"ThuongTru\":{"
		                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
		                              "\"Phuong_Xa\":\"Phuong 6\","
		                              "\"Tinh_TP\":\"Ho Chi Minh\""
		                            "}"
		                          "},"
		                          "\"SoNguoiO\":{"
		                            "\"1\":\"Nguyen Van A\","
		                            "\"2\":\"Nguyen Van B\","
		                            "\"3\":\"Nguyen Van C\""
		                          "},"
		                          "\"TienDien\": [24, 56, 98],"
		                          "\"TienNuoc\":30.000"
		                        "},"
		                        "\"1002\":{"
		                          "\"SoPhong\":5,"
		                          "\"NguoiThue\":{"
		                            "\"Ten\":\"Phan Hoang Trung\","
		                            "\"CCCD\":\"012345678912\","
		                            "\"Tuoi\":24,"
		                            "\"ThuongTru\":{"
		                              "\"Duong\":\"53 Le Dai Hanh\","
		                              "\"Phuong_Xa\":\"Phuong 11\","
		                              "\"Tinh_TP\":\"Ho Chi Minh\""
		                            "}"
		                          "},"
		                          "\"SoNguoiO\":{"
		                            "\"1\":\"Phan Van Nhat\","
		                            "\"2\":\"Phan Van Nhi\","
		                            "\"2\":\"Phan Van Tam\","
		                            "\"3\":\"Phan Van Tu\""
		                          "},"
		                          "\"TienDien\":23.000,"
		                          "\"TienNuoc\":40.000"
		                        "}"
		                      "}";
		    
		
		    // Phân tích cú pháp chuỗi JSON
		    JsonValue* json_value = parse_json(&json_str);
		
		   test(json_value);
		
		    // Kiểm tra kết quả phân tích cú pháp
		
		       // Giải phóng bộ nhớ được cấp phát cho JsonValue
		    free_json_value(json_value);
		    
		        //printf("test = %x", '\"');
		
		       // hienthi(5);
		    
		    return 0;
		}
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 10: Linked List
> https://www.simplilearn.com/tutorials/data-structure-tutorial/linked-list-in-data-structure#:~:text=A%20linked%20list%20is%20the,reference%20to%20the%20next%20node.
>
> https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
>
> https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/

<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/ee824eda-c2cd-498d-a35a-f328d0e35802">

**What is a Linked List?** 

+ A linked list is a linear data structure that stores a collection of data elements dynamically.
+ Nodes represent those data elements, and links or pointers connect each node.
+ Each node consists of two fields, the information stored in a linked list and a pointer that stores the address of its next node.
+ The last node contains null in its second field because it will point to no node.
+ A linked list can grow and shrink its size, as per the requirement.
+ It does not waste memory space.

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/979b63f1-cfa0-4070-ace0-37433d0e36ca)

		tyedef struct Node { 
			int value;
			struct Node* next;
		} Node;
		
		Node* createNode (int value) {
			Node* ptr = (Node*)malloc(sizeof(Node));
		 	ptr->value = value;
		  	ptr->next = NULL;
		   	return ptr;
		};

### 1, Insertion at Beginning
> In this operation, we are adding an element at the beginning of the list.
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/d69d5ce7-5b09-41f9-90e5-3689469f3123)

**a, Algorithm**

> 1. START
> 2. Create a node to store the data
> 3. Check if the list is empty
> 4. If the list is empty, add the data to the node and assign the head pointer to it.
> 5. If the list is not empty, add the data to a node and link to the current head. Assign the head to the newly added node.
> 6. END

**b, Example**

		#include <stdio.h>
		#include <string.h>
		#include <stdlib.h>
		struct node {
		   int data;
		   struct node *next;
		};
		struct node *head = NULL;
		struct node *current = NULL;
		
		// display the list
		void printList(){
		   struct node *p = head;
		   printf("\n[");
		   
		   //start from the beginning
		   while(p != NULL) {
		      printf(" %d ",p->data);
		      p = p->next;
		   }
		   printf("]");
		}
		
		//insertion at the beginning
		void insertatbegin(int data){
		   
		   //create a link
		   struct node *ptr = (struct node*) malloc(sizeof(struct node));
		   ptr->data = data;
		   
		   // point it to old first node
		   ptr->next = head;
		   
		   //point first to new first node
		   head = ptr;
		}
		void main(){
		   int k=0;
		   insertatbegin(12);
		   insertatbegin(22);
		   insertatbegin(30);
		   insertatbegin(44);
		   insertatbegin(50);
		   printf("Linked List: ");
		   
		   // print list
		   printList();
		}
  
<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/592effc0-2d14-4b7a-90c2-4d6f5742f9f3">

  
### 2, Insertion at Ending
> In this operation, we are adding an element at the ending of the list.
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/f0610056-d3e5-4984-9eb8-b1ef9c95dc04)

**a, Algorithm**

> 1. START
> 2. Create a new node and assign the data
> 3. Find the last node
> 4. Point the last node to new node
> 5. END

**b, Example**

		#include <stdio.h>
		#include <string.h>
		#include <stdlib.h>
		struct node {
		   int data;
		   struct node *next;
		};
		struct node *head = NULL;
		struct node *current = NULL;
		
		// display the list
		void printList(){
		   struct node *p = head;
		   printf("\n[");
		   
		   //start from the beginning
		   while(p != NULL) {
		      printf(" %d ",p->data);
		      p = p->next;
		   }
		   printf("]");
		}
		
		//insertion at the beginning
		void insertatbegin(int data){
		
		   //create a link
		   struct node *lk = (struct node*) malloc(sizeof(struct node));
		   lk->data = data;
		
		   // point it to old first node
		   lk->next = head;
		   
		   //point first to new first node
		   head = lk;
		}
		void insertatend(int data){
		
		   //create a link
		   struct node *lk = (struct node*) malloc(sizeof(struct node));
		   lk->data = data;
		   lk->next = NULL;
		   struct node *linkedlist = head;
		
		   // point it to old first node
		   while(linkedlist->next != NULL)
		      linkedlist = linkedlist->next;
		
		   //point first to new first node
		   linkedlist->next = lk;
		}
		void main(){
		   int k=0;
		   insertatbegin(12);
		   insertatend(22);
		   insertatend(30);
		   insertatend(44);
		   insertatend(50);
		   printf("Linked List: ");
		   
		   // print list
		   printList();
		}

<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d8f39a14-fe6e-4e6d-b49e-bd107bd3dc8c">

### 3, Insertion at a Given Position
> In this operation, we are adding an element at any position within the list.
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/6c3b2d99-93db-4b78-9c4d-2d99ab5992c5)

**a, Algorithm**

> 1. START
> 2. Create a new node and assign data to it
> 3. Iterate until the node at position is found
> 4. Point first to new first node
> 5. END

**b, Example**

		#include <stdio.h>
		#include <string.h>
		#include <stdlib.h>
		struct node {
		   int data;
		   struct node *next;
		};
		struct node *head = NULL;
		struct node *current = NULL;
		
		// display the list
		void printList(){
		   struct node *p = head;
		   printf("\n[");
		   
		   //start from the beginning
		   while(p != NULL) {
		      printf(" %d ",p->data);
		      p = p->next;
		   }
		   printf("]");
		}
		
		//insertion at the beginning
		void insertatbegin(int data){
		
		   //create a link
		   struct node *lk = (struct node*) malloc(sizeof(struct node));
		   lk->data = data;
		
		   // point it to old first node
		   lk->next = head;
		
		   //point first to new first node
		   head = lk;
		}
		void insertafternode(struct node *list, int data){
		   struct node *lk = (struct node*) malloc(sizeof(struct node));
		   lk->data = data;
		   lk->next = list->next;
		   list->next = lk;
		}
		void main(){
		   int k=0;
		   insertatbegin(12);
		   insertatbegin(22);
		   insertafternode(head->next, 30);
		   printf("Linked List: ");
		
		   // print list
		   printList();
		}

  <img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/abd78c80-61bf-480c-9e33-1b3e688b8d2b">

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 11: Stack - Queue
### A. Stack
> https://www.programiz.com/dsa/stack
>
> https://medium.com/@noransaber685/understanding-the-stack-data-structure-in-c-introduction-implementation-and-examples-8d3fb03de809

**I. What is Stack?**

**1. What is stack**

+ A stack is a linear data structure in which **the insertion of a new element** and **removal of an existing element** takes place at the same end **represented as the top** of the stack.
+  It follows the principle of LIFO (Last In First Out) - This means the last element inserted inside the stack is removed first.

<img width="300" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/55f10aaa-82e2-4680-8ae4-39c561f2c990">

**II, Basic Operations on Stack**

+ push() to insert an element into the stack
+ pop() to remove an element from the stack
+ peek() Get the value of the top element without removing it.
+ isempty() Check if the stack is empty.
+ isfull() Check if the stack is full.
+ size() returns the size of stack.

**How does it work?**

- The operations work as follows:

		+ A pointer called TOP is used to keep track of the top element in the stack.
		+ When initializing the stack, we set its value to -1 so that we can check if the stack is empty by comparing TOP == -1.
		+ On pushing an element, we increase the value of TOP and place the new element in the position pointed to by TOP.
		+ On popping an element, we return the element pointed to by TOP and reduce its value.
		+ Before pushing, we check if the stack is already full
		+ Before popping, we check if the stack is already empty

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d462b229-251d-47f8-aff5-04c5ce8c892a">

**1, peek()**

		int peek() {
		   return stack[top];
		}
  
**2, isempty() and isfull()**

		bool isempty() {
		   if(top == -1)
		      return true;
		   else
		      return false;
		}
		
		bool isfull() {
		   if(top == MAXSIZE)
		      return true;
		   else
		      return false;
		}

**3, push()**

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/e9f2b080-6a10-40c0-a328-86d260fc36eb)

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/cb6720f7-56a7-4fc2-8e89-26bc6251b2d9)

		void push(int data) {
		   if(!isFull()) {
		      top = top + 1;   
		      stack[top] = data;
		   } else {
		      printf("Stack overflow\n");
		   }
		}

**3, pop()**
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/74b92116-7d5d-4cb3-9821-1e2125aa4f6a)

		int pop(int data) {
		   if(!isempty()) {
		      data = stack[top];
		      top = top - 1;   
		      return data;
		   } else {
		      printf("Stack underflow\n");
		   }
		}

**III, Complete Example**

EX1:

		#include <stdio.h>
		#include <stdlib.h>
		
		typedef struct Stack {
		    int* items; // mảng để lưu giá trị của từng ô
		    int size;
		    int top;
		} Stack;
		
		void initialize( Stack *stack, int size) {
		    stack->items = (int*) malloc(sizeof(int) * size);
		    stack->size = size;
		    stack->top = -1;
		}
		
		int is_empty( Stack stack) {
		    return stack.top == -1;
		}
		
		int is_full( Stack stack) {
		    return stack.top == stack.size - 1;
		}
		
		void push( Stack *stack, int value) {
		    if (!is_full(*stack)) {
		        stack->items[++stack->top] = value;
		    } else {
		        printf("Stack overflow\n");
		    }
		}
		
		int pop( Stack *stack) {
		    if (!is_empty(*stack)) {
		        return stack->items[stack->top--];
		    } else {
		        printf("Stack underflow\n");
		        return -1;
		    }
		}
		
		int top( Stack stack) {
		    if (!is_empty(stack)) {
		        return stack.items[stack.top];
		    } else {
		        printf("Stack is empty\n");
		        return -1;
		    }
		}
		
		int main() {
		    Stack stack1;
		    initialize(&stack1, 5);
		
		
		    push(&stack1, 10);
		    push(&stack1, 20);
		    push(&stack1, 30);
		    push(&stack1, 40);
		    push(&stack1, 50);
		    push(&stack1, 60);
		
		    printf("Top element: %d\n", top(stack1)); // 50
		
		    printf("Pop element: %d\n", pop(&stack1)); // 50
		    printf("Pop element: %d\n", pop(&stack1)); // 40
		
		    printf("Top element: %d\n", top(stack1)); // 30
		
		    return 0;
		}

EX2:

		#include <stdio.h>
		#include <stdlib.h>

		void push();
		void pop();
		void display();

		struct node {
		    int data;
		    struct node* next;
		};
		
		struct node* temp; // Variable to store the top of the stack
		
		int main() {
		    printf("LINKED LIST IMPLEMENTATION USING STACKS\n\n");
		    do {
		        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		        printf("Enter your choice:");
		        int choice; scanf("%d", &choice);
		        
		        switch (choice) {
		            case 1:
		                push();
		                break;
		            case 2:
		                pop();
		                break;
		            case 3:
		                display();
		                break;
		            case 4:
		                exit(0);
		                break;
		            default:
		                printf("Please re-enter!\n");
		                break;
		        }
		    } while (choice != 4);
		    return 0;
		}
		
		void push() {
		    int data;
		    struct node* pointer = (struct node*)malloc(sizeof(struct node));
		    
		    if (pointer == NULL) printf("Stack overflow\n");
		    else {
		        printf("Enter the element to be inserted: ");
		        scanf("%d", &data);
		        
		        if (temp == NULL) {
		            pointer->data = data;
		            pointer->next = NULL;
		            temp = pointer;
		        } else {
		            pointer->data = data;
		            pointer->next = temp;
		            temp = pointer;
		        }
		    }
		}
		
		void pop() {
		    int item;
		    struct node* pointer;
		    
		    if (temp == NULL) {
		        printf("Stack underflow\n");
		    }
		    else {
		        item = temp->data;
		        pointer = temp;
		        temp = temp->next;
		        free(pointer);
		        printf("The deleted item is %d\n", item);
		    }
		}
		
		void display() {
		    struct node* pointer;
		    pointer = temp;
		    
		    if (pointer == NULL) {
		        printf("Stack underflow\n");
		    }
		    else {
		        printf("The elements of the stack are:\n");
		        
		        while (pointer != NULL) {
		            printf("%d\n", pointer->data);
		            pointer = pointer->next;
		        }
		    }
		}

### B. Queue
> https://www.programiz.com/dsa/queue
>
> https://www.scaler.com/topics/data-structures/queue-in-data-structure/

**I. What is Queue?**

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/6318de71-e333-4fce-b048-86106e9d205b)

+ Queue follows the **First In First Out (FIFO)** rule - the item that goes in first is the item that comes out first.
<img width="566" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/065c4cd5-c919-4a80-b60c-55d6fbb38400">

**II, Basic Operations on Queue**

+ Enqueue: Add an element to the end of the queue
+ Dequeue: Remove an element from the front of the queue
+ IsEmpty: Check if the queue is empty
+ IsFull: Check if the queue is full
+ Peek: Get the value of the front of the queue without removing it

**How does it work?**

- Queue operations work as follows:

		+ two pointers FRONT and REAR
		+ FRONT track the first element of the queue
		+ REAR track the last element of the queue
		+ initially, set value of FRONT and REAR to -1

  <img width="450" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/b505dc7b-f5b8-4c3d-91b9-e9baef1e969f">

**III, Complete Example**

Ex:

		#include <stdio.h>
		#include <stdlib.h>
		
		
		typedef struct Queue {
		    int* items; // mảng để lưu giá trị của từng ô
		    int size;
		    int front, rear; // để xác định phần tử nào đứng đầu, phần tử nào đứng cuối hàng
		} Queue;
		
		void initialize(Queue *queue, int size) {
		    queue->items = (int*) malloc(sizeof(int)* size);
		    queue->front = -1;
		    queue->rear = -1;
		    queue->size = size;
		}
		
		int is_empty(Queue queue) {
		    return queue.front == -1;
		}
		
		int is_full(Queue queue) {
		    return (queue.rear + 1) % queue.size == queue.front;
		}
		
		void enqueue(Queue *queue, int value) {
		    if (!is_full(*queue)) {
		        if (is_empty(*queue)) {
		            queue->front = queue->rear = 0;
		        } else {
		            queue->rear = (queue->rear + 1) % queue->size;
		        }
		        queue->items[queue->rear] = value;
		    } else {
		        printf("Queue overflow\n");
		    }
		}
		
		int dequeue(Queue *queue) {
		    if (!is_empty(*queue)) {
		        int dequeued_value = queue->items[queue->front];
		        if (queue->front == queue->rear) {
		            queue->front = queue->rear = -1;
		        } else {
		            queue->front = (queue->front + 1) % queue->size;
		        }
		        return dequeued_value;
		    } else {
		        printf("Queue underflow\n");
		        return -1;
		    }
		}
		
		int front(Queue queue) {
		    if (!is_empty(queue)) {
		        return queue.items[queue.front];
		    } else {
		        printf("Queue is empty\n");
		        return -1;
		    }
		}
		
		int main() {
		    Queue queue;
		    initialize(&queue, 3);
		
		    enqueue(&queue, 10);
		    enqueue(&queue, 20);
		    enqueue(&queue, 30);
		
		    printf("Front element: %d\n", front(queue));
		
		    printf("Dequeue element: %d\n", dequeue(&queue));
		    printf("Dequeue element: %d\n", dequeue(&queue));
		
		    printf("Front element: %d\n", front(queue));
		
		    enqueue(&queue, 40);
		    enqueue(&queue, 50);
		    printf("Dequeue element: %d\n", dequeue(&queue));
		    printf("Front element: %d\n", front(queue));
		
		    return 0;
		}

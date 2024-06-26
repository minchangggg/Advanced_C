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

> Input

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

> Output

		Sum: 10
  
Example 2:

> Input

		#include <stdio.h>
		#include <stdarg.h>
		
		typedef enum { TEMPERATURE_SENSOR, PRESSURE_SENSOR } SensorType;
		
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

> Output

		Temperature Sensor ID: 1, Reading: 36.50 degrees
		Additional Info: Room Temperature
		Pressure Sensor ID: 2, Reading: 101325 Pa
  
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
### A. Void Pointer
> https://www.scaler.com/topics/void-pointer/

`Syntax: void *ptr_void;`

Ex:

> Input

		#include <stdio.h>
		#include <stdlib.h>

		int sum(int a, int b) {
		    return a+b;
		}
		
		int main() {
		    char array[] = "Hello";
		    int value = 5;
		    double test = 15.7;
		    char letter = 'A';
		   
		    void *ptr = &value;
		    printf("value is: %d\n", *(int*)(ptr));
		
		    ptr = &test;
		    printf("value is: %f\n", *(double*)(ptr));
		
		    ptr = &letter;
		    printf("value is: %c\n", *(char*)(ptr));
		
		    ptr = (void*)sum;
		    printf("sum: %d\n", ((int (*)(int,int))ptr)(5,6));
		
		    void *ptr1[] = {&value, &test, &letter , (void*)sum, array};
		    printf("value: %d\n", *(int*)ptr1[0]);
		    printf("value: %s\n", ((char*)ptr1[4]));
		
		    return 0;
		}

> Output

		value is: 5
		value is: 15.700000
		value is: A
		sum: 11
		________________________________
		
		value: 5
		value: Hello

### B. Function Pointer
> https://daynhauhoc.com/t/con-tro-ham-function-pointers/31959

Function pointer is a pointer that points to a function.

(vì function nằm ở code segment - vùng nhớ read-only khi thực thi chương trình -> Function pointer là 1 pointer to const)

Function pointers syntax  `<return_type> (*<name_of_pointer>)( <data_type_of_parameters> );`

Ex 1:

> Input

		#include <stdio.h>
		
		void greetEnglish() {
		    printf("Hello!\n");
		}
		
		void greetFrench() {
		    printf("Bonjour!\n");
		}
		
		int main() {
		    void (*ptrToFunc)(); // Khai báo con trỏ hàm
		
		    ptrToFunc = greetEnglish; // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
		    // Gọi hàm thông qua con trỏ hàm -> In ra: Hello!
      		    (*ptrToFunc)();// cách 1
	 	    ptrToFunc();// cách 2
		
		    ptrToFunc = greetFrench; // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
		    // Gọi hàm thông qua con trỏ hàm -> In ra: Bonjour!
      		    (*ptrToFunc)(); // cách 1
	    	    ptrToFunc(); // cách 2
		
		    return 0;
		}

> Output

		Hello!
		Hello!
		Bonjour!
		Bonjour!
  
Ex 2:

> Input

		#include <stdio.h>
		
		void sum(int a, int b) {
		    printf("Sum of %d and %d is: %d\n",a,b, a+b);
		}
		
		void subtract(int a, int b) {
		    printf("Subtract of %d by %d is: %d \n", a, b, a-b);
		}
		
		void multiple(int a, int b) {
		    printf("Multiple of %d and %d is: %d \n", a, b, a*b );
		}
		
		void divide(int a, int b) {
		    if (b == 0) {
		        printf("Mau so phai khac 0\n");
		        return;
		    }
		    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
		}
		
		void calculator(void (*ptr)(int, int), int a, int b) {
		    ptr(a,b);
		}
		
		int main() {
	            // Cách 1: dùng hàm calculator thay địa chỉ hàm cần tính cho con trỏ hàm
	            printf("\tProgram calculate: \n");
			    calculator(sum,5,2);
			    calculator(subtract,5,2);
			    calculator(multiple,5,2);
			    calculator(divide,5,2);
	
	            printf ("______________________________\n");
	
	            // Cách 2: tạo 1 mảng chứa các con trỏ hàm cho từng hàm riêng biệt
	            printf("\tProgram calculate: \n");
			    void (*ptr[])(int, int) = {sum, subtract, multiple, divide};
			    ptr[0](5,2);
	            ptr[1](5,2);
	            ptr[2](5,2);
	            ptr[3](5,2);
			
		    return 0;
		}

> Output

		        Program calculate: 
		Sum of 5 and 2 is: 7
		Subtract of 5 by 2 is: 3 
		Multiple of 5 and 2 is: 10 
		5 divided by 2 is: 2.500000 
		______________________________
		        Program calculate: 
		Sum of 5 and 2 is: 7
		Subtract of 5 by 2 is: 3 
		Multiple of 5 and 2 is: 10 
		5 divided by 2 is: 2.500000 

Ex 3:

> Input

		#include <stdio.h>
		#include <string.h>
		
		void bubbleSort(int arr[], int n) {
		    int i, j, temp;
		    for (i = 0; i < n-1; i++) {    
		        for (j = i+1; j < n; j++) {
		            if (arr[i] > arr[j]) {
		                temp = arr[i];
		                arr[i] = arr[j];
		                arr[j] = temp;
		            }
	      		}
	 	    }	
		}
		
		int main() {
		    int arr[] = {64, 34, 25, 12, 22, 11, 90};
		    int n = sizeof(arr)/sizeof(arr[0]);
		    bubbleSort(arr, n);
		    printf("Sorted array: \n");
		    for (int i=0; i < n; i++)
		        printf("%d ", arr[i]);
		    return 0;
		}

Ex 4: 

> Input
		
		#include <stdio.h>
		#include <string.h>
		
		typedef struct {
		   char ten[50];
		   float diemTrungBinh;
		   int id;
		} SinhVien;
		
		int stringCompare(const char *str1, const char *str2) {
		   while (*str1 && (*str1 == *str2)) {
		       str1++;
		       str2++;
		   }
		   return *(const unsigned char*)str1 - *(const unsigned char*)str2;
		}
		
		// Hàm so sánh theo tên
		int compareByName(const void *a, const void *b) {
		   SinhVien *sv1 = (SinhVien *)a;
		   SinhVien *sv2 = (SinhVien *)b;
		   return stringCompare(sv1->ten, sv2->ten);
		}
		
		// Hàm so sánh theo điểm trung bình
		int compareByDiemTrungBinh(const void *a, const void *b) {
		   SinhVien *sv1 = (SinhVien *)a;
		   SinhVien *sv2 = (SinhVien *)b;
		   if (sv1->diemTrungBinh > sv2->diemTrungBinh) return 1;
		   return 0;
		}
		
		// Hàm so sánh theo ID
		int compareByID(const void *a, const void *b) {
		   SinhVien *sv1 = (SinhVien *)a;
		   SinhVien *sv2 = (SinhVien *)b;
		   return sv1->id - sv2->id;
		}
		
		// Hàm sắp xếp chung
		void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *)) {
		   int i, j;
		   SinhVien temp;
		   for (i = 0; i < size-1; i++)    
		       for (j = i+1; j < size; j++)
		           if (compareFunc(array+i, array+j)>0) {
		               temp = array[i];
		               array[i] = array[j];
		               array[j] = temp;
		           }
		}
		
		void display(SinhVien *array, size_t size) {
		   for (size_t i = 0; i < size; i++) {
		       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
		   }
		   printf("\n");
		}
		
		int main() {
		   SinhVien danhSachSV[] = {
		       {  
		           .ten = "Hoang",
		           .diemTrungBinh = 7.5,
		           .id = 100
		       },
		       {
		           .ten = "Tuan",
		           .diemTrungBinh = 4.5,
		           .id = 101
		       },
		       {
		           .ten = "Vy",
		           .diemTrungBinh = 6.8,
		           .id = 102},
		       {  
		           .ten = "Ngan",
		           .diemTrungBinh = 5.6,
		           .id = 10
		       },
		   };
		   size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);
		
		   // Sắp xếp theo tên
		   sort(danhSachSV, size, compareByName);
		   display(danhSachSV, size);
		
		   // Sắp xếp theo điểm trung bình
		   sort(danhSachSV, size, compareByDiemTrungBinh);
		   display(danhSachSV, size);
		
		   // Sắp xếp theo ID
		   sort(danhSachSV, size, compareByID);
		   display(danhSachSV, size);
		
		   return 0;
		}

Ex 5: 

		#include <stdio.h>
		
		typedef struct {
		   void (*start)(int gpio);
		   void (*stop)(int gpio);
		   void (*changeSpeed)(int gpio, int speed);
		} MotorController;
		
		typedef int PIN;
		
		// Các hàm chung
		void startMotor(PIN pin) {
		   printf("Start motor at PIN %d\n", pin);
		}
		
		void stopMotor(PIN pin) {
		   printf("Stop motor at PIN %d\n", pin);
		}
		
		void changeSpeedMotor(PIN pin, int speed) {
		   printf("Change speed at PIN %d: %d\n", pin, speed);
		}
		
		// Macro để khởi tạo GPIO và MotorController
		#define INIT_MOTOR(motorName, pinNumber) \
		   PIN PIN_##motorName = pinNumber; \
		   MotorController motorName = {startMotor, stopMotor, changeSpeedMotor};
		
		int main() {
		   // Sử dụng macro để khởi tạo
		   INIT_MOTOR(motorA, 1);
		   INIT_MOTOR(motorB, 2);
		
		   // Sử dụng motorA
		   motorA.start(g_motorA);
		   motorA.changeSpeed(g_motorA, 50);
		   motorA.stop(g_motorA);
		
		   // Sử dụng motorB
		   motorB.start(g_motorB);
		   motorB.changeSpeed(g_motorB, 75);
		   motorB.stop(g_motorB);
		
		   return 0;
		}


### C. Pointer to Constant
#### Syntax: int const *ptr_const; 
#### Syntax: const int *ptr_const;

Ex: 

		#include <stdio.h>
		#include <stdlib.h>
		
		int main() {
		    
		    int value = 5;
		    int const *ptr_const = &value;
		
		    //*ptr_const = 7; // wrong
		    //ptr_const++; // right
		    
		    printf("value: %d\n", *ptr_const);
		
		    value = 9;
		    printf("value: %d\n", *ptr_const);
		
		    return 0;
		}

### D. Constant Pointer

#### Syntax: int *const const_ptr = &value;

Ex:

		#include <stdio.h>
		#include <stdlib.h>
		
		
		int main() {
		    
		    int value = 5;
		    int test = 15;
		    int *const const_ptr = &value;
		
		    printf("value: %d\n", *const_ptr);
		
		    *const_ptr = 7;
		    printf("value: %d\n", *const_ptr);
		
		    //const_ptr = &test; // wrong
		    
		    return 0;
		}

### E. Pointer to Pointer

Ex:

		#include <stdio.h>
		
		int main() {
		    int value = 42;
		    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến
		
		    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ
		
		    /*
		        **ptr2 = &ptr1
		        ptr2 = &ptr1;
		        *ptr2 = ptr1 = &value;
		        **ptr2 = *ptr1 = value
		    */
		
		    printf("address of value: %p\n", &value);
		    printf("value of ptr1: %p\n", ptr1);
		
		    printf("address of ptr1: %p\n", &ptr1);
		    printf("value of ptr2: %p\n", ptr2);
		
		    printf("dereference ptr2 first time: %p\n", *ptr2);
		
		    printf("dereference ptr2 second time: %d\n", **ptr2);
		
		    return 0;
		}

### F. NULL Pointer

Ex:

		#include <stdio.h>
		
		int main() {
		    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ 0x0000000
		
		    if (ptr == NULL) {
		        printf("Pointer is NULL\n");
		    } else {
		        printf("Pointer is not NULL\n");
		    }
		
		    int score_game = 5;
		    if (ptr == NULL) {
		        ptr = &score_game;
		        *ptr = 30;
		        ptr = NULL;
		    }
		    return 0;
		}
________________________________________________________________________________________________________________________________________________________________________
# Lesson 4: EXTERN - STATIC - VOLATILE - REGISTER
### A. Extern
	- Syntax: extern data_type variable_name;

### B. Static
**1. Static local variables**

Ex: 

		#include <stdio.h>
		
		void exampleFunction() {
		    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
		    count++;
		    printf("Count: %d\n", count);
		}
		
		int main() {
		    exampleFunction();  // In ra "Count: 1"
		    exampleFunction();  // In ra "Count: 2"
		    exampleFunction();  // In ra "Count: 3"
		    return 0;
		}


**2. Static global variables**

Ex: 

> File motor.c

		#include <stdio.h>
		#include "motor.h"
		
		void startMotor(PIN pin) {
		   printf("Start motor at PIN %d\n", pin);
		}
		
		void stopMotor(PIN pin) {
		   printf("Stop motor at PIN %d\n", pin);
		}
		
		void changeSpeedMotor(PIN pin, int speed) {
		   printf("Change speed at PIN %d: %d\n", pin, speed);
		}
		
			 
		void init_motor(MotorController *motorName) {
			motorName->start = startMotor;
			motorName->stop = stopMotor;
			motorName->changeSpeed = changeSpeedMotor;
		}

> File motor.h

		#ifndef __MOTOR_H
		#define __MOTOR_H
		
		typedef struct {
			 void (*start)(int gpio);
		   void (*stop)(int gpio);
		   void (*changeSpeed)(int gpio, int speed);
		} MotorController;
		
		typedef int PIN;
		
		static void startMotor(PIN pin);
		static void stopMotor(PIN pin);
		static void changeSpeedMotor(PIN pin, int speed);
			 
		void init_motor(MotorController *motorName); 
		
		#endif

**3. Static in class**

		#include <iostream>
		
		typedef enum {
		    red = 0,
		    blue,
		    green,
		    purple,
		    black,
		    yellow
		} Pen_Color;
		
		void print_color_pen(Pen_Color color) {
			switch (color) {
			    case red:
			        std::cout << "Red\n";
			        break;
			    case blue:
			        std::cout << "Blue\n";
			        break;
			    case green:
			        std::cout << "Green\n";
			        break;
			    
			    default:
			        break;
			    }
			}
		
		
		class PEN {
			public:
			    Pen_Color pen_color;
			    static int pen_length;
			
			    PEN(Pen_Color color);
			    Pen_Color get_color()
			    {
			        return pen_color;
			    }
			    void set_length(int length)
			    {
			        pen_length = length;
			    }
			};
		
		int PEN::pen_length;
		
		PEN::PEN(Pen_Color color) {
		    pen_color = color;
		    pen_length = 10;
		}
		
		int main(int argc, char const *argv[]) {
		    PEN blue_pen(blue);
		    PEN red_pen(red);
		    PEN green_pen(green);
		
		    blue_pen.set_length(9);
		
		    std::cout << "Color: ";
		    print_color_pen(blue_pen.get_color());
		    std::cout << "Length: " << blue_pen.pen_length << '\n';
		
		    std::cout << "Color: ";
		    print_color_pen(red_pen.get_color());
		    std::cout << "Length: " << red_pen.pen_length << '\n';
		
		    std::cout << "Color: ";
		    print_color_pen(green_pen.get_color());
		    std::cout << "Length: " << green_pen.pen_length << '\n';
		
		    return 0;
		}

### C. Volatile
Ex:

		#include "stm32f10x.h"
		
		volatile int i = 0;
		int a = 100;
		
		int main() {
			while(1) {
				i = *((int*) 0x20000000);
				if (i > 0) break;	
			}
			a = 200;
		}

### D. Register

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/8cffd3cf-f6e8-4241-8b92-e126aba8716c">

Ex:

		#include <stdio.h>
		#include <time.h>
		
		int main() {
		    // Lưu thời điểm bắt đầu
		    clock_t start_time = clock();
		    int i;
		
		    // Đoạn mã của chương trình
		    for (i = 0; i < 2000000; ++i) {
		        // Thực hiện một số công việc bất kỳ
		    }
		
		    // Lưu thời điểm kết thúc
		    clock_t end_time = clock();
		
		    // Tính thời gian chạy bằng miligiây
		    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
		
		    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);
		
		    return 0;
		}
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
> https://www.w3schools.com/js/js_json_intro.asp
>
> https://www.geeksforgeeks.org/cjson-json-file-write-read-modify-in-c/
### I, Overview 
	+ JSON stands for JavaScript Object Notation
	+ JSON is a text format for storing and transporting data; which is used for data exchange between applications and web services. 
	+ JSON is "self-describing", easy to read and write for humans and machines alike. 
a, JSON Values

- In JSON, values must be one of the following data types:
  
	+ a string (must be written in double quotes) -> Ex: {"name":"John"}
	+ a number (must be an integer or a floating point) -> Ex: {"age":30}
	+ an object (Values in JSON can be objects) -> Ex: { "employee":{"name":"John", "age":30, "city":"New York"} }
	+ an array -> Ex: { "employees":["John", "Anna", "Peter"] }
	+ a boolean -> Ex: {"sale":true} 
	+ null -> Ex: {"middlename":null} 

- JSON values cannot be one of the following data types:

	a function
	a date
	undefined

b, JSON Objects

		{ "name": "Bob Johnson", "age": 35, "city": "Chicago" },
		{ "name": "John Doe", "age": 30, "city": "New York", "occupation": "Software Engineer", "isStudent": false },
		{
		    "name": "Jane Smith",
		    "age": null,
		    "city": "Los Angeles",
		    "contact": { "email": "jane.smith@example.com", "phone": "555-1234" }
		}

Ex: 

		#include <stdio.h> 
		#include <cjson/cJSON.h> 
		
		int main() { 
		// create a cJSON object 
		cJSON *json = cJSON_CreateObject(); 
		cJSON_AddStringToObject(json, "name", "John Doe"); 
		cJSON_AddNumberToObject(json, "age", 30); 
		cJSON_AddStringToObject(json, "email", "john.doe@example.com"); 
		
		// convert the cJSON object to a JSON string 
		char *json_str = cJSON_Print(json); 
		
		// write the JSON string to a file 
		FILE *fp = fopen("data.json", "w"); 
		if (fp == NULL) { 
			printf("Error: Unable to open the file.\n"); 
			return 1; 
		} 
		printf("%s\n", json_str); 
		fputs(json_str, fp); 
		fclose
		// free the JSON string and cJSON object 
		cJSON_free(json_str); 
		cJSON_Delete(json); 
		return 0; 
		}

 ### II, How does it work? 
 
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
		            size_t count; // số lượng element
		        } array;
		        struct {
		            char **keys;
		            struct JsonValue *values;
		            size_t count; // số cặp key-value
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
		    if (strncmp(*json, "null", 4) == 0) { // khi bắt gặp đc chữ n -> nó lấy thêm 3 phần tử tiếp theo -> so sánh với null
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
		    char *end; //:') 
		
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
		
		JsonValue *parse_json(const char **json) { // làm việc với giá trị json_str_value 
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

  **II, Complete Example**
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 10: Linked List
> https://techacademy.edu.vn/danh-sach-lien-ket-don-c/
>
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
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 12: Binary search - File operations - Code standards
> https://www.geeksforgeeks.org/binary-search/

### A. Binary search
**1. How does Binary Search work?**

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/9cf16d9e-cb4a-4bbc-abef-0d8088dcae9d">

**1. Iterative Method**

**Ex 1:**

		#include <stdio.h>
		 
		int binarySearch(int arr[], int l, int r, int x) {
		    while (l <= r) {
		        int m = l + (r - l) / 2;
		 
		        if (arr[m] == x) return m; // If found at mid, then return it
		        if (arr[m] < x) l = m + 1; // If x greater, ignore left half
		        else r = m - 1; // If x is smaller, ignore right half
		    }
		    // If we reach here, then element was not present
		    return -1;
		}
		
		int main(void) {
		    int arr[] = { 2, 3, 4, 10, 40 };
		    int n = sizeof(arr) / sizeof(arr[0]);
		    int x = 10;
		    int result = binarySearch(arr, 0, n - 1, x);
		    (result == -1) ? printf("Element is not present in array")
		                   : printf("Element is present at index %d", result);
		    return 0;
		}

**2. Recursive Method**

**Ex 1:**

		#include <stdio.h>
		
		int binarySearch(int array[], int x, int low, int high) {
		  if (high >= low) {
		    int mid = low + (high - low) / 2;
	
		    if (array[mid] == x) return mid; // If found at mid, then return it
		    if (array[mid] > x) return binarySearch(array, x, low, mid - 1); // Search the left half
		    return binarySearch(array, x, mid + 1, high); // Search the right half
		  }
		  return -1;
		}
		
		int main(void) {
		  int array[] = {3, 4, 5, 6, 7, 8, 9};
		  int n = sizeof(array) / sizeof(array[0]);
		  int x = 4;
		  int result = binarySearch(array, x, 0, n - 1);
		  if (result == -1) printf("Not found");
		  else printf("Element is found at index %d", result);
		}

**Ex 2:** 

		#include <stdio.h>
		#include <stdlib.h>
		
		int binarySearch(int* arr, int l, int r, int x) {
		    if (r >= l) {
		        int mid = l + (r - l) / 2;
		        if (arr[mid] == x)  return mid;
		        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
		        return binarySearch(arr, mid + 1, r, x);
		    }
		    return -1;
		}
		
		void swap(int* a, int* b) {
		    int temp = *a;
		    *a = *b;
		    *b = temp;
		}
		
		void bubbleSort(int arr[], int n) {
		    int i, j;
		    for (i = 0; i < n - 1; i++) {
		        for (j = 0; j < n - i - 1; j++) { 
		            if (arr[j] > arr[j + 1])
		                swap(&arr[j], &arr[j + 1]);
		        }
		    }
		}
		
		int main() {
		    int n, x, i;
		    printf("Nhap so phan tu cua mang: "); scanf("%d", &n);
		    int* arr = (int*)malloc(n * sizeof(int));
		    printf("Nhap cac phan tu cua mang: ");
		    for (i = 0; i < n; i++) { scanf("%d", &arr[i]); }
		    bubbleSort(arr, n);
		    for (int i = 0; i < n; i++) { printf("i = %d\n", arr[i]); }
		    printf("Nhap gia tri can tim: "); scanf("%d", &x);
		    int result = binarySearch(arr, 0, n - 1, x);
		    if (result == -1) printf("Khong tim thay %d trong mang.\n", x);
		    else printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);
		    free(arr);
		    return 0;
		}

### B. File operations
> https://www.geeksforgeeks.org/basics-file-handling-c/
>
> https://www.programiz.com/c-programming/c-file-input-output#google_vignette

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/120c94d0-fddd-40f4-bbcc-b85de5967903">

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 13: Class
### 1. Declaring Object
### 2. Constructor
### 3. Destructor
### 4. Static keyword
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 14: OOP
### 1. Encapsulation // tính đóng gói
**Ex:** 

		#include <iostream>
		#include <string>
		
		using namespace std;
		
		class Student {
		private:
			string Name;
			double GPA;
			int StudentID;
		
		public:
			Student(string name) {
				Name = name;
				static int id = 1000;
				StudentID = id;
				++id;
			}
		
			string getName() { return Name; }
			double getGPA() { return GPA; }
			int getID() { return StudentID; }
			
			void setName(string name) { Name = name; };
			void setGPA(double gpa) { GPA = gpa; };
			void setStudentID(int studentID) { StudentID = studentID; }
		};
		
		int main() {
			Student student1("Trung"); student1.setGPA(8);
			Student student2("Thai"); student2.setGPA(9);
			Student student3("Thao"); student3.setGPA(10);
			
			cout << "Name: " << student1.getName() << "\tGPA: " << student1.getGPA() << "\tID: " << student1.getID() << endl;
			cout << "Name: " << student2.getName() << "\tGPA: " << student2.getGPA() << "\tID: " << student2.getID() << endl;
			cout << "Name: " << student3.getName() << "\tGPA: " << student3.getGPA() << "\tID: " << student3.getID() << endl;
			
			return 0;
		}

### 2. Inheritance // tính kế thừa 
**Ex:**

		#include <iostream>
		#include <string>
		
		using namespace std;
		
		class Person {
		protected:
		    string Name;
		    int Age;
		    string Home_Address;
		
		public:
		    string getName() { return Name; }
		    void setName(string name) { Name = name; }
		
		    int getAge() { return Age; }
		    void setAge(int age) { Age = age; }
		
		    string getAddress() { return Home_Address; }
		    void setAddress(string address) { Home_Address = address; }
		
		    void displayInfo() { 
		        cout << "Name: " << Name << "\tAge: " << Age << "\tAddress: " << Home_Address << endl; 
		    }
		};
		
		class Student : public Person {
		private:
		    string School_Name;
		    double GPA;
		    int StudentID;
		
		public:
		    Student() {
		        static int id = 1000;
		        StudentID = id;
		        ++id;
		    }
		
			string getSchoolName() { return School_Name; }
		    void setSchoolName(string school_name) { School_Name = school_name; }
		
		    double getGPA() { return GPA; }
		    void setGPA(double gpa) { GPA = gpa; }
		
		    int getID() { return StudentID; }
		
		    void displayInfo() { // overriding
		        cout << "Name: " << Name << "\tAge: " << Age << "\tAddress: " << Home_Address << "\tSchool name: " << School_Name << "\tGPA: " << GPA << endl;
		    }
		};
		
		int main() {
		    Person person1;
		    person1.setName("Trung");
		    person1.setAge(20);
		    person1.setAddress("HCM");
		    person1.displayInfo();
		
		    Student student1;
		    student1.setName("Trunggg");
		    student1.setAge(24);
		    student1.setAddress("HCMM");
		    student1.setGPA(8.1);
		    student1.setSchoolName("DinhTienHoang");
		    student1.displayInfo();
		
		    return 0;
		}

### 3. Polymorphism
**a, Function overriding**

**Ex:** 

> Input

		#include <iostream>
		#include <string>
		
		using namespace std;
		
		class Calc {
		public:
		    int sum(int a, int b) {
		        return a+b;
		    }
		    int sum(int a, int b, int c) {
		        return a+b+c;
		    }
		    double sum(double a, double b) {
		        return a+b;
		    }
		};
		
		int main() {
		    Calc* ptr = new Calc();
		    cout << "Sum: " << ptr->sum(1,2) << endl;
		    cout << "Sum: " << ptr->sum(2.5,3.7) << endl;
		    cout << "Sum: " << ptr->sum(1,2,3) << endl;
		
		    return 0;
		}

> Output

		Sum: 3
		Sum: 6.2
		Sum: 6

**b, Virtual fuction**

**Ex 1:**

> Input

		#include <iostream>
		#include <string>
		
		using namespace std;
		
		class Person {
		public:
		  void show() { cout << "hello person" << endl; } 
		  virtual void displayInfo() { cout << "HELLO PERSON"<< endl; } // thêm virtual vào chỗ này
		};
		
		class Student : public Person {
		public:
		  void show() { cout << "hello student" << endl; } 
		  void displayInfo() { cout << "HELLO STUDENT"<< endl; }
		};
		
		int main() {
		  Person *ptr = NULL; 
		  Person person1;   
		  Student student1;
		  
		  ptr = &person1;
		  ptr->show(); 
		  ptr->displayInfo();  

    	          cout << "-----------------------" << endl;
	       
		  ptr = &student1;
		  ptr->show();
		  ptr->displayInfo();
		
		  return 0;
		}

> Output

		hello person
		HELLO PERSON
		
		hello person
		HELLO STUDENT

**Ex 2:**

> Input

		#include <iostream>
		#include <string>
		
		using namespace std;
		
		class Parent {
		public:
		  virtual string test() { return "Hello Parent"; } // thêm virtual vào chỗ này
		  void displayInfo() {cout << test() << endl; }
		};
		
		class Baby : public Parent {
		public:
		  string test() { return "Hello Baby"; }
		};
		
		int main() {
		  Parent parent;
		  parent.displayInfo();
		  
		  cout << "-----------------------" << endl;
		  
		  Baby baby;
		  baby.displayInfo();
		  return 0;
		}
  
> Output

		Hello Parent
		-----------------------
		Hello Baby

**Ex 3:** 

> Input

		#include <iostream>
		#include <string>
		
		using namespace std;
		
		class Buffalo {
		public:
		    virtual void  action(){cout << "Hello Buffalo\n";}; // thêm virtual vào chỗ này
		}; 
		class YoungBuffalo : public Buffalo {
		public:
		    void action(){ cout << "Hello Young Buffalo\n";};
		};
		void takeAnBuffalo(Buffalo* buffalo){
		    buffalo->action();
		}
		int main() {
		  Buffalo *buffalo = new Buffalo();
		  Buffalo *youngBuffalo = new YoungBuffalo();
    
		  takeAnBuffalo(buffalo);
    		  cout << "-----------------------" << endl;
		  takeAnBuffalo(youngBuffalo);
		}

> Output

		Hello Buffalo
		-----------------------
		Hello Young Buffalo

### 4. Abstraction // Tính trừu tượng 
Ex: 

> Input

		#include <iostream>
		#include <string>
		#include <cmath>
		
		using namespace std;
		
		class GiaiPhuongTrinh {
		    private:
		        double a, b, c;
		        int x1, x2;
		
		        double delta;
		
		        void tinhNghiem() {
		            delta = b*b - 4*a*c;
		            if (delta < 0) {
		                delta = -1; 
		            }
		            else if (delta == 0)  {
		                x1 = x2 = -b/ (2*a);  
		            }    
		            else if (delta > 0) {
		                delta = 1;
		                x1 = (-b + sqrt(delta))/(2*a);
		                x2 = (-b - sqrt(delta))/(2*a);
		            }
		        }
		     
		    public:
		        void enterNumber(double num_a, double num_b, double num_c);
		        void printResult();
		
		};
		
		void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c) {
		    a = num_a;
		    b = num_b;
		    c = num_c;
		}
		
		void GiaiPhuongTrinh::printResult() {
		    tinhNghiem();
		    switch ((int)delta) {
		        case -1:
		            cout << "PT vo nghiem" << endl;
		            break;
		        case 0:
		            cout << "PT co nghiem kep: " << x1 << endl;
		            break;
		        default: 
		            cout << "PT co 2 nghiem phan biet:" << endl; 
		            cout << "x1 = " << x1 << "\tx2 = " << x2 << endl; 
		            break;
		    }
		}
		
		int main() {
		    GiaiPhuongTrinh phuongtrinh1;
		    phuongtrinh1.enterNumber(1,-3,2);
		    phuongtrinh1.printResult();
		
		    return 0;
		}

> Output

		PT co 2 nghiem phan biet:
		x1 = 2  x2 = 1
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 15: Standard template library
## A. Container
### I. Vector
> https://www.geeksforgeeks.org/vector-in-cpp-stl/
> 
> https://www.programiz.com/cpp-programming/vectors
>
> https://topdev.vn/blog/vector-trong-c/
>
> https://blog.28tech.com.vn/stl-vector-trong-c
>
> https://www.programiz.com/cpp-programming/algorithm

Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted

**1, Declaration and Initialization**

		vector<data_type> vector_name;
  
Ex: 
		#include <iostream>
		#include <vector>
		using namespace std;
		
		int main() {
			vector<int> vector1; // Khai báo vector rỗng
			
			// Method 1: Create and Initialize a Vector
			vector<int> vector2 = {1, 2, 3, 4, 5}; // Initializer list
			vector<int> vector3 {1, 2, 3, 4, 5}; // Uniform initialization
			
			// Method 2: Create a Vector with Size
			int n = 20; 
			vector<int> v3(n); 
			
			int val = 10; 
			vector<int> v4(m, val); //Khai báo vector có sẵn m phần tử có cùng giá trị val
			
			return 0;
		}
  
**2, C++ Vector Functions**

a. Capacity__________________________________________________________________________________________________________________________

`.size(): returns the number of elements present in the vector // kích thước - trả về số lượng phần tử ĐANG ĐƯỢC SỬ DỤNG trong vector`

`.capacity(): check the overall size of a vector // dung lượng - trả về số lượng phần tử ĐƯỢC CẤP PHÁT cho vector nằm TRONG BỘ NHỚ`

`.empty(): returns 1 (true) if the vector is empty`

`.resize(n): change the number of elements present in the vector`

Ex: 

		#include <iostream> 
		#include <vector>  
		using namespace std; 
		   
		int main() { 
		    vector<int> vec1; 
		   
		    for (int i = 1; i <= 10; i++) 
		        vec1.push_back(i); 
		   
		    cout << "Size of our vector: " << vec1.size() << endl; 
		    cout << "nCapacity of our vector: " << vec1.capacity() << endl; 
		    cout << "nMax_Size of our vector: " << vec1.max_size() << endl; 
		   
		    // resizes the vector size to 4 
		    vec1.resize(4); 
		   
		    // prints the vector size after resize() 
		    cout << "nSize of our vector after resize: " << vec1.size() << endl;  
		   
		    // checks if the vector is empty or not 
		    if (vec1.empty() == false) cout << "nVector is not empty"; 
		    else cout << "nVector is empty"; 
		   
		    return 0; 
		}

b. Access Elements of a Vector_______________________________________________________________________________________________________
   
`.at(): access the element from the specified index`

`.front(): returns the first element of the vector`

`.back(): returns the last element of the vector`

c. Add Elements to a Vector___________________________________________________________________________________________________________

`.push_back(): This method pushes elements to the back of a vector.`

		vector<int> v = {1,2,3,4};
		v.push_back(5);
		int n = v.size();
  
		cout << "The last element is: " << v[n - 1];
		// Output: The last element is: 5 
  
`.insert(): This method inserts new elements before the element at the specified position.`

		vector<int> v = {1,2,3,4};
		v.insert(v.begin(),0); // Insert at beginning
		v.insert(v.end(),6); // Insert at end
		
		cout << "The first element is: " << v[0] << "\n";
		// Output: The first element is: 0
		
		cout << "The last element is: " << v[5] << "\n";
		// Output: The last element is: 6
  
Ex: 

		#include <iostream>
		#include <vector>
		using namespace std;
		
		int main() {
			vector <int> arr1 = {2,5,7,4,9};
			
			arr1.at(0) = 3; // 3 5 7 4 9
			arr1.resize(7);  // 3 5 7 4 9 0 0 	    
			arr1.push_back(10); // 3 5 7 4 9 0 0 10
			
			// Duyet vector bang chi so 
			for (int i = 0; i < arr1.size(); i++) { 
				cout << "Value: " << arr1.at(i) << endl;
			}
			
			cout << "-----------" << endl;
   
			// Duyet vector bang ranged-base for loop
			for (const int& i : arr1) { 
				cout << "Value: " << i << endl;
			}
			for (int i : arr1) {
				cout << "Value: " << i << endl;
			}
			
			return 0;
		}


d. Delete Elements from C++ Vectors

`.pop_back()`

`.erase()`

`.clear(): removes all the elements of the vector`

Ex: 

	#include <iostream>
	#include <vector>
	using namespace std;
	
	int main(){
		vector<string> v = {"Da Nang", "Ngay 5"};
		cout << "Size of vector : " << v.size() << endl;
		v.push_back("Thang 2");
		v.push_back("Nam 2024");
		cout << "Size of vector : " << v.size() << endl;
		cout << "Access vector : ";

		for(int i = 0; i < v.size(); i++){
			cout << v[i] << ", ";
		}

		v.pop_back(); 
		cout << "\nSize of vector : " << v.size() << endl;
		}

**3, C++ Vector Iterators**
Vector iterators are used to point to the memory address of a vector element. In some ways, they act like pointers in C++.

Syntax: `vector<T>::iterator iteratorName;`

a. begin() function

		vector<int> num = {1, 2, 3};
		vector<int>::iterator iter;
		
		// iter points to num[0]
		iter = num.begin();
  
b. end() function

		vector<int> num = {1, 2, 3};
		vector<int>::iterator iter;
		
		// iter points to the last element of num
		iter = num.end() - 1;
c. Ex
		#include <iostream>
		#include <vector>
		using namespace std;
		
		int main() {
			vector<int> num {1, 2, 3, 4, 5};
			vector<int>::iterator iter;
			
			// use iterator with for loop
			for (iter = num.begin(); iter != num.end(); ++iter) {
				cout << *iter << "  ";
			}
			
			return 0;
		}

		#include <iostream> 
		#include <vector> 
		using namespace std; 
		   
		int main() { 
		    vector<int> vec1; 
		   
		    for (int i = 1; i <= 10; i++) 
		        vec1.push_back(i); 
		   
		    cout << "Understanding begin() and end() function: " << endl; 
		    for (auto i = vec1.begin(); i != vec1.end(); ++i) 
		        cout << *i << " "; 
		 
		    return 0; 
		}

**4, Vector Và Mảng 1 Chiều**

		#include <iostream>
		#include <vector>
		
		using namespace std;
		
		int main(){
		    int n, tmp; cout << "Nhap so luong phan tu : ";
		    cin >> n;
		    vector<int> v(n);
		    for(int i = 0; i < n; i++){
		        cout << "Nhap phan tu thu " << i + 1 << " : ";
		        cin >> v[i];
		    }
		    cout << "Day so vua nhap : \n";
		    for(int i = 0; i < v.size(); i++){
		        cout << v[i] << " ";
		    }
		    return 0;
		}

**5, Vector Và Mảng 2 Chiều**

Cách 1: 

		#include <iostream>
		#include <vector>
		using namespace std;
		
		int main(){
		    int n, m;
		    cout << "Nhap hang, cot : ";
		    cin >> n >> m;
		    vector<vector<int>> v;
		    for(int i = 0; i < n; i++){
		        vector<int> row;
		        for(int j = 0; j < m; j++){
		            cout << "Nhap phan tu hang " << i + 1 << ", cot " << j + 1 << " : ";
		            int tmp; cin >> tmp;
		            row.push_back(tmp);
		        }   
		        v.push_back(row);
		    }
		    cout << "\nMang 2 chieu vua nhap : \n";
		    for(int i = 0; i < n; i++){
		        for(int j = 0; j < m; j++){
		            cout << v[i][j] << " ";
		        }
		        cout << endl;
		    }
		    return 0;
		}

Cách 2:

		#include <iostream>
		#include <vector>
		using namespace std;
		
		int main(){
		    int n, m;
		    cout << "Nhap hang, cot : ";
		    cin >> n >> m;
		    vector<vector<int>> v(n, vector<int>(m));
		    for(int i = 0; i < n; i++){
		        for(int j = 0; j < m; j++){
		            cout << "Nhap phan tu hang " << i + 1 << ", cot " << j + 1 << " : ";
		            cin >> v[i][j];
		        }   
		    }
		    cout << "\nMang 2 chieu vua nhap : \n";
		    for(int i = 0; i < n; i++){
		        for(int j = 0; j < m; j++){
		            cout << v[i][j] << " ";
		        }
		        cout << endl;
		    }
		    return 0;
		}
  
### II. List
> https://www.programiz.com/cpp-programming/list
>
> https://websitehcm.com/list-trong-c/
>
> https://laptrinhcanban.com/cpp/lap-trinh-cpp-co-ban/list-trong-cpp/list-trong-cpp-la-gi/
>
> https://viblo.asia/p/cau-truc-du-lieu-va-giai-thuat-danh-sach-lien-ket-doi-doubly-linked-list-924lJ82WKPM

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/e2695ead-47bf-4d44-bbdd-8a45c1d53bdc)




### III. Map

### IV. Array

## B. Iterator

## C. Algorithms

## D. Functor

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 16: Generic Programming
> https://www.startertutorials.com/blog/generic-programming-cpp.html
> 
> https://www.scaler.com/topics/cpp/generic-programming-in-cpp/
>
> https://albertoferrari.github.io/generics/cpp_generic_programming.pdf
>
> https://www.codeguru.com/cplusplus/exploring-the-c-generics-programming-model/
>
## A. Generic Functions using Template
**Ex 1:**

		#include <iostream> 
		using namespace std; 
		  
		// One function works for all data types. 
		// This would work even for user defined types 
		// if operator '>' is overloaded 
		template <typename T> 
		  
		T myMax(T x, T y) { 
		    return (x > y) ? x : y; 
		} 
		  
		int main() {  
		    cout << myMax<int>(3, 7) << endl; // call myMax for int
		    cout << myMax<double>(3.5, 7.5) << endl; // call myMax for double  
		    cout << myMax<char>('g', 'e') << endl; // call myMax for char 
		    return 0; 
		} 

**Ex 2:** 

		#include <iostream>
		using namespace std;
  
		class Person {
		    private:
		        int age;
		        string name;
		    public:
		        Person(string _name, int _age) {
		            age = _age;
		            name = _name;
		        }
		        void toString() {
		            cout << name << " is " << age << " years old."<< endl;
		        }
		};
		
		template < class T > 
		void printTheData(T &obj) {
			obj.toString();
		}
		
		int main() {
		    Person p1 = Person("Tommy Vercetti", 21);
		    printTheData(p1);
		    return 0;
		}


## B. Generic Class using Template
**Ex 1:**

		#include <iostream>
		using namespace std;
		
		template < class T >
		  class Container {
		    private:
		      T data;
		    public:
		      static int count;
		    Container() {
		      count++;
		    }
		
		    static void displayStaticVariable() {
		      cout << count << endl;
		    }
		  };
		
		template < class T >
		  int Container < T > ::count = 0;
		
		int main() {
		  Container < int > obj1;
		  Container < float > obj2;
		  Container < int > obj3;
		  Container < int > ::displayStaticVariable();
		  Container < float > ::displayStaticVariable();
		
		  return 0;
		}

**Ex 2:**

		#include <iostream> 
		using namespace std; 
		
		template <typename T> 
		class Array { 
		    private: 
		    	T* ptr; 
		    	int size; 
		    
		    public: 
		    	Array(T arr[], int s); 
		    	void print(); 
		}; 
		
		template <typename T> 
		Array<T>::Array(T arr[], int s) { 
			ptr = new T[s]; 
			size = s; 
			for (int i = 0; i < size; i++) 
				ptr[i] = arr[i]; 
		} 
		
		template <typename T> 
		void Array<T>::print() { 
			for (int i = 0; i < size; i++) 
				cout << " " << *(ptr + i); 
			cout << endl; 
		} 
		
		int main() { 
			int arr[5] = { 1, 2, 3, 4, 5 }; 
			Array<int> a(arr, 5); 
			a.print(); 
			return 0; 
		} 

**Ex 3:** 

		#include <iostream>
		using namespace std;
		
		template <typename E>class MyStack{
		private:
		   int SIZE;
		   int tos;
		   E *items;
		public:
		   MyStack(int=10);
		   ~MyStack(){ delete[] items;}
		   void push(const E&);
		   E pop();
		};
		
		template<typename E>MyStack<E>::
		   MyStack(int s):SIZE(s>0?s:10),tos(-1),items(new E[SIZE]){}
		
		template<typename E> void MyStack<E>::push(const E &value){
		   if (tos == SIZE - 1)
		      cout<<"Stack is full"<<endl;
		   else
		      items[++tos] = value;
		}
		
		template<typename E> E MyStack<E>::pop() {
		   E item;
		   if (tos == -1)
		      cout<<"Stack is empty"<<endl;
		   else
		      item = items[tos--];
		      return item;
		}
		
		int main() {
		   MyStack<string> strStack(4);
		   strStack.push("January");
		   strStack.push("February");
		   strStack.push("March");
		   strStack.push("April");
		   cout<<strStack.pop()<<endl;
		   cout<<strStack.pop()<<endl;
		   cout<<strStack.pop()<<endl;
		   cout<<strStack.pop()<<endl;
		   cout<<strStack.pop()<<endl;   // stack is empty now
		   return 0;
		}

## C. Working with multi-type Generics

		#include <iostream> 
		using namespace std; 
		  
		template <class T, class U> 
		class A { 
		    T x; 
		    U y; 
		  
		public: 
		    A() { 
		        cout << "Constructor Called" << endl; 
		    } 
		}; 
		  
		int main() { 
		    A<char, char> a; 
		    A<int, double> b; 
		    return 0; 
		} 
__________________________________________________________________________________________________________________________________________________________________________
# Lesson 17: Smart Pointer - Lambda
<img width="350" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d7568942-e7a3-432c-85a1-d5d279ccc919">

> https://www.scaler.com/topics/cpp/dynamic-memory-allocation-in-cpp/
>
> https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/
>
> https://daynhauhoc.com/t/cap-phat-dong-dynamic-memory-allocation/31145
>
> https://howkteam.vn/course/khoa-hoc-lap-trinh-c-can-ban/cap-phat-dong-trong-c-dynamic-memory-allocation-2734

`+ Static memory allocation (Compile-time Memory Allocation) // Cấp phát bộ nhớ tĩnh`

		Xảy ra trên các biến tĩnh và biến toàn cục.
		Vùng nhớ của các loại biến này được cấp phát một lần khi chương trình bắt đầu chạy và vẫn tồn tại trong suốt thời gian tồn tại của chương trình.
		Kích thước của biến/mảng phải được biết tại thời điểm biên dịch chương trình.
  
`+ Automatic memory allocation (Run-time Memory Allocation) // Cấp phát bộ nhớ tự động`

		Xảy ra trên các tham số hàm và biến cục bộ.
		Vùng nhớ của các loại biến này được cấp phát khi chương trình đi vào khối lệnh và được giải phóng khi khối lệnh bị thoát.
		Kích thước của biến/mảng phải được biết tại thời điểm biên dịch chương trình.

`+ Dynamic memory allocation // Cấp phát bộ nhớ động`

## A. new and delete Operators
a. The "new" operator in C++

Syntax: `data_type* ptr_var = new data_type;`

b. The "delete" Operator in C++

Syntax: `delete ptr_var;`

**Example 1: C++ Dynamic Memory Allocation**

		#include <iostream>
		using namespace std;
		
		int main() {
		
		  // declare an int pointer
		  int* pointInt;
		
		  // declare a float pointer
		  float* pointFloat;
		
		  // dynamically allocate memory
		  pointInt = new int;
		  pointFloat = new float;
		
		  // assigning value to the memory
		  *pointInt = 45;
		  *pointFloat = 45.45f;
		
		  cout << *pointInt << endl;
		  cout << *pointFloat << endl;
		
		  // deallocate the memory
		  delete pointInt;
		  delete pointFloat;
		
		  return 0;
		}

**Example 2: C++ new and delete Operator for Arrays**

		// C++ Program to store GPA of n number of students and display it
		// where n is the number of students entered by the user
		
		#include <iostream>
		using namespace std;
		
		int main() {
		
		  int num;
		  cout << "Enter total number of students: ";
		  cin >> num;
		  float* ptr;
		    
		  // memory allocation of num number of floats
		  ptr = new float[num];
		
		  cout << "Enter GPA of students." << endl;
		  for (int i = 0; i < num; ++i) {
		    cout << "Student" << i + 1 << ": ";
		    cin >> *(ptr + i);
		  }
		
		  cout << "\nDisplaying GPA of students." << endl;
		  for (int i = 0; i < num; ++i) {
		    cout << "Student" << i + 1 << ": " << *(ptr + i) << endl;
		  }
		
		  // ptr memory is released
		  delete[] ptr;
		
		  return 0;
		}

**Example 3: C++ new and delete Operator for Objects**
		
		#include <iostream>
		using namespace std;
		
		class Student {
		  private:
		    int age;
		
		  public:
		    // constructor initializes age to 12
		    Student() : age(12) {}
		
		    void getAge() {
		      cout << "Age = " << age << endl;
		    }
		};
		
		int main() {
		  // dynamically declare Student object
		  Student* ptr = new Student();
		
		  // call getAge() function
		  ptr->getAge();
		
		  // ptr memory is released
		  delete ptr;
		
		  return 0;
		}

## B. Smart Pointer
> https://www.geeksforgeeks.org/smart-pointers-cpp/
>
> https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-in-cpp/
>
> https://viblo.asia/p/cc-smart-pointer-MG24BKzBJz3
>
> https://viblo.asia/p/tim-hieu-smartpointer-trong-c-phan-1-4dbZND8Q5YM
>
> https://techacademy.edu.vn/smartpointer-trong-c/

		#include <iostream>
		using namespace std;
		 
		class SmartPtr {
		private:
		    int* ptr; 
		public:
		    SmartPtr(int* p = NULL) { ptr = p; }
		    ~SmartPtr() { delete (ptr); }
		 
		    int& operator*() { return *ptr; } // Overloading dereferencing operator
		    int getValue() { return *ptr; }
		    void setValue(int value) { *ptr = value; }
		};
		 
		int main() {
		   SmartPtr ptr1(new int);
		   ptr1.setValue(50);
		   cout << "Value: " << ptr1.getValue() << endl;
		   cout << "Value: " << *ptr1 << endl;
		
		   cout << "_____________________________" << endl;
		   SmartPtr ptr2(new int);
		   *ptr2 = 20;
		   cout << "Value: " << ptr2.getValue() << endl;
		   cout << "Value: " << *ptr2 << endl;
		
		    return 0;
		}

### I. auto_ptr
### II. unique_ptr

		#include <iostream>
		#include <memory>
		
		using namespace std;
		
		template < typename T >
		class HinhChuNhat {
		private:
		    T ChieuDai, ChieuRong;
		
		public:
		    HinhChuNhat(T dai, T rong){
		        ChieuDai = dai;
		        ChieuRong = rong;
		        cout << "Constructor called. "  << endl;
		    }
		
		    void tinhDienTich() {
		        cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
		    }
		
		    ~HinhChuNhat() {
		        cout << "Destructor called " << endl;
		    }
		};
		
		int main() {
		
		    unique_ptr <HinhChuNhat<float>> ptr1(new HinhChuNhat<float>(10.5,5.2));
		    (*ptr1).tinhDienTich(); // Dien tich: 54.6
		
		    //unique_ptr <HinhChuNhat> ptr2(ptr1); // Khong cho phep vì giát trị ptr1 thực chất là địa chỉ của object HinhChuNhat<float>(10.5,5.2) mà mỗi unique ptr chỉ đc trỏ đến 1 object 
      
		    unique_ptr <HinhChuNhat<float>> ptr2 = move(ptr1); // gan object HinhChuNhat(10,5) cho ptr2, sau do remove ptr1
		    (*ptr2).tinhDienTich(); // Dien tich: 54.6
		    // (*ptr1).tinhDienTich(); -> lỗi, 1 unique chỉ đi 1 object, ptr1 đã bị remove
		
		    return 0;
		}

### III. shared_ptr

		    #include <iostream>
		    #include <memory>
		    
		    using namespace std;
		    
		    class HinhChuNhat {
		    private:
		        int ChieuDai;
		        int ChieuRong;
		    
		    public:
		        HinhChuNhat(int dai, int rong){
		            ChieuDai = dai;
		            ChieuRong = rong;
		            cout << "Constructor called. "  << endl;
		        }
		    
		        void tinhDienTich() {
		            cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
		        }
		    
		        ~HinhChuNhat() {
		            cout << "Destructor called " << endl;
		        }
		    };
		    
		    int main() {
		        shared_ptr <HinhChuNhat> ptr1 (new HinhChuNhat(40,10));
		        (*ptr1).tinhDienTich();
		        shared_ptr <HinhChuNhat> ptr2 (ptr1);
		        shared_ptr <HinhChuNhat> ptr3;
		        ptr3 = ptr2;
		    
		        (*ptr2).tinhDienTich();
		        (*ptr1).tinhDienTich();
		        (*ptr3).tinhDienTich();
		        
		        cout << "Count: " << ptr1.use_count() << endl; // số con trỏ, trỏ đến địa chỉ object HinhChuNhat(40,10)
		        cout << "Count: " << ptr2.use_count() << endl; // số con trỏ, trỏ đến địa chỉ object HinhChuNhat(40,10)
		        cout << "Count: " << ptr3.use_count() << endl; // số con trỏ, trỏ đến địa chỉ object HinhChuNhat(40,10)
		
		        ptr3.reset();
		        // (*ptr3).tinhDienTich(); -> không hợp lệ, ctr bị lỗi
		        cout << "Count: " << ptr1.use_count() << endl;
		        cout << "Count: " << ptr3.use_count() << endl; // ptr3 đang không trỏ đến 1 object nào cả 
		
		        return 0;
		    }

### IV. weak_ptr

			#include <iostream>
			#include <memory>
			
			using namespace std;
			
			class HinhChuNhat {
			private:
			    int ChieuDai;
			    int ChieuRong;
			
			public:
			    HinhChuNhat(int dai, int rong){
			        ChieuDai = dai;
			        ChieuRong = rong;
			        cout << "Constructor called. "  << endl;
			    }
			
			    void tinhDienTich() {
			        cout << "Dien tich: " << ChieuDai * ChieuRong << endl;
			    }
			    ~HinhChuNhat() {
			        cout << "Destructor called " << endl;
			    }
			};
			
			int main() {
			    shared_ptr <HinhChuNhat> ptr1 (new HinhChuNhat(40,10));
			    shared_ptr <HinhChuNhat> ptr2(ptr1);
			    weak_ptr <HinhChuNhat> ptr3 (ptr1);
		            weak_ptr <HinhChuNhat> ptr4 (ptr2);
				    
		            // ________________________________________________________________________________________________________________________________________ 
		            cout << "\nCase 1" << endl; // Khi chưa reset, giá trị của ptr1 và ptr2 vẫn còn.
		            
		            if (auto ptr_lock = ptr3.lock()) ptr_lock->tinhDienTich(); // diện tích = 400
				    else cout << "Object has been deallocated" << endl;
				    
		            if (auto ptr_lock = ptr4.lock()) ptr_lock->tinhDienTich();  // diện tích = 400
				    else cout << "Object has been deallocated" << endl;
		
		            cout << "Count: " <<ptr1.use_count() << endl;
		            cout << "Count: " <<ptr2.use_count() << endl;
		
		            // ________________________________________________________________________________________________________________________________________ 
		            cout << "\nCase 2" << endl; // Khi chỉ reset giá trị ptr1 -> vẫn còn tồn tại 1 share pointer là ptr2 trỏ đến object -> lock() vẫn sẽ trả về một shared_ptr hợp lệ có thể sử dụng để truy cập đối tượng.
				    
		            ptr1.reset(); 
				    if (auto ptr_lock = ptr3.lock()) ptr_lock->tinhDienTich(); // diện tích = 400
				    else cout << "Object has been deallocated" << endl;
		            cout << "Count: " <<ptr1.use_count() << endl; // tuy nhiên count ở đây đã = 0
		            cout << "Count: " <<ptr2.use_count() << endl;
		
		            // ________________________________________________________________________________________________________________________________________ 
		            cout << "\nCase 3 " << endl; // Cả ptr1 và ptr2 đã bị reset-> shared_ptr đã bị giải phóng -> lock() sẽ trả về một shared_ptr rỗng. 
		            
		            ptr2.reset(); 
		            if (auto ptr_lock = ptr4.lock()) ptr_lock->tinhDienTich();
				    else cout << "Object has been deallocated" << endl; // "Object has been deallocated"
		            cout << "Count: " <<ptr1.use_count() << endl; // count = 0
		            cout << "Count: " <<ptr2.use_count() << endl; // count = 0
		
			    return 0;
			}

## B. Lambda

		#include <iostream>
		#include <functional>
		
		#define PI 3.14
		
		using namespace std;
		
		void processFunction(int a, int b, const function<void(int, int)>& func) {
		    cout << "Processing numbers: " << a << " and " << b << endl;
		    func(a, b);
		}
		
		int main() {
		    int a = 10;
		    const double g = 9.8;
		
		    processFunction(7, 9, [a](int x, int y) {
		        cout << "Product: " << x * y + a << endl;
		    });
		
		    processFunction(7, 9, [g](int x, int y) {
		        cout << "Product: " << x + y + g << endl;
		    });
		
		    processFunction(7, 9, [](int x, int y) {
		        cout << "Product: " << x - y + PI << endl;
		    });
		
		    return 0;
		}

__________________________________________________________________________________________________________________________________________________________________________
# Lesson 18: Multithreading	
> https://viblo.asia/p/lam-quen-voi-multithreading-trong-c-qm6RWQYXGeJE
>
> https://viblo.asia/p/lam-quen-voi-multithreading-p2-AQ3vVka1RbOr
>
> https://viblo.asia/p/concurrency-in-c11-LzD5dOLzljY
>
> https://toilangthangit.wordpress.com/
> 
> https://websitehcm.com/c-multithreading/

## A, Tổng quan về các mô hình lập trình: tuần tự, đồng thời và song song
> https://zalopay-oss.github.io/go-advanced/ch1-basic/ch1-05-concurrency-parallelism.html

**I. Mô hình lập trình tuần tự Sequential**.
+ Thời gian đầu, CPU chỉ có một nhân duy nhất, các ngôn ngữ khi đó sẽ theo **mô hình lập trình tuần tự**.
+ Xử lý tuần tự là khả năng xử lý chỉ một tác vụ trong một khoảng thời gian, các tác vụ sẽ được thực thi theo thứ tự hết tác vụ này sẽ thực thi tiếp tác vụ khác.
+ Dưới đây là ví dụ cho mô hình xử lý tuần tự (sequential processing):
  
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/9f2644b6-e056-4b8b-b753-b6655d7c1f94)

+ Ngày nay, với sự phát triển của công nghệ, **mô hình lập trình đồng thời Concurrency đối với các hệ thống lõi đơn** và **mô hình lập trình song song Parallelism đối với các hệ thống đa lõi và đa xử lý** ngày càng phổ biến với những ưu điểm nổi bật.

**II. Mô hình lập trình đồng thời Concurrency**
+ Đối với **hệ thống lõi đơn(máy tính có một processor với một unit/core)** thì ĐA LUỒNG (Multithreading) thực chất **xử lý task tuần tự**.
+ Bản chất tại một thời điểm nhân CPU chỉ có thể xử lý một tác vụ, vậy làm sao 1 máy tính có CPU 1 nhân có thể làm được việc xử lý đồng thời nhiều tác vụ của các tiến trình cùng lúc.
+ Như câu nói của Rob Pike: Concurrency is about dealing with lots of things at once-Rob Pike, ông đã sử dụng từ dealing (phân chia xử lý) để nói đến khái niệm concurrency.
+ Thật như vậy, nhân CPU không bao giờ đợi xử lý xong một tác vụ rồi mới xử lý tiếp tác vụ khác, mà nhân CPU đã chia các tác vụ lớn thành các tác vụ nhỏ hơn và sắp xếp xen kẽ lẫn nhau. Nhân CPU xẽ tận dụng thời gian rảnh của tác vụ này để đi làm tác vụ khác, một lúc thì làm tác vụ nhỏ này, một lúc khác thì làm tác vụ nhỏ khác. Việc này được gọi là **task switching**. Như vậy chúng ta sẽ cảm thấy máy tính xử lý nhiều việc cùng lúc tại cùng thời điểm. Nhưng bản chất bên dưới nhân CPU thì nó chỉ có thể thực thi một tác vụ nhỏ trong tác vụ lớn tại thời điểm đó.
+ Dưới đây là ví dụ về việc chia nhỏ tác vụ và xử lý trong mô hình concurrency

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/09152694-4476-4799-8e3b-5fe14ef40a5c)

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/26090c70-0ae8-454f-a858-d5902b6c715a)

		Trong đó, màu đỏ: task 1; màu xanh: task 2; màu xám: context switch
		Context switch: Hệ điều hành sẽ lưu trạng thái CPU và instruction pointer của task hiện tại; tìm task sẽ được thực hiện tiếp; load trạng thái CPU cho việc thực hiện task tiếp theo)
  
**III. Mô hình lập trình song song Parallelism.**

+ Đối với **hệ thống đa lõi và đa xử lý (máy tính có nhiều processor | máy tính có nhiều core trong một processors)** thì ĐA LUỒNG (Multithreading) thực chất là các LUỒNG (thread) **xử lý song song các task khác nhau cùng một lúc, các tác vụ này hoàn toàn độc lập với nhau** trên **lõi hoặc bộ vi xử lý khác nhau**. Thay vì một nhân CPU chúng ta chỉ có thể xử lý một tác vụ nhỏ tại một thời điểm thì khi số nhân CPU có nhiều hơn chúng ta có thể xử lý các tác vụ song song với nhau cùng lúc trên các nhân CPU.
+ Dưới đây là ví dụ cho mô hình xử lý song song các tác vụ cùng một thời điểm.
  
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/8e8ba1ae-b324-457a-a33d-a1164f8f3e34)		
   
+ Trong thực tế, trên mỗi nhân của CPU vẫn xảy ra quá trình xử lý đồng thời miễn là tại một thời điểm không có xảy ra việc xử lý cùng một tác vụ trên hai nhân CPU khác nhau, mô hình trên vẽ lại như sau:
  
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/266eaccb-5449-4f19-a4a0-0e9645b3a6fb)

### B. Các mô hình của Concurrency
**I. Multiprocessing**

+ Ở multiprocessing, sẽ có nhiều process (tiến trình). Mỗi tiến trình chỉ có một thread (luồng).
+ Các process giao tiếp với nhau thông qua Interprocess Communication (signals, sockets, files, pipes, message queues, …).
+ Dưới đây là ví dụ cho việc giao tiếp giữa 2 process chạy đồng thời
  
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/dbeaca76-9b08-464b-a538-cecf27fcafc0)

**II. Multithreading**

+ Ở multithreading, một process chứa hai hay nhiều thread. Việc giao tiếp giữa các thread này sẽ qua Shared memory.
+ Dưới đây là ví dụ cho việc giao tiếp giữa 2 thread qua shared memory
  
![image](https://github.com/minchangggg/Advanced_C/assets/125820144/d718b6c2-fa21-4b29-87cd-eb751c5ded65)

+ Lợi ích của Multithreading trong C++ là:
  
	Tăng hiệu năng và thời gian thực thi.
	Tận dụng tài nguyên hệ thống: Bằng cách sử dụng multithreading, chương trình có thể tận dụng được nhiều bộ xử lý (cores) của máy tính. Mỗi luồng (thread) có thể chạy trên một bộ xử lý riêng, đồng thời thực hiện các tác vụ độc lập. Điều này giúp tối ưu hóa sử dụng tài nguyên hệ thống và đảm bảo rằng máy tính hoạt động ở mức tối đa.
	Xử lý đồng thời các tác vụ độc lập: Multithreading cho phép chương trình chạy đồng thời các tác vụ độc lập nhau. Điều này rất hữu ích trong các tình huống cần xử lý song song các công việc như xử lý dữ liệu đồng thời, phản hồi các sự kiện đồng thời, hoặc thực hiện các tác vụ background trong khi chương trình vẫn tiếp tục hoạt động.
	Tăng tính tương tác và sự phản hồi của ứng dụng: Multithreading cho phép chương trình chạy các tác vụ không liên quan song song với nhau. Điều này tạo ra một trải nghiệm tương tác mượt mà hơn, giúp người dùng cảm nhận được sự phản hồi nhanh chóng của ứng dụng và không bị gián đoạn.

## C. Sử dụng shared memory cho Multithreading 
+ `Threads`
+ `Race conditions`
+ `Mutexes`
+ `Deadlock`
+ `Condition variables`
+ `Asynchonous tasks`
+ `Atomicity`

### I. Threads
#### 1. Cơ bản về thread
+ Mỗi chương trình C++ đều có **tối thiểu một thread**, nó được chạy trong runtime: thread đó là main().
+ Sau đó chương trình có thể khởi chạy các thread khác nữa với từng tác vụ nhất định phục vụ cho một mục đích nào đó.
+ Những thread này chạy đồng bộ với các thread khác cũng như thread được khỏi tạo ban đầu. Khi tác vụ của một thread chạy xong và trả về một kết quả nào đó, thread đó sẽ kết thúc; tương tự như chương trình sẽ kết thúc khi chương trình nhận giá trị trả về từ main().
+ Như các bạn cũng đã biết, nếu chúng ta có một đối tượng std::thread cho một thread nào đó, chúng ta cần đợi cho đến khi nó chạy xong.
+ Nhưng trước khi việc đó xảy ra, mình cần làm là khởi tạo một thread.
#### a. Việc khởi chạy một thread (launching a thread)

		// Đầu tiên include header thread 
		#include <thread>
		
		// Khi muốn khởi tạo 1 thread, tạo 1 thread object:
		thread t_empty;

+ Hàm khởi tạo mặc định của thread class được sử dụng. Chúng ta không chuyền bất cứ 1 thông tin nào vào thread. Tức là không có gì được chạy trong thread này.
+ Chúng ta phải khởi tạo thread. Nó có thể được hoàn thành bằng cách khác. Khi bạn tạo 1 thread, bạn có thể truyền 1 con trỏ hàm vào khởi tạo của nó -> 1 thread được khởi tạo, function sẽ bắt đầu chạy, nó chạy trong 1 thread riêng biệt

		#include <iostream>
		#include <thread>
		using namespace std;
		void threadFunc() {
			cout << "Welcome to Multithreading" << endl;
		}
  
		int main() {
			//truyền 1 function tới thread
			thread funcTest1(threadFunc);
		}

+ Việc biên dịch đoạn code trên không có vấn đề gì, tuy nhiên bạn sẽ lập tức đối mặt với 1 runtime error
+ Lý do là: Main thread tạo 1 thread mới là funcTest1 với paramaters threadFunc. **Main thread không đợi funcTes1 huỷ, nó tiếp tục hoạt động và sẽ kết thúc**, nhưng **funcTest vẫn chạy -> Nó sẽ dẫn đễn lỗi**. **TẤT CẢ CÁC THREAD PHẢI HUỶ TRƯỚC KHI MAIN THREAD HUỶ**. Vậy làm các nào khắc phục vấn đề này ?

#### b. Dùng Join threads để chờ một thread cho đến khi nó hoàn thành tác vụ
+ Thread class cung cấp method **join()**, hàm này chỉ **return khi tất cả các thread kết thúc**, điều đó có nghĩa là **main thread sẽ đợi đến khi tất cả các thread con hoàn thành công việc của nó**. 

**Ex 1**

		#include <iostream>
		#include <thread>
		using namespace std;
		void threadFunc() {
			cout << "Welcome to Multithreading" << endl;
		}
  
		int main() {
			//truyền 1 function tới thread
			thread funcTest1(threadFunc);
  
			//main sẽ block đến khi funcTest1 kết thúc
			funcTest1.join();
		}
  
**Ex 2:**

		#include <iostream>
		#include <thread>
		
		void printHello() {
		    std::cout << "Hello from thread!" << std::endl;
		}
		
		int main() {
  		    // Tạo một luồng t1 với hàm printHello
		    std::thread t1(printHello);
      
      		    // Hàm join() được gọi để chờ luồng t1 kết thúc trước khi chương trình kết thúc.
		    t1.join();
      
		    return 0;
		}

**Ex 3:**

		struct func {
		   int& i;
		   func(int& i_):i(i_){}
		   void operator()() {
		      for(unsigned j=0;j<1000000;++j) {
		         do_something(i); // point1: Potential access to dangling reference
		      }
		   }
		};
  
		void oops() {
		   int some_local_state=0;
		   func my_func(some_local_state);
		   std::thread my_thread(my_func);
		   my_thread.join(); // point2: wait for thread to finish
                }

> Việc sử dụng my_thread.join() nhằm mục đích cho thread này chạy xong trước khi kết thúc function oop() và do đó, nó cũng sẽ chạy trước khi biến some_local_state bị huỷ. Nếu biến này bị huỷ trước khi thread chạy xong, sẽ dẫn đến việc ở lần chạy tiếp theo, do_something(i) (point1) sẽ truy cập vào một biến đã bị huỷ (some_local_state). Điều này có thể dẫn đến những kết quả không mong muốn của chương trình.
> Lưu ý là chúng ta chỉ được gọi join() một lần với mỗi một thread cụ thể, bởi vì hành động này dọn dẹp các tài nguyên, bộ nhớ liên quan tới thread đó. Một khi chúng ta đã gọi hàm join(), hàm joinable() sẽ trả về giá trị false.

#### c. Khởi tạo thread với object hoặc 1 function của class
+ Có thể khởi tạo thread không chỉ với 1 function mà có thể dùng với 1 object hoặc 1 function của class.
  
**Ex 1:**

		class myFunctor {
		public:
			void operator()() {
				cout << "This is my function object" << endl;
			}
		};
  
		int main() {
  			// 1. Khởi tạo thread bằng cách truyền object của class myFunctor vào hàm khởi tạo của thread
			myFunctor myFunc1;
			thread functorTest1(myFunc1);
			if (functorTest1.joinable()) functorTest1.join();
		}

**Ex 2:**

		class myFunctor {
		public:
			void publicFunction() {
				cout << "public function of myFunctor class is called" << endl;
			}
		};
  
		int main() {
		 	// 2. Khởi tạo thread với 1 public function của class, phải định nghĩa function và truyền object của class định nghĩa function đó
			myFunctor myFunc2;
			thread functorTest2(&myFunctor::publicFunction,myFunc2);
			if (functorTest2.joinable()) functorTest2.join();
		}
  
#### d. Joinable and not Joinable threads
+ Sau khi hàm join return, thread trở lên không thể join lại. 1 joinable thread là 1 thread mà đại diện cho 1 execution mà chưa join.
+ 1 thread không là joinable khi nó được khởi tạo mặc định hoặc được moved/assigned tới 1 thread khác hoặc joind hoặc detach hàm đã được ọi Not joinable thread có thể huỷ 1 cách an toàn. Hàm joinable() để checks thread có là joinable thread hay không (trả về true nếu thread là joinable and false nếu ngược lại). Nên sử dụng hàm này trước khi call hàm join();
	
  		//truyền 1 function tới thread
		thread funcTest1(threadFunc);
  
		//check if thread is joinable
		if (funcTest1.joinable()) {
		//main is blocked until funcTest1 is not finished
		    funcTest1.join();
		}
#### e. Việc chờ một thread trong các trường hợp đặc biệt (exceptional circumstances)
Đặc biệt ở đây có nghĩa là gì? Ví dụ:

+ Điều gì xảy ra nếu chương trình chúng ta xảy ra lỗi sau khi thread đã khởi chạy và trước khi chúng ta gọi hàm join().
+ Ở trường hợp này, chương trình quăng exception rồi bị chấm dứt (terminate) trước khi hàm join() được gọi (tham khảo phần References).
  
Do vậy để tránh trường hợp này chúng ta sẽ sử dụng các cách sau:

**Dùng try/catch** 

+ Ngoài việc gọi hàm join() trong trường hợp lý tưởng không có exception, chúng ta cũng sẽ gọi hàm join() khi exception xảy ra:

			struct func;
			void f() {
				int some_local_state=0;
				func my_func(some_local_state);
				std::thread t(my_func);
				try {
					do_something_in_current_thread();
				}
				catch(...) {
					t.join(); //point1
					throw;
				}
				t.join(); //point2
			}
+ Việc dùng try/catch sẽ đảm bảo cho việc truy cập vào biến some_local_state sẽ kết thúc trước khi hàm kết thúc, dù là kết thúc bình thương (point2) hay do exception (point1).

**Dùng RAII (Resource Acquisition Is Initialization)**

+ Nếu việc sử dụng try/catch hơi dài dòng, thì chúng ta có thể sử dụng cách này, nó cung cấp cho chúng ta một class thực hiện việc gọi join() trong destructor:
  
			class thread_guard {
			   std::thread& t;
			   public:
			   explicit thread_guard(std::thread& t_): t(t_){}
			   ~thread_guard() {
				if(t.joinable()) t.join();
			   }
			   thread_guard(thread_guard const&)=delete;
			   thread_guard& operator=(thread_guard const&)=delete;
			};
  
			struct func;
			void f() {
			   int some_local_state=0;
			   func my_func(some_local_state);
			   std::thread t(my_func);
			   thread_guard g(t);
			   do_something_in_current_thread();
			}

+ Ở cách này, khi hàm f() kết thúc, những đối tượng trong function này sẽ được huỷ theo thứ tự ngược, có nghĩa là đối tượng thread_guard với tên g sẽ gọi hàm huỷ trước, sau đó, hàm join() sẽ được gọi trong hàm destructor này. Việc này được tiến hành ngay cả khi hàm do_something_in_current_thread() quăng exception nào đó.
+ Nếu chúng ta không cần đợi một thread chạy xong trước khi chương trình/hàm kết thúc, mình có thể sử dụng hàm detach(). Một khi hàm này được gọi, nó sẽ không có bất kỳ liên kết nào nữa với đối tượng std::thread, do đó đảm bảo việc std::terminate() sẽ không được gọi khi đối tượng std::thread bị huỷ, mặc dù thread này chạy ngầm.
  
#### f. Detaching thread
+ Thread trở thành not joinable sau khi hàm detach được gọi.
+ Việc gọi detach() ở đối tượng std::thread có nghĩa tách một thread chạy độc lập/chạy ngầm. Một khi thread chạy ngầm, quyền sở hữu (ownership) và điều khiển sẽ do C++ Runtime Library thực hiện, việc này sẽ đảm bảo các tài nguyên liên qua đến thread đó sẽ được lấy lại một cách chính xác khi thread kết thúc.
+ Một thread khi đã detach còn được gọi là daemon thread (ở một số sách nói về khái niệm của daemon process trong UNIX – tiến trình chạy ngầm trong hệ thống mà không hề có User interface). Những thread loại này thường chạy xuyên suốt vòng đời của ứng dụng, thực hiện các tác vụ chạy ngầm như theo dõi hệ thống, dọn dẹp tài nguyên…
+ Việc khi nào sử dụng detach() phụ thuộc vào từng task cụ thể, để từ đó ta có những cơ chế để biết được thread đó đã hoàn thành hay chưa – hay là được sử dụng cho những task kiểu “fire and forget“.

		//detach funcTest1 from main thread
		funcTest1.detach();
		if (funcTest1.joinable()) {
			//main is blocked until funcTest1 is not finished
			funcTest1.join();
		}
		else cout << "functTest1 is detached" << endl;

+ mainthread không đợi các thread con bị huỷ!

#### 2. Truyền đối số cho thread (Passing arguments to a thread function)

**Ex 1:**

		#include <iostream>
		#include <thread>
		using namespace std;

		void printSomeValues(int val, string str, double dval) {
			cout << val << " " << str <<" " << dval << endl;
		}
  
		int main() {
			string str = "Hello";
			thread paramPass(printSomeValues, 5, str, 3.2); //5, str and 3.2 are passed to printSomeValues function
			if (paramPass.joinable()) paramPass.join();
		}
  
> Output Ex 1

		5 Hello 3.2

**Ex 2:** // Ví dụ về việc sử dụng nhiều luồng để tăng hiệu suất của chương trình

		#include <iostream>
		#include <thread>
		#include <vector>
		
		void printSum(int start, int end, int* sum) {
		    for (int i = start; i <= end; i++) {
		        (*sum) += i;
		    }
		}
		
		int main() {
		    int sum = 0;
		    std::vector<std::thread> threads;

       		    // Sử dụng 10 luồng để tính tổng của các số từ 1 đến 1000. Mỗi luồng tính tổng cho một phần của dãy số.
		    for (int i = 0; i < 10; i++) {
		        threads.push_back(std::thread(printSum, i * 100 + 1, (i + 1) * 100, &sum));
		    }
      		    // Sau đó gộp kết quả lại -> Sử dụng multithreading như vậy có thể tăng hiệu suất của chương trình.
		    for (int i = 0; i < 10; i++) {
		        threads[i].join();
		    }
      
		    std::cout << "Sum = " << sum << std::endl;
		    return 0;
		}


**Ex 3:**

		#include <iostream>
		#include <thread>
		using namespace std;
		
		class myFunctorParam {
		public:
			void operator()(int* arr, int length) {
				cout << "An array of length " << length << " is passed to thread" << endl;
				for (int i = 0; i != length; ++i) cout << arr[i] << " ";
				cout << endl << endl;
			}
			
			void changeSign(int* arr, int length) {
				cout << "An arrray of length " << length << " is passed to thread" << endl;
				for (int i = 0; i != length; ++i) cout << arr[i] << " ";
				cout << "\nChanging sign of all elements of initial array" << endl;
				for (int i = 0; i != length; ++i) {
					arr[i] *= -1;
					cout << arr[i] << " ";
				}
			}
		};
		
		int main() {
			int arr2[5] = { -1, -3, -5, -7, 0 };
		   	myFunctorParam objParamPass;
		   	
		   	thread test(objParamPass, arr2, 5);
			thread test2(&myFunctorParam::changeSign, &objParamPass, arr2, 5);
			
			if (test.joinable()) test.join();
			if (test2.joinable()) test2.join();
		}

> Output Ex 2

		An array of length 5 is passed to thread
		-1 -3 -5 -7 0 
		
		An arrray of length 5 is passed to thread
		-1 -3 -5 -7 0 
		Changing sign of all elements of initial array
		1 3 5 7 0 
  
#### 3. Chuyển quyền sở hữu của một thread
#### a. Bối cảnh
+ Chúng ta muốn viết một hàm tạo một thread (luồng) để chạy ngầm nhưng cần chuyển lại quyền sở hữu thread mới này cho hàm gọi thay vì ngồi đợi cho thread chạy xong.
+ Chúng ta cần tạo một thread và chuyển lại quyền sở hữu cho một hàm – mà hàm đó cần đợi cho tác vụ hoàn thành.
+ Cả 2 trường hợp này, ta cần thưc hiện chuyển quyền sở hữu thread cho một thread khác hoặc là một function (hàm).
#### b. Giải pháp
+ Sử dụng hàm std::move() của đối tượng std::thread

<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/128779f1-a66a-4ad8-9485-7046be154e73">

		Chuyển quyền sở hữu cho một thread khác
  
+ Ở ví dụ trên, ta đã thực hiện việc chuyển quyền sở hữu của thread t1 -> t2 bằng std::move(). Lúc này t1 không còn bất cứ liên kết với bất cứ thread nào – trở thành empty thread. Do đó, nó có thể được gán để chạy một thread mới.

#### c. Lợi ích của việc hỗ trợ std::move() ở std::thread
+ Chúng ta có thể xây dựng một class thread_guard như ở mục 1.3 (RAII) tại phần 1 của bài viết; giúp cho class này sở hữu quyền thực sự một thread. Điều này giúp chúng ta rất lớn, nó giúp ta tránh được kết quả không mong muốn trong quá trình chạy khi mà một đối tượng của class RAII tồn tại lâu hơn một thread mà nó đang tham chiếu – có nghĩa là không một thread nào khác có thể join hay detach thread một khi quyền sở hữu đã được chuyển sang đối tượng khác.

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/ff96e1ff-58e3-45fd-8af9-79fcf111578a">

		Chuyển quyền sở hữu ngay tại constructor của class scoped_thread ở 1 – 2
  
+ Việc hỗ trợ chuyển quyền sở hữu ở std::thread cho phép các containers (vùng chứa) nếu các containers đó là move-aware container (như là std::vector). Việc đặt các đối tượng thread vào std::vector là một bước hướng tới việc quản lý các thread một cách tự động, thay vì phải tạo từng biến cho mỗi thread rồi sau đó join từng cái riêng lẻ.

#### 4. Việc chọn số lượng thread cần khi chạy 
#### a. Bối cảnh
+ Giả sử chúng ta có một vấn đề phức tạp cần giải quyết, vậy chúng ta cần bao nhiêu thread để giải quyết một vấn đề nào đó?
#### b. Giải pháp
+ C++ Standard Library hỗ trợ chúng ta trong việc xác định số lượng threads có thể chạy lúc runtime bằng std::thread::hardware_concurrency(). Hàm này sẽ trả về số thread có thể chạy đồng thời của một chương trình.
+ Lưu ý: đây chỉ là con số tham khảo bời vì nó có thể trả về 0 nếu giá trị không được xác định rõ hoặc do lý do gì đó không thể tính toán được. Nhưng nó có thể hữu dụng giúp chúng ta trong việc chia các task giữa các thread.

	Ví dụ về std::thread::hardware_concurrency()

<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d6b58e9c-c86d-4da6-a8a2-6cc8a5213462">

	Output 

<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/962fd81d-975a-446e-aeed-7274fb47ab6b">

### II. Race conditions
+ Xảy ra khi có **hai hay nhiều yêu cầu** có thể **truy cập dữ liệu** được chia sẻ và chúng cố gắng **thay đổi** nó **cùng một lúc**. Vì thuật toán lập lịch luồng có thể hoán đổi giữa các luồng bất kỳ lúc nào, nên bạn không biết thứ tự mà các luồng sẽ cố gắng truy cập vào dữ liệu được chia sẻ. Do đó, kết quả của sự thay đổi dữ liệu lại phụ thuộc vào thuật toán lập lịch luồng, tức là cả hai luồng đang "chạy đua" để truy cập/thay đổi dữ liệu.
+ Vì lẽ đó, Race condition có thể gây ra lỗi không mong muốn trong lập trình, vì thế chúng ta cần phải tìm ra cách để giải quyết việc tranh chấp này. Hay chí ít là phải xác định được yêu cầu nào có quyền thao tác với dữ liệu. Đó là lí do Mutex ra đời.

### III. Mutex (Mutual Exclusion)
+ Hay còn gọi là "loại trừ lẫn nhau" được tạo ra nhằm ngăn chặn Race condition. Với mục tiêu một luồng không bao giờ được truy cập vào tài nguyên mà một luồng thực thi đang nắm giữ.
+ Tài nguyên được chia sẻ là một đối tượng dữ liệu, mà hai hoặc nhiều luồng đồng thời đang cố gắng sửa đổi. Thuật toán Mutex đảm bảo rằng nếu một quy trình đang chuẩn bị thao tác sửa đổi trên một đối tượng dữ liệu thì không một quy trình/luồng nào khác được phép truy cập hay sửa đổi cho đến khi nó hoàn tất và giải phóng đối tượng để các quy trình khác có thể tiếp tục.
+ Trong C++, chúng ta sử dụng std::mutex để khởi tạo một đối tượng mutex, sau đó gọi hàm lock() và unlock() để chỉ cho phép 1 thread tại một thời điểm có quyền truy cập vào đối tượng/ dữ liệu.
+ Dưới đây là một ví dụ đơn giản về cách sử dụng mutex để đồng bộ hóa truy cập vào biến được chia sẻ giữa các luồng:

**Ex 1:**

		#include <iostream>
		#include <thread>
		#include <mutex>
		
		std::mutex mtx; // Khai báo một mutex global
		
		int sharedVariable = 0; // Biến được chia sẻ giữa các luồng
		
		// Hàm thực hiện công việc cho luồng
		void threadFunction() {
			// Khóa mutex trước khi truy cập vào biến được chia sẻ
			mtx.lock();
			sharedVariable++; // Thực hiện một hoạt động trên biến được chia sẻ
			std::cout << "Giá trị biến được chia sẻ: " << sharedVariable << std::endl;
			// Mở khóa mutex sau khi thực hiện xong
			mtx.unlock();
		}

		int main() {
			// Tạo và bắt đầu hai luồng
			std::thread t1(threadFunction);
			std::thread t2(threadFunction);
			
			// Đợi cho các luồng kết thúc
			t1.join();
			t2.join();
			
			return 0;
		}

+ Trong ví dụ này, std::mutex mtx; là một biến mutex được khai báo global. Trong hàm threadFunction, mutex được khóa bằng cách sử dụng mtx.lock() trước khi truy cập vào biến sharedVariable, và được mở khóa bằng cách sử dụng mtx.unlock() sau khi đã thực hiện xong các hoạt động trên biến đó.

**Ex 3:**

		#include <iostream>
		#include <thread>
		#include <mutex>
		
		int dem = 0;
		
		using namespace std;
		
		mutex mtx;
		
		void delay(int s) {
		    for (size_t i = 0; i < 0xffff; i++) {
		        for (size_t j = 0; j < 5*s; j++) { }
		    }  
		}
		
		void funcA() {
		    while (1) {
		        mtx.lock();
		        dem++;
		        mtx.unlock();
		        cout<<"funcA: "<<dem<<endl;
		        delay(4000);
		    }
		}
		
		void funcB(){
		    while (1) {
		        mtx.lock();
		        dem++;
		        mtx.unlock();
		        cout<<"funcB: "<<dem<<endl;
		        delay(1000);
		    }
		}
		
		int main(int argc, char const *argv[]) {
		    thread t1(funcA);
		    thread t2(funcB);
		
		    t1.join();
		    t2.join();
		    
		    return 0;
		}

**Ex 4:**

		// C++ program to illustrate the thread synchronization using mutex 
		#include <iostream> 
		#include <thread> 
  		#include <mutex> 
		
		using namespace std; 
		
		// Create object for mutex 
		mutex mtx; 
		
		// Shared resource 
		int number = 0; 
		
		// function to increment the number 
		void increment(){ 
			// Lock the thread using lock 
			mtx.lock(); 
			
			// increment number by 1 for 1000000 times 
			for(int i=0; i<1000000; i++){ 
				number++; 
			} 
			
			// Release the lock using unlock() 
			mtx.unlock(); 
		} 
		
		int main() { 
			thread t1(increment); 
			thread t2(increment); 
		
			t1.join(); 
			t2.join(); 
			
			// Print the number after the execution of both threads 
			std::cout<<"Number after execution of t1 and t2 is "<<number; 
			
			return 0; 
		} 

+ Tuy nhiên, vì các thread khác phải chờ đến khi unlock được gọi mới có quyền truy cập nên sẽ dẫn tới một vấn đề được gọi là deadlock. Ngoài ra, việc này khiến chúng ta phải luôn ghi nhớ phải gọi unlock mỗi khi kết thúc một hàm, hay thậm khi cả có lỗi xảy ra. Do đó, C++ Standard có hỗ trợ việc gọi unlock() một cách tự động.
  
**a, std::unique_lock:**

+ std::unique_lock cho phép bạn khóa và mở khóa mutex một cách linh hoạt.
+ Nó có thể được sử dụng để khóa một mutex trong một phạm vi cụ thể và tự động mở khóa khi ra khỏi phạm vi đó.
+ std::unique_lock có thể được sử dụng cho các tình huống cần đặt khóa trong thời gian dài hoặc cần mở khóa trước thời gian kết thúc.

**b, std::shared_lock:**

+ std::shared_lock cũng được sử dụng để khóa mutex, nhưng nó hỗ trợ việc chia sẻ truy cập giữa các luồng.
+ Nó cho phép nhiều luồng cùng đọc một tài nguyên mà không cần phải chờ đợi khi một luồng khác đang đọc (khóa đọc).
+ Khi một luồng muốn ghi vào tài nguyên (khóa ghi), nó phải chờ cho đến khi tất cả các luồng đang đọc kết thúc.

**c, Ví dụ cách sử dụng std::unique_lock và std::shared_lock:**

**Ex 1**

		#include <iostream>
		#include <thread>
		#include <mutex>
		
		std::mutex mtx; // Mutex được chia sẻ
		
		void reader() {
			std::shared_lock<std::mutex> lock(mtx);
			std::cout << "Luồng đọc..." << std::endl;
		}
		
		void writer() {
			std::unique_lock<std::mutex> lock(mtx);
			std::cout << "Luồng ghi..." << std::endl;
		}
		
		int main() {
			std::thread t1(reader);
			std::thread t2(writer);
			std::thread t3(reader);
			
			t1.join();
			t2.join();
			t3.join();
			
			return 0;
		}

+ Trong ví dụ này, reader() sử dụng std::shared_lock để cho phép nhiều luồng đọc cùng một lúc, trong khi writer() sử dụng std::unique_lock để đảm bảo rằng chỉ có một luồng được phép ghi vào tài nguyên tại một thời điểm.

**Ex 2**
		
		#include <iostream> 
		#include <shared_mutex> 
		#include <mutex> 
		#include <thread> 
		using namespace std; 
		
		// creating a shared_mutex object 
		shared_mutex mutx; 
		int shared_data = 11; 
		
		// callable with shared lock 
		void readData() { 
			shared_lock<shared_mutex> lock(mutx); 
			cout << "Thread " << this_thread::get_id() << ": "; 
			cout << shared_data << endl; 
		} 
		
		// callable with unique_lock 
		void writeData(int n) { 
			unique_lock<shared_mutex> lock(mutx); 
			shared_data = n; 
			cout << "Thread" << this_thread::get_id() << ": \n"; 
		} 
		
		int main() { 
			thread t1(readData); 
			thread t2(writeData, 128); 
			thread t3(writeData, 10); 
			thread t4(readData); 
			
			t1.join(); 
			t2.join(); 
			t3.join(); 
			t4.join(); 
   
			return 0; 
		}
  
### IV. Deadlock
#### 1. Deadlock là gì?
+ Deadlock là trạng thái mà 2 hay nhiều thread sẽ chờ đợi lẫn nhau vì mỗi thread (vd là A) giữ một tài nguyên và chờ đợi tài nguyên từ thread khác (vd là B) – trong khi thread B này cũng đang cần tài nguyên từ A để mở khoá mutex.

<img width="450" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/83173629-d655-4afc-9b73-fd269763d451">

=> Ở ví dụ này, khi chạy chương trình sẽ xảy ra deadlock do mỗi thread đang đợi thread khác để giải phóng khoá mutex. Dưới đây là kết quả chạy chương trình

<img width="450" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/a3fa17d2-d8b6-4030-9bf3-415350456370">

#### 2. Các cách để tránh deadlock
#### a. Nên sử dụng một khoá mutex duy nhất
#### b. Tránh việc khoá một mutex rồi sau đó gọi một hàm được cung cấp bởi người dùng
#### c. Sử dụng std::lock() khi muốn khoá nhiều hơn một mutex.
#### d. Khoá mutex theo thứ tự giống nhau

### V. std::condition_variable : 
+ là một phần của thư viện chuẩn C++ (C++11 trở đi) được sử dụng để đồng bộ hóa giữa các luồng thông qua sự kích hoạt (notify) và chờ đợi (wait) của các sự kiện.
+ Nó cho phép một hoặc nhiều luồng đợi cho đến khi một điều kiện cụ thể được đáp ứng trước khi tiếp tục thực hiện các công việc khác.
+ Hiểu đơn giản nó đóng vai trò như cái điện thoại, nhằm đồng bộ thứ tự thực thi của các threads trong chương trình.
+ Để sử dụng std::condition_variable, bạn cần kết hợp nó với một hoặc nhiều mutex. Thông thường, việc kết hợp std::condition_variable với std::unique_lock là phổ biến.
+ Dưới đây là một ví dụ về cách sử dụng std::condition_variable để đồng bộ hóa giữa hai luồng:

**Ex 1:**

		#include <iostream>
		#include <thread>
		#include <mutex>
		#include <condition_variable>
		#include <chrono>
		
		std::mutex mtx;
		std::condition_variable cv;
		bool ready = false;
		
		void threadFunction1() {
			for (int i = 0; i < 5; ++i) {
				std::this_thread::sleep_for(std::chrono::seconds(1));
				{
				std::unique_lock<std::mutex> lock(mtx);
				ready = true;
				}
				cv.notify_one();
			}
		}
		
		void threadFunction2() {
			for (int i = 0; i < 5; ++i) {
				std::unique_lock<std::mutex> lock(mtx);
				cv.wait(lock, [] { return ready; });
				ready = false; // Đặt lại cờ trạng thái
				std::cout << "Luồng 2 nhận được thông báo và tiếp tục thực hiện công việc." << std::endl;
			}
		}
		
		int main() {
			std::thread t1(threadFunction1);
			std::thread t2(threadFunction2);
			
			t1.join();
			t2.join();
			
			return 0;
		}

+ Trong ví dụ này, threadFunction1 sẽ chạy một vòng lặp trong đó nó sẽ thực hiện việc chuẩn bị dữ liệu và gửi thông báo cho threadFunction2 sau mỗi giây. Trong khi threadFunction2 sẽ chờ đợi thông báo và sau đó tiếp tục thực hiện công việc của nó. Điều này sẽ diễn ra trong 5 lần lặp, mỗi lần đợi một thông báo mới từ threadFunction1.

**Ex 2:**

		// C++ program to illustrate the use of shared_mutex 
		#include <iostream> 
		#include <shared_mutex> 
		#include <mutex> 
		#include <thread> 
		#include <condition_variable>
		using namespace std; 
		
		// creating a shared_mutex object 
		mutex mutx; 
		condition_variable cv;
		int data_test = 0;
		
		
		void delay(int s){
		    for (size_t i = 0; i < 0xffff; i++) {
		        for (size_t j = 0; j < 5*s; j++) { }
	  	    } 
		}
		
		void writeData(){
		    for (int i = 0; i < 5; i++) {
		        delay(5000);
		        unique_lock<mutex> lock(mutx);
		        data_test = data_test+i;
		       
		        cv.notify_one(); 
		    }
		}
		
		void readData(){
		    for (size_t i = 0; i < 5; i++) {
		       unique_lock<mutex> lock(mutx);
		       cv.wait(lock);
		       cout<<"data: "<<data_test<<endl;
		    }
		}
		
		// driver code 
		int main() { 
			thread t1(writeData); 
			thread t2(readData); 
			
			t1.join(); 
			t2.join(); 
		
			return 0; 
		}

**Ex 3:**

		#include <iostream>
		#include <thread>
		#include <condition_variable>
		#include <mutex>
		#include <chrono>
		#include <queue>
  
		using namespace std;
		
		condition_variable cond_var;
		mutex m;
		
		int main() {
		    int value = 100;
		    bool notified = false;
      
		    thread reporter([&]() {
		        unique_lock<mutex> lock(m);
		        while (!notified) {
		            cond_var.wait(lock);
		        }
		        cout << "The value is " << value << endl;
		    });
		
		    thread assigner([&]() {
		        value = 20;
		        notified = true;
		        cond_var.notify_one();
		    });
		
		    reporter.join();
		    assigner.join();
		    return 0;
		}

**Ex 4:**

+ Chúng ta có một hàng đợi, producer thread sẽ có nhiệm vụ thêm phần tử vào hàng đợi này.
+ Cũng trong lúc đó, ta có consumer thread cũng đang chờ để xử lý khi hàng đợi này có dữ liệu từ producer thread.
+ producer sẽ thêm phần tử vào trong hàng đợi, sau đó thông báo cho consumer biết (thông qua notify_one()), và nó sẽ thực hiện in ra giá trị vừa được thêm vào.
  
<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/3033e716-2ac8-46d1-9e2f-7bb6acc71f76">

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/2201c1ee-61fd-40bc-a890-fa456ae4c77d">

### VI. Bất đồng bộ (Asynchronous)
#### 1. Bối cảnh
+ Giả sử bạn có một một chương trình, trong chương trình này có một hàm để tính giai thừa. Giả định rằng hàm này chạy rất tốn thời gian, mà bạn muốn tách ra một thread riêng để chạy. Khi thread thực thi xong, bạn làm thế nào để nhận kết quả của hàm này trả về? (cách cũ bạn có thể xài condition variable và mutex – nhưng ở đây mình không sử dụng cách này).
#### 2. Giải pháp
+ Sử dụng std::async() kết hợp std::future (bất đồng bộ)
+ Trong lập trình, bất đồng bộ thường ám chỉ việc thực hiện một tác vụ mà không cần chờ đợi kết quả của tác vụ trước đó hoàn thành.
+ Các tác vụ bất đồng bộ thường được thực hiện song song và có thể hoàn thành trong thời gian khác nhau.
+ Bất đồng bộ thường được sử dụng trong các tình huống khi bạn muốn tiếp tục thực hiện các tác vụ khác mà không cần chờ đợi kết quả từ các tác vụ trước đó.

**Ex 1:**

<img width="500" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/ad8d53eb-c309-4f30-8372-908a136e7e0f">

+ Ở ví dụ trên, chúng ta **gọi std::async()** và nó **trả về một std::future**.
+ Để **lấy được giá trị trả về**, ta sử dụng hàm **get() từ std::future** để nhận **giá trị trả về** của hàm **factorial()**.
+ Lưu ý: get() chỉ được gọi một lần, nếu không sẽ gây crash chương trình.
+ Hàm async() với tham số std::launch:async sẽ tạo một thread riêng biệt, tách biệt khỏi main thread.

**Ex 2:**

		#include <iostream>
		#include <thread>
		#include <chrono>
		
		// Hàm thực hiện công việc bất đồng bộ
		void asynchronousTask() {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			std::cout << "Công việc bất đồng bộ đã hoàn thành!" << std::endl;
		}
		
		int main() {
			// Tạo một luồng để thực hiện công việc bất đồng bộ
			std::thread asyncThread(asynchronousTask);
			
			std::cout << "Chương trình đang tiếp tục thực hiện công việc khác..." << std::endl;
			
			// Đợi cho luồng kết thúc
			asyncThread.join();
			
			std::cout << "Chương trình đã hoàn thành!" << std::endl;
			
			return 0;
		}

+ Trong ví dụ này, hàm asynchronousTask được gọi trong một luồng riêng biệt bằng cách sử dụng std::thread. Hàm này thực hiện một công việc bất đồng bộ bằng cách chờ 2 giây và sau đó in ra một thông báo. Trong khi đó, chương trình tiếp tục thực hiện các công việc khác mà không cần chờ đợi luồng bất đồng bộ hoàn thành.
+ Điều này chứng minh rằng công việc bất đồng bộ đã tiếp tục thực hiện mà không cần chờ đợi luồng hoàn thành, và chương trình tiếp tục thực hiện các công việc khác.

**Ex 3:**

		#include <iostream>
		#include <thread>
		#include <future>
		#include <chrono>
		
		// Hàm thực hiện công việc bất đồng bộ và trả về một kết quả
		int asynchronousTask() {
			std::this_thread::sleep_for(std::chrono::seconds(2));
			return 42;
		}
		
		int main() {
			// Tạo một tác vụ bất đồng bộ và lấy kết quả bằng future
			std::future<int> resultFuture = std::async(std::launch::async, asynchronousTask);
			
			// Thực hiện một số công việc khác
			std::cout << "Chương trình đang tiếp tục thực hiện công việc khác..." << std::endl;
			
			// Chờ và lấy kết quả từ tác vụ bất đồng bộ
			int result = resultFuture.get(); // Đợi và lấy kết quả từ tác vụ
			
			std::cout << "Kết quả từ tác vụ bất đồng bộ là: " << result << std::endl;
			
			return 0;
		}

+ Trong ví dụ này, chúng ta sử dụng std::async để tạo một tác vụ bất đồng bộ và std::future để lấy kết quả từ tác vụ đó. Phương thức get() được sử dụng để đợi và lấy kết quả từ tác vụ. Khi tác vụ hoàn thành, kết quả được trả về và được gán cho biến result.

Here are the most commonly used C standard library header files, categorized by their primary purpose:

---

## 1. Input, Output & File Handling

* **`<stdio.h>` (Standard Input/Output)**
Handles basic input and output operations.
* *Key Functions:* `printf()`, `scanf()`, `fgets()`, `puts()`, `fopen()`, `fclose()`, `fprintf()`



---

## 2. General Utilities & Memory Management

* **`<stdlib.h>` (Standard Library)**
Handles dynamic memory allocation, process control, random numbers, and numeric conversions.
* *Key Functions:* `malloc()`, `calloc()`, `realloc()`, `free()`, `exit()`, `rand()`, `atoi()`, `qsort()`


* **`<stdbool.h>` (Boolean Type & Values)** *(C99+)*
Provides native boolean support, defining the `bool` type alongside `true` and `false`.
* **`<stddef.h>` (Standard Definitions)**
Defines common types and macros used across C, such as `NULL`, `size_t`, `ptrdiff_t`, and the `offsetof()` macro.

---

## 3. Strings & Character Processing

* **`<string.h>` (String Manipulation)**
Provides utilities for copying, concatenating, comparing, and searching strings and raw byte arrays.
* *Key Functions:* `strlen()`, `strcpy()`, `strncpy()`, `strcat()`, `strcmp()`, `memcpy()`, `memset()`


* **`<ctype.h>` (Character Handling)**
Functions to test and convert individual characters (ASCII checks).
* *Key Functions:* `isalpha()`, `isdigit()`, `isalnum()`, `isspace()`, `toupper()`, `tolower()`



---

## 4. Mathematics & Data Types

* **`<math.h>` (Mathematical Functions)**
Provides common floating-point mathematical computations *(Note: require linking with `-lm` in GCC)*.
* *Key Functions:* `sqrt()`, `pow()`, `abs()`, `fabs()`, `sin()`, `cos()`, `ceil()`, `floor()`


* **`<stdint.h>` (Exact-Width Integer Types)** *(C99+)*
Defines integer types with fixed bit sizes for cross-platform portability.
* *Key Types:* `int8_t`, `int16_t`, `int32_t`, `int64_t`, `uint8_t`, `uint32_t`, `uint64_t`


* **`<limits.h>` & `<float.h>` (Implementation Limits)**
Define macros specifying minimum and maximum value ranges for basic integral (`INT_MAX`, `CHAR_MIN`) and floating-point types (`FLT_MAX`).

---

## 5. System, Time & Assertions

* **`<time.h>` (Time & Date Utilities)**
Provides functions to get system time, format dates, and calculate time differences.
* *Key Functions:* `time()`, `clock()`, `difftime()`, `strftime()`


* **`<assert.h>` (Diagnostics)**
Provides the `assert()` macro to create runtime debugging checks that abort execution if an expression evaluates to false.
* **`<errno.h>` (Error Reporting)**
Defines the global `errno` variable and specific integer macros (like `ENOENT`, `ENOMEM`) to report system call and library function errors.

---

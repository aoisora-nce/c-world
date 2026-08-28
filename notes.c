/* =========================================================================
 * 1. C PRIMITIVE TYPES OVERVIEW
 * =========================================================================
 *
 *               ┌──────────────────────────────────────────┐
 *               │           C PRIMITIVE TYPES              │
 *               └────────────────────┬─────────────────────┘
 *                                    │
 *      ┌─────────────────────────────┼─────────────────────────────┐
 *      │                             │                             │
 * ┌────┴───────────────┐    ┌────────┴──────────┐         ┌─────────┴─────────┐
 * │      INTEGERS      │    │  FLOATING-POINT   │         │    CHARACTERS     │
 * │   (Whole Numbers)  │    │     (Decimals)    │         │ (Letters/Symbols) │
 * └────────────────────┘    └───────────────────┘         └───────────────────┘
 * │ short  (2 bytes)        │ float       (4 bytes)       │ char (1 byte)
 * │ int    (4 bytes)        │ double      (8 bytes)
 * │ long   (4/8 bytes)      │ long double (12-16 bytes)
 *
 * Note: Sizes above are typical on modern 64-bit systems.
 * ========================================================================= */

/* =========================================================================
 * 2. CORE TYPES & FORMAT SPECIFIERS CHEAT SHEET
 * =========================================================================
 *
 * +-------------------+-------+---------------+-------------------+-----------------------------------------+
 * | Type              | Bytes | Format Spec.  | Literal Example   | Notes                                   |
 * +-------------------+-------+---------------+-------------------+-----------------------------------------+
 * | char              | 1     | %c (or %d)    | 'A'               | 8-bit integer (-128..127 / 0..255)      |
 * | int               | 4     | %d or %i      | 100               | Standard signed integer                 |
 * | unsigned int      | 4     | %u (%x / %o)  | 100u              | Hex (%x), Octal (%o)                    |
 * | long              | 4/8   | %ld           | 100000L           | Size depends on architecture            |
 * | long long         | 8     | %lld          | 10000000000LL     | Guaranteed at least 64 bits             |
 * | float             | 4     | %f            | 19.7f             | Single precision                        |
 * | double            | 8     | %f / %lf      | 19.7              | Default decimal type in C               |
 * | long double       | 12/16 | %Lf           | 19.7L             | Extended precision                      |
 * | char * (string)   | 8*    | %s            | "Hello"           | Array/Pointer of characters             |
 * | void * (pointer)  | 8*    | %p            | (void*)&var       | Memory address                          |
 * +-------------------+-------+---------------+-------------------+-----------------------------------------+
 *
 * PRINTF PROMOTION RULES:
 * - `float` is automatically promoted to `double` in printf. `%f` and `%lf` work identically.
 * - `char` and `short` are promoted to `int` in variadic functions like printf.
 * - `%%` prints a literal '%' sign.
 * ========================================================================= */

/* =========================================================================
 * 3. LITERALS, IMPLICIT CONVERSION & DEMOTION
 * =========================================================================
 *
 * A. DOUBLE LITERAL WARNING:
 *    Decimal literals without a suffix (e.g., 19.7) default to `double`.
 *    - float a = 19.7;   // Truncates 8-byte double to 4-byte float (-Wconversion)
 *    - float a = 19.7f;  // Explicit float literal (clean)
 *    - double a = 19.7;  // Matching double variable (clean)
 *
 * B. IMPLICIT TRUNCATION:
 *    Assigning a floating-point number to an integer type STRIPS the decimal
 *    part entirely (it does NOT round).
 *    - int a = 19.7;     // Stores 19
 *
 * C. CHARACTERS ARE SMALL INTEGERS:
 *    Assigning a float to a `char` truncates to an integer, then treats that
 *    integer as an ASCII code.
 *    - char c = 65.9;    // Stores 65 ('A' in ASCII)
 *
 * D. OVERFLOW & BOUNDARIES:
 *    If a truncated value exceeds the memory limit of the target type, it wraps.
 *    - char x = 300.5;   // Truncates to 300. Max char is 127/255.
 *                        // Wraps (300 % 256 = 44) -> stores 44 (ASCII ',').
 *
 * DEMOTION EXAMPLES SUMMARY:
 * +------------------+--------------+-----------+-----------+---------------------------------------+
 * | Code             | Stored Value | %d Output | %c Output | Result / Behavior                     |
 * +------------------+--------------+-----------+-----------+---------------------------------------+
 * | int  a = 19.7;   | 19           | 19        | \x13      | Truncated decimal                     |
 * | char a = 19.7;   | 19           | 19        | (blank)   | Non-printable control character       |
 * | char a = 65.8;   | 65           | 65        | A         | ASCII 65 = 'A'                        |
 * | char a = 300.5;  | 44           | 44        | ,         | Truncated & Overflown (modulo wrap)   |
 * +------------------+--------------+-----------+-----------+---------------------------------------+
 *
 * BEST PRACTICE:
 * Always compile with `-Wall -Wconversion` to catch implicit demotions:
 * $ gcc -Wall -Wconversion main.c -o main
 * ========================================================================= */

/* =========================================================================
 * 4. SAFE USER INPUT (SCANF & STDIN HANDLING)
 * =========================================================================
 *
 * A. SCANF SYNTAX & DIFFERENCES FROM PRINTF:
 *    - Needs address-of operator (&): `scanf("%d", &var);`
 *    - Exception: Arrays/Strings already act as memory pointers (no & needed).
 *    - MUST use `%lf` for `double` in scanf (unlike printf where `%f` works).
 *    - Use leading space `" %c"` to skip unread trailing newlines/spaces.
 *
 * B. RETURN VALUE & BOUNDS SAFETY:
 *    - scanf() returns the COUNT of successfully assigned items (or EOF on failure).
 *    - Always check return values: `if (scanf("%d", &val) == 1)`
 *    - ALWAYS enforce width limits on strings to avoid buffer overflows:
 *      char buf[20];
 *      scanf("%19s", buf); // Leaves room for null-terminator '\0'
 *
 * C. CLEARING LEFTOVER BUFFER:
 *    If the user enters extra characters, they sit in `stdin` and ruin the
 *    next read. Clear them using a flush loop:
 *
 *    int c;
 *    while ((c = getchar()) != '\n' && c != EOF);
 *
 * D. INDUSTRY STANDARD PATTERN (fgets + sscanf):
 *    Avoid raw `scanf()` issues by reading an entire line at once:
 *
 *    char line[100];
 *    int val;
 *    if (fgets(line, sizeof(line), stdin)) {
 *        if (sscanf(line, "%d", &val) == 1) {
 *            // Input successfully parsed
 *        }
 *    }
 * ========================================================================= */

/* =========================================================================
 * 5. CONSTANTS, DEFINES & TYPEDEFS
 * =========================================================================
 *
 * A. CONST KEYWORD (Read-only Variables):
 *    - `const int MAX_USERS = 100;`
 *    - Read-only at runtime; type-checked by compiler. Must be initialized.
 *
 * B. #DEFINE MACROS (Preprocessor Text Replacement):
 *    - `#define PI 3.14159`
 *    - Replaces text before compilation. No semicolon, no memory allocated.
 *
 * C. TYPEDEF (Creating Type Aliases):
 *    - `typedef unsigned long long u64;`
 *    - Creates a cleaner name for complex or lengthy types: `u64 big_num = 100000ULL;`
 * ========================================================================= */

/* =========================================================================
 * 6. INTEGER ARITHMETIC & PROMOTION PITFALLS
 * =========================================================================
 *
 * A. INTEGER DIVISION TRUNCATION:
 *    - Dividing two integers truncates toward zero (discards decimals).
 *    - Example: 
 *        int a = 5, b = 2;
 *        double res = a / b;        // res = 2.0 (5/2 evaluates as int 2 first!)
 *        double res = (double)a / b; // res = 2.5 (Explicit cast forces float division)
 *
 * B. INTEGER OVERFLOW (Undefined Behavior):
 *    - Signed integer overflow is UNDEFINED in C (can cause security bugs).
 *    - Example: 
 *        INT_MAX + 1  ==> Behavior unpredictable / wraparound to negative.
 *    - Unsigned integer overflow is defined: it wraps around using modulo $2^n$.
 * ========================================================================= */

/* =========================================================================
 * 7. OPERATOR PRECEDENCE & EVALUATION ORDER
 * =========================================================================
 *
 * A. COMMON PRECEDENCE TIERS:
 *    1. Parentheses `()`, Array Subscript `[]`, Structure Member `.`
 *    2. Unary Operators: `++`, `--`, `!`, `&` (address-of), `*` (dereference), `sizeof`
 *    3. Arithmetic: `*`, `/`, `%`  then  `+`, `-`
 *    4. Relational / Equality: `<`, `>`, `<=`, `>=`, `==`, `!=`
 *    5. Logical AND/OR: `&&`, `||`
 *    6. Assignment: `=`, `+=`, `-=`, etc.
 *
 * B. POST-INCREMENT vs PRE-INCREMENT:
 *    - `int a = 5; int b = a++;` ==> `b` gets 5, then `a` becomes 6.
 *    - `int a = 5; int b = ++a;` ==> `a` becomes 6, then `b` gets 6.
 *
 * C. SHORT-CIRCUIT EVALUATION:
 *    - `(A && B)`: If A is false, B is NEVER evaluated.
 *    - `(A || B)`: If A is true, B is NEVER evaluated.
 * ========================================================================= */

/* =========================================================================
 * 8. SIZEOF OPERATOR & MEMORY LAYOUT
 * =========================================================================
 *
 * A. SIZEOF EVALUATION:
 *    - `sizeof` is a compile-time operator (not a runtime function).
 *    - Format specifier for `sizeof` is `%zu` (size_t type).
 *    - Example: `printf("Size of int: %zu bytes\n", sizeof(int));`
 *
 * B. ARRAY SIZEOF TRAP:
 *    - `int arr[10]; sizeof(arr)`      ==> Returns 40 (10 * 4 bytes).
 *    - Inside a function where `arr` was passed as a parameter:
 *      `sizeof(arr)`                    ==> Returns 8 (size of a pointer, NOT the array!).
 * ========================================================================= */

/* =========================================================================
 * 9. SCOPE, LIFETIME & VARIABLE STORAGE CLASSES
 * =========================================================================
 *
 * A. LOCAL / AUTO (Block Scope):
 *    - Created on stack when block `{}` starts; destroyed when block ends.
 *    - Contains GARBAGE VALUES if not explicitly initialized!
 *      `int x;` // x could be 0, 98213, or -4821. Always initialize!
 *
 * B. GLOBAL (File Scope):
 *    - Declared outside functions; accessible anywhere. Defaults to 0.
 *
 * C. STATIC LOCAL VARIABLES:
 *    - `static int count = 0;`
 *    - Retains its value between function calls (lives for the entire program execution).
 * ========================================================================= */

/* =========================================================================
 * 10. SUMMARY OF C BEGGINER GOLDEN RULES
 * =========================================================================
 *
 * 1. ALWAYS initialize variables before reading them (`int x = 0;`).
 * 2. ALWAYS specify a length limit when reading strings with scanf (`%19s`).
 * 3. ALWAYS check the return value of `scanf` or `fgets`.
 * 4. ALWAYS use `%lf` for `scanf("%lf", &double_var)` and `%f` for `printf`.
 * 5. CAST at least one operand to `(double)` when dividing integers for precision.
 * 6. COMPILE with warning flags enabled: `gcc -Wall -Wextra -Wconversion main.c`
 * ========================================================================= */

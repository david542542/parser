#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include <stdint.h>
#include <stdlib.h>
/* #include "new.h" */

void countdown(int n) {

    // Statements in a recursive function that come after the recursive call are
    // executed in the opposite order from which the functions are called.    static intptr_t initial_address=0;
    /* if (n!=0) { */
        /* initial_address = initial_address > (intptr_t) &n ? initial_address : (intptr_t) &n; */
        /* printf("%d...at address %p | offset: -%#zx\n", n, &n, initial_address - (intptr_t) &n); // pushing upto the stack (will grow down...) */
        /* countdown(n-1); */
        /* printf("%d...at address %p | offset: -%#zx\n", n, &n, initial_address - (intptr_t) &n); // pushing upto the stack (will grow down...) */
    /* } else  */
        /* printf("Liftoff!\n"); */
}
void print_binary(int n) {
    if (n > 1) {
        print_binary(n>>1);
        putchar((n%2+'0'));
    } else {
        putchar(n+'0');
    }
}
void swap(int* a, int* b) {
    // remember, a and be are both memory addresses now!
    // * indirection or dereferencing or value-of
    printf("The address of a is: %p\n", a);
    printf("The address of address-of a is: %p\n", &a);
    int tmp = *a;
    *a=*b;
    *b=tmp;
}
int* sum_array(int* x) {
    x = (int*) 44;
    getchar();
    // printf(x);
    int sum=0;
    for (int i=0; i < (sizeof(x) / sizeof(*x)); i++ ) {
        sum += x[i];
    }
    // printf("%d\n", sum);
    int* e = malloc(sizeof(*e)*3);
    printf("Sizeof(e): %zu\n", sizeof(*e));
    *e = 4;
    e[1] = 5;
    *(e+2) = 6;
    *(e+7) = 9;

    printf("%d\n", *(e+7));
    int ex[3] = {1,7,9};
    e = ex;


    // char * hello    = "Hello";
    // char * goodbye  = "Goodbye";
    // printf("hello=%s, goodbye=%s\n", hello, goodbye);

    // char * tmp_str  = hello;
    // hello = goodbye; // here we change the address, not the value at the address
    // goodbye = hello; 
    // &ex = e;
    // int e[] = e
    return e;
}

int add_two(int num) {
    return num + 2;
}
int square(int n)
{
    return n*n;
}
int main(void)
{

    // const int a1=4;
    // a1=2; // cannot do this because the a1 value is readonly (as guaranteed by the OS).
    // const int* a1_ptr = &a1;
    // a1_ptr = (void*) 10; // can change the pointer address of the item here.
    // printf("a1 address: %p\n", a1_ptr);
    // const int* const a1_ptr2 = &a1;
    // a1_ptr2 = (void*) 10;   // cannot do this because the pointer address is now const


    int b1 = 5;
    
    // 1. cannot change the value but can change the pointer address
    // (const int) or "Constant int" is the type, and the Pointer address is referenced with (*b1_ptr)
    const int *b1_ptr = &b1;
    // *b1_ptr = 7;         // cannot change the value because "const int" is the type
    b1_ptr = (int*) 144;    // <-- this is ok

    // 2. can change the value but cannot change the pointer address
    // (int) is the type and (* const b1_ptr2) is the constant pointer address
    int* const b1_ptr2 = &b1;
    *b1_ptr2 = 7;           // <-- this is ok
    // b1_ptr2 = (int*) 123; // but cannot change pointer address

    // 3. cannot change the value or pointer address
    // (const int) is the constant type and (* const b1_ptr3) is the constant pointer address
    const int * const b1_ptr3 = &b1;
    // *b1_ptr3 = 7;           // <-- this is not allowed
    // b1_ptr3 = (int*) 123; // <-- this is not allowed either

    const char * name = "David";
    name = "Todd"; // not illegal, because we are not changing the value! just pointing to a different string literal address

    char* const name2 = "david";
    // name2 = "Sarah"; // illegal since we are trying to change the memory address of the pointer at name2 now.

    const char name3[] = "Tom";
    // name3[1] = 'i'; // <-- illegal since trying to change the value
    const char* name4 = name3;
    // name4[1] = 'x';  // <--ilelgal since trying to change an individual char
    name4 = "Hero"; // <-- ok since changing the memory address that is pointed to


    // name
    // name3 = "Hello";

    const typedef struct Animal {
        int id;         
        char* name;
    } Animal;
    Animal dag = {.id=1, .name="Dog"};
    // dog.id=2;         // illegal
    // dog.name = "Bob"; // illegal
    // dog = 1234;

    typedef struct Animal2 {
        int id;         
        char* name;
    } Animal2;
    Animal2 dog = {.id=1, .name="Dog"};
    dog.id=2;
    dog.name = "Bob";
    printf("%p\n", &dog);
    // dog = &dog + 2; // cannot do this since it's on the stack...the memory address is the start of data itself, doesn't point anywhere


    typedef struct Animal3 {
        int id;         
        char* name;
    } Animal3;
    Animal3 *dug = &(Animal3) {.id=1, .name="Dog"};
    dug->id=3;
    dug->name="Bobby";
    dug = (Animal3*) 1234; // since its a pointer we can also reassign its address
    // dog.id=2;
    // dog.name = "Bob";

    return 0;
    int (*add_func)(int) = add_two;
    int d = (*add_func)(10);
    printf("%d\n", d);


    int (*squared)(int) = &square; // note: they cannot have the same name
    printf("The square of %d is %d\n", d, (*square)(d));
    printf("The square of %d is %d\n", d, (&square)(d));
    printf("The square of %d is %d\n", d, square(d));


    // struct thing {
        // int num; 
        // int (*add_func)(int);
    // };
    // struct thing xx = {.num=4, .add_func=add_two};
    // int yy = xx.add_func(xx.num);
    // printf("%d\n", yy);
    // void* item;
    // int (*add)(int num);

    // Item* something;
    return 0;
    int da[] = {1,2,3};
    int* da_ptr = (int*) da;
    // Differences between an Array and an Array-cast-to-pointer

    // the decayed pointer is not an lvalue!!!
    int xa[] = {3,5,9,12};
    printf("Sizeof: %zu\n", sizeof(xa));
    int* e = sum_array((int*)xa);
    printf("**%d**\n", e[0]);
    sum_array(&xa[0]);
    sum_array((int*) xa);
    sum_array((int*) &xa);
    // an array of three elements. Each element has type int[2] and is a coordinate.

    int arrar[2];
    memcpy(arrar, (int[2]){1,2}, sizeof(arrar)); // one way to initialize it
    printf("The address of arrar is: %p, and of first element: %p\n", arrar, &arrar[0]);
    arrar == &arrar[0]; 


    // pointer arithmetic
    int dates[4];
    int *pointer_dates;

    double bills[4];
    double *pointer_bills;

    // this will add sizeof(type) * i to the address!
    // in other words, it adds one 'storage unit' to the pointer (like its an array and grabs the next index)
    for (int i=0; i < 4; i ++)
        printf("pointers + %d: %p %p\n", i, pointer_dates+i, pointer_bills+i);

    // dates + 2 == &date[2];
    // *(dates + 2) == dates[2];

    // NOTE -- arrays and pointer have the following relationship
    // ptr+i    == &arr[i]       // address-of element in array at index I is same as ptr + I
    // *(ptr+1) == arr[i]       // value-of (ptr + I) is the same as array at index I, which grabs that element value
    // *(ar + n) --> "Go to memory location 'ar', move over 'n' units, and retrieve the value there.
    #define SIZE 4
    long long items[4]   = {1LL,2LL,4LL,8LL};
    long long *ptr_items = &items[0];
    for (int i=0; i < SIZE; i++) {
        printf("%d: Array: %lld | Pointer: %lld\n", i, items[i], ptr_items[i]);
        printf("%d: AddressA: %p | AddressP: %p | Same? %c\n", i, &items[i], ptr_items+i, (&items[i]==ptr_items+i)?'y':'n');
        printf("%d: ValueA: %lld | ValueP: %lld | Same? %c\n", i, items[i], *(ptr_items+i), (items[i]==*(ptr_items+i))?'y':'n');
    }

    // getchar();
    // getchar();


    // behind the scenes, the name of the array is also the address of the first element in the array!!
    // int arrar = {1,2};
    int coordinates[3][2] =  {
        {0,0},
        {2,2},
        {5,5}
    };
    size_t array_size = sizeof(coordinates)/sizeof(coordinates[0]);
    size_t element_size = sizeof(coordinates[0]) / sizeof(coordinates[0][0]);
    // full element at position array[i] (coordinates hardcoded)
    for (int i=0 ; i < array_size ; i++) {
        printf("The coordinate at index %d is (%d, %d)\n", i, **(coordinates+i), *(*(coordinates+i)));
        printf("The coordinate at index %d is (%d, %d)\n", i, coordinates[i][0], coordinates[i][1]);
        // inner element at position array[i][j]
        for (int j=0; j < element_size; j++) {
            printf("The %c value at coordinate (%d, %d) is %d\n", (j==0)?'x':'y', coordinates[i][0], coordinates[i][1], coordinates[i][j]);
        }
    }
    return 0;
    // getchar(); getchar();

    printf("The length of the mda array is: %zu and the number of elements is: %zu\n", 
            sizeof(coordinates), sizeof(coordinates)/sizeof(coordinates[0]));
    int ax=6;
    short xar[ax];
    for (int i = 0; i < sizeof(xar)/sizeof(*xar); ++i) {
        xar[i]=i*i;
        printf("Element %d = %d\n", i, xar[i]);
    }

    int newarr[10] = {1, [4] = 5, 6, [9]=10}; // same as doing {1,0,0,0,5,6,0,0,10}
    for (int i = 0; i < sizeof(newarr)/sizeof(newarr[0]); ++i) {
        printf("_arr_[%d]=%d\n", i, newarr[i]);
    }
    // if you only *partially* initialize an array, the non-initialized values will be set to zero.
    // but if the array isn't initialized at all, its values are garbage.
    const int arr[4] = {2,4,8,};
    size_t arr_size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
    /* const int arr[4]; */
    /* arr[0] = 2; */
    /* size_t num_arr_elements = sizeof(arr); */
    printf("The num of array elements is %zu\n", sizeof(arr)/sizeof(arr[0]));
    for (int i=0, arr_i; arr_i=arr[i], i<4; i++) {
        printf("The int at array index %d is %d\n", i, arr_i);
        printf("The int at array index %d is %d\n", i, arr[i]);
    }
    // swap values of hey, you
    int hey=9, you=6;
    printf("Hey=%d, You=%d\n", hey, you);
    int *hey_ptr = &hey;
    int *you_ptr = &you;

    you_ptr = hey_ptr;
    /* int *tmp_addr = you_ptr; */
    /* int tmp_value = *you_ptr; */
    /* you_ptr = hey_ptr; */
    /* hey_ptr = tmp_addr; */

    printf("Hey=%d, You=%d\n", hey, *you_ptr);

    char * hello    = "Hello";
    char * goodbye  = "Goodbye";
    printf("hello=%s, goodbye=%s\n", hello, goodbye);

    char * tmp_str  = hello;
    hello = goodbye; // here we change the address, not the value at the address
    goodbye = hello; 
    printf("hello=%s, goodbye=%s\n", hello, goodbye);

    /* int tmp_value = *hey_pointer; */
    /* *you_pointer = *hey_pointer; */
    /* *hey_pointer = tmp_value; */
    /* printf("Hey=%d, You=%d\n", hey, you); */
    // hey_pointer ==> address of hey

    return 0;


    char girl1[] = "Cindy";
    char girl2[] = "Carmen";

    printf("Girl1: %s | Girl2: %s\n", girl1, girl2);

    printf("Girl1: %s | Girl2: %s\n", girl1, girl2);

    int x=7;
    int* cc=&x; // cc equals the address of x
    *cc=17;   // the value of cc (which is also the address of x) is now 17
    printf("%d\n", x); // this means the value of x is also 17!


    int a=7, b=27, tmp;
    printf("a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return 1;



    /* printf("%s\n", HELLO); */
    print_binary(8);
    putchar('\n');
    countdown(7);
    return 1;
    // 1. Send text from stdin to an output file
    // gcc test.c -o test.o && ./test.o <<< "Hello this is something new" > new.txt

    // 2. Send text from a file to an output file
    // gcc test.c -o test.o && ./test.o < test.c > new.txt

    // 3. Or can do an echo and use that as stdin
    // gcc test.c -o test.o && echo 'hello' | ./test.o

    // 4. Or can do the same thing with printf
    // $ gcc test.c -o test.o && printf 'hello%d\n' 44 | ./test.o
    char c;
    bool is_newline = true;
    bool inword = false;
    int num_words = 0;

    while ((c = getchar()) != EOF) {
        if (isspace(c) && inword) 
            num_words ++;
        if (!isspace(c))
            inword = true;
        else
            inword = false;
        if (is_newline) {
            putchar('/'); 
            putchar('/');
            is_newline = false;
        }
        putchar(c);
        if (c=='\n')
            is_newline=true;
    }
    printf("The number of words was %d\n", num_words);
}

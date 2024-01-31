#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta3_codes
cc -o test hafta3_3_string.c 
*/

/*
int main(){
  char str1[] = "some text";  char str2[10] = "yes";  char str3[3] = "four";  char str4[4] = "fou";  char *ptr = "more teeext";

 
  printf("strlen(str1): %lu\n", strlen(str1));
  printf("strlen(str2): %lu\n", strlen(str2));
  printf("strlen(str3): %lu\n", strlen(str3));
  printf("strlen(str4): %lu\n", strlen(str4));
  printf("strlen(ptr): %lu\n", strlen(ptr));

  for(int i=0; i<strlen(ptr); i++)
    printf("%d: %c ", i, ptr[i]);
  printf("\nsonuncu: %d \n", ptr[strlen(ptr)]);
  return 0; }
*/


int main ()  {
  char array[10];
  char ptr[] = "10 spaces";  
  char *ptr1 = (char*) ptr;  // 1* READ EXPLANATION IN THE BOTTOM, we get "Bus error: 10" 
  //char *ptr1 = "10 spaces";

  char *ptr2;
  // array = "not OK"; // can NOT assign to an address of an array!

  array[5] = 'A';	// OK

  printf("ptr1: %s\n", ptr1);
  ptr1[5] = 'B';	// OK
  printf("ptr1: %s\n", ptr1);


  ptr1="OK";
  printf("ptr1: %s\n", ptr1);
  //ptr1[5]='C';	// questionable due to the prior assignment

  // *ptr2 = "not OK";	// type mismatch ERROR 
  ptr2="OK"; 
  printf("ptr2: %s\n", ptr2);

  return 0;
}



/* 1*READ EXPLANATION BELOW!!


For optimization purposes, C compiler might put string literal into code (non-writable) section of your application. This does help modern OS virtual memory: for non-writable memory page, in case of memory pressure OS can just discard the page from memory to reload it later.

If you write constant string literal compiler would not expect you to attempt to modify it later.

Consider this code:

#include <stdio.h>
int main()
{
	const char str[] = "ABCD";
    char *ptr = (char *)str;
    ptr[1] = 'b';   // bus error here if literal
    printf("%s\n", ptr);
    return 0;
}
Compiler do see “const char str[]” and put the “ABCD” string into code section. Please note this is a tricky situation, compiler just honored your request (const declaration) but you tricked it later (typecasting const char[] to just char[] in next line). The joy of C (you can easily shoot yourself in the foot). It would access it relatively to the code (on intel architectures it would be IP/EIP/RIP register):

(__TEXT,__text) section
_main:
0000000100000f70	pushq	%rbp
0000000100000f71	movq	%rsp, %rbp
0000000100000f74	movb	$0x62, _main.str(%rip)
0000000100000f7b	leaq	_main.str(%rip), %rdi
0000000100000f82	callq	0x100000f8c ## symbol stub for: _puts
0000000100000f87	xorl	%eax, %eax
0000000100000f89	popq	%rbp
0000000100000f8a	retq
Obviously, attempting to write to code section (line 5) would result some critical error and program would be killed (signal Bus error: 10 on Mac, for example).

If you change “const char str[]” to just “char str[]” then you’d hint compiler you might intend to modify the data later, and compiler would put it into data section (or copies it onto the stack at launch) and access it relatively to the data section or stack section:

(__TEXT,__text) section
_main:
0000000100000f60	pushq	%rbp
0000000100000f61	movq	%rsp, %rbp
0000000100000f64	subq	$0x10, %rsp
0000000100000f68	movb	$0x0, -0x4(%rbp)
0000000100000f6c	movl	$0x44434241, -0x8(%rbp)
0000000100000f73	movb	$0x62, -0x7(%rbp)
0000000100000f77	leaq	-0x8(%rbp), %rdi
0000000100000f7b	callq	0x100000f88 ## symbol stub for: _puts
0000000100000f80	xorl	%eax, %eax
0000000100000f82	addq	$0x10, %rsp
0000000100000f86	popq	%rbp
0000000100000f87	retq
Here the application writes into the stack region (line 8) and run without crashing, printing “AbCD”.



================================================================================================================================================
================================================================================================================================================
Why does assigning a string literal to a char pointer prevent you from being able to modify individual characters of the string, in C?

It doesn’t. Modifying the characters of a C string literal (whether by assigning the string literal to a char pointer or not) is undefined by the C Standard, but most compilers will compile such code. If the string literal is stored in writable memory, the modification will succeed. If it isn’t, as is usually the case when running on memory-managed systems, then the attempt to modify the characters will result in an access violation.

In C++ programs, as opposed to C programs, string literals consist of const chars, so it’s a compile-time error to modify one directly. However, you can assign it to a char pointer and modify it that way, so the claim in your question is actually backwards:

"string literal"[4] = 'x'; // compiles in C but not C++
 
// compiles in both C and C++, get access violation on memory-managed systems but will succeed on many embedded systems
char* foo = (char*)”string literal”;
foo[4] = ‘x’;
================================================================================================================================================
================================================================================================================================================

*/

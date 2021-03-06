/* halt.c
 *	Simple program to test whether running a user program works.
 *	
 *	Just do a "syscall" that shuts down the OS.
 *
 * 	NOTE: for some reason, user programs with global data structures 
 *	sometimes haven't worked in the Nachos environment.  So be careful
 *	out there!  One option is to allocate data structures as 
 * 	automatics within a procedure, but if you do this, you have to
 *	be careful to allocate a big enough stack to hold the automatics!
 */

#include "syscall.h"

int space[1024];

void test()
{
	Print("Enter test", sizeof("Enter test"));
	Yield();

	Print("Back to test", sizeof("Back to test"));
	Yield();
}

int
main()
{
	Print("Enter main", sizeof("Enter main"));
	Fork(test);

	Print("Back to main", sizeof("Back to main"));
	Yield();

	Print("Exec sort", sizeof("Exec sort"));
	Exec("../test/sort");

	Print("Final in main and Halt\n", sizeof("Final in main and Halt\n"));
    Halt();
    /* not reached */
}


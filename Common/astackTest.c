#include <stdio.h>
#include <time.h>
#include "astack.h"

#define TEST_LENGTH 500000000

void testStandard()
{
	struct astack stacky;
	time_t start, end;
	int i;
	start = time(NULL);
	initAStack(stacky, long);

	while (i < TEST_LENGTH) {
		AStack_Push(stacky, i, long);
		++i;
	}

	while (!AStack_Empty(stacky)) {
		AStack_Top(stacky, -5, long);
		AStack_Pop(stacky);
	}

	AStack_Free(stacky);

	printf("Standard Test took: %ld\n", time(NULL) - start);

}

void testPreAlloc()
{
	struct astack stacky;
	time_t start, end;
	int i;
	start = time(NULL);
	initAStack(stacky, long);
	AStack_Resize(stacky, long, TEST_LENGTH);
	while (i < TEST_LENGTH) {
		AStack_Push(stacky, i, long);
		++i;
	}

	while (!AStack_Empty(stacky)) {
		AStack_Top(stacky, -5, long);
		AStack_Pop(stacky);
	}

	AStack_Free(stacky);

	printf("PreAlloc Test took: %ld\n", time(NULL) - start);

}


int main()
{
	testStandard();
	testPreAlloc();

}
#include "arena.h"
#include <iostream>

int main() {
	Arena arena = new_arena(1 << 30);
	double* arr = ALLOC(&arena, double, 9);
	for (int i = 0; i < 9; ++i)
		arr[i] = 1.0;
	double* arr_2 = ALLOC(&arena, double, 40);
	for (int i = 0; i < 40; ++i)
		arr_2[i] = (double)i;

	// Add test of grabbing view with Fastor.
	return 0;
}
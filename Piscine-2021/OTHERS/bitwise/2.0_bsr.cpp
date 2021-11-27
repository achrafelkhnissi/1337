#include <cassert>
#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <random>
#include <cstdlib> // for rand()
#include <time.h> // for clock()
#include <chrono>
#include <climits> // for DBL_MAX
#include <x86intrin.h> // for intrinsics (function that use powerful underlying assembly instruction)
#pragma intrinsic(bit_scan_reverse)
// g++ -std=c++17 -masm=intel highestSetBit.cpp  && ./a.out
#include <immintrin.h>


//#define F(x) &uint8_t ()(uint32_t) ("highestSetBitIndex".append('x'))

#include <fcntl.h>
#include <stdio.h>
#include <elf.h>
#include <libelf.h>
#include <stdlib.h>
//#include <string.h>


using namespace std;
using namespace std::chrono;

/******************************************************************************/
/* Helpers                                                                    */
/******************************************************************************/

//uint32_t highestSetBitOnly( uint32_t n ) __attribute__((optimize("-O3")));

uint8_t onPurposeSlowFunction(uint32_t n)
{
	return sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) *sqrt(n * n) *sqrt(n * n) *sqrt(n * n) * sqrt(n * n) \
		* sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) *sqrt(n * n) *sqrt(n * n) *sqrt(n * n) * sqrt(n * n)
		* sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) * sqrt(n * n) *sqrt(n * n) *sqrt(n * n) *sqrt(n * n) * sqrt(n * n);
}

void int_to_bin(int num) {
  char str[9] = {0};
  int i;
  for (i=7; i>=0; i--) {
    str[i] = (num&1)?'1':'0';
    num >>= 1;
  }
  printf("%s\n", str);
}

uint8_t exampleFunctionForInlineAssembly(uint32_t n) // undefined behavior if n == 0
{
	uint8_t a = 0;
	__asm__ __volatile__ (R"(
		.intel_syntax noprefix
	        bsr eax, edi
		.att_syntax noprefix
	)"
			//	"mov %%edx, %1\n\t"
			"mov %0, %%al\n\t"
			:[a]"=r" (a)
			//		:[n]"r" (n)
			);
	return a;

}


uint8_t highestSetBitIndex100(uint32_t n) // undefined behavior if n == 0
{
	uint8_t a = 0;
	__asm__ __volatile__ (R"(
		.intel_syntax noprefix
	        bsr eax, edi
		.att_syntax noprefix
	)"
			//	"mov %%edx, %1\n\t"
			"mov %0, %%al\n\t"
			:[a]"=r" (a)
			//		:[n]"r" (n)
			);
	return a;

}


/******************************************************************************/
/* Functions Test                                ******************************/
/******************************************************************************/

uint32_t lowestSetBitOnly(uint32_t n)
{
	return n &= -n ;
}

void propagateBits(uint32_t *n) {
	*n |= *n >> 1;
    *n |= *n >> 2;
    *n |= *n >> 4;
    *n |= *n >> 8;
    *n |= *n >> 16;
}

uint32_t highestSetBitOnly(uint32_t n)
{
	propagateBits(&n);
	return n - (n >> 1);
}

uint32_t vsNextPowerOfTwo(uint32_t value)
{
	uint32_t n = highestSetBitOnly(value);
	return  n << (!!(value ^ n)); // it's over 9000!
}

uint8_t highestSetBitIndex1(uint32_t n)
{
	uint8_t r = 0;
	while (n >>= 1)
		r++;
	return r;
}

uint8_t highestSetBitIndex2(uint32_t n) {
	return (uint8_t)(log(n) / log(2));
}

uint8_t highestSetBitIndex3(uint32_t b)
{
	static const uint32_t deBruijnMagic = 0x06EB14F9;
	static const uint8_t deBruijnTable[64] = {
		0,  0,  0,  1,  0, 16,  2,  0, 29,  0, 17,  0,  0,  3,  0, 22,
		30,  0,  0, 20, 18,  0, 11,  0, 13,  0,  0,  4,  0,  7,  0, 23,
		31,  0, 15,  0, 28,  0,  0, 21,  0, 19,  0, 10, 12,  0,  6,  0,
		0, 14, 27,  0,  0,  9,  0,  5,  0, 26,  8,  0, 25,  0, 24,  0,
	};
	return deBruijnTable[(highestSetBitOnly(b) * deBruijnMagic) >> 26];
}

uint8_t highestSetBitIndex4(uint32_t n) // undefined behavior if n == 0
{
	__asm__ __volatile__ (R"(
		.intel_syntax noprefix
	        bsr eax, edi
		.att_syntax noprefix
		)"
			);
}

uint8_t highestSetBitIndex5(uint32_t n)
{
	return _bit_scan_reverse(n); // undefined behavior if n == 0
}


uint8_t highestSetBitIndex6(uint32_t n)
{
	return 31 - __builtin_clz(n); // undefined behavior if n == 0
}


uint8_t highestSetBitIndex7(uint32_t n) // undefined behavior if n == 0
{
	__asm__ __volatile__ (R"(.intel_syntax noprefix
		lzcnt ecx, edi
		mov eax, 31
		sub eax, ecx
		.att_syntax noprefix
	)");
}

uint8_t highestSetBitIndex8(uint32_t b)
{
  static const uint32_t Magic = (uint32_t) 0x07C4ACDD;

  static const int BitTable[32] = {
     0,  9,  1, 10, 13, 21,  2, 29,
    11, 14, 16, 18, 22, 25,  3, 30,
     8, 12, 20, 28, 15, 17, 24,  7,
    19, 27, 23,  6, 26,  5,  4, 31,
  };
  propagateBits(&b);

  return BitTable[(b * Magic) >> 27];
}

/*
** credit: https://sites.google.com/site/sydfhd/articles-tutorials/de-bruijn-sequence-generator
*/

uint8_t highestSetBitIndex9(uint32_t b)
{
	static const uint8_t u = 0;
  static const uint8_t BitTable[64] = {
     2,  u,  u,  u,  9,  u, 29,  5,
     u,  u,  3,  u,  u,  u, 21,  u,
     u, 18, 10,  u, 23, 13, 30,  u,
     6,  u, 27,  1,  u,  u,  u,  4,
     u,  u, 20,  u, 17, 22, 12,  u,
    26,  u,  u,  u, 19, 16, 11, 25,
     u,  u, 15, 24, 14,  u, 31,  u,
     u,  u,  7,  u,  u,  8, 28,  u,
  };

  propagateBits(&b);
  b += (b << 3);     // Multiply by 9
  b += (b << 4);     // Multiply by 17
 /* b  = (b << 5) - b; // Multiply by 31
  b  = (b << 17) - b;// Multiply by 131071*/
  b  -= (b << 5); // Multiply by 31
  b  -= (b << 17);// Multiply by 131071
  return BitTable[b >> 26];
}

/******************************************************************************/
/* Benchmark Main                                                             */
/******************************************************************************/
#define N			10000
#define BATTLE_NB	10000



double benchmark(uint8_t (*f)(uint32_t)) {
	auto start = high_resolution_clock::now();
	uint8_t a = 0;

	for (int i{}; i != N; ++i)
		a |= f(rand());

	auto stop = high_resolution_clock::now();
	double elapsedTime = duration_cast<nanoseconds>(stop - start).count();
	// std::cerr << "Duration: " << duration << " ms\n";
	return elapsedTime;
}

double overHead(uint8_t (*f)(uint32_t)) {
	auto start = high_resolution_clock::now();
	uint8_t a = 0;

	for (int i{}; i != N; ++i)
		a |= rand();

	auto stop = high_resolution_clock::now();
	double elapsedTime = duration_cast<nanoseconds>(stop - start).count();
	// std::cerr << "Duration: " << duration << " ms\n";
	return elapsedTime;
}

int main(void) {
	srand (time (NULL));
	uint64_t simulationsCount = 0;
	uint8_t (*func_ptr[])(uint32_t) = {&onPurposeSlowFunction, \
		&highestSetBitIndex1, &highestSetBitIndex2, &highestSetBitIndex3, \
		&highestSetBitIndex4, &highestSetBitIndex5, &highestSetBitIndex6, \
		&highestSetBitIndex7, &highestSetBitIndex8, &highestSetBitIndex9};
	int len = sizeof(func_ptr) / sizeof(void*);

#ifdef __DEBUG__
	for (uint32_t a = UINT_MAX; a > UINT_MAX - 100; a--) {
		//cout << endl << "Testing with: " << a << endl;
		uint32_t res = (uint32_t)func_ptr[1](a);
		for (int i = 2; i < len; i++) {

			uint32_t cur =(uint32_t)func_ptr[i](a);
			if (res != cur)
				printf("error with function %u returning %u instead of %u\n", i, cur, res);
			//cout << (uint32_t)(func_ptr[i](a)) << endl;
		//cout << (uint32_t)(highestSetBitIndex1(a)) << endl;
		}
	}
	return 0;
#endif

	int battle = BATTLE_NB;
	simulationsCount = (N * battle) / 1000000.0f; // million of simulations
	double elapsedTime[len] = {};
	int score[len] = {};

	while (battle--) {
		int currentScore = 0;
		int lowestLatencyIndex = 0;
		double lowestLatency = numeric_limits<double>::max();
		double currentElapsedTime = 0;
		for (int i = 1; i < len; i++) {
			currentElapsedTime = benchmark(func_ptr[i]);
			currentElapsedTime -= overHead(func_ptr[i]);
			if (currentElapsedTime < lowestLatency) {
				lowestLatency = currentElapsedTime;
				lowestLatencyIndex = i;
			}
			elapsedTime[i] += currentElapsedTime;
		}
		//printf("winner %d \n", lowestLatencyIndex);
		score[lowestLatencyIndex]++;
	}
	int winner = 0;
	int bestScore = 0;
	for (int i = 0; i < len; i++) {
		elapsedTime[i] /= N * 1000;
		if (score[i] > bestScore)
		{
			bestScore = score[i];
			winner = i;
		}
	}
	char color[13]; // https://misc.flogisoft.com/bash/tip_colors_and_formatting
	strncpy(color, "\e[1m\e[96m", 13); //bold and cyan
	printf("\n%s%lu million simulations result:\n\e[0m", color, simulationsCount);
	for (int i = 1; i < len; ++i) {
		color[0] = '\0';
		if (i == winner) // \033[5m
			strncpy(color, "\e[1m\e[5m\e[92m", 13); // bold, blink and green
		printf("\tFunction %2d scored %6d with an average time of %s%03.1lf\e[0m ms\n", i, score[i], color, elapsedTime[i]);
	}
	putchar('\n');

	return 0;
}

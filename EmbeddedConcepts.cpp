// EmbeddedConcepts.cpp : Defines the entry point for the application.
//

#include "EmbeddedConcepts.h"

using namespace std;

uint16_t multiplicationWitoutStar(uint8_t a, uint8_t b) {
	uint16_t result = 0;
	for (int i = 0; i < b; i++) {
		result += a;
	}
	return result;
}
uint16_t bitwiseMultiplication(uint8_t a, uint8_t b) {
	uint16_t result = 0;
	uint16_t bigA = a;
	while ((b & 0xFF) != 0) {
		if ((b & 0x01) == 1)
			result = result + bigA;
		b = b >> 0x01;
		bigA = bigA << 0x01;
	}

	return result;
}

int main()
{
	std::cout << bitwiseMultiplication(15, 16) << std::endl;
	return 0;
}

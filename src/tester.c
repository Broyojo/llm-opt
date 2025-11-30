#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "impl.c"
#include "yours.c"

int I = 100000;
int J = 200;

spint ref;
spint yours;

void test_yours()
{
	spint x[9], y[9], z[9];
	int i, j;
	x[0] = 0x3b1799d;
	x[1] = 0x4018bfd;
	x[2] = 0x19c6b447;
	x[3] = 0xc81f60c;
	x[4] = 0x5257bdd;
	x[5] = 0x1dc82334;
	x[6] = 0x1b78fac4;
	x[7] = 0x1e87248a;
	x[8] = 0x11dc60;
	y[0] = 0x1c8960a9;
	y[1] = 0x11e8fd3d;
	y[2] = 0xf0b5b46;
	y[3] = 0x18cd675a;
	y[4] = 0x1e150bd9;
	y[5] = 0x121a7232;
	y[6] = 0x1e0a2e74;
	y[7] = 0x682c833;
	y[8] = 0x4b9542;
	for (i = 0; i < I; i++)
		for (j = 0; j < J; j++) {
			modmul(x, y, z);
			modmul(z, x, y);
			modmul(y, z, x);
			modmul(x, y, z);
			modmul(z, x, y);
		}
	printf("yours check 0x%06x\n", (int)z[0] & 0xFFFFFF);
	yours = (int)z[0] & 0xFFFFFF;
}

void test_modmul()
{
	spint x[9], y[9], z[9];
	int i, j;
	x[0] = 0x3b1799d;
	x[1] = 0x4018bfd;
	x[2] = 0x19c6b447;
	x[3] = 0xc81f60c;
	x[4] = 0x5257bdd;
	x[5] = 0x1dc82334;
	x[6] = 0x1b78fac4;
	x[7] = 0x1e87248a;
	x[8] = 0x11dc60;
	y[0] = 0x1c8960a9;
	y[1] = 0x11e8fd3d;
	y[2] = 0xf0b5b46;
	y[3] = 0x18cd675a;
	y[4] = 0x1e150bd9;
	y[5] = 0x121a7232;
	y[6] = 0x1e0a2e74;
	y[7] = 0x682c833;
	y[8] = 0x4b9542;
	for (i = 0; i < I; i++)
		for (j = 0; j < J; j++) {
			modmul_ref(x, y, z);
			modmul_ref(z, x, y);
			modmul_ref(y, z, x);
			modmul_ref(x, y, z);
			modmul_ref(z, x, y);
		}
	printf("ref check 0x%06x\n", (int)z[0] & 0xFFFFFF);
	ref = (int)z[0] & 0xFFFFFF;
}

int main()
{
	srand(time(NULL));
	I = rand() % (100000 + 1);
	J = rand() % (200 + 1);
	printf("Testing:\n");
	test_modmul();
	test_yours();
	if (yours == ref) {
		printf("correct!\n");
		return 0;
	} else {
		printf("incorrect: I=%u, J=%u\n", I, J);
		return 1;
	}

}

#include <stdio.h>
#include <stdint.h>

#define sspint int32_t
#define spint uint32_t
#define udpint uint64_t
#define dpint uint64_t

#define Wordlength 32
#define Nlimbs 9
#define Radix 29
#define Nbits 255
#define Nbytes 32

#define MERSENNE
#define MULBYINT

// Modular multiplication, c=a*b mod 2p
__attribute__((hot, flatten))
void modmul(const spint * __restrict a, const spint * __restrict b, spint * __restrict c)
{
        extern void modmul_ref(const spint *, const spint *, spint *);
        modmul_ref(a, b, c);
}

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
__attribute__((always_inline))
void modmul(const spint * __restrict a, const spint * __restrict b, spint * __restrict c)
{
        const spint a0 = a[0];
        const spint a1 = a[1];
        const spint a2 = a[2];
        const spint a3 = a[3];
        const spint a4 = a[4];
        const spint a5 = a[5];
        const spint a6 = a[6];
        const spint a7 = a[7];
        const spint a8 = a[8];
        const spint b0 = b[0];
        const spint b1 = b[1];
        const spint b2 = b[2];
        const spint b3 = b[3];
        const spint b4 = b[4];
        const spint b5 = b[5];
        const spint b6 = b[6];
        const spint b7 = b[7];
        const spint b8 = b[8];
        dpint t = 0;
        dpint tt;
        spint lo;
        dpint hi;
        spint carry;
        spint s;
        const spint mask = (spint)0x1fffffff;
        const dpint wrap = (dpint)0x4c0;
        tt = (dpint) a1 * (dpint) b8;
        tt += (dpint) a2 * (dpint) b7;
        tt += (dpint) a3 * (dpint) b6;
        tt += (dpint) a4 * (dpint) b5;
        tt += (dpint) a5 * (dpint) b4;
        tt += (dpint) a6 * (dpint) b3;
        tt += (dpint) a7 * (dpint) b2;
        tt += (dpint) a8 * (dpint) b1;
        lo = (spint) tt & mask;
        t += (dpint) lo * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b0;
        spint v0 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a2 * (dpint) b8;
        tt += (dpint) a3 * (dpint) b7;
        tt += (dpint) a4 * (dpint) b6;
        tt += (dpint) a5 * (dpint) b5;
        tt += (dpint) a6 * (dpint) b4;
        tt += (dpint) a7 * (dpint) b3;
        tt += (dpint) a8 * (dpint) b2;
        lo = (spint) tt & mask;
        spint sum = (spint) (lo + hi);
        t += (dpint) sum * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b1;
        t += (dpint) a1 * (dpint) b0;
        spint v1 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a3 * (dpint) b8;
        tt += (dpint) a4 * (dpint) b7;
        tt += (dpint) a5 * (dpint) b6;
        tt += (dpint) a6 * (dpint) b5;
        tt += (dpint) a7 * (dpint) b4;
        tt += (dpint) a8 * (dpint) b3;
        lo = (spint) tt & mask;
        sum = (spint) (lo + hi);
        t += (dpint) sum * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b2;
        t += (dpint) a1 * (dpint) b1;
        t += (dpint) a2 * (dpint) b0;
        spint v2 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a4 * (dpint) b8;
        tt += (dpint) a5 * (dpint) b7;
        tt += (dpint) a6 * (dpint) b6;
        tt += (dpint) a7 * (dpint) b5;
        tt += (dpint) a8 * (dpint) b4;
        lo = (spint) tt & mask;
        sum = (spint) (lo + hi);
        t += (dpint) sum * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b3;
        t += (dpint) a1 * (dpint) b2;
        t += (dpint) a2 * (dpint) b1;
        t += (dpint) a3 * (dpint) b0;
        spint v3 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a5 * (dpint) b8;
        tt += (dpint) a6 * (dpint) b7;
        tt += (dpint) a7 * (dpint) b6;
        tt += (dpint) a8 * (dpint) b5;
        lo = (spint) tt & mask;
        sum = (spint) (lo + hi);
        t += (dpint) sum * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b4;
        t += (dpint) a1 * (dpint) b3;
        t += (dpint) a2 * (dpint) b2;
        t += (dpint) a3 * (dpint) b1;
        t += (dpint) a4 * (dpint) b0;
        spint v4 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a6 * (dpint) b8;
        tt += (dpint) a7 * (dpint) b7;
        tt += (dpint) a8 * (dpint) b6;
        lo = (spint) tt & mask;
        sum = (spint) (lo + hi);
        t += (dpint) sum * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b5;
        t += (dpint) a1 * (dpint) b4;
        t += (dpint) a2 * (dpint) b3;
        t += (dpint) a3 * (dpint) b2;
        t += (dpint) a4 * (dpint) b1;
        t += (dpint) a5 * (dpint) b0;
        spint v5 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a7 * (dpint) b8;
        tt += (dpint) a8 * (dpint) b7;
        lo = (spint) tt & mask;
        sum = (spint) (lo + hi);
        t += (dpint) sum * wrap;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b6;
        t += (dpint) a1 * (dpint) b5;
        t += (dpint) a2 * (dpint) b4;
        t += (dpint) a3 * (dpint) b3;
        t += (dpint) a4 * (dpint) b2;
        t += (dpint) a5 * (dpint) b1;
        t += (dpint) a6 * (dpint) b0;
        spint v6 = (spint) t & mask;
        t = t >> 29u;
        tt = (dpint) a8 * (dpint) b8;
        lo = (spint) tt & mask;
        t += (dpint) (spint) (lo + hi) * (dpint) 0x4c0;
        hi = (spint) (tt >> 29u);
        t += (dpint) a0 * (dpint) b7;
        t += (dpint) a1 * (dpint) b6;
        t += (dpint) a2 * (dpint) b5;
        t += (dpint) a3 * (dpint) b4;
        t += (dpint) a4 * (dpint) b3;
        t += (dpint) a5 * (dpint) b2;
        t += (dpint) a6 * (dpint) b1;
        t += (dpint) a7 * (dpint) b0;
        spint v7 = (spint) t & mask;
        t = t >> 29u;
        t += (dpint) a0 * (dpint) b8;
        t += (dpint) a1 * (dpint) b7;
        t += (dpint) a2 * (dpint) b6;
        t += (dpint) a3 * (dpint) b5;
        t += (dpint) a4 * (dpint) b4;
        t += (dpint) a5 * (dpint) b3;
        t += (dpint) a6 * (dpint) b2;
        t += (dpint) a7 * (dpint) b1;
        t += (dpint) a8 * (dpint) b0;
        t += (dpint) hi *(dpint) 0x4c0;
        spint v8 = (spint) t & mask;
        t = t >> 29u;
	// second reduction pass

	udpint ut = (udpint) t;
	ut = (ut << 6) + (spint) (v8 >> 23u);
	v8 &= 0x7fffff;
	ut *= 0x13;
	s = v0 + ((spint) ut & mask);
	c[0] = (spint) (s & mask);
	carry = (s >> 29) + (spint) (ut >> 29);
	c[1] = v1 + carry;
	c[2] = v2;
	c[3] = v3;
	c[4] = v4;
	c[5] = v5;
	c[6] = v6;
	c[7] = v7;
	c[8] = v8;
}

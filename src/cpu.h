#include <stdint.h>
typedef struct {
    uint64_t A;  // register A
    uint64_t B;  // register B
    uint64_t C;  // register C
    uint64_t D;  // register D
    uint64_t E;  // register E
    uint64_t F;  // register F
    uint64_t G;  // register G
    uint64_t H;  // register H
    uint64_t I;  // register I
    uint64_t J;  // register J
    uint64_t K;  // register K
    uint64_t L;  // register L
    uint64_t M;  // register M
    uint64_t N;  // register N
    uint64_t O;  // register O
    uint64_t P;  // register P
    uint64_t Q;  // register Q
    uint64_t R;  // register R
    uint64_t S;  // register S
    uint64_t T;  // register T
    uint64_t U;  // register U
    uint64_t V;  // register V
    uint64_t W;  // register W
    uint64_t X;  // register X
    uint64_t Y;  // register Y
    uint64_t Z;  // register Z
    uint64_t PC; // Program Counter
} __attribute__ ((packed)) cpu_t;
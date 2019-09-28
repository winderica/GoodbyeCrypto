#pragma once
#include "millerRabin.cpp"

auto generatePrime(unsigned long seed) {
    gmp_randclass randClass(gmp_randinit_default);
    randClass.seed(seed);
    mpz_class res = randClass.get_z_bits(1024);
    if (res % 2 == 0) {
        res += 1;
    }
    while (millerRabin(res, 40) == 0) {
        res += 2;
    }
    return res;
}
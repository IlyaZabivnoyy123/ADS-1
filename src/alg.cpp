// Copyright 2022 NNTU-CS
#include <cstdint>
#include <cmath>  // Добавьте этот заголовок для функции sqrt
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    if (value == 2) {
        return true;
    }
    if (value % 2 == 0) {
        return false;
    }
    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    uint64_t count = 0;
    uint64_t number = 1;
    while (count < n) {
        number++;
        if (checkPrime(number)) {
            count++;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1;
    while (true) {
        if (checkPrime(num)) {
            return num;
        }
        num++;
    }
    return 0; // Теоретически сюда никогда не дойдем, но для компилятора оставим
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; num++) {
        if (checkPrime(num)) {
            sum += num;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    for (uint64_t num = lbound; num + 2 < hbound; num++) {
        if (checkPrime(num) && checkPrime(num + 2)) {
            count++;
        }
    }
    return count;
}

/*
 *
 *  Created on: Sep 30, 2019
 *      Author: rimon
 */
#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    long int prev_1 = 1, prev_2 = 0 ,result = 0;
    if (n == 1){
        result = 1;
    }
    for (int i=1 ; i < n; i++){
        result = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = result;
    }

    return result;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

   /* std::cout << fibonacci_naive(n) << '\n';*/
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
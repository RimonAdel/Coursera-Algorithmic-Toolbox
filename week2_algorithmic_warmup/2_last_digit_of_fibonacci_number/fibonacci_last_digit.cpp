/*
 *
 *  Created on: Sep 30, 2019
 *      Author: rimon
 */
#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}


int get_fibonacci_last_digit(int n) {
    long int prev_1 = 1, prev_2 = 0 ,result = 0;
    if (n == 1){
        result = 1;
    }
    for (int i=1 ; i < n; i++){
        result = prev_1 + prev_2;
        prev_2 = prev_1 % 10;
        prev_1 = result % 10;
    }

    return result%10;
}

void test_solution() {
    for (int n = 0; n < 20; ++n)
        assert(get_fibonacci_last_digit_naive(n) == get_fibonacci_last_digit(n));
}

int main() {
    int n = 0;
    std::cin >> n;

   /* std::cout << fibonacci_naive(n) << '\n';*/
    /*test_solution();*/
    std::cout << get_fibonacci_last_digit(n) << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
using std::vector;

long long fibonacci_sum_fast(long long n, int m) {
    vector<int> g1;
    g1.push_back(0);
    g1.push_back(1); 
    g1.push_back(1);
    if (n <= 0){
        return 0;
    }
    n += 2;
    if (n <= 1)
    {
        return n;
    }
    long int prev_1 = 1, prev_2 = 0 ,result = 0;
    int length = 3 , j =2;
    while(true){
        j++;
        prev_1 = 1, prev_2 = 0 ,result = 0;
        for (int i = 0 ; i < j-1; i++){
            result = prev_1 + prev_2;
            prev_2 = prev_1 % m;
            prev_1 = result % m;
        }
        if((result%m) == 1 && g1[length-1] == 1 && g1[length-2]==0){
            break;
        }
       
        g1.push_back((result%m));
        length++;
    }

    if (g1[n%(length-2)] == 0){
        return g1[n%(length-2)-1];
    }
    return g1[n%(length-2)]-1;
}

long long get_fibonacci_partial_sum_fast(long long to, long long from){
    int from_result = fibonacci_sum_fast(from-1,100);
    int to_result = fibonacci_sum_fast(to,100);
    if (to_result < from_result){
        to_result += 100;
    }
    // std::cout << "to_result = "<<  to_result << " from_result = " << from_result << " ";

    return abs(to_result-from_result)%10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(to, from);
}

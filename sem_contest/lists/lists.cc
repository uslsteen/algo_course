#include <list>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>

int main(int argc, char** argv) {

    const int num = argc > 1 ? atoi(argv[1]) : 10000000;
    std::vector<int> m_vec(num);

    for (size_t i = 0; i < num; ++i)
        m_vec[i] = rand();

    //! there is more comfortable for 
    std::list<int> m_list{m_vec.begin(), m_vec.end()};

    long long ls = 0;
    clock_t lstart = clock();

    for (auto q : m_list)
        ls += q;

    clock_t lend = clock();
    
    clock_t vstart = clock();

    for (auto q : m_vec)
        ls += q;

    clock_t vend = clock();

    std::cout << "list time:" << (lend - lstart) / CLOCKS_PER_SEC << std::endl
              << "vec time:" << (vend - vstart) / CLOCKS_PER_SEC << std::endl;
                 
} 
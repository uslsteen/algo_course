#include <iostream>
#include <vector>
#include <cstdint>

std::vector<uint64_t> fact_vec{};

void fact_init(size_t perm_size) {
    fact_vec.push_back(1);

    for (size_t i = 1; i < perm_size; ++i)
        fact_vec.push_back(fact_vec[i - 1] * i);
}

/**
 * @brief Get the avlbl num
 * 
 * @param avlbl_ind - current index of permutation
 * @param used_num  - vector which says is used number num at index i
 */
size_t get_avlbl_num(size_t avlbl_ind ,std::vector<bool>& used_num) {

    size_t num_ind = 0, ind = 0;
    for (; ind < used_num.size(); ++ind) {

        if (!used_num[ind])
            ++num_ind;
        if (avlbl_ind == num_ind)
            break;
    }
    return ind;
}

void get_perm(size_t perm_size, size_t perm_num) {

    std::vector<bool> used_num(perm_size, false);

    for (size_t i = 0; i < perm_size; ++i) {
        
        size_t avlbl_ind = ((perm_num - 1) / fact_vec[perm_size - i - 1]) + 1;
        size_t avlbl_num = get_avlbl_num(avlbl_ind, used_num);

        used_num[avlbl_num] = true;

        std::cout << avlbl_num + 1 << " ";
        perm_num = (perm_num - 1) % fact_vec[perm_size - i - 1] + 1;
    }   

}

int main() {

    size_t perm_size = 0, perm_num = 0;
    std::cin >> perm_size >> perm_num;

    if (!std::cin.good())
        return -1;

    fact_init(perm_size);
    get_perm(perm_size, perm_num);

    return 0;
}


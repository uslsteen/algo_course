#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using m_pair = std::pair<int, char>;

auto comp_let = [](const void *lhs, const void *rhs) -> int {
    const char lhs_let = *static_cast<const char *>(lhs);
    const char rhs_let = *static_cast<const char *>(rhs);

    return std::toupper(lhs_let) - std::toupper(rhs_let);
};

auto comp_pair = [](const void *lhs, const void *rhs) -> int {
    const m_pair lhs_p = *static_cast<const m_pair *>(lhs);
    const m_pair rhs_p = *static_cast<const m_pair *>(rhs);

    char res_let = std::toupper(rhs_p.second) - std::toupper(lhs_p.second);
    int res_freq = lhs_p.first - rhs_p.first;

    if (res_freq != 0)
        return res_freq;
    else
        return res_let;
};

void print_vec(const std::vector<m_pair> &vec) {

    auto vec_end = vec.rend();
    for (auto vec_it = vec.rbegin(); vec_it != vec_end; ++vec_it)
        std::cout << (*vec_it).second << " " << (*vec_it).first << std::endl;
}

void count_lettrs(const std::string &str) {

    std::vector<m_pair> freq_vec{};
    std::string cpy{str};

    auto new_last = std::unique(cpy.begin(), cpy.end());
    cpy.erase(new_last, cpy.end());

    for (auto &&cpy_it : cpy) {
        auto fst = str.find_first_of(cpy_it);
        auto lst = str.find_last_of(cpy_it);

        freq_vec.push_back({lst - fst + 1, cpy_it});
    }
    m_pair *beg = &freq_vec[0];
    std::qsort(beg, freq_vec.size(), sizeof(decltype(freq_vec)::value_type), comp_pair);

    print_vec(freq_vec);
}

int main() {
    std::string input{};
    std::cin >> input;
    char *beg = &input[0];

    if (!std::cin.good())
        return -1;

    std::qsort(beg, input.size(), sizeof(decltype(input)::value_type), comp_let);
    std::string sorted{beg};

    count_lettrs(sorted);
    return 0;
}
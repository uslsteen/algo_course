#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>

using m_pair = std::pair<int, int>;

enum class belong_type
{
    WHOLE = 1,
    LEFT_INCL = 2,
    RIGHT_INCL = 3,
    NONE = 4
};

std::ostream &operator<<(std::ostream &os, m_pair pair) {
    os << "[" << pair.first << " ; " << pair.second << "]";
    return os;
}

auto comp_rng = [](m_pair lhs, m_pair rhs) -> int {
    int lhs_l = lhs.second - lhs.first,
        rhs_l = rhs.second - rhs.first;

    return lhs_l > rhs_l;
};

inline int get_num(const std::string &str) {
    return std::stoi(str.substr(0, 2)) * 60 + std::stoi(str.substr(3, 2));
}

void sort_data(std::vector<m_pair> &range_pair) {
    std::sort(range_pair.begin(), range_pair.end(), comp_rng);
}

m_pair transform(const std::string &str) {

    int rng_start = get_num(str.substr(0, 5));
    int rng_end = get_num(str.substr(6, 5));

    return m_pair{rng_start, rng_end};
}

int input_data(std::vector<m_pair> &range_pair) {

    std::string range{};

    size_t pass_num = 0;
    std::cin >> pass_num;

    if (!std::cin.good())
        return -1;

    std::getchar();

    for (size_t iter = 0; iter < pass_num; ++iter) {
        std::getline(std::cin, range);
        range_pair.push_back(transform(range));
    }
    return 0;
}

inline belong_type is_belong(const m_pair &res, const m_pair &range) {

    if ((range.first > res.first && range.second < res.second) ||
        (range.first < res.first && range.second > res.second))
        return belong_type::WHOLE;

    else if (range.first < res.first && (range.second > res.first &&
                                         range.second < res.second))
        return belong_type::RIGHT_INCL;

    else if (range.second > res.second && (range.first > res.first &&
                                           range.first < res.second))
        return belong_type::LEFT_INCL;

    else
        return belong_type::NONE;
}

int upd_res(m_pair &res, m_pair &range, belong_type type) {

    switch (type) {
    case belong_type::WHOLE: {
        res.first = range.first;
        res.second = range.second;
        break;
    }

    case belong_type::RIGHT_INCL:
        res.second = range.second;
        break;

    case belong_type::LEFT_INCL:
        res.first = range.first;
        break;

    default:
        std::cout << "Error: undefined interaction type\n";
        break;
    }

    if (res.first > res.second)
        throw std::runtime_error{"Error connected with range [beg; end] : beg > end\n"};

    return 1;
}

int find_intersect(std::vector<m_pair> &range_pair) {

    m_pair res = *range_pair.begin();
    // m_pair res = *range_pair.begin();
    int intersct_num = 1;

    for (auto &&range_it : range_pair) {

        belong_type type = is_belong(res, range_it);

        if (type != belong_type::NONE) {
            std::cout << range_it << "inter with" << res << std::endl;
            intersct_num += upd_res(res, range_it, type);
        } else
            continue;
    }
    return intersct_num;
}

auto main() -> int {
    std::vector<m_pair> range_pair{};

    input_data(range_pair);
    sort_data(range_pair);

    for (auto &&pair_it : range_pair)
        std::cout << pair_it << std::endl;

    try {
        int inter_num = find_intersect(range_pair);
        std::cout << inter_num;
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}
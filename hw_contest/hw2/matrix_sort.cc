#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

/*************                  *************/

namespace linalg {
class matrix;
}

namespace sort_algo {

void qsort_cols(linalg::matrix &matr, size_t low, size_t high);
size_t partition(linalg::matrix &matr, size_t low, size_t high);
} // namespace sort_algo

namespace linalg {

using p_inds = std::pair<size_t, size_t>;

class matrix final {

  public:
  private:
    int **m_data = nullptr;
    size_t m_nrows = 0;
    size_t m_ncols = 0;

  public:
    /**
       * @brief Construct a new matrix object
       *
       * @param nrows
       * @param ncols
       */
    matrix(const size_t nrows, const size_t ncols)
        : m_nrows(nrows), m_ncols(ncols) {

        allocate();
    }

    /**
       * @brief Construct a new matrix object
       *
       * @param nrows
       * @param ncols
       * @param data
       */
    matrix(const size_t nrows, const size_t ncols, const std::vector<int> &data)
        : m_nrows(nrows), m_ncols(ncols) {
        size_t nelems = nrows * ncols;

        allocate();

        for (size_t i = 0; i < nelems; ++i)
            m_data[i / ncols][i % ncols] = data[i];
    }

    matrix(const matrix &rhs) : m_nrows(rhs.m_nrows), m_ncols(rhs.m_ncols) {

        allocate();

        for (size_t i = 0; i < m_nrows; ++i)
            for (size_t j = 0; j < m_ncols; ++j)
                m_data[i][j] = rhs.m_data[i][j];
    }

    ~matrix() {
        for (size_t i = 0; i < m_nrows; ++i)
            delete[] m_data[i];

        delete[] m_data;
        m_data = nullptr;
    }

    size_t nrows() const { return m_nrows; }
    size_t ncols() const { return m_ncols; }

    int *operator[](const size_t pos) { return m_data[pos]; }

    void transpose() /* ref annotated method */
    {
        matrix tmp{*this};

        for (size_t i = 0; i < m_ncols; ++i)
            for (size_t j = 0; j < m_nrows; ++j)
                m_data[i][j] = tmp.m_data[j][i];
    }

    void swap_rows(const p_inds &inds) {

        size_t ind_i = inds.first, ind_j = inds.second;

        assert(ind_i >= 0 && ind_j >= 0);
        assert(ind_i < m_nrows && ind_j < m_nrows);

        std::swap(m_data[ind_i], m_data[ind_j]);
    }

    void swap_cols(const p_inds &inds) {

        size_t ind_i = inds.first, ind_j = inds.second;

        assert(ind_i >= 0 && ind_j >= 0);
        assert(ind_i < m_nrows && ind_j < m_nrows);

        transpose();
        std::swap(m_data[ind_i], m_data[ind_j]);
        transpose();
    }

    void sort() {
        p_inds min_pos = get_min_el();

        swap_rows(p_inds{min_pos.first, 0});
        swap_cols(p_inds{min_pos.second, 0});

        sort_algo::qsort_cols(*this, 1, ncols() - 1);
    }

  private:
    p_inds get_min_el() const {

        p_inds min_inds{0, 0};
        int min_elem = m_data[0][0];

        for (size_t i = 0; i < m_nrows; ++i) {
            for (size_t j = 0; j < m_ncols; ++j) {

                if (m_data[i][j] < min_elem) {
                    min_inds = {i, j};
                    min_elem = m_data[i][j];
                }
            }
        }
        return min_inds;
    }

    void allocate() {

        m_data = new int *[m_nrows];

        for (size_t i = 0; i < m_nrows; ++i)
            m_data[i] = new int[m_ncols];
    }
};

std::ostream &operator<<(std::ostream &os, matrix &matr) {

    for (size_t i = 0; i < matr.nrows(); ++i) {
        for (size_t j = 0; j < matr.ncols(); ++j)
            os << matr[i][j] << " ";

        os << std::endl;
    }

    return os;
}
} // namespace linalg

auto main() -> int {

    size_t rows = 0, cols = 0;
    std::cin >> rows >> cols;

    if (!std::cin.good())
        return -1;

    std::vector<int> m_vec{};
    int elem = 0;

    for (size_t i = 0; i < rows * cols; ++i) {
        std::cin >> elem;
        m_vec.push_back(elem);
    }

    linalg::matrix matr{rows, cols, m_vec};

    matr.sort();
    std::cout << matr;
}

namespace sort_algo {

auto comp = [](int lhs, int rhs) -> int {
    return lhs - rhs;
};

size_t partition(linalg::matrix &matr, size_t low, size_t high) {

    size_t pivot = high;
    size_t prev_beg = low - 1;

    for (size_t beg = low; beg <= high - 1; ++beg) {
        if (comp(matr[0][beg], matr[0][pivot]) < 0) {
            ++prev_beg;
            matr.swap_cols(linalg::p_inds{prev_beg, beg});
        }
    }

    matr.swap_cols(linalg::p_inds{prev_beg + 1, high});
    return (prev_beg + 1);
}

void qsort_cols(linalg::matrix &matr, size_t low, size_t high) {

    if (low >= high)
        return;

    size_t pos = partition(matr, low, high);

    if (pos > low)
        qsort_cols(matr, low, pos - 1);

    qsort_cols(matr, pos + 1, high);
}

} // namespace sort_algo
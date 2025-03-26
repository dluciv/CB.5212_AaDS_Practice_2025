#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <typeinfo>
#include <optional>
#include <string_view>
#include <limits>

#include <Eigen/Dense>
#include <lazycsv.hpp>

// https://en.cppreference.com/w/cpp/utility/from_chars
// C++23's constexpr from_char demo / C++26's operator bool() demo:
auto to_double = [](std::string_view s) -> std::optional<double>
{
    double value{};
#if __cpp_lib_to_chars >= 202306L
    if (std::from_chars(s.data(), s.data() + s.size(), value))
#else
    if (std::from_chars(s.data(), s.data() + s.size(), value).ec == std::errc{})
#endif
        return value;
    else
        return std::nullopt;
};

int main() {
    std::vector<std::vector<double>> rcsv{};
    {
        lazycsv::parser parser{ "AB.csv" };
        for (const auto row : parser)
        {
            std::vector<double> r{};
            for (const auto cell : row)
            {
                r.push_back(to_double(cell.raw()).value_or(std::numeric_limits<double>::quiet_NaN()));
            }
            rcsv.push_back(r);
        }
    }

    // Создаем матрицы с использованием Eigen
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> A(rcsv.size(), rcsv.begin()->size());

    int ir = 0;
    for(auto r : rcsv)
    {
        int ic = 0;
        std::cout << "row:";
        for(double e: r) {
            A(ir, ic++) = e;
        }
        ir++;
        std::cout << std::endl;
    }

    Eigen::MatrixXd B(3, 2); // ColMajor по-умолчанию будет скорее
    // https://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html
    B << 7, 8,
         9, 10,
         11, 12;

    // Умножение матриц с использованием Eigen
    Eigen::MatrixXd C = A * B;

    std::cout << "Матрица A:\n" << A << "\n\n";
    std::cout << "Матрица B:\n" << B << "\n\n";
    std::cout << "Результат умножения (C = A * B):\n" << C << "\n";

    // Редактирование на месте
    double c = 2.0;
    A.row(0) += c * A.row(1);
    A.coeffRef(1, 1) -= B.coeff(1, 1);
    std::cout << "Новая матрица A:\n" << A << "\n\n";

    return 0;
}

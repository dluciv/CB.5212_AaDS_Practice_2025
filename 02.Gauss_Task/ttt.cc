#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <typeinfo>

#include <Eigen/Dense>
#include <glaze/csv.hpp>

struct gauss_matrix {
    std::vector<std::vector<double>> data{};
};

int main() {
    // https://stackoverflow.com/a/2602060/539470
    std::ifstream file("AB.csv");
    std::string abcsv(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );
    std::cout << abcsv << std::endl;

    // glaze
    // auto csv = glz::read_csv<glz::rowwise, std::vector<std::vector<double> > >(abcsv);
    // std::cout << typeid(csv).name() << csv << std::endl;
    gauss_matrix m;
    auto r = glz::read_csv<glz::rowwise>(m, abcsv);
    for(auto r: m.data) {
        for(auto e: r)
            std::cout << e << ' ';
        std::cout << std::endl;
    }
    std::cout << typeid(r).name() << std::endl;

    // Создаем матрицы с использованием Eigen
    Eigen::Matrix<double, -1, -1, Eigen::RowMajor> A(2, 3);
    A << 1, 2, 3,
         4, 5, 6;


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

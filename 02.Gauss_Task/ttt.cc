#include <iostream>
#include <Eigen/Dense>

int main() {
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
    А.coeffRef(1, 1) -= B.coeff(1, 1);
    std::cout << "Новая матрица A:\n" << A << "\n\n";

    return 0;
}

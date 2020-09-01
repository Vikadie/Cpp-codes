#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data)
{
    this->_data.resize(data.size());
    for (size_t row = 0; row < data.size(); row++) {
        _data[row].resize(data[row].size());
        for (size_t col = 0; col < data[row].size(); col++)
            _data[row][col] = data[row][col];
    }

    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    std::vector<std::vector<int> > matrix;
    size_t size2 = other._data.size();
    matrix.resize(size2);
    for (size_t r = 0; r < size2; r++) {
        matrix[r].resize(size2);
        matrix[r] = other._data[r];
    }
    int size1 = this->_data.size();
    matrix.resize(size1);
    for (size_t row = 0; row < size1; row++) {
        matrix[row].resize(size1);
        for (size_t col = 0; col < size1; col++)
            _data[row][col] += matrix[row][col];
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    std::vector<std::vector<int> > matrix;
    size_t size2 = other._data.size();
    matrix.resize(size2);
    for (size_t r = 0; r < size2; r++) {
        matrix[r].resize(size2);
        matrix[r] = other._data[r];
    }
    int size1 = this->_data.size();
    matrix.resize(size1);
    for (size_t row = 0; row < size1; row++) {
        matrix[row].resize(size1);
        for (size_t col = 0; col < size1; col++)
            _data[row][col] -= matrix[row][col];
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    std::vector<std::vector<int> > matrix;
    size_t size2 = other._data.size();
    matrix.resize(size2);
    for (size_t r = 0; r < size2; r++) {
        matrix[r].resize(size2);
        matrix[r] = other._data[r];
    }

    int matrix1Size = this->_data.size();

    for (size_t row = 0; row < this->_data.size(); row++) {
        if (row < matrix.size()) {
            matrix[row].resize(matrix1Size, 1);
            for (size_t col = 0; col < this->_data[row].size(); col++)
                _data[row][col] *= matrix[row][col];
        }
    }

    return *this;
}

Matrix& Matrix::operator/=(const Matrix& other)
{
    std::vector<std::vector<int> > matrix;
    size_t size2 = other._data.size();
    matrix.resize(size2);
    for (size_t r = 0; r < size2; r++) {
        matrix[r].resize(size2);
        matrix[r] = other._data[r];
    }

    int matrix1Size = this->_data.size();

    for (size_t row = 0; row < this->_data.size(); row++) {
        if (row < matrix.size()) {
            matrix[row].resize(matrix1Size, 1);
            for (size_t col = 0; col < this->_data[row].size(); col++)
                if (matrix[row][col] == 0)
                    _data[row][col] = 0;
                else
                    _data[row][col] /= matrix[row][col];
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (size_t r = 0; r < matrix._data.size(); r++) {
        for (size_t c = 0; c < matrix._data[r].size(); c++)
            os << matrix._data[r][c] << " ";
        os << std::endl;
    }
    return os;
}

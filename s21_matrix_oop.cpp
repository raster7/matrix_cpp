#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw MyException("Error!");
  } else {
    rows_ = rows;
    cols_ = cols;
    this->initializating();
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->initializating();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool flag = true;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (matrix_[i][j] != other.matrix_[i][j]) {
          flag = false;
        }
      }
    }
  } else {
    flag = false;
  }
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  } else {
    throw MyException("Error!");
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  } else {
    throw MyException("Error!");
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.rows_) {
    S21Matrix tmp_matrix(*this);
    setCols(other.cols_);
    double res;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        res = 0;
        for (int k = 0; k < other.rows_; k++) {
          res += (tmp_matrix.matrix_[i][k] * other.matrix_[k][j]);
        }
        matrix_[i][j] = res;
      }
    }
  } else {
    throw MyException("Error!");
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix new_matrix(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      new_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return new_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ == cols_) {
    if (rows_ == 1) {
      return *this;
    }
    S21Matrix new_matrix(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor_matrix(rows_ - 1, cols_ - 1);
        for (int l = 0; l < rows_ - 1; l++) {
          for (int k = 0; k < cols_ - 1; k++) {
            if (l < i && k < j) {
              minor_matrix.matrix_[l][k] = matrix_[l][k];
            } else if (l < i) {
              minor_matrix.matrix_[l][k] = matrix_[l][k + 1];
            } else if (k < j) {
              minor_matrix.matrix_[l][k] = matrix_[l + 1][k];
            } else {
              minor_matrix.matrix_[l][k] = matrix_[l + 1][k + 1];
            }
          }
        }
        new_matrix.matrix_[i][j] = pow(-1, i + j) * minor_matrix.Determinant();
      }
    }
    return new_matrix;
  } else {
    throw MyException("Error!");
  }
}

double S21Matrix::Determinant() {
  double determinant = 0;
  if (rows_ == cols_) {
    if (rows_ == 1) {
      determinant = matrix_[0][0];
    } else if (rows_ == 2) {
      determinant =
          matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
    } else if (rows_ > 2) {
      for (int i = 0; i < rows_; i++) {
        S21Matrix tmp_matrix(rows_ - 1, cols_ - 1);
        for (int j = 0; j < rows_; j++) {
          for (int k = 0; k < cols_; k++) {
            if (j != 0 && k != i) {
              if (k > i) {
                tmp_matrix.matrix_[j - 1][k - 1] = matrix_[j][k];
              } else {
                tmp_matrix.matrix_[j - 1][k] = matrix_[j][k];
              }
            }
          }
        }
        determinant += matrix_[0][i] * pow(-1, i) * tmp_matrix.Determinant();
      }
    }
  } else {
    throw MyException("Error!");
  }
  return determinant;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ == cols_) {
    double determinant = this->Determinant();
    if (determinant != 0) {
      S21Matrix transpose_matrix(this->Transpose());
      S21Matrix inverse_matrix(transpose_matrix.CalcComplements());
      inverse_matrix.MulNumber(1 / determinant);
      return inverse_matrix;
    } else {
      throw MyException("Error!");
    }
  } else {
    throw MyException("Error!");
  }
}

int S21Matrix::getRows() { return rows_; }

int S21Matrix::getCols() { return cols_; }

void S21Matrix::setRows(int rows) {
  if (rows < 0) {
    throw MyException("Error!");
  } else if (rows == 0) {
    rows_ = rows;
    this->deleteMatrix();
  } else if (rows != rows_) {
    S21Matrix tmp_matrix(*this);
    this->deleteMatrix();
    int originalRows;
    if (rows > rows_)
      originalRows = rows_;
    else
      originalRows = rows;
    rows_ = rows;
    this->initializating();
    for (int i = 0; i < originalRows; i++) {
      for (int j = 0; j < tmp_matrix.cols_; j++) {
        matrix_[i][j] = tmp_matrix(i, j);
      }
    }
  }
}

void S21Matrix::setCols(int cols) {
  if (cols < 0) {
    throw MyException("Error!");
  } else if (cols == 0) {
    cols_ = cols;
    this->deleteMatrix();
  } else if (cols != cols_) {
    S21Matrix tmp_matrix(*this);
    this->deleteMatrix();
    int originalCols;
    if (cols > cols_)
      originalCols = cols_;
    else
      originalCols = cols;
    cols_ = cols;
    this->initializating();
    for (int i = 0; i < tmp_matrix.rows_; i++) {
      for (int j = 0; j < originalCols; j++) {
        matrix_[i][j] = tmp_matrix(i, j);
      }
    }
  }
}

void S21Matrix::initializating() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  this->SumMatrix(other);
  S21Matrix tmp_matrix(*this);
  return tmp_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  this->SubMatrix(other);
  S21Matrix tmp_matrix(*this);
  return tmp_matrix;
}

S21Matrix S21Matrix::operator*(const double num) {
  this->MulNumber(num);
  S21Matrix tmp_matrix(*this);
  return tmp_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  this->MulMatrix(other);
  S21Matrix tmp_matrix(*this);
  return tmp_matrix;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

void S21Matrix::operator=(const S21Matrix& other) {
  this->deleteMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->initializating();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::operator+=(const S21Matrix& other) { this->SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { this->SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { this->MulMatrix(other); }

void S21Matrix::operator*=(const double num) { this->MulNumber(num); }

double& S21Matrix::operator()(const int i, const int j) {
  if (i < rows_ && j < cols_) {
    return this->matrix_[i][j];
  } else {
    throw MyException("Error!");
  }
}

void S21Matrix::deleteMatrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}
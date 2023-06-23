#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <cmath>
#include <exception>
#include <iostream>

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;
  double** matrix_;

 public:
  // constructors and destructor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // methods for matrix
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // accessors
  int getRows();
  int getCols();

  // mutators
  void setRows(int rows);
  void setCols(int cols);

  // help funcs
  void initializating();
  void deleteMatrix();

  // operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  void operator=(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
  double& operator()(const int i, const int j);
};

// exception class
class MyException : public std::exception {
 private:
  char const* message_;

 public:
  explicit MyException(char const* msg) { message_ = msg; }
  char const* what() { return message_; }
};

#endif  // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
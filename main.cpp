#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(mutatorsTests, SetCols1) {
  S21Matrix matrix(2, 2);
  matrix.setCols(3);
  EXPECT_EQ(3, matrix.getCols());
}

TEST(mutatorsTests, SetCols2) {
  S21Matrix matrix(2, 2);
  matrix.setCols(1);
  EXPECT_EQ(1, matrix.getCols());
}

TEST(mutatorsTests, SetCols3) {
  S21Matrix matrix(2, 2);
  matrix.setCols(2);
  EXPECT_EQ(2, matrix.getCols());
}

TEST(mutatorsTests, SetRows1) {
  S21Matrix matrix(2, 2);
  matrix.setRows(3);
  EXPECT_EQ(3, matrix.getRows());
}

TEST(mutatorsTests, SetRows2) {
  S21Matrix matrix(2, 2);
  matrix.setRows(1);
  EXPECT_EQ(1, matrix.getRows());
}

TEST(mutatorsTests, SetRows3) {
  S21Matrix matrix(2, 2);
  matrix.setRows(2);
  EXPECT_EQ(2, matrix.getRows());
}

TEST(constructorsTests, initMatrixByDefaultConstructor1) {
  S21Matrix matrix;
  EXPECT_EQ(0, matrix.getRows());
  EXPECT_EQ(0, matrix.getCols());
}

TEST(constructorsTests, initMatrixByParametrizedConstructor1) {
  S21Matrix matrix(1, 1);
  EXPECT_EQ(1, matrix.getRows());
  EXPECT_EQ(1, matrix.getCols());
}

TEST(constructorsTests, initMatrixByParametrizedConstructor2) {
  S21Matrix matrix(4, 6);
  EXPECT_EQ(4, matrix.getRows());
  EXPECT_EQ(6, matrix.getCols());
}

TEST(constructorsTests, initMatrixByParametrizedConstructor3) {
  EXPECT_ANY_THROW(S21Matrix matrix(0, -2));
}

TEST(constructorsTests, initMatrixByCopyConstructor) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(matrix1);
  EXPECT_EQ(matrix1.getRows(), matrix2.getRows());
  EXPECT_EQ(matrix1.getCols(), matrix2.getCols());
}

TEST(constructorsTests, initMatrixByMoveConstructor) {
  S21Matrix matrix1(2, 2);
  // S21Matrix matrix2(std::move(matrix1));
  EXPECT_EQ(2, matrix1.getRows());
  // EXPECT_EQ(matrix1.getCols(), matrix2.getCols());
}

TEST(operationsWithMatrixTests, EqMatrix1) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(operationsWithMatrixTests, EqMatrix2) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(1, 2);
  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(operationsWithMatrixTests, EqMatrix3) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  matrix1(0, 0) = 3;
  matrix2(0, 0) = 2;
  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(operationsWithMatrixTests, SumMatrix1) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 1;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }
  matrix1.SumMatrix(matrix2);
  S21Matrix matrix3(2, 2);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 3;
    }
  }
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, SumMatrix2) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 1;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }
  matrix1.SumMatrix(matrix2);
  S21Matrix matrix3(2, 2);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 4;
    }
  }
  EXPECT_FALSE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, SumMatrix3) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 1;
    }
  }
  S21Matrix matrix2(1, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }

  EXPECT_ANY_THROW(matrix1.SumMatrix(matrix2));
}

TEST(operationsWithMatrixTests, SubMatrix1) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 3;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 1;
    }
  }
  matrix1.SubMatrix(matrix2);
  S21Matrix matrix3(2, 2);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 2;
    }
  }
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, SubMatrix2) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 3;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 1;
    }
  }
  matrix1.SubMatrix(matrix2);
  S21Matrix matrix3(2, 2);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 1;
    }
  }
  EXPECT_FALSE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, SubMatrix3) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 3;
    }
  }
  S21Matrix matrix2(1, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 1;
    }
  }
  EXPECT_ANY_THROW(matrix1.SubMatrix(matrix2));
}

TEST(operationsWithMatrixTests, MulNumber1) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 2;
    }
  }
  matrix1.MulNumber(5);
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 10;
    }
  }
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(operationsWithMatrixTests, MulNumber2) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 3;
    }
  }
  matrix1.MulNumber(0);
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 1;
    }
  }
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(operationsWithMatrixTests, MulMatrix1) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 2;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 3;
    }
  }
  matrix1.MulMatrix(matrix2);
  S21Matrix matrix3(2, 2);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 12;
    }
  }
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, MulMatrix2) {
  S21Matrix matrix1(3, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 3;
    }
  }
  S21Matrix matrix2(2, 3);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 1;
    }
  }
  matrix1.MulMatrix(matrix2);
  S21Matrix matrix3(3, 3);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 6;
    }
  }
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, MulMatrix3) {
  S21Matrix matrix1(1, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 2;
    }
  }
  S21Matrix matrix2(2, 1);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }
  matrix1.MulMatrix(matrix2);
  S21Matrix matrix3(1, 1);
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      matrix3(i, j) = 8;
    }
  }
  EXPECT_TRUE(matrix1 == matrix3);
}

TEST(operationsWithMatrixTests, MulMatrix4) {
  S21Matrix matrix1(1, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 2;
    }
  }
  S21Matrix matrix2(1, 1);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }
  EXPECT_ANY_THROW(matrix1.MulMatrix(matrix2));
}

TEST(operationsWithMatrixTests, TransposeMatrix1) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 2;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }
  S21Matrix matrix3 = matrix1.Transpose();
  EXPECT_TRUE(matrix3 == matrix2);
}

TEST(operationsWithMatrixTests, TransposeMatrix2) {
  S21Matrix matrix1(2, 1);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      matrix1(i, j) = 2;
    }
  }
  S21Matrix matrix2(1, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      matrix2(i, j) = 2;
    }
  }
  S21Matrix matrix3 = matrix1.Transpose();
  EXPECT_TRUE(matrix3 == matrix2);
}

TEST(operationsWithMatrixTests, TransposeMatrix3) {
  S21Matrix matrix1(2, 2);
  for (int i = 0; i < matrix1.getRows(); i++) {
    for (int j = 0; j < matrix1.getCols(); j++) {
      if (i == 0)
        matrix1(i, j) = 2;
      else
        matrix1(i, j) = 3;
    }
  }
  S21Matrix matrix2(2, 2);
  for (int i = 0; i < matrix2.getRows(); i++) {
    for (int j = 0; j < matrix2.getCols(); j++) {
      if (j == 0)
        matrix2(i, j) = 2;
      else
        matrix2(i, j) = 3;
    }
  }
  S21Matrix matrix3 = matrix1.Transpose();
  EXPECT_TRUE(matrix3 == matrix2);
}

TEST(operationsWithMatrixTests, CalcComplementsMatrix1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 4;
  matrix2(0, 1) = -3;
  matrix2(1, 0) = -2;
  matrix2(1, 1) = 1;

  S21Matrix matrix3 = matrix1.CalcComplements();

  EXPECT_TRUE(matrix3 == matrix2);
}

TEST(operationsWithMatrixTests, CalcComplementsMatrix2) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 2;
  matrix1(0, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 9;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 7;
  matrix1(2, 0) = 8;
  matrix1(2, 1) = 4;
  matrix1(2, 2) = 1;

  S21Matrix matrix2(3, 3);
  matrix2(0, 0) = -23;
  matrix2(0, 1) = 47;
  matrix2(0, 2) = -4;
  matrix2(1, 0) = 22;
  matrix2(1, 1) = -54;
  matrix2(1, 2) = 40;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 49;
  matrix2(2, 2) = -44;

  S21Matrix matrix3 = matrix1.CalcComplements();

  EXPECT_TRUE(matrix3 == matrix2);
}

TEST(operationsWithMatrixTests, CalcComplementsMatrix3) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 2;
  matrix1(0, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 9;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 7;
  matrix1(2, 0) = 8;
  matrix1(2, 1) = 4;
  matrix1(2, 2) = 1;

  S21Matrix matrix2(3, 3);
  matrix2(0, 0) = -23;
  matrix2(0, 1) = 47;
  matrix2(0, 2) = -4;
  matrix2(1, 0) = 22;
  matrix2(1, 1) = 0;
  matrix2(1, 2) = 40;
  matrix2(2, 0) = 7;
  matrix2(2, 1) = 49;
  matrix2(2, 2) = -44;

  S21Matrix matrix3 = matrix1.CalcComplements();

  EXPECT_FALSE(matrix3 == matrix2);
}

TEST(operationsWithMatrixTests, CalcComplementsMatrix4) {
  S21Matrix matrix1(1, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  EXPECT_ANY_THROW(matrix1.CalcComplements());
}

TEST(operationsWithMatrixTests, CalcComplementsMatrix5) {
  S21Matrix matrix1(1, 1);
  matrix1(0, 0) = 1;
  S21Matrix matrix2 = matrix1.CalcComplements();
  EXPECT_TRUE(matrix2(0, 0) == 1);
}

TEST(operationsWithMatrixTests, Determinant1) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 2;
  matrix1(0, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 9;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 7;
  matrix1(2, 0) = 8;
  matrix1(2, 1) = 4;
  matrix1(2, 2) = 1;

  double determinant = matrix1.Determinant();

  EXPECT_EQ(208, determinant);
}

TEST(operationsWithMatrixTests, Determinant2) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 4;
  matrix1(1, 0) = -3;
  matrix1(1, 1) = 6;

  double determinant = matrix1.Determinant();

  EXPECT_EQ(18, determinant);
}

TEST(operationsWithMatrixTests, Determinant3) {
  S21Matrix matrix1(4, 4);
  matrix1(0, 0) = 2;
  matrix1(0, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(0, 3) = 9;
  matrix1(1, 0) = 9;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 7;
  matrix1(1, 3) = 12;
  matrix1(2, 0) = 8;
  matrix1(2, 1) = 4;
  matrix1(2, 2) = 1;
  matrix1(2, 3) = 18;
  matrix1(3, 0) = 9;
  matrix1(3, 1) = 5;
  matrix1(3, 2) = 2;
  matrix1(3, 3) = 6;

  double determinant = matrix1.Determinant();

  EXPECT_EQ(-2988, determinant);
}

TEST(operationsWithMatrixTests, Determinant4) {
  S21Matrix matrix1(2, 1);
  matrix1(0, 0) = 1;
  matrix1(1, 0) = 3;

  EXPECT_ANY_THROW(matrix1.Determinant());
}

TEST(operationsWithMatrixTests, Determinant5) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 4;
  matrix1(1, 0) = 5;
  matrix1(1, 1) = 6;

  double determinant = matrix1.Determinant();

  EXPECT_FALSE(18 == determinant);
}

TEST(operationsWithMatrixTests, InverseMatrix1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = -2;
  matrix2(0, 1) = 1;
  matrix2(1, 0) = 1.5;
  matrix2(1, 1) = -0.5;

  S21Matrix matrix3 = matrix1.InverseMatrix();

  EXPECT_TRUE(matrix2 == matrix3);
}

TEST(operationsWithMatrixTests, InverseMatrix2) {
  S21Matrix matrix1(1, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
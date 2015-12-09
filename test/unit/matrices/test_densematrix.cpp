#include "test_matrix.h"
#include <src/matrices/densematrix.h>

typedef ::testing::Types<DenseMatrix<int>,
                         DenseMatrix<double>> DenseMatrixTests;

INSTANTIATE_TYPED_TEST_CASE_P(DenseMatrix, MatrixTest, DenseMatrixTests);

TEST(DenseMatrix, begin)
{
    DenseMatrix<> matrix(1, 1);

    EXPECT_NE(matrix.begin(), matrix.end());
    EXPECT_EQ(matrix.begin() + 1, matrix.end());
}

TEST(DenseMatrix, end)
{
    DenseMatrix<> matrix(1, 1);

    EXPECT_NE(matrix.begin(), matrix.end());
    EXPECT_EQ(matrix.begin(), matrix.end() - 1);
}

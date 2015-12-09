#include "test_matrix.h"
#include <src/matrices/compressedmatrix.h>

typedef ::testing::Types<CompressedMatrix<int>,
                         CompressedMatrix<double>> CompressedMatrixTests;

INSTANTIATE_TYPED_TEST_CASE_P(CompressedMatrix, MatrixTest, CompressedMatrixTests);

TEST(CompressedMatrix, begin)
{
    CompressedMatrix<> matrix(1, 3);

    EXPECT_EQ(matrix.begin(), matrix.end());

    matrix[0][2] = 7.;
    EXPECT_EQ(*matrix.begin(), matrix[0][2]);

    matrix[0][1] = 6.;
    EXPECT_EQ(*matrix.begin(), matrix[0][1]);

    matrix[0][0] = 5.;
    EXPECT_EQ(*matrix.begin(), matrix[0][0]);
}

TEST(CompressedMatrix, end)
{
    CompressedMatrix<> matrix(1, 3);

    EXPECT_EQ(matrix.begin(), matrix.end());

    matrix[0][0] = 5.;
    EXPECT_EQ(*(matrix.end() - 1), matrix[0][0]);

    matrix[0][1] = 6.;
    EXPECT_EQ(*(matrix.end() - 1), matrix[0][1]);

    matrix[0][2] = 7.;
    EXPECT_EQ(*(matrix.end() - 1), matrix[0][2]);
}

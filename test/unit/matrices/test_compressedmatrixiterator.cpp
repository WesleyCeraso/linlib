#include "test_matrixiterator.h"
#include <src/matrices/compressedmatrix.h>

typedef ::testing::Types<CompressedMatrix<int>,
                         CompressedMatrix<double>> CompressedMatrixIteratorTests;

INSTANTIATE_TYPED_TEST_CASE_P(CompressedMatrixIterator, MatrixIteratorTest, CompressedMatrixIteratorTests);

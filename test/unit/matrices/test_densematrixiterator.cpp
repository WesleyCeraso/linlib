#include "test_matrixiterator.h"
#include <src/matrices/densematrix.h>

typedef ::testing::Types<DenseMatrix<int>,
                         DenseMatrix<double>> DenseMatrixIteratorTests;

INSTANTIATE_TYPED_TEST_CASE_P(DenseMatrixIterator, MatrixIteratorTest, DenseMatrixIteratorTests);

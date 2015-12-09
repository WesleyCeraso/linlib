#ifndef TEST_MATRIXITERATOR_H
#define TEST_MATRIXITERATOR_H

#include <gtest/gtest.h>
#include <src/matrices/matrix.h>
#include <src/matrices/matrixutils.h>

template <typename T>
class MatrixIteratorTest : public ::testing::Test {};

TYPED_TEST_CASE_P(MatrixIteratorTest);

TYPED_TEST_P(MatrixIteratorTest, compoundAddition)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;
    
    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());
    
    iterator it = matrix.begin();

    it += 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 3);

    it += 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 6);

    it += 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 9);
    EXPECT_EQ(it, matrix.end());

}

TYPED_TEST_P(MatrixIteratorTest, preIncrement)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();

    it += 2;
    EXPECT_EQ(std::distance(matrix.begin(), ++it), 3);

    it += 2;
    EXPECT_EQ(std::distance(matrix.begin(), ++it), 6);

    it += 2;
    EXPECT_EQ(std::distance(matrix.begin(), ++it), 9);
    EXPECT_EQ(it, matrix.end());
}

TYPED_TEST_P(MatrixIteratorTest, posIncrement)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();

    it += 2;
    EXPECT_EQ(std::distance(matrix.begin(), it++), 2);

    it += 2;
    EXPECT_EQ(std::distance(matrix.begin(), it++), 5);

    it += 2;
    EXPECT_EQ(std::distance(matrix.begin(), it++), 8);
    EXPECT_EQ(it, matrix.end());
}

TYPED_TEST_P(MatrixIteratorTest, addition)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();

    it = it + 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 3);

    it = it + 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 6);

    it = it + 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 9);
    EXPECT_EQ(it, matrix.end());
}

TYPED_TEST_P(MatrixIteratorTest, compoundSubtraction)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.end();

    it -= 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 6);

    it -= 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 3);

    it -= 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 0);
    EXPECT_EQ(it, matrix.begin());
}

TYPED_TEST_P(MatrixIteratorTest, preDecrement)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.end();

    it -= 2;
    EXPECT_EQ(std::distance(matrix.begin(), --it), 6);

    it -= 2;
    EXPECT_EQ(std::distance(matrix.begin(), --it), 3);

    it -= 2;
    EXPECT_EQ(std::distance(matrix.begin(), --it), 0);
    EXPECT_EQ(it, matrix.begin());
}

TYPED_TEST_P(MatrixIteratorTest, posDecrement)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.end();

    it -= 2;
    EXPECT_EQ(std::distance(matrix.begin(), it--), 7);

    it -= 2;
    EXPECT_EQ(std::distance(matrix.begin(), it--), 4);

    it -= 2;
    EXPECT_EQ(std::distance(matrix.begin(), it--), 1);
    EXPECT_EQ(it, matrix.begin());
}

TYPED_TEST_P(MatrixIteratorTest, subtraction)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.end();

    it = it - 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 6);

    it = it - 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 3);

    it = it - 3;
    EXPECT_EQ(std::distance(matrix.begin(), it), 0);
    EXPECT_EQ(it, matrix.begin());
}

TYPED_TEST_P(MatrixIteratorTest, operatorEquality)
{
    typedef typename TypeParam::value_type value_type;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    EXPECT_EQ(matrix.begin() + 9, matrix.end() - 0);
    EXPECT_EQ(matrix.begin() + 8, matrix.end() - 1);
    EXPECT_EQ(matrix.begin() + 7, matrix.end() - 2);
    EXPECT_EQ(matrix.begin() + 6, matrix.end() - 3);
    EXPECT_EQ(matrix.begin() + 5, matrix.end() - 4);
    EXPECT_EQ(matrix.begin() + 4, matrix.end() - 5);
    EXPECT_EQ(matrix.begin() + 3, matrix.end() - 6);
    EXPECT_EQ(matrix.begin() + 2, matrix.end() - 7);
    EXPECT_EQ(matrix.begin() + 1, matrix.end() - 8);
    EXPECT_EQ(matrix.begin() + 0, matrix.end() - 9);
}

TYPED_TEST_P(MatrixIteratorTest, operatorInequality)
{
    typedef typename TypeParam::value_type value_type;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    EXPECT_NE(matrix.begin() + 0, matrix.end() - 0);
    EXPECT_NE(matrix.begin() + 1, matrix.end() - 1);
    EXPECT_NE(matrix.begin() + 2, matrix.end() - 2);
    EXPECT_NE(matrix.begin() + 3, matrix.end() - 3);
    EXPECT_NE(matrix.begin() + 4, matrix.end() - 4);
    EXPECT_NE(matrix.begin() + 5, matrix.end() - 5);
    EXPECT_NE(matrix.begin() + 6, matrix.end() - 6);
    EXPECT_NE(matrix.begin() + 7, matrix.end() - 7);
    EXPECT_NE(matrix.begin() + 8, matrix.end() - 8);
    EXPECT_NE(matrix.begin() + 9, matrix.end() - 9);
}

TYPED_TEST_P(MatrixIteratorTest, indirection)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;
    typedef typename TypeParam::const_iterator const_iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());
    for (const_iterator cit = matrix.cbegin(); cit != matrix.cend(); ++cit)
    {
        EXPECT_EQ(*cit, std::numeric_limits<value_type>::max());
    }
    for (iterator it = matrix.begin(); it != matrix.end(); ++it)
    {
        *it = value_type();
    }
    for (const_iterator cit = matrix.cbegin(); cit != matrix.cend(); ++cit)
    {
        EXPECT_EQ(*cit, value_type());
    }
}

TYPED_TEST_P(MatrixIteratorTest, difference)
{
    typedef typename TypeParam::value_type value_type;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    EXPECT_EQ(matrix.end() - (matrix.begin() + 0), 9);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 1), 8);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 2), 7);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 3), 6);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 4), 5);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 5), 4);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 6), 3);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 7), 2);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 8), 1);
    EXPECT_EQ(matrix.end() - (matrix.begin() + 9), 0);
}

TYPED_TEST_P(MatrixIteratorTest, row)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;
    typedef typename TypeParam::const_iterator const_iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();
    const_iterator cit = matrix.cbegin();

    iterator it2 = it;
    const_iterator cit2 = cit;

    EXPECT_EQ(it2++, it);
    EXPECT_EQ(cit2++, cit);

    iterator it3 = it2;
    const_iterator cit3 = cit2;

    EXPECT_EQ(it3++, it2);
    EXPECT_EQ(cit3++, cit2);

    EXPECT_EQ(it3, it2 + 1);
    EXPECT_EQ(cit3, cit2 + 1);
    EXPECT_EQ(it2, it + 1);
    EXPECT_EQ(cit2, cit + 1);
}

TYPED_TEST_P(MatrixIteratorTest, column)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();
    EXPECT_EQ(it++.column(), 0);
    EXPECT_EQ(it++.column(), 1);
    EXPECT_EQ(it++.column(), 2);
    EXPECT_EQ(it++.column(), 0);
}

TYPED_TEST_P(MatrixIteratorTest, rowColumn)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(0, 0));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(0, 1));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(0, 2));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(1, 0));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(1, 1));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(1, 2));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(2, 0));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(2, 1));
    EXPECT_EQ(it++.rowColumn(), std::make_tuple(2, 2));
}

TYPED_TEST_P(MatrixIteratorTest, constructor)
{
    typedef typename TypeParam::value_type value_type;
    typedef typename TypeParam::iterator iterator;

    TypeParam matrix(3, 3, std::numeric_limits<value_type>::max());

    iterator it = matrix.begin();
}

REGISTER_TYPED_TEST_CASE_P(MatrixIteratorTest,
                           compoundAddition,
                           preIncrement,
                           posIncrement,
                           addition,
                           compoundSubtraction,
                           preDecrement,
                           posDecrement,
                           subtraction,
                           operatorEquality,
                           operatorInequality,
                           indirection,
                           difference,
                           row,
                           column,
                           rowColumn,
                           constructor);

#endif

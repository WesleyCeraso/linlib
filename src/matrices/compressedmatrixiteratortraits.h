#ifndef COMPRESSEDMATRIXITERATORTRAITS_H
#define COMPRESSEDMATRIXITERATORTRAITS_H

#include <algorithm>

template <class> class CompressedMatrix;
template <class, bool> class CompressedMatrixIterator;
template <class> struct matrix_traits;

template <class T, bool Const>
struct matrix_iterator_traits<CompressedMatrixIterator<T, Const>>
{
    typedef typename matrix_traits<CompressedMatrix<T>>::value_type value_type;
    typedef typename matrix_traits<CompressedMatrix<T>>::size_type size_type;
    typedef typename matrix_traits<CompressedMatrix<T>>::difference_type difference_type;
    typedef typename std::conditional<Const, const value_type &, value_type &>::type return_type;
};

#endif


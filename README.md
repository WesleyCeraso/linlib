# Linlib [![build status](https://gitlab.com/ci/projects/20830/status.png?ref=master)](https://gitlab.com/ci/projects/20830?ref=master) [![license](http://img.shields.io/badge/license-MIT-red.svg?style=flat)](LICENSE)
**Linlib** is an open source library that provides linear algebra structures and algorithms. It is multiplataform, written in C++11, and is available at https://gitlab.com/wesleyceraso/linlib or https://github.com/wesleyceraso/linlib.

### Features
- Dense and Compressed (CSC) matrices
- Linear system solvers:
  - Gradient descent
  - Conjugate gradient method
  - Biconjugate gradient method (BiCG)
  - Biconjugate gradient stabilized method (BiCGSTAB)
  - LU decomposition

**Linlib** is flexible and expansible, so you can create new structures and/or algorithms and use them along with the existing ones.

### Getting started
Clone the repository
```
git clone https://gitlab.com/wesleyceraso/linlib.git
```
Enter the project and create a build directory
```
cd linlib
mkdir build
```
Configure and build
```
cmake ../
cmake --build .
```
Execute the unit tests
```
ctest 
```
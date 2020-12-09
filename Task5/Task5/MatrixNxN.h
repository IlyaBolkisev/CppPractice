#ifndef TASK5_MATRIXNXN_H
#define TASK5_MATRIXNXN_H
class MatrixNxN 
{
	int(**matrix);
public:
	explicit MatrixNxN(int);
	int element(int, int) const;
	void setElement(int, int, int);
	void fillRandomElements(int, int);
	int sumPrincipalDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(int) const;
	int minColumn(int) const;
	int maxColumn(int) const;
	int dim;
};
#endif // !TASK5_MATRIXNXN_H
#pragma once

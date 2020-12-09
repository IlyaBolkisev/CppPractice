#ifndef TASK5_MATRIX3X3_H	
#define TASK5_MATRIX3X3_H
class Matrix3x3 
{
public:
	int(matrix[3][3]);
	explicit Matrix3x3();
	int element(const int, const int) const;
	void setElement(const int, const int, const int);
	void fillRandomElements(const int, const int);
	int sumPrincipalDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int) const;
	int minColumn(const int) const;
	int maxColumn(const int) const;
};
#endif // TASK5_MATRIX_H
#pragma once

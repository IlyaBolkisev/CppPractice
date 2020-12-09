#include <iostream>
#include "MatrixNxN.h"
using namespace std;

MatrixNxN::MatrixNxN(int iDim)
{
	dim = iDim;
	int** m = new int* [iDim];
	for (int i = 0; i < iDim; i++)
	{
		m[i] = new int[iDim];
		for (int j = 0; j < iDim; j++)
			m[i][j] = 0;
	}
	matrix = m;
};

int MatrixNxN::element(const int i, const int j) const
{
	return matrix[i][j];
}

void MatrixNxN::setElement(const int i, const int j, const int value)
{
	this->matrix[i][j] = value;
}

void MatrixNxN::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0;i < this->dim;i++)
		for (int j = 0;j < this->dim;j++)
		{
			int val = minVal + rand() % (maxVal - minVal);
			this->setElement(i, j, val);
		}
}

int MatrixNxN::sumPrincipalDiag() const
{
	int sum = 0;
	for (int i = 0;i < this->dim;i++)
		sum += this->matrix[i][i];
	return sum;
}

int MatrixNxN::sumSecondaryDiag() const
{
	int sum = 0;
	for (int i = 0;i < this->dim;i++)
		sum += this->matrix[i][this->dim - i - 1];
	return sum;
}

int MatrixNxN::productPrincipalDiag() const
{
	int product = 1;
	for (int i = 0;i < this->dim;i++)
		product *= this->matrix[i][i];
	return product;
}

int MatrixNxN::productSecondaryDiag() const
{
	int product = 1;
	for (int i = 0;i < this->dim;i++)
		product *= this->matrix[i][this->dim - i - 1];
	return product;
}

int MatrixNxN::sumRow(const int iRow) const
{
	int sum = 0;
	for (int i = 0;i < this->dim;i++)
		sum += this->matrix[iRow][i];
	return sum;
}

int MatrixNxN::minColumn(const int iCol) const
{
	int min = this->matrix[0][iCol];
	for (int i = 0;i < this->dim;i++)
		if (this->matrix[i][iCol] < min)
			min = this->matrix[i][iCol];
	return min;
}

int MatrixNxN::maxColumn(const int iCol) const
{
	int max = this->matrix[0][iCol];
	for (int i = 0;i < this->dim;i++)
		if (this->matrix[i][iCol] > max)
			max = this->matrix[i][iCol];
	return max;
}


//int main()
//{
//	int size = 5;
//	cout << "size = " << size << endl;
//	MatrixNxN m(size);
//	m.fillRandomElements(-10, 10);
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//			cout << m.element(i, j) << " ";
//		cout << endl;
//	}
//	cout << endl;
//
//	cout << "sumPrincipalDiag " << m.sumPrincipalDiag() << endl;
//	cout << "sumSecondaryDiag " << m.sumSecondaryDiag() << endl;
//	cout << "productPrincipalDiag " << m.productPrincipalDiag() << endl;
//	cout << "productSecondaryDiag " << m.productSecondaryDiag() << endl;
//	cout << "sumRow" << endl;
//	for (int i = 0;i < size;i++)
//		cout << m.sumRow(i) << endl;
//	for (int i = 0;i < size;i++)
//	{
//		cout << "maxColumn col=" << i << " " << m.maxColumn(i) << endl;
//		cout << "minColumn col=" << i << " " << m.minColumn(i) << endl;
//	}
//}
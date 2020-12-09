#include <iostream>
#include "Matrix3x3.h"
using namespace std;

Matrix3x3::Matrix3x3()
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			matrix[i][j] = 0;
};

int Matrix3x3::element(const int i, const int j) const
{
	return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	this->matrix[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
		{
			int value = minVal + rand() % (maxVal - minVal);
			this->setElement(i, j, value);
		}
}

int Matrix3x3::sumPrincipalDiag() const
{
	return this->matrix[0][0] + this->matrix[1][1] + this->matrix[2][2];
}

int Matrix3x3::sumSecondaryDiag() const
{
	return this->matrix[0][2] + this->matrix[1][1] + this->matrix[2][0];
}

int Matrix3x3::productPrincipalDiag() const
{
	return this->matrix[0][0] * this->matrix[1][1] * this->matrix[2][2];
}

int Matrix3x3::productSecondaryDiag() const
{
	return this->matrix[0][2] * this->matrix[1][1] * this->matrix[2][0];
}

int Matrix3x3::sumRow(const int iRow) const
{
	return this->matrix[iRow][2] + this->matrix[iRow][1] + this->matrix[iRow][0];
}

int Matrix3x3::minColumn(const int iCol) const
{
	int min = this->matrix[0][iCol];
	for (int i = 0;i < 3;i++)
		if (this->matrix[i][iCol] < min)
			min = this->matrix[i][iCol];
	return min;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int max = this->matrix[0][iCol];
	for (int i = 0;i < 3;i++)
		if (this->matrix[i][iCol] > max)
			max = this->matrix[i][iCol];
	return max;
}


//int main()
//{
//	Matrix3x3 m;
//	m.fillRandomElements(-10, 10);
//	for (int i = 0;i < 3;i++)
//	{
//		for (int j = 0;j < 3;j++)
//			cout << m.matrix[i][j] << ' ';
//		cout << endl;
//	}
//	cout << endl;
//
//	cout << "sumPrincipalDiag " << m.sumPrincipalDiag() << endl;
//	cout << "sumSecondaryDiag " << m.sumSecondaryDiag() << endl;
//	cout << "productPrincipalDiag " << m.productPrincipalDiag() << endl;
//	cout << "productSecondaryDiag " << m.productSecondaryDiag() << endl;
//	cout << "sumRow" << endl;
//	for (int i = 0;i < 3;i++)
//		cout << m.sumRow(i) << endl;
//	for (int i = 0;i < 3;i++)
//	{
//		cout << "maxColumn col=" << i << " " << m.maxColumn(i) << endl;
//		cout << "minColumn col=" << i << " " << m.minColumn(i) << endl;
//	}
//}

#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

void Matrix::set_matrix(bool zero = 1)
{
	if (zero) cout << "Enter the elements of your matrix: " << endl;
	if (rows == 0 && columns == 0)
	{
		cout << "Please, enter the size of your matrix.\nNumber of rows: ->\t";
		cin >> rows;
		cout << "Number of columns: ->\t";
		cin >> columns;
	}
	for (int i = 0; i < rows; i++)
	{
		if (zero) cout << i + 1 << " row: " << endl;
		for (int j = 0; j < columns; j++)
		{
			//ввод элементов без проверки
			if (zero) cin >> p[i][j];
			else p[i][j] = 0;
		}
	}
}

void Matrix::get_matrix()
{
	cout << "Your matrix:" << endl;
	if (!p)
	{
		cout << "It is empty" << endl;
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << p[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void Matrix::get_element(int i, int j)
{
	cout << "Element in " << i + 1 << " row in " << j + 1 << " column: " << p[i][j] << endl;
}

// Сложение двух матриц
Matrix Matrix :: operator+(Matrix& m2)
{
	assert(rows == m2.rows && columns == m2.columns && p != nullptr);
	Matrix result(rows, columns);
	result.p = new int* [result.rows];
	for (int i = 0; i < result.rows; i++)
	{
		result.p[i] = new int[result.columns];
		for (int j = 0; j < result.columns; j++)
		{
			result.p[i][j] = p[i][j] + m2.p[i][j];
		}
	}
	return result;
}

// К матрице прибавляется число
Matrix& Matrix :: operator+(int value)
{
	assert(rows && columns && "Matrix has no elements");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			p[i][j] += value;
		}
	}
	return *this;
}

// Префиксная форма инкремента
Matrix& Matrix :: operator++()
{
	assert(rows && columns && "Matrix has no elements");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			p[i][j]++;
		}
	}
	return *this;
}

// Постфиксная форма инкремента
Matrix Matrix :: operator++(int)
{
	assert(rows && columns && "Matrix has no elements");
	Matrix temp(*this);
	++(*this);
	return temp;
}

bool operator>(Matrix& m1, Matrix& m2)
{
	return (det_nxn(m1, 0) > det_nxn(m2, 0));
}

bool operator>(Matrix& m1, int value)
{
	return (det_nxn(m1, 0) > value);
}

bool operator>(int value, Matrix& m2)
{
	return (value > det_nxn(m2, 0));
}

bool operator<(Matrix& m1, Matrix& m2)
{
	return (det_nxn(m1, 0) < det_nxn(m2, 0));
}

bool operator<(Matrix& m1, int value)
{
	return (det_nxn(m1, 0) < value);
}

bool operator<(int value, Matrix& m2)
{
	return (value < det_nxn(m2, 0));
}

// Вычисление определителя матрицы NxN
int det_nxn(Matrix& m, int i)
{
	assert(m.rows == m.columns && m.rows > 1);
	int det = 0;
	if (m.rows == 2)
	{
		det += (m.p[0][0] * m.p[1][1]) - (m.p[0][1] * m.p[1][0]);
		return det;
	}
	else if (i == m.columns)
	{
		return det;
	}
	else
	{
		Matrix temp(m);
		int value_i = temp.p[0][i];
		if (i % 2) value_i *= -1;
		temp.del_row(0).del_column(i);
		det += value_i * det_nxn(temp, 0);
		//cout << endl << det << "\t" << i;
		det += det_nxn(m, i + 1);
		//cout << endl << det << "\t" << i;
		return det;
	}
}

Matrix& Matrix::del_row(int i_row)
{
	assert(i_row < rows && "Out of range!");
	for (int i = i_row; i < rows - 1; i++)
	{
		p[i] = p[i + 1];
	}
	--rows;
	return *this;
}

Matrix& Matrix::del_column(int i_column)
{
	assert(i_column < columns && "Out of range!");
	for (int j = 0; j < rows; j++)
	{
		for (int i = i_column; i < columns - 1; i++)
		{
			p[j][i] = p[j][i + 1];
		}
	}
	--columns;
	return *this;
}
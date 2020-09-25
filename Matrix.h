#include <iostream>

using namespace std;

class Matrix {
private:
	int** p;
	int rows, columns;

public:
	Matrix(int a = 0, int b = 0)
	{
		rows = a;
		columns = b;
		if (!a && !b) p = nullptr;
		else
		{
			p = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				p[i] = new int[columns];
			}
		}

		// изначально матрица нулевая
		set_matrix(0);
	}

	// Конструктор копирования
	Matrix(Matrix& m)
	{
		if (!m.rows && !m.columns)
		{
			p = nullptr;
			rows = columns = 0;
		}
		else
		{
			rows = m.rows;
			columns = m.columns;
			p = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				p[i] = new int[columns];
				for (int j = 0; j < columns; j++)
				{
					p[i][j] = m.p[i][j];
				}
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++) delete(p[i]);
		delete(p);
		cout << "Matrix destroyed." << endl;
	}

	void set_matrix(bool);
	void get_matrix();
	void get_element(int, int);
	Matrix& del_row(int);
	Matrix& del_column(int);
	Matrix operator+(Matrix&);
	Matrix& operator+(int);
	Matrix& operator++(); // префиксная форма
	Matrix operator++(int); // постфиксная форма
	friend int det_nxn(Matrix&, int);
	friend bool operator>(Matrix&, Matrix&);
	friend bool operator>(Matrix&, int);
	friend bool operator>(int, Matrix&);
	friend bool operator<(Matrix&, Matrix&);
	friend bool operator<(Matrix&, int);
	friend bool operator<(int, Matrix&);
};
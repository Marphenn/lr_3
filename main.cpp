#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	//8)
	Matrix m1(2, 2), m2(2, 2);
	m1.set_matrix(1);
	m1.get_matrix();
	m2.set_matrix(1);
	m2.get_matrix();

	Matrix sum(2, 2);
	sum = m1 + m2;
	sum.get_matrix();
	sum + 3;
	sum.get_matrix();
	sum++;
	sum.get_matrix();

	cout << endl << det_nxn(m1, 0) << endl;
	cout << endl << det_nxn(m2, 0) << endl;

	if (m1 > m2) cout << "M1 is greater than M2" << endl;
	if (m1 < m2) cout << "M1 is less than M2" << endl;

	int value = 50;
	if (m1 > 50) cout << "M1 is greater than " << value << endl;
	if (50 < m2) cout << value << " is less than M2" << endl;

	//9)
	Matrix* m3 = new Matrix(2, 3);
	m3->set_matrix(1);
	m3->get_matrix();

	Matrix* m3_copy = new Matrix(*m3);
	m3_copy->get_matrix();
	m3_copy->del_column(1);
	m3_copy->get_matrix();
	
	//10)
	Matrix* array = new Matrix[3];
	for (int i = 0; i < 3; i++)
	{
		array[i].set_matrix(1);
	}
	for (int i = 0; i < 3; i++)
	{
		array[i].get_element(0, 0);

	}
	delete(array);
	
	return 0;
}
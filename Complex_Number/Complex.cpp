#include "Complex.h"
#include <iostream>

using namespace std;

//����������� �� ���������(����������� �������������� � ������ ����� ������� ��������)
Complex::Complex()
{
	m_re = 0;
	m_im = 0;
}

//����������� � �����������(����������� �������������� � ������ ����� �������� �������������� ����������)
Complex::Complex(double re, double im)
{
	m_re = re;
	m_im = im;
}

//����
/*� ������� ��������� ��������� � �������� ������ �������� �������������� �����;
  ����� ����� ������ �������������, �� ����� ��������� ��������� � �������� ������ �������� ������ �����;
  ��� �������� ������������� �������� ������ �������������� ��� ������ ����� �����, ����� ������� ����������, ����������� � ������ "main()"*/
void Complex::Input()
{
	cout << "Insert Re = ";
	cin >> m_re;

	cout << "Insert Im = ";
	cin >> m_im;
}

//�����
void Complex::Output(int index)//��������� �������� ���������� �� ����� ����� ������� ����� ���������, �.�. z1, z2,...
{
	if (m_re != 0 && m_im == 0) throw 100;//���� �������������� ����� �� ����� ����, � ������ ����� 0(�.�. ����� �� �����������) �������� ����������;
	else if (m_im < 0) cout << "z" << index << " = " << m_re << m_im << "i\n";//���� ������ ����� ������������, �� ����� ���������� � ���� Zindex = Re - Imi.
	else cout << "z" << index << " = " << m_re << " + " << m_im << "i\n";//����� ���������� ����� ����� �������� � ����������� �����
}

//���������� �������������� �����
void Complex::set_Re(double re)
{
	m_re = re;
}

//���������� ������ �����
void Complex::set_Im(double im)
{
	m_im = im;
}

//���������� ������ � �������������� ����� ��� ������������ �����
void Complex::set_Complex(double re, double im)
{
	m_re = re;
	m_im = im;
}

//����� �������� �������������� �����
double Complex::get_Re()
{
	return m_re;
}

//����� �������� ������ �����
double Complex::get_Im()
{
	return m_im;
}

//�������� ��������
Complex Complex::operator+(const Complex& z)//������� ������ �� ������ ���� �� ������(������ ���������). 
{
	if ((m_im == 0 && m_re != 0) || (z.m_im == 0 && z.m_re != 0)) throw 100;//���� ���� �� ����� �� �������� ����������� - �������� ����������
	Complex result;
	result.m_re = this->m_re + z.m_re; //���������� �������������� �����
	result.m_im = this->m_im + z.m_im; //���������� ������ �����

	return result; //���������� ���������
}

//�������� ���������
Complex Complex::operator*(const Complex& z)//������� ������ �� ������ ���� �� ������(������ ���������). 
{
	if ((m_im == 0 && m_re != 0) || (z.m_im == 0 && z.m_re != 0)) throw 100;//���� ���� �� ����� �� �������� ����������� - ������ ����������
	Complex result;
	result.m_re = (this->m_re * z.m_re) - (this->m_im * z.m_im);//����������� �������� �������������� �����
	result.m_im = (this->m_re * z.m_im) + (this->m_im * z.m_re);//����������� �������� ������ �����

	return result;
}

//�������� �������
Complex Complex::operator/(const Complex& z)//������� ������ �� ������ ���� �� ������(������ ���������). 
{
	if (z.m_re == 0 && z.m_im == 0) throw 101;//���� �������� ����� 0 �������� ����������
	if ((m_re != 0 && m_im == 0) || (z.m_re != 0 && z.m_im == 0)) throw 100;//���� ���� �� ����� �� ����������� �������� ����������
	Complex result;
	result.m_re = ((this->m_re * z.m_re) + (this->m_im * z.m_im)) / ((z.m_re * z.m_re) + (z.m_im * z.m_im));//����������� �������� �������������� �����
	result.m_im = ((z.m_re * this->m_im) - (this->m_re * z.m_im)) / ((z.m_re * z.m_re) + (z.m_im * z.m_im));//����������� �������� ������ �����

	return result;
}

Complex Complex::operator=(const Complex& z)
{
	if ((m_re != 0 && m_im == 0) || (z.m_re != 0 && z.m_im == 0)) throw 100;//���� ���� �� ����� �� ����������� ������ ����������
	if (this == &z) return *this;//�������� �� ��������������
	m_re = z.m_re;//����������� �������������� ����� ������� �������� ������
	m_im = z.m_im;//����������� ������ ����� ������� �������� ������
	return *this;
}

//�������� ���������
bool Complex::operator==(Complex& z)
{
	if ((m_im == 0 && m_re != 0) || (z.m_im == 0 && z.m_re != 0)) throw 100;//���� ���� �� ����� �� ����������� ������ ����������
	if (m_re == z.m_re && m_im == z.m_im) return true;//���������� �������������� � ������ �����, ���� ����� ���������� "True"
	return false;//���� �� ����� ���������� "False"
}
#include "Complex.h"
#include <iostream>

using namespace std;

//Конструктор по умолчанию(Присваивает действительной и мнимой части нулевые значения)
Complex::Complex()
{
	m_re = 0;
	m_im = 0;
}

//Конструктор с параметрами(Присваивает действительной и мнимой части значения соотвествующих параметров)
Complex::Complex(double re, double im)
{
	m_re = re;
	m_im = im;
}

//Ввод
/*В консоли выводится сообщение с просьбой ввести значение действительной части;
  После ввода данных пользователем, на экран выводится сообщение с просьбой ввести значение мнимой части;
  При введении пользователем символов вместо действительной или мнимой части числа, будет создано исключение, обработаное в фукции "main()"*/
void Complex::Input()
{
	cout << "Insert Re = ";
	cin >> m_re;

	cout << "Insert Im = ";
	cin >> m_im;
}

//Вывод
void Complex::Output(int index)//Передаётся параметр отвечающий за номер числа которое будет выводится, т.е. z1, z2,...
{
	if (m_re != 0 && m_im == 0) throw 100;//Если Действительная часть не равна нулю, а мнимая равна 0(т.е. число не комплексное) создаётся исключение;
	else if (m_im < 0) cout << "z" << index << " = " << m_re << m_im << "i\n";//Если мнимая часть отрицательна, то число выведеться в виде Zindex = Re - Imi.
	else cout << "z" << index << " = " << m_re << " + " << m_im << "i\n";//Иначе комплесное число будет выведено в стандартной форме
}

//Установить Действительную часть
void Complex::set_Re(double re)
{
	m_re = re;
}

//Установить Мнимую часть
void Complex::set_Im(double im)
{
	m_im = im;
}

//Установить Мнимую и действительную часть для комплексного числа
void Complex::set_Complex(double re, double im)
{
	m_re = re;
	m_im = im;
}

//Взять значение действительной части
double Complex::get_Re()
{
	return m_re;
}

//Взять значение мнимой части
double Complex::get_Im()
{
	return m_im;
}

//Оператор сложения
Complex Complex::operator+(const Complex& z)//Передаём ссылку на объект того же класса(второе слагаемое). 
{
	if ((m_im == 0 && m_re != 0) || (z.m_im == 0 && z.m_re != 0)) throw 100;//Если одно из чисел не является комплексным - создаётся исключение
	Complex result;
	result.m_re = this->m_re + z.m_re; //Складываем действительные части
	result.m_im = this->m_im + z.m_im; //Складываем мнимые части

	return result; //Возвращаем результат
}

//Оператор умножения
Complex Complex::operator*(const Complex& z)//Передаём ссылку на объект того же класса(второй множитель). 
{
	if ((m_im == 0 && m_re != 0) || (z.m_im == 0 && z.m_re != 0)) throw 100;//Если одно из чисел не является комплексным - создаём исключение
	Complex result;
	result.m_re = (this->m_re * z.m_re) - (this->m_im * z.m_im);//Высчитываем значение действительной части
	result.m_im = (this->m_re * z.m_im) + (this->m_im * z.m_re);//Высчитываем значение мнимой части

	return result;
}

//Оператор деления
Complex Complex::operator/(const Complex& z)//Передаём ссылку на объект того же класса(второй множитель). 
{
	if (z.m_re == 0 && z.m_im == 0) throw 101;//Если делитель равен 0 создаётся исключение
	if ((m_re != 0 && m_im == 0) || (z.m_re != 0 && z.m_im == 0)) throw 100;//Если одно из чисел не комплексное создаётся исключение
	Complex result;
	result.m_re = ((this->m_re * z.m_re) + (this->m_im * z.m_im)) / ((z.m_re * z.m_re) + (z.m_im * z.m_im));//Высчитываем значение действительной части
	result.m_im = ((z.m_re * this->m_im) - (this->m_re * z.m_im)) / ((z.m_re * z.m_re) + (z.m_im * z.m_im));//Высчитываем значение мнимой части

	return result;
}

Complex Complex::operator=(const Complex& z)
{
	if ((m_re != 0 && m_im == 0) || (z.m_re != 0 && z.m_im == 0)) throw 100;//Если одно из чисел не комплексное создаём исключение
	if (this == &z) return *this;//Проверка на самоприсвоение
	m_re = z.m_re;//Присваиваем действительную часть правого операнда левому
	m_im = z.m_im;//Присваиваем мнимую часть правого операнда левому
	return *this;
}

//Оператор сравнения
bool Complex::operator==(Complex& z)
{
	if ((m_im == 0 && m_re != 0) || (z.m_im == 0 && z.m_re != 0)) throw 100;//Если одно из чисел не комплексное создаём исключение
	if (m_re == z.m_re && m_im == z.m_im) return true;//Сравниваем действительные и мнимые части, если равны возвращаем "True"
	return false;//Если не равны возвращаем "False"
}
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

using namespace std;

class Logger
{
public:
    void info(string info)
    {
        cout <<"[INFO]: " << info << endl;
    }
};

class Complex
{
public:
    double real;
    double imaginary;
    Logger Logger;
    double getArg()
    {
        Logger.info("Вычисляем фи");
        if (real > 0)
        {
            return atan(imaginary / real);
        }
        else if (real < 0)
        {
            if (imaginary >= 0)
            {
                return M_PI + atan(imaginary / real);
            }
            if (imaginary < 0)
            {
                return -M_PI + atan(imaginary / real);
            }
        }
        else
        {
            if (imaginary > 0)
            {
                return M_PI / 2;
            }
            if (imaginary < 0)
            {
                return -M_PI / 2;
            }
        }
        return 0;
    }

    double getAbs()
    {
        Logger.info("Вычисляем модуль");
        return sqrt(real * real + imaginary * imaginary);
    }
	Complex(double r, double i)
    {
        Logger.info("Создаем экземпляр класса");
        real = r;
        imaginary = i;
    }
    Complex()
    {
        Logger.info("Создаем экземпляр класса");
        real = 0;
        imaginary = 0;
    }
    void showNumber()
    {
        Logger.info("Выводим различные формы на экран");
        cout << "Тригонометрическая форма:\nZ = " << getAbs() << " * (cos" << getArg() << " + i*sin" << getArg() << ")\n";
        cout <<  "Показательная форма:\nZ = " << getAbs() << "*e^(i*" << getArg() << ")\n";
    }

    void pow(unsigned n)
    {
        Logger.info("Возводим в степень");
        cout << "Z^" << n << " = " << std::pow(getAbs(),n) << "*(cos" << n*getArg() << " + i*sin" << n*getArg() << ")\n";
    }

    void root(unsigned n)
    {
        Logger.info("Вычисляем корень и находим корни уравнения");
        Complex number;
 
        cout << "Z^" << 1.0/n << " = " << std::pow(getAbs(), 1.0 / n) << "*(cos(" << getArg() / n << "+2*3,14*k*" << 1.0/n << ") + i*sin(" << getArg() / n << "+2*3,14*k*" << 1.0/n << "))\n";
        for (int i = 0; i < n; i++)
        {
            number.real = std::pow(getAbs(), 1.0 / 2) * cos((getArg() + (2 * M_PI * i)) / n);
            number.imaginary = std::pow(getAbs(), 1.0 / 2) * sin((getArg() + (2 * M_PI * i)) / n);
            printf("Z%d = %5.3f + i * %5.3f\n",i, number.real,number.imaginary);
        }
    }

    Complex operator +(const Complex& num2)
    {
        Complex number;
        number.real = this->real + num2.real;
        number.imaginary = this->imaginary + num2.imaginary;
        return number;
    }
    Complex operator -(const Complex& num2)
    {
        Complex number;
        number.real = this->real - num2.real;
        number.imaginary = this->imaginary - num2.imaginary;
        return number;
    }
    Complex operator *(const Complex& num2)
    {
        Complex number;
        number.real = (this->real * num2.real) - (this->imaginary * num2.imaginary);
        number.imaginary = (this->imaginary * num2.real + this->real * num2.imaginary);
        return number;
    }
    Complex operator /(const Complex& num2)
    {
        Complex number;
        number.real = ((this->real * num2.real) + (this->imaginary * num2.imaginary)) / (num2.imaginary * num2.imaginary + num2.real * num2.real);
        number.imaginary = (this->imaginary * num2.real - this->real * num2.imaginary) / (num2.imaginary * num2.imaginary + num2.real * num2.real);
        return number;
    }
};

    ostream& operator<<(ostream& os,const Complex& num)
	{
		os << "Z = " << num.real << " + i * " << num.imaginary;
        return os;
	}
    
    istream& operator >>(istream& is, Complex num)
	{
		is >> num.real >> num.imaginary;
        return is;
	}


int splitLine(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ') return i;
    }
    return 0;
}
void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите вещественную и мнимую части первого комплексного чилса через пробел\n";
    double r,i;
    while (!(cin >> r >> i)) 
    { 
		cin.clear();
		cin.ignore(INT_MAX, '\n');   // ignore invalid input.
        cout << "Неверные данные. Попробуйте еще раз\n";
    }
		Complex number1{r,i};
        cout << "Введите вещественную и мнимую части первого комплексного чилса через пробел\n";
    while (!(cin >> r >> i)) 
    { 
		cin.clear();
		cin.ignore(INT_MAX, '\n');   // ignore invalid input.
		cout << "Неверные данные. Попробуйте еще раз 0\n";
    }
        Complex number2(r,i);
    cout << "Сложение " << number1+number2 << endl;
    cout << "Вычитание " << number1-number2 << endl;
    cout << "Умножение " << number1*number2 << endl;
    cout << "Деление " << number1/number2 << endl;
    number1.showNumber();
    unsigned power;
    cout << "Введите степень числа\n";
    cin >> power;
    number1.pow(power);
    cout << "Введите степень корня\n";
    cin >> power;
    number1.root(power);
}
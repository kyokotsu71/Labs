//площадь треугольника по трем сторонам

#include <iostream>

class Triangle {
private:
    double m_side1 = 0;
    double m_side2 = 0;
    double m_side3 = 0;
    double m_square = 0;

public:
    //Конструктор
    Triangle(double side1, double side2, double side3) {
        std::cout << "Works1" << std::endl;
        m_side1 = side1;
        m_side2 = side2;
        m_side3 = side3;
    }
    //Деструктор
    ~Triangle(){
        std::cout << "Works2" << std::endl;
    }
    //Сеттер
    bool SetSquare(double square) {

        if (square < 0) {
            std::cout << "Некорректные данные" << std::endl;
            return false;
        }
        m_square = square;
    }


    //Геттер
    double GetSquare() {
        double p = (m_side1 + m_side2 + m_side3) / 2;
        m_square = sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
        return m_square;
    }

    void show() {
        //условие существования треугольника
        if ((m_side1 < m_side2 + m_side3) && (m_side2 < m_side1 + m_side3) && (m_side3 < m_side1 + m_side2))
            std::cout << m_square << std::endl;
        else {
            std::cout << "Треугольник не существует" << std::endl;
            
        }
    }
};


int main()
{
    setlocale(0, "ru");
    double side1, side2, side3;
    std::cin >> side1 >> side2 >> side3;

    Triangle triangle1(side1, side2, side3);
    triangle1.GetSquare();
    triangle1.show();
}
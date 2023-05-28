#include <iostream>

class Shape {
protected:
    std::string shapeName;
    unsigned short sideCount;
    unsigned short a, b, c;
    unsigned short A, B, C;
    bool congruence;
public:
    Shape() {
        shapeName = "Фигура";
        congruence = true;
        sideCount = 0;
    }

    std::string Congruence() {
        if (this->congruence) {
            return "Правильная";
        }
        else {
            return "Неправильная";
        }
    }
    virtual void getInfo() {
        std::cout << shapeName << ": " << '\n'
            << Congruence() << '\n'
            << "Количество сторон: " << sideCount;
    }
};

class Triangle :public Shape {
public:
    Triangle() :Shape() {
        shapeName = "Треугольник";
        congruence = true;
        sideCount = 3;
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 70;
    }
    void getInfo() override {
        std::cout << shapeName << ": " << '\n'
            << Congruence() << '\n'
            << "Количество сторон: " << sideCount << '\n'
            << "Стороны: a=" << a
            << " b=" << b
            <<" c=" << c << '\n'
            << "Углы: A=" << A
            << " B=" << B
            << " C=" << C;
    }
};

class RightTriangle : public Triangle {
 public:
    RightTriangle(bool congruence) : Triangle() {
        shapeName = "Прямоугольный треугольник";
        if (!congruence) {
           this->congruence = congruence;
            C = 90;
        }
        else {
            congruence = true;
            B = 40;
            C = 90;
        }
     }
};

class IsoscelesTrainge : public Triangle {
public:
    IsoscelesTrainge() :Triangle() {
        shapeName = "Равнобедренный треугольник";
        congruence = false;
        c = 10;
        C = 50;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() :Triangle() {
        shapeName = "Равносторонний треугольник";
        congruence = true;
        a = b = c = 30;
        A = B = C = 60;
    }
};

class Tetragon : public Shape {
protected:
    unsigned short d;
    unsigned short D;
public:
    Tetragon() :Shape() {
        shapeName = "Четырёхугольник";
        congruence = false;
        sideCount = 4;
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }
    void getInfo() override {
        std::cout << shapeName << ": " << '\n'
            << Congruence() << '\n'
            << "Количество сторон: " << sideCount << '\n'
            << "Стороны: a=" << a
            << " b=" << b
            << " c=" << c
            << " d=" << d << '\n'
            << "Углы: A=" << A
            << " B=" << B
            << " C=" << C
            << " D=" << D;
    }
};

class Rectangle : public Tetragon {
public:
    Rectangle() : Tetragon() {
        shapeName = "Прямоугольник";
        congruence = true;
        a = c = 10;
        b = d = 20;
        A = B = C = D = 90;
    }
};

class Square : public Tetragon {
public:
    Square() :Tetragon() {
        shapeName = "Квадрат";
        congruence = true;
        a = b = c = d = 20;
        A = B = C = D = 90;
    }
};

class Parallelogram :public Tetragon {
public:
    Parallelogram() :Tetragon() {
        shapeName = "Параллелограмм";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
    }
};

class Rhombus : public Tetragon {
public:
    Rhombus() :Tetragon() {
        shapeName = "Ромб";
        a = b = c = d = 30;
        A = C = 30;
        B = D = 40;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    Shape* shape = new Shape;
    shape->getInfo();
    delete shape;

    std::cout << std::endl << std::endl;

    Triangle tr;
    Shape* new_shape = &tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    RightTriangle r_tr_irregular(false);
    new_shape = &r_tr_irregular;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    RightTriangle r_tr(true);
    new_shape = &r_tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    IsoscelesTrainge iso_tr;
    new_shape = &iso_tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    EquilateralTriangle eq_tr;
    new_shape = &eq_tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Tetragon tetra;
    new_shape = &tetra;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Rectangle rect;
    new_shape = &rect;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Square sq;
    new_shape = &sq;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Parallelogram prlgrm;
    new_shape = &prlgrm;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Rhombus rh;
    new_shape = &rh;
    new_shape->getInfo();

}


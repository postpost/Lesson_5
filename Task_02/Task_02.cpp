#include <iostream>

class Shape {
protected:
    unsigned short a, b, c;
    unsigned short A, B, C;
    std::string shapeName;
public:
    virtual void PrintInfo() {
        std::cout << shapeName << ":\n"
            << "Стороны: a=" << a
            << " b=" << b
            << " c=" << c << '\n'
            << "Углы: A=" << A
            << " B=" << B
            << " C=" << C;
    }
};

class Triangle : public Shape {
public:
    Triangle() :Shape() {
       shapeName = "Треугольник";
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 70;
    }
};

class RightTriagle :public Triangle {
public:
    RightTriagle() :Triangle() {
        shapeName = "Прямоугольный треугольник";
        C = 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() :Triangle() {
        shapeName = "Равнобедренный треугольник";
        a = 10;
        b = 20;
        c = 10;
        A = 50;
        B = 60;
        C = 50;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() :Triangle() {
        shapeName = "Равносторонний треугольник";
        a = 30;
        b = 30;
        c = 30;
        A = 60;
        B = 60;
        C = 60;
    }
};

class Tetragon :public Shape {
protected:
    unsigned short d;
    unsigned short D;
public:
    Tetragon() : Shape() {
        shapeName = "Четырёхугольник";
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }
    void PrintInfo() override {
        std::cout << shapeName << ":\n"
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
        c = 10;
        d = 20;
        A = B = C = D = 90;
       
    }
};

class Square : public Tetragon {
public:
    Square() : Tetragon() {
        shapeName = "Квадрат";
        a = b = c = d = 20;
        A = B = C = D = 90;
    }
};

class Parallelogram : public Tetragon {
public:
    Parallelogram() : Tetragon() {
        shapeName = "Параллелограмм";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
    }
};

class Rhombus : public Tetragon {
public:
    Rhombus() : Tetragon() {
        shapeName = "Ромб";
        a = b = c = d = 30;
        A = C = 30;
        B = D = 40;
    }
};

void PrintInfo(Shape* shape) {
    shape->PrintInfo();
}

int main()
{
    setlocale(LC_ALL, "ru");
    Triangle tr;
    Shape* shape = &tr;
    PrintInfo(shape);

    std::cout << std::endl << std:: endl;

    RightTriagle r_tr;
    shape = &r_tr;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    IsoscelesTriangle iso_tr;
    shape = &iso_tr;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    EquilateralTriangle eq_tr;
    shape = &eq_tr;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Tetragon tetra;
    shape = &tetra;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Rectangle rect;
    shape = &rect;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Square sq;
    shape = &sq;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Parallelogram prlgrm;
    shape = &prlgrm;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Rhombus rh;
    shape = &rh;
    PrintInfo(shape);

}

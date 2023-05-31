#include <iostream>

class Shape {
protected:
       std::string shapeName;
public:
    virtual void PrintInfo() {
    }
};

class Triangle : public Shape {
protected:
    unsigned short a, b, c;
    unsigned short A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C){
       shapeName = "Треугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    void PrintInfo() override {
       std::cout << shapeName << ":\n"
                << "Стороны: a=" << a
                << " b=" << b
                << " c=" << c << '\n'
                << "Углы: A=" << A
                << " B=" << B
                << " C=" << C;
        
    }
};

class RightTriagle :public Triangle {
public:
    RightTriagle(int a, int b, int c, int A, int B):Triangle(a, b, c, A, B, C) {
        shapeName = "Прямоугольный треугольник";
        this->C = 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) :Triangle(a, b, c, A, B, C) {
        shapeName = "Равнобедренный треугольник";
        this->a = this->c = a;
        this->b = b;
        this->A = this->C = A;
        this->B = B;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) :Triangle(a, b, c, A, B, C) {
        shapeName = "Равносторонний треугольник";
        this->a = this->b = this->c = a;
        this->A = this->B = this->C = 60;
     }
};

class Tetragon :public Shape {
protected:
    unsigned short a, b, c, d;
    unsigned short A, B, C, D;
public:
    Tetragon(int a, int b, int c, int d, int A, int B, int C, int D){
        shapeName = "Четырёхугольник";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
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
    Rectangle(int a, int b) : Tetragon(a, b, c, d, A, B, C, D) {
        shapeName = "Прямоугольник";
        this->a = this->c = a;
        this->b = this->d = b;
        this->A = this->B = this->C = this->D = 90;
    }
};

class Square : public Tetragon {
public:
    Square(int a) : Tetragon(a, b, c, d, A, B, C, D) {
        shapeName = "Квадрат";
        this->a = this-> b = this-> c = this->d = a;
        this->A = this->B = this->C = this->D = 90;
    }
};

class Parallelogram : public Rectangle {
public:
    Parallelogram(int a, int b, int A, int B) : Rectangle(a, b) {
        shapeName = "Параллелограмм";
        this->A = this->C = A;
        this->B = this->D = B;
    }
};

class Rhombus : public Square {
public:
    Rhombus(int a, int A, int B) : Square(a) {
        shapeName = "Ромб";
        this->A = this->C = A;
        this->B = this->D = B;
    }
};

void PrintInfo(Shape* shape) {
    shape->PrintInfo();
}

int main()
{
    setlocale(LC_ALL, "ru");
    Triangle tr(10, 20, 30, 50, 60, 70);
    Shape* shape = &tr;
    PrintInfo(shape);

    std::cout << std::endl << std:: endl;

    RightTriagle r_tr(10, 20, 30, 50, 60);
    shape = &r_tr;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    IsoscelesTriangle iso_tr(10, 20, 50,60);
    shape = &iso_tr;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    EquilateralTriangle eq_tr(30);
    shape = &eq_tr;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Tetragon tetra(10,20,30,40,50,60,70,80);
    shape = &tetra;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Rectangle rect(10,20);
    shape = &rect;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Square sq(20);
    shape = &sq;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Parallelogram prlgrm(20,30,30,40);
    shape = &prlgrm;
    PrintInfo(shape);

    std::cout << std::endl << std::endl;

    Rhombus rh(30,30,40);
    shape = &rh;
    PrintInfo(shape);

}

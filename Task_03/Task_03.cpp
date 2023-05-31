#include <iostream>

class Shape {
protected:
    std::string shapeName;
    unsigned short sideCount;
    bool congruence;
public:
    Shape() {
        shapeName = "������";
        sideCount = 0;
    }

     bool check_congruence() {
        if (sideCount == 0) {
            return this->congruence= true;
        }
        else return this->congruence= false;
    }

    virtual std::string Congruence() {
        check_congruence();
        if (congruence) {
            return "����������";
        }
        else {
            return "������������";
        }
    }
    virtual void getInfo() {
        std::cout << shapeName << ": " << '\n'
            << Congruence() << '\n'
            << "���������� ������: " << sideCount;
    }
};

class Triangle :public Shape {
protected:
    unsigned short a, b, c;
    unsigned short A, B, C;
    
public:
    Triangle(int a, int b, int c, int A, int B, int C) {
        shapeName = "�����������";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        sideCount = 3;
    }
    virtual bool check_congruence()  {
        if ((A + B +C) == 180 && sideCount == 3) {
            return this->congruence = true;
        }
        else return this->congruence = false;
    }

     std::string Congruence() override {
        check_congruence();
        if (congruence) {
            return "����������";
        }
        else {
            return "������������";
        }
    }
    void getInfo() override {
        std::cout << shapeName << ": " << '\n'
            << Congruence() << '\n'
            << "���������� ������: " << sideCount << '\n'
            << "�������: a=" << a
            << " b=" << b
            <<" c=" << c << '\n'
            << "����: A=" << A
            << " B=" << B
            << " C=" << C;
    }
};

class RightTriangle : public Triangle {
 public:
     RightTriangle(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, C) {
         shapeName = "������������� �����������";
         this->C = 90;
         congruence = Triangle::check_congruence();
     }
     bool check_congruence() override {
         if (congruence == true && C == 90 ) {
             return congruence = true;
         }
         else return congruence = false;
     }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B) :Triangle(a, b, c, A, B, C) {
        shapeName = "�������������� �����������";
        this->a = this->c = a;
        this->b = b;
        this->A = this->C = A;
        this->B = B;
        congruence = Triangle::check_congruence();
    }

    bool check_congruence() override {
        if (congruence == true && a == c && A == C ) {
            return congruence = true;
        }
        else return congruence = false;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) :Triangle(a, b, c, A, B, C) {
        shapeName = "�������������� �����������";
        this->a = this->b = this->c = a;
        this->A = this->B = this->C = 60;
    }
    bool check_congruence() override {
        if ((a == b && b == c) && (A == B && B == C && A == 60)) {
            return congruence = true;
        }
        else return congruence = false;
    }
};

class Tetragon : public Shape {
protected:
    unsigned short a, b, c, d;
    unsigned short A, B, C, D;
public:
    Tetragon(int a, int b, int c, int d, int A, int B, int C, int D) {
        shapeName = "��������������";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        sideCount = 4;
    }

    virtual bool check_congruence() {
        if (sideCount == 4 && ((A + B + C +D) == 360)) {
            return congruence = true;
        }
        else return congruence = false;
    }

    std::string Congruence() override {
        check_congruence();
        if (congruence) {
            return "����������";
        }
        else {
            return "������������";
        }
    }
    void getInfo() override {
        std::cout << shapeName << ": " << '\n'
            << Congruence() << '\n'
            << "���������� ������: " << sideCount << '\n'
            << "�������: a=" << a
            << " b=" << b
            << " c=" << c
            << " d=" << d << '\n'
            << "����: A=" << A
            << " B=" << B
            << " C=" << C
            << " D=" << D;
    }
};

class Rectangle : public Tetragon {
public:
    Rectangle(int a, int b) : Tetragon(a, b, c, d, A, B, C, D) {
        shapeName = "�������������";
        this->a = this->c = a;
        this->b = this->d = b;
        this->A = this->B = this->C = this->D = 90;
       
    }
    bool check_congruence() override {
        if (a ==c && b== d && (A == 90 && B == 90 && C==90 && D== 90)) {
            return congruence = true;
        }
        else return congruence = false;
    }

};

class Square : public Tetragon {
public:
    Square(int a) : Tetragon(a, b, c, d, A, B, C, D) {
        shapeName = "�������";
        this->a = this->b = this->c = this->d = a;
        this->A = this->B = this->C = this->D = 90;
    }

    bool check_congruence() override {
        if (a == b && b == c && c == d && (A == 90 && B == 90 && C == 90 && D == 90)) {
            return congruence = true;
        }
        else return congruence = false;
    }
};

class Parallelogram :public Rectangle {
public:
    Parallelogram(int a, int b, int A, int B) : Rectangle(a, b) {
        shapeName = "��������������";
        this->A = this->C = A;
        this->B = this->D = B;
        congruence = Tetragon::check_congruence();
    }
    bool check_congruence() override {
        if (congruence == true && a == c && b == d && A == C && B == D) {
            return congruence = true;
        }
        else return congruence = false;
    }
};

class Rhombus : public Square {
public:
    Rhombus(int a, int A, int B) : Square(a) {
        shapeName = "����";
        this->A = this->C = A;
        this->B = this->D = B;
    }

    bool check_congruence() override {
        if (a == b == c == d && A == C && B == D) {
            return congruence = true;
        }
        else return congruence = false;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    Shape* shape = new Shape;
    shape->getInfo();
    delete shape;

    std::cout << std::endl << std::endl;

    Triangle tr(10, 20, 30 ,50 ,60 ,70);
    Shape* new_shape = &tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    RightTriangle r_tr_irregular(10,20,30,50,60);
    new_shape = &r_tr_irregular;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    RightTriangle r_tr(10,20,30,50,40);
    new_shape = &r_tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    IsoscelesTriangle iso_tr(10, 20, 50, 60);
    new_shape = &iso_tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    EquilateralTriangle eq_tr (60);
    new_shape = &eq_tr;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Tetragon tetra(10, 20, 30, 40, 50, 60, 70, 80);
    new_shape = &tetra;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Rectangle rect (10, 20);
    new_shape = &rect;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Square sq (20);
    new_shape = &sq;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Parallelogram prlgrm (20, 30, 30, 40);
    new_shape = &prlgrm;
    new_shape->getInfo();

    std::cout << std::endl << std::endl;

    Rhombus rh (30, 30, 40);
    new_shape = &rh;
    new_shape->getInfo();
}


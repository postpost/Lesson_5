#include <iostream>

class Shape 
{
protected:
	unsigned short side_num;
	std::string shape_name;
public:
	Shape() {
		side_num = 0;
		shape_name = "������";
	}
	virtual void PrintInfo() {
		std::cout << shape_name << ": " << side_num << std::endl;
	}
};

class Triangle : public Shape {
public:
	Triangle(): Shape()  {
		side_num = 3;
		shape_name = "�����������";
}
	void PrintInfo() override {
		std::cout << shape_name << ": " << side_num << std::endl;
	}
};

class Tetragon : public Shape {
public:
	Tetragon() : Shape() {
		side_num = 4;
		shape_name = "���������������";
	}
	void PrintInfo() override {
		std::cout << shape_name << ": " << side_num << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "���������� ������:\n";
	Shape shape;
	shape.PrintInfo();

	Triangle triangle;
	triangle.PrintInfo();

	Tetragon tetragon;
	tetragon.PrintInfo();


}


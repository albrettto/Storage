#include <iostream>
#include<time.h>
using namespace std;

class Shape {
public:   
    Shape() {
    }
    virtual void show_parameters() {
        printf("Абстрактная фигура\n");
    }
    ~Shape() {
        printf("Фигура удалилась\n");
    }

};

class Point : public Shape {
public:
    int x, y;
    Point() {
        x = 0;
        y = 0;
        printf("Конструктор Point()\n");
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        printf("Конструктор Point(int x, int y)\n");
    }
    Point(Point &p) {
        x = p.x;
        y = p.y;
        printf("Конструктор Point(Point &p)\n");
    }
    ~Point() {
        printf("Точка удалилась\n");
    }
    virtual void show_parameters() {
        printf("Это точка\n");
        printf("Координаты ( %i , %i )\n", x, y);
    }
    void reset() { // метод сброса координаты точки
        x = 0;
        y = 0;
        printf("Функция reset. (x = %i; y = %i)\n", x, y);
    }
    void move(int a, int b) { // метод для перемещения точки
        x += a;
        y += b;
        printf("Функция move. (x = %i; y = %i)\n", x, y);
    }
};

class Section : public Shape {
protected: // атрибуты доступные только классу Section и его дочерним классам
    Point* p1;
    Point* p2;
public:
    Section() { // конструктор без параметров
        p1 = new Point;
        p2 = new Point;
        printf("Конструктор Section()\n");
    }
    Section(int x1, int y1, int x2, int y2) { // конструктор с параметрами
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
        printf("Конструктор Section(int x1, int y1, int x2, int y2)\n");
    }
    Section(const Section& s) { // конструктор копирования
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
        printf("Конструктор Section(const Section &s).\n");
    }
    ~Section() { // деструктор
        printf("Отрезок удалился.\n");
        delete p1;
        delete p2;
    }
    virtual void show_parameters() {
        printf("Это отрезок\n");
        printf("Начало отрезка ( %i, %i ); Конец отрезка ( %i, %i )\n", p1->x, p1->y, p2->x, p2->y);
    }
    void get_length(const Section& s) { // метод, который находит длину прямой
        int a = (s.p2->x - s.p1->x) * (s.p2->x - s.p1->x);
        int b = (s.p2->y - s.p1->y) * (s.p2->y - s.p1->y);
        double len = sqrt(a + b);
        printf( "Длина отрезка = %f\n" , len);
    }
};

class Storage {
private:
    Shape** objects;
    int size;
public:
    Storage(int size)
    {
        this->size = size;
        objects = new Shape * [size];
    }
    void SetObject(int index, Shape* object) {
        objects[index] = object;
        object->show_parameters();
    }
    Shape GetObject(int index) {
        return *objects[index];
    }
};

int main()
{
    setlocale(0, "");
    srand(time(0));
}

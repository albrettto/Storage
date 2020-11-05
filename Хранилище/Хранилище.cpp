#include <iostream>
#include<time.h>
#include <math.h>
using namespace std;

#define M_PI 3.14159265358979323846

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
        //printf("Конструктор Point()\n");
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        //printf("Конструктор Point(int x, int y)\n");
    }
    Point(Point &p) {
        x = p.x;
        y = p.y;
        //printf("Конструктор Point(Point &p)\n");
    }
    ~Point() {
        printf("Точка удалилась\n");
    }
    virtual void show_parameters() {
        printf("Это точка!  Координаты ( %i , %i )\n", x, y);
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
        //printf("Конструктор Section()\n");
    }
    Section(int x1, int y1, int x2, int y2) { // конструктор с параметрами
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
        //printf("Конструктор Section(int x1, int y1, int x2, int y2)\n");
    }
    Section(const Section &s) { // конструктор копирования
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
        ///printf("Конструктор Section(const Section &s).\n");
    }
    ~Section() { // деструктор
        printf("Отрезок удалился.\n");
        delete p1;
        delete p2;
    }
    virtual void show_parameters() {
        printf("Это отрезок!    Начало отрезка ( %i, %i );  Конец отрезка ( %i, %i )\n", p1->x, p1->y, p2->x, p2->y);
    }
    void get_length(const Section &s) { // метод, который находит длину прямой
        int a = (s.p2->x - s.p1->x) * (s.p2->x - s.p1->x);
        int b = (s.p2->y - s.p1->y) * (s.p2->y - s.p1->y);
        double len = sqrt(a + b);
        printf( "Длина отрезка = %f\n" , len);
    }
};

class Circle: public Shape {
public:
    int x, y, rad;
    Circle() {
        //printf("Конструктор Circle().\n");
    }
    Circle(int x, int y, int rad) {
        this->x = x;
        this->y = y;
        this->rad = rad;
        //printf("Конструктор Circle(int x, int y, int rad).\n");
    }
    Circle(const Circle &c) {
        x = c.x;
        y = c.y;
        rad = c.rad;
        //printf("Конструктор Circle(const Circle &c).\n");
    }
    ~Circle() {
        printf("Круг удалился.\n");
    }
    virtual void show_parameters() {
        printf("Это круг!   Координаты начала( %i , %i );   Радиус( %i )\n", x, y, rad);
    }
    void get_area(const Circle &c) { // метод, который находит длину прямой
        printf("Площадь круга = %f\n", (double) M_PI * (c.rad * c.rad));
    }
};

class Storage {
private:
    Shape** objects;
    int size;
public:
    Storage() {
    }
    Storage(int size)
    {
        this->size = size;
        objects = new Shape * [size];
        for (int i = 0; i < size; ++i)
            objects[i] = NULL;
    }
    void Add_Object(int index, Shape* object) {
        objects[index] = object;
    }
    void Delete_Object(int index) {
        delete objects[index];
        objects[index] = NULL;
        printf("Удалил объект arr[%i]\n", index);
    }
    void Method(int index) {
        objects[index]->show_parameters();
    }
    int Length_Storage() {
        int len = 0;
        for (int i = 0; i < size; ++i)
            if (objects[i] != NULL)
                len++;
        return len;
    }
    void Passing_Objects() {
        for (int i = 0; i < size; ++i)
        {
            cout << i << ") ";
            if (objects[i] != NULL)
                Method(i);
            else
                printf("Здесь пусто!\n");
        }
    }
        Shape GetObject(int index) {
            return *objects[index];
        }
    };

    int main()
    {
        setlocale(0, "");
        srand(time(0));
        Storage arr(7);
        int n = 100;
        /*for (int i = 0; i < n; ++i) {
            int variant = 1 + rand() % 4;
            printf("%i) ", i);
            switch (variant) {
            case 1:
                printf("\n");

                break;
            case 2:
                printf("\n");
                break;
            case 3:
                printf("\n");
                break;
            }
        }*/
        //arr.Add_Object(0, new Circle(1, 3, 5));
        //cout << "\n\n\n";
        //arr.Add_Object(1, new Point(1, 3));
        //cout << "\n\n\n";
        //arr.Add_Object(2, new Circle(1, 3, 5));
        //cout << "\n\n\n";
        //arr.Add_Object(3, new Section(1, 3, 4, 5));
        //cout << "\n\n\n";
        //arr.Delete_Object(2);
        // /*cout << "\n\n\n";
        // arr.Method(2);*/
        //printf("Длина хранилища = %i", arr.Length_Storage());
        //cout << "\n\n\n";
        //arr.Passing_Objects();


    }
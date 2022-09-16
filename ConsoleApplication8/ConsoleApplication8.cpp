#include <iostream>
#include <conio.h>
using namespace std;

class shape {
public:
    virtual void draw() {

    }
};
class Square : public shape {
private:
    int type;
    int longX;
    int x;
    int y;
public:
    Square(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void setTipo(int type) {
        type = type;
    }
    int getTipo() {
        if (type != 1 && type != 2)
        {
            type = 1;
        }
        return type;
    }
    void setLargo(int large) {
        longX = large;
    }
    int getLargo() {
        if (longX < 2)
        {
            longX = 2;
        }
        return longX;
    }
    void draw();
};
void Square::draw() {
    for (int c = 1; c <= y; c++)
    {
        cout << endl;
    }
    for (int c = 1; c <= longX; c++)
    {
        for (int n = 1; n <= x; n++)
        {
            cout << " ";
        }
        for (int i = 1; i <= longX; i++)
        {
            if (getTipo() == 1)
            {
                cout << " *";
            }
            else
            {
                if ((c == 1 || i == 1) || (c == longX) || (i == longX))
                {
                    cout << " *";
                }
                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}

class Triangle : public shape {
private:
    int Type;
    int longX;
    int x;
    int y;
public:
    Triangle(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void setTipo(int type) {
        Type = type;
    }
    int getTipo() {
        if (Type != 1 && Type != 2)
        {
            Type = 1;
        }
        return Type;
    }
    void setLargo(int large) {
        longX = large;
    }
    int getLargo() {
        if (longX < 2)
        {
            longX = 2;
        }
        return longX;
    }
    void draw();
};
void Triangle::draw() {
    for (int c = 0; c < y; c++)
    {
        cout << endl;
    }
    for (int c = 1; c <= longX; c++)
    {
        for (int n = 1; n < x; n++)
        {
            cout << " ";
        }
        for (int i = 0; i < c; i++)
        {
            if (getTipo() == 1)
            {
                cout << " *";
            }
        }
        cout << endl;
    }
}

void canvas(shape* forma) {
    forma->draw();
}

class Programa {
private:
    int opc, x, y;
public:
    Programa() {
        opc = x = y = 0;
    }
    void run() {
        do {
            cout << "selecciona una de las figuras:" << endl;
            cout << "1 Square" << endl;
            cout << "2 Triangle" << endl;
           
            cin >> opc;
            system("cls");

            cout << "Selecciona las coordenadas deseadas de la figura" << endl;
            cout << "X: ";
            cin >> x;
            cout << "Y: ";
            cin >> y;

            int largo;
            cout << "Introduzca la medida del alto: ";
            cin >> largo;

            if (opc == 1)
            {
                cout << "Elige la opcion que desee \n1 Relleno \t 2 Hueco" << endl;
                
                cin >> opc;

                Square c = Square(x, y);
                c.setLargo(largo);
                c.setTipo(opc);
                canvas(&c);
            }
            else if (opc == 2)
            {
                Triangle t = Triangle(x, y);
                t.setLargo(largo);
                t.setTipo(1);
                canvas(&t);
            }

            cout << "\nRepetir programa:";
            cout << "\n1.- Si 2.- No" << endl;
            cin >> opc;
            system("cls");
        } while (opc == 1);
    }
};
int main()
{
    Programa menu;
    menu.run();
    return 0;
}
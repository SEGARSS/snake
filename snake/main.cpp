#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


//--------------------------------------------------------------------------------------------------------------------------------------
int main()
{  
    // Размер игрового окна
    RenderWindow window(VideoMode({ 800, 800 }), "snake");

    ////Прямоугольник
    //RectangleShape rectangle;
    //rectangle.setSize(Vector2f(30, 10)); //Размер
    //rectangle.setOutlineColor(Color(171, 72, 39)); // Цвет
    //rectangle.setOutlineThickness(3); // Толщина линии обводки фигуры
    //rectangle.setFillColor(Color::Red); // Цвет заливки фигуры
    //rectangle.setPosition({ 30, 40 }); // Позиция

    //Хвост
    CircleShape circle1(15);//Фигура (размер)
    circle1.setOutlineColor(Color(171, 72, 39)); // Цвет линии обводки фигуры
    circle1.setOutlineThickness(5); // Толщина линии обводки фигуры
    circle1.setFillColor(Color::Red); // Цвет заливки фигуры
    circle1.setPosition({ 100, 100 }); // Позиция

    //Тело
    CircleShape circle2(15); //Фигура (размер)
    circle2.setOutlineColor(Color(171, 72, 39)); // Цвет линии обводки фигуры
    circle2.setOutlineThickness(5); // Толщина линии обводки фигуры
    circle2.setFillColor(Color::Red); // Цвет заливки фигуры
    circle2.setPosition({ 140, 100 }); // Позиция

    //Голова
    CircleShape circle3(15); //Фигура (размер)
    circle3.setOutlineColor(Color(171, 72, 39)); // Цвет линии обводки фигуры
    circle3.setOutlineThickness(5); // Толщина линии обводки фигуры
    circle3.setFillColor(Color::Red); // Цвет заливки фигуры
    circle3.setPosition({ 180, 100 }); // Позиция

    //Верхний глаз
    CircleShape circle4(3); //Фигура (размер)
    circle4.setOutlineColor(Color::Black); // Цвет линии обводки фигуры
    circle4.setOutlineThickness(1); // Толщина линии обводки фигуры
    circle4.setFillColor(Color::Black); // Цвет заливки фигуры
    circle4.setPosition({ 197, 118 }); // Позиция

    //Нижний глаз
    CircleShape circle5(3); //Фигура (размер)
    circle5.setOutlineColor(Color::Black); // Цвет линии обводки фигуры
    circle5.setOutlineThickness(1); // Толщина линии обводки фигуры
    circle5.setFillColor(Color::Black); // Цвет заливки фигуры
    circle5.setPosition({ 197, 106 }); // Позиция

    //Еда
    CircleShape octagon(80, 8);
    octagon.setRadius(10); //Размер фигуры
    octagon.setOutlineColor(Color::Black); // Цвет линии обводки фигуры
    octagon.setOutlineThickness(1); // Толщина линии обводки фигуры
    octagon.setFillColor(Color::Green); // Цвет заливки фигуры
    octagon.setPosition({ 220, 100 }); // Позиция


    // Старт игрового окна
    while (window.isOpen())
    {
        
        // Process events
        while (const optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<Event::Closed>())
                window.close();
        }


        // Очистка окна.
        window.clear(Color::Cyan);
        
        //Рисуем фигуры с заданными параметрами.
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(circle4);
        window.draw(circle5);
        window.draw(octagon);

        // Update the window
        window.display();
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
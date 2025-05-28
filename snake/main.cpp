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

    CircleShape circle1;
    circle1.setRadius(15); //Размер фигуры
    circle1.setOutlineColor(Color(171, 72, 39)); // Цвет линии обводки фигуры
    circle1.setOutlineThickness(5); // Толщина линии обводки фигуры
    circle1.setFillColor(Color::Red); // Цвет заливки фигуры
    circle1.setPosition({ 100, 100 }); // Позиция

    CircleShape circle2;
    circle2.setRadius(15); //Размер фигуры
    circle2.setOutlineColor(Color(171, 72, 39)); // Цвет линии обводки фигуры
    circle2.setOutlineThickness(5); // Толщина линии обводки фигуры
    circle2.setFillColor(Color::Red); // Цвет заливки фигуры
    circle2.setPosition({ 140, 100 }); // Позиция

    CircleShape circle3;
    circle3.setRadius(15); //Размер фигуры
    circle3.setOutlineColor(Color(171, 72, 39)); // Цвет линии обводки фигуры
    circle3.setOutlineThickness(5); // Толщина линии обводки фигуры
    circle3.setFillColor(Color::Red); // Цвет заливки фигуры
    circle3.setPosition({ 180, 100 }); // Позиция

    CircleShape circle4;
    circle4.setRadius(3); //Размер фигуры
    circle4.setOutlineColor(Color::Black); // Цвет линии обводки фигуры
    circle4.setOutlineThickness(1); // Толщина линии обводки фигуры
    circle4.setFillColor(Color::Black); // Цвет заливки фигуры
    circle4.setPosition({ 197, 118 }); // Позиция

    CircleShape circle5;
    circle5.setRadius(3); //Размер фигуры
    circle5.setOutlineColor(Color::Black); // Цвет линии обводки фигуры
    circle5.setOutlineThickness(1); // Толщина линии обводки фигуры
    circle5.setFillColor(Color::Black); // Цвет заливки фигуры
    circle5.setPosition({ 197, 106 }); // Позиция

    CircleShape circle6;
    circle6.setRadius(3); //Размер фигуры
    circle6.setOrigin({ 50, 50 });
    circle6.setOutlineColor(Color::Black); // Цвет линии обводки фигуры
    circle6.setOutlineThickness(1); // Толщина линии обводки фигуры
    /*circle6.setRotation({ 10 });*/
    circle6.setFillColor(Color::Green); // Цвет заливки фигуры
    circle6.setPosition({ 220, 100 }); // Позиция

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
        //window.draw(rectangle); 
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(circle4);
        window.draw(circle5);
        window.draw(circle6);

        // Update the window
        window.display();
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
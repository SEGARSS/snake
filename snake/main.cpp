#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


//--------------------------------------------------------------------------------------------------------------------------------------
int main()
{  
    // Размер игрового окна
    RenderWindow window(VideoMode({ 700, 600 }), "snake"); // Размер игрового окна, и текст игрового окна

    // Фоновая картинка игрового поля
    const Texture texture("D:\\Obuchenie\\snake\\snake\\decoration\\Images\\pole.jpg"); // Как сократить путь к файлу?
    Sprite sprite(texture);

    // Загрузка музыки
    Music music("D:\\Obuchenie\\snake\\snake\\decoration\\music\\snake.ogg");
    music.play();

    //Вариант змейки с картинки
    
    //Змея (голова)
    Image snake;
    snake.loadFromFile("D:\\Obuchenie\\snake\\snake\\decoration\\Images\\snake\\golova.png");

    Texture snaketexture(snake);

    Sprite spritesnake(snaketexture);
    spritesnake.setPosition({ 167, 100 });
    spritesnake.setScale({ 0.8, 0.8 });

    //Вариант змейки с фигур

    /*
    //Прямоугольник
    RectangleShape rectangle;
    rectangle.setSize(Vector2f(30, 10));           //Размер
    rectangle.setOutlineColor(Color(171, 72, 39));//Цвет
    rectangle.setOutlineThickness(3);            //Толщина линии обводки фигуры
    rectangle.setFillColor(Color::Red);         //Цвет заливки фигуры
    rectangle.setPosition({ 30, 40 });         //Позиция
    */

    /*
    //Хвост
    CircleShape circle1(12);                     //Фигура (размер)
    circle1.setOutlineColor(Color(171, 72, 39));// Цвет линии обводки фигуры
    circle1.setOutlineThickness(5);            // Толщина линии обводки фигуры
    circle1.setFillColor(Color::Red);         // Цвет заливки фигуры
    circle1.setPosition({ 100, 100 });       // Позиция
    //Тело
    CircleShape circle2(12);                     //Фигура (размер)
    circle2.setOutlineColor(Color(171, 72, 39));// Цвет линии обводки фигуры
    circle2.setOutlineThickness(5);            // Толщина линии обводки фигуры
    circle2.setFillColor(Color::Red);         // Цвет заливки фигуры
    circle2.setPosition({ 133, 100 });       // Позиция
    //Голова
    CircleShape circle3(12);                     //Фигура (размер)
    circle3.setOutlineColor(Color(171, 72, 39));// Цвет линии обводки фигуры
    circle3.setOutlineThickness(5);            // Толщина линии обводки фигуры
    circle3.setFillColor(Color::Red);         // Цвет заливки фигуры
    circle3.setPosition({ 167, 100 });       // Позиция

    //Верхний глаз
    CircleShape circle4(2);                //Фигура (размер)
    circle4.setOutlineColor(Color::Black);// Цвет линии обводки фигуры
    circle4.setOutlineThickness(1);      // Толщина линии обводки фигуры
    circle4.setFillColor(Color::Black); // Цвет заливки фигуры
    circle4.setPosition({ 180, 115 }); // Позиция
    //Нижний глаз
    CircleShape circle5(2);                //Фигура (размер)
    circle5.setOutlineColor(Color::Black);// Цвет линии обводки фигуры
    circle5.setOutlineThickness(1);      // Толщина линии обводки фигуры
    circle5.setFillColor(Color::Black); // Цвет заливки фигуры
    circle5.setPosition({ 180, 105 }); // Позиция

    //Еда
    CircleShape octagon(10, 4);               //Фигура (размер)              
    octagon.setOutlineColor(Color::Black);   // Цвет линии обводки фигуры
    octagon.setOutlineThickness(1);         // Толщина линии обводки фигуры
    octagon.setFillColor(Color(17,17,253));// Цвет заливки фигуры
    octagon.setPosition({ 240, 106 });    // Позиция
    */


    // Начать игровой цикл
    while (window.isOpen())
    {
        
        // События процесса
        while (const optional event = window.pollEvent())
        {
            // Закрыть окно: выход
            if (event->is<Event::Closed>())
                window.close();
        }


        // Очистка окна.
        window.clear(Color::Cyan);
        
        //Рисуем фигуры с заданными параметрами.
        window.draw(sprite);
        window.draw(spritesnake);

        //window.draw(circle1);
        //window.draw(circle2);
        //window.draw(circle3);
        //window.draw(circle4);
        //window.draw(circle5);
        //
        //window.draw(octagon);


        // Обновить окно
        window.display();
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
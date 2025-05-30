#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <chrono>

using namespace sf;
using namespace std;

const int SIZE_CELL = 50; // Размер одной ячейки в пикселях
const Color BODY_COLOR(171, 72, 39); // Цвет линии обводки фигуры

//--------------------------------------------------------------------------------------------------------------------------------------
int main()
{  
    // Размер игрового окна
    RenderWindow window(VideoMode({ 700, 600 }), "snake"); // Размер игрового окна, и текст игрового окна

    // 12 x 10
    // 50 px
    // Фоновая картинка игрового поля
    const Texture texture("decoration\\Images\\pole.jpg"); // Как сократить путь к файлу?
    Sprite backgroud(texture);

    // Загрузка музыки
    Music music("decoration\\music\\snake.ogg");
    music.play();

    //--------------------------------------------------------------------------------------------------------
    
    //Вариант змейки с картинки
    
    //Змея (голова)
    //Image snake;
    //snake.loadFromFile("decoration\\Images\\snake\\golova.png");

    //Texture snaketexture(snake);

    //Sprite spritesnake(snaketexture);
    //spritesnake.setPosition({ 167, 100 });
    //spritesnake.setScale({ 0.8, 0.8 });

    //--------------------------------------------------------------------------------------------------------

    //Вариант змейки с фигур

    vector<CircleShape> snakeBody;

    CircleShape bodyTile(12); //шаблон
    bodyTile.setRadius(12);
    bodyTile.setOutlineColor(BODY_COLOR); // Цвет линии обводки фигуры
    bodyTile.setOutlineThickness(5);     // Толщина линии обводки фигуры
    bodyTile.setFillColor(Color::Red);  // Цвет заливки фигуры

    bodyTile.setPosition({ 1 * SIZE_CELL + 12, 1 * SIZE_CELL + 12 });
    snakeBody.push_back(bodyTile); //копия идет в вектор
    bodyTile.setPosition({ 2 * SIZE_CELL + 12, 1 * SIZE_CELL + 12 });
    snakeBody.push_back(bodyTile);
    bodyTile.setPosition({ 3 * SIZE_CELL + 12, 1 * SIZE_CELL + 12 });
    snakeBody.push_back(bodyTile);

    //snakeBody.push_back(CircleShape());
    //snakeBody[0].setRadius(12);
    //snakeBody[0].setOutlineColor(BODY_COLOR);// Цвет линии обводки фигуры
    //snakeBody[0].setOutlineThickness(5);            // Толщина линии обводки фигуры
    //snakeBody[0].setFillColor(Color::Red);         // Цвет заливки фигуры
    //snakeBody[0].setPosition({ 1 * SIZE_CELL + 12, 1 * SIZE_CELL + 12 });       // Позиция

    

    //-----------------------------------------------------------------------------------------------------------

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

    //Еда
    CircleShape octagon(10, 4);               //Фигура (размер)               
    octagon.setOutlineColor(Color::Black);   // Цвет линии обводки фигуры
    octagon.setOutlineThickness(1);         // Толщина линии обводки фигуры
    octagon.setFillColor(Color(17,17,253));// Цвет заливки фигуры
    octagon.setPosition({ 240, 106 });    // Позиция
    */

    //-----------------------------------------------------------------------------------------------------------

	chrono::milliseconds tick(50);

	Clock clock;

	// Начать игровой цикл
	while (window.isOpen())
	{

		// События процесса
		while (const std::optional event = window.pollEvent())
		{
			// Закрыть окно: выход
			if (event->is<Event::Closed>())
				window.close();
		}

		if (clock.getElapsedTime() > Time(tick)) 
        {
			clock.restart();

			// Очистка окна.
			window.clear(Color::Cyan);

			//Рисуем фигуры с заданными параметрами.
			window.draw(backgroud);

			for (int i = 0; i < snakeBody.size(); ++i)
			{
				CircleShape& body = snakeBody[i];
				Vector2f pos = body.getPosition();
				body.setPosition({ pos.x + 1, pos.y });
			}





			window.draw(snakeBody[snakeBody.size() - 1]);
			Vector2f pos = snakeBody[snakeBody.size() - 1].getPosition();

			//Верхний глаз
			CircleShape circle4(2);                //Фигура (размер)
			circle4.setOutlineColor(Color::Black);// Цвет линии обводки фигуры
			circle4.setOutlineThickness(1);      // Толщина линии обводки фигуры
			circle4.setFillColor(Color::Black); // Цвет заливки фигуры
			circle4.setPosition({ pos.x + 13 , pos.y + 15 }); // Позиция
			//Нижний глаз
			CircleShape circle5(2);                //Фигура (размер)
			circle5.setOutlineColor(Color::Black);// Цвет линии обводки фигуры
			circle5.setOutlineThickness(1);      // Толщина линии обводки фигуры
			circle5.setFillColor(Color::Black); // Цвет заливки фигуры
			circle5.setPosition({ pos.x + 13 , pos.y + 5 }); // Позиция

			window.draw(circle4);
			window.draw(circle5);

			for (int i = 0; i < snakeBody.size() - 1; ++i)
			{
				window.draw(snakeBody[i]);
			}

			// Обновить окно
			window.display();
		}
	}

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
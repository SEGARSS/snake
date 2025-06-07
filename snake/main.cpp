#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <chrono>

using namespace sf;
using namespace std;

const int SIZE_CELL = 50; // Размер одной ячейки в пикселях
const Color BODY_COLOR(171, 72, 39); // Цвет линии обводки фигуры


//помогает не дублировать код
//-------------------------------------------------------------------------------------------------------
CircleShape getSnakeBodyTile(float x, float y)//функция генерирует кружок, и устанавливает все необходимые параметры
{
    CircleShape body;

    body.setRadius(12);               // Радиус
    body.setOutlineColor(BODY_COLOR);// Цвет линии обводки фигуры
    body.setOutlineThickness(5);    // Толщина линии обводки фигуры
    body.setFillColor(Color::Red); // Цвет заливки фигуры
    body.setPosition({ x * SIZE_CELL + 12, y * SIZE_CELL + 12 });// Позиция // +12 потому что это радиус нашего кружка    

    return body;
}
//-------------------------------------------------------------------------------------------------------
CircleShape getSnakeGlasisTile(float x, float y)
{
    CircleShape glasis;

    glasis.setRadius(2);                 //Фигура (размер)
    glasis.setOutlineColor(Color::Black);// Цвет линии обводки фигуры
    glasis.setOutlineThickness(1);      // Толщина линии обводки фигуры
    glasis.setFillColor(Color::Black); // Цвет заливки фигуры
    glasis.setPosition({ x + SIZE_CELL + 2, y + SIZE_CELL + 2 }); // Позиция

    return glasis;
}
//-------------------------------------------------------------------------------------------------------
enum class Direction//перечисление, хранит варианты направления движения
{
    up,
    down,
    left,
    right
};
//-------------------------------------------------------------------------------------------------------
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
    /*
    Music music("decoration\\music\\snake.ogg");
    music.play();
    */

    //--------------------------------------------------------------------------------------------------------
    
    //Вариант змейки с картинки.
    
    //Змея (голова)
    //Image snake;
    //snake.loadFromFile("decoration\\Images\\snake\\golova.png");

    //Texture snaketexture(snake);

    //Sprite spritesnake(snaketexture);
    //spritesnake.setPosition({ 167, 100 });
    //spritesnake.setScale({ 0.8, 0.8 });

    //--------------------------------------------------------------------------------------------------------

    //Вариант змейки с фигур

    vector<CircleShape> snakeBody; //Змея вся
    snakeBody.push_back(getSnakeBodyTile(1, 1));// Кординаты 1 - это по Х, следом 1 по Y.
    snakeBody.push_back(getSnakeBodyTile(2, 1));
    snakeBody.push_back(getSnakeBodyTile(3, 1));

    CircleShape glaz_left;  //Глаз левый
    CircleShape glaz_right;//Глаз правый
    glaz_left = getSnakeGlasisTile(122, 24);
    glaz_right = getSnakeGlasisTile(122, 14);

    CircleShape food; // Будущая еда
    food = getSnakeBodyTile(6, 5);

    Direction direction = Direction::right; // Начальная позиция змеи    

    //----------------------------------------------------------------------------------------------------------

	chrono::milliseconds tick(1000);

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

            //Нажатие клавишь
            if (event->is<Event::KeyPressed>())
            {
                if (Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    direction = Direction::down;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    direction = Direction::right;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    direction = Direction::left;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    direction = Direction::up;
                }
            }
            
		}

        if (clock.getElapsedTime() > Time(tick))
        {
            clock.restart();

            //цикл двигает все кроме головы
            // snakeBody.size() - 1 потому что логика на голову змеи у нас другая
            for (int i = 0; i < snakeBody.size() - 1; i++)
            {
                //считали позицию следующего кружка в pos
                Vector2f pos = snakeBody[i + 1].getPosition();//Здесь запросили позицию следующу
                snakeBody[i].setPosition(pos); //Сюда её положили (указали)
                snakeBody[i].setPosition(pos); // Попробовать закоментить
            }                    

            //логика движения головы змеи
            //считали позицию головы змеи в pos
            //голова змеи это последний элемент вектора
            //индекс snakeBody.size() - 1
            Vector2f pos = snakeBody[snakeBody.size() - 1].getPosition();
            //установили позицию текущего кружка увеличив х на 50
            if (direction == Direction::up)
            {
                pos.y -= SIZE_CELL;
            }            
            if (direction == Direction::down) 
            {
                pos.y += SIZE_CELL;
            }
            if (direction == Direction::left)
            {
                pos.x -= SIZE_CELL;
            }
            if (direction == Direction::right)
            {
                pos.x += SIZE_CELL;
            }
            snakeBody[snakeBody.size() - 1].setPosition(pos);            
        }

        // Очистка окна.
        window.clear(Color::Cyan);

        //Рисуем фигуры с заданными параметрами.
        window.draw(backgroud);
        
        //Рисуем тело змеи
        for (int i = 0; i < snakeBody.size(); ++i) 
        {
            window.draw(snakeBody[i]);
        }

        //Привязка глаз к голове
        Vector2f pos = snakeBody[snakeBody.size() - 1].getPosition();
        //Верхний глаз               
        glaz_left.setPosition({ pos.x + 13 , pos.y + 15 }); // Позиция
        window.draw(glaz_left);
        //Нижний глаз
        glaz_right.setPosition({ pos.x + 13 , pos.y + 5 }); // Позиция
        window.draw(glaz_right);
        
        window.draw(food);

        // Обновить окно
        window.display();

	}

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
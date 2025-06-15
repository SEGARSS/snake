#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <random>

#include <vector>
#include <iostream>
#include <chrono>

using namespace sf;
using namespace std;

const float SIZE_CELL = 50; // Размер одной ячейки в пикселях
const Color BODY_COLOR(171, 72, 39); // Цвет линии обводки фигуры
const Color FOOD_COLOR(0, 177, 0); // Цвет линии обводки фигуры

//еда
//-------------------------------------------------------------------------------------------------------
CircleShape getSnakeFoodTile(float x, float y)//функция генерирует кружок, и устанавливает все необходимые параметры
{
    CircleShape body;

    body.setRadius(12);               // Радиус
    body.setOutlineColor(FOOD_COLOR);// Цвет линии обводки фигуры
    body.setOutlineThickness(5);    // Толщина линии обводки фигуры
    body.setFillColor(Color::Green); // Цвет заливки фигуры
    body.setPosition({ x * SIZE_CELL + 12, y * SIZE_CELL + 12 });// Позиция // +12 потому что это радиус нашего кружка    

    return body;
}
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
    glasis.setPosition({ x * SIZE_CELL + 2, y * SIZE_CELL + 2 }); // Позиция

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
    // для генерации случайных чисел
    //пока не заморачивайся, просто прими как факт, что это нужные строки
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 10);// сам генератора случайного числа (генерирует число от 1 до 10)
    //используем для генерации случайных координат для еды
    
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

    CircleShape glaz_left = getSnakeGlasisTile(122, 24);;  //Глаз левый
    CircleShape glaz_right = getSnakeGlasisTile(122, 14);;//Глаз правый

    CircleShape food = getSnakeFoodTile(6, 5); // Будущая еда

    Direction direction = Direction::right; // Начальная позиция змеи    

    int ochki = 0;
    // ДОБАВИЛИ условная переменная для отслеживания конца игры
    bool gameEnd = false;

    //----------------------------------------------------------------------------------------------------------

	chrono::milliseconds tick(500);

	Clock clock;

    //Надпись с очками игрока
    const Font font("ARIAL.TTF");

    Text text(font, L"Очки 0"); //L - чтоб были русские буквы вместо крякозябры.
    text.setCharacterSize(30); //Размер текста
    text.setStyle(Text::Bold);//Стиль текста
    text.setFillColor(Color::Red);//Цвет текста

    
    Text gameOver(font, L"gameOver"); //L - чтоб были русские буквы вместо крякозябры.
    gameOver.setCharacterSize(60); //Размер текста
    gameOver.setStyle(Text::Bold);//Стиль текста
    gameOver.setFillColor(Color::Black);//Цвет текста
    gameOver.setPosition(sf::Vector2f(250.0f - 60, 300.0f - 60));

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
                    if (direction != Direction::up)
                    {
                        direction = Direction::down;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    if (direction != Direction::left)
                    {
                        direction = Direction::right;
                    }                    
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    if (direction != Direction::right)
                    {
                        direction = Direction::left;
                    }                    
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    if (direction != Direction::down)
                    {
                        direction = Direction::up;
                    }
                }
            }
            
		}

        if (clock.getElapsedTime() > Time(tick) && gameEnd == false)
        {
            clock.restart();

            //цикл двигает все кроме головы
            // snakeBody.size() - 1 потому что логика на голову змеи у нас другая
            for (int i = 0; i < snakeBody.size() - 1; i++)
            {
                //считали позицию следующего кружка в pos
                Vector2f pos = snakeBody[i + 1].getPosition();//Здесь запросили позицию следующу
                snakeBody[i].setPosition(pos); //Сюда её положили (указали)
            }                    

            //логика движения головы змеи
            //считали позицию головы змеи в pos
            //голова змеи это последний элемент вектора
            //индекс snakeBody.size() - 1
            // snakeBody[snakeBody.size() - 1] - равнозначно - snakeBody.back()
            Vector2f pos = snakeBody.back().getPosition();
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
            snakeBody.back().setPosition(pos);
        }

        //Проверка, что позиция еды совподает с позицией головы
        if (food.getPosition() == snakeBody.back().getPosition())
        {
            //gameEnd = true;                
            
            ochki++; //увеличиваем очки
            //перемещаем еду на случайную пазицию
            //distrib(gen) - генерирует случайное число
            food.setPosition({ (distrib(gen) * SIZE_CELL) + 12, (distrib(gen) * SIZE_CELL) + 12});

            // ДОБАВИЛИ теперь змея растет когда "ест" еду, т.е. сталкивается с едой
            // новые функции вектора
            /* 
            front() - дает доступ к самому первому элементу в векторе(работает так же как back(), 
            который дает доступ к последнему элементу вектора)
            insert(позиция, значение) - вставляет значение на позицию в векторе, 
            в примере вставляется в начало вектора значение первого элемента вектора)
            begin() - итератор (указатель) на первый элемент вектора, 
            нужен т.к. insert принимает именно итератор, куда нужно вставить элемент
            1 вариант добавления - дублируем первый элемент, из-за чего у нас две последних секции наслаиваются, 
            пока не сдвинется змейка.
            */
            snakeBody.insert(snakeBody.begin(), snakeBody.front());
            //2 вариант - сохранить позицию первой секции до ее передвижения в starPoz, добавить новую секцию в вектор с позицией 0 0, а потом установить этой секции позицию starPoz
            //snakeBody.insert(snakeBody.begin(), getSnakeBodyTile(0, 0));
            //snakeBody.front().setPosition(starPoz);
            //добавляли сначала для отладки, чтобы понять как добавляются элементы
            //тут получили багу - змейка телепортируется в начало поля, м б потом используем как игровой элемент
            //snakeBody.push_back(getSnakeBodyTile(1,1));
        }

        // Очистка окна.
        window.clear(Color::Cyan);

        //Рисуем фигуры с заданными параметрами.
        window.draw(backgroud);
               

        //Рисуем вывод очков на доске
        text.setString(L"очки " + std::to_string(ochki));//Конвертируем int в string.(to_string)
        window.draw(text);


        
        //Рисуем тело змеи
        for (int i = 0; i < snakeBody.size(); ++i) 
        {
            window.draw(snakeBody[i]);
        }



        //Привязка глаз к голове
        Vector2f pos = snakeBody.back().getPosition();
        //Верхний глаз               
        glaz_left.setPosition({ pos.x + 13 , pos.y + 15 }); // Позиция
        window.draw(glaz_left);
        //Нижний глаз
        glaz_right.setPosition({ pos.x + 13 , pos.y + 5 }); // Позиция
        window.draw(glaz_right);
        
        window.draw(food);

        if (gameEnd)
        {
            window.draw(gameOver);
        }

        // Обновить окно
        window.display();
	}
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------
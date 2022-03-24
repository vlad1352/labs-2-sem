#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Header.h"
#include "Header1.h"
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;


class Player
{
private: float x, y;

public:
	float  w, h, dx, dy, speed = 0;
	int dir = 0, playerScore, health;
	bool life;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H)
	{
		health = 100, playerScore = 0;
		cout << playerScore;
		life = true;
		File = F;
		w = W; h = H;
		image.loadFromFile("images/" + File);
		image.createMaskFromColor(Color(255, 255, 255));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));


	}

	//движение и жизнь
	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed;  dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}
		x += dx * time;
		y += dy * time;
		speed = 0;
		sprite.setPosition(x, y);
		interectionWithMap();
		if (health <= 0)
		{
			life = false;
			sprite.setColor(Color::Color(128, 106, 89));


		}
	}

	//взаимодействие с картой
	void interectionWithMap()
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if ((TileMap[i][j] == '0'))
				{
					if (dy > 0)  y = i * 32 - h;
					if (dy < 0)  y = i * 32 + 32;
					if (dx > 0)  x = j * 32 - w;
					if (dx < 0)  x = j * 32 + 32;
				}
				if (TileMap[i][j] == 's')
				{

					health -= 5;
					TileMap[i][j] = ' ';
				}
				if (TileMap[i][j] == 'f')
				{

					health += 20;
					TileMap[i][j] = ' ';
				}
				if (TileMap[i][j] == 'k')
				{
					playerScore += 1;
					TileMap[i][j] = ' ';
				}
				if ((TileMap[i][j] == 'a') && (playerScore == 1))
				{
					playerScore += 1;
					life = false;
					TileMap[i][j] = ' ';
					TileMap[i][j + 1] = ' ';
				}
			}
	}

	//текущие положение игрока
	float getplayercoordinateX()
	{
		return x;
	}
	float getplayercoordinateY()
	{
		return y;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");

	RenderWindow window(VideoMode(1000, 500), "Stairas 2D 1.4");
	view.reset(sf::FloatRect(0, 0, 1000, 500));//размер "вида" камеры при создании объекта вида камеры. 

	//shrift
	Font font;
	Text text("", font, 40), text1("", font, 40);
	text.setStyle(Text::Bold | Text::Underlined);

	Image map_image;
	map_image.loadFromFile("images/map1.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Music music;
	music.openFromFile("music/los8bit.ogg");
	music.play();

	Clock clock, gameClock, gameTimeClock;
	int gameTime = 0;

	float CurrentFrame = 0;//хранит текущий кадр

	Player night("night1.png", 200, 200, 128.0, 128.0);

	while (window.isOpen())
	{
		if (night.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();


		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 600; //скорость игры


		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}
		//управление
		if (night.life) {
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				night.dir = 1; night.speed = 0.1;
				CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до 5 суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
				if (CurrentFrame > 5) CurrentFrame -= 5;
				night.sprite.setTextureRect(IntRect(128 * int(CurrentFrame), 384, 128, 128));
				getplayercoordinateforview(night.getplayercoordinateX(), night.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой

			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				night.dir = 0; night.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 5) CurrentFrame -= 5;
				night.sprite.setTextureRect(IntRect(128 * int(CurrentFrame), 256, 128, 128));
				getplayercoordinateforview(night.getplayercoordinateX(), night.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой

			}
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				night.dir = 3; night.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 6) CurrentFrame -= 6;
				night.sprite.setTextureRect(IntRect(128 * int(CurrentFrame), 128, 128, 128));
				getplayercoordinateforview(night.getplayercoordinateX(), night.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой

			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				night.dir = 2; night.speed = 0.1;
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 6) CurrentFrame -= 6;
				night.sprite.setTextureRect(IntRect(128 * int(CurrentFrame), 0, 128, 128));
				getplayercoordinateforview(night.getplayercoordinateX(), night.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой

			}
		}

		window.setView(view);
		window.clear(Color(128, 106, 89));

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
				if ((TileMap[i][j] == 'k')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
				if ((TileMap[i][j] == 'a')) s_map.setTextureRect(IntRect(194, 0, 32, 32));
				if ((TileMap[i][j] == 'A')) s_map.setTextureRect(IntRect(226, 0, 32, 32));

				s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

				window.draw(s_map);
			}

		night.update(time);


		if (night.life == true)
		{
			gameTime = gameTimeClock.getElapsedTime().asSeconds();
		}
		else
		{
			music.pause();
			if ((night.life == false) && (night.playerScore == 2))
			{
				text.setString("You Win");
				text.setPosition(view.getCenter().x - 150, view.getCenter().y - 50);
			}
			else
			{
				text.setString("Death");
				text.setPosition(view.getCenter().x - 50, view.getCenter().y - 50);
			}
		}

		ostringstream playerHealthString, gameTimeString;
		gameTimeString << gameTime;
		playerHealthString << night.health;
		text1.setString("Health: " + playerHealthString.str() + "\nTime: " + gameTimeString.str());
		text1.setPosition(view.getCenter().x - 500, view.getCenter().y - 250);

		window.draw(night.sprite);
		window.draw(text);
		window.draw(text1);
		window.display();
	}

	return 0;
}
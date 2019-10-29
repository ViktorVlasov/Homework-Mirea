#include <SFML/Graphics.hpp>

using namespace sf;


int main()
{

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Главное окно
	RenderWindow window(VideoMode(600, 400), "Flag!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// Тогда закрываем его
				window.close();
		}

		// Цвет фона
		window.clear(Color(0, 0, 255, 0));

		// Горизонтальная белая линия
		RectangleShape whitehoriz(Vector2f(260.f, 40.f));
		whitehoriz.setFillColor(Color(255, 255, 255));
		whitehoriz.move(0, 55);
		window.draw(whitehoriz);

		// Вертикальная белая линия
		RectangleShape whitevertical(Vector2f(40.f, 150.f));
		whitevertical.setFillColor(Color(255, 255, 255));
		whitevertical.move(110, 0);
		window.draw(whitevertical);


		/*Главная белая диагональ*/
		ConvexShape convex;
		convex.setPointCount(6);
		// Устанавливаем координаты вершин
		convex.setPoint(0, Vector2f(0.f, 0.f));
		convex.setPoint(1, Vector2f(30.f, 0.f));
		convex.setPoint(2, Vector2f(260.f, 130.f));
		convex.setPoint(3, Vector2f(260.f, 150.f));
		convex.setPoint(4, Vector2f(230.f, 150.f));
		convex.setPoint(5, Vector2f(0.f, 20.f));
		// Цвет
		convex.setFillColor(Color::White);
		window.draw(convex);
		

		/* Побочная белая диагональ */
		ConvexShape convexR; 
        	convexR.setPointCount(6); // Вершины
		// Устанавливаем координаты вершин
		convexR.setPoint(0, Vector2f(260.f, 0.f));
		convexR.setPoint(1, Vector2f(260.f, 20.f));
		convexR.setPoint(2, Vector2f(30.f, 150.f));
		convexR.setPoint(3, Vector2f(0.f, 150.f));
		convexR.setPoint(4, Vector2f(0.f, 130.f));
		convexR.setPoint(5, Vector2f(230.f, 0.f));
		// Цвет
		convexR.setFillColor(Color::White); 
		window.draw(convexR); // Отрисовываем

		// Вертикальная красная линия
		RectangleShape redvertical(Vector2f(20.f, 150.f));
		redvertical.setFillColor(Color(255, 0, 0));
		redvertical.move(120, 0);
		window.draw(redvertical);

		// Горизонтальная красная линия
		RectangleShape redhoriz(Vector2f(260.f, 20.f));
		redhoriz.setFillColor(Color(255, 0, 0));
		redhoriz.move(0, 65);
		window.draw(redhoriz);


		/*Наклонная красная верхний левый угол.*/
		ConvexShape RedMain1; // 260 150

		RedMain1.setPointCount(4);
		// Устанавливаем координаты вершин
		RedMain1.setPoint(0, Vector2f(0.f, 0.f));
		RedMain1.setPoint(1, Vector2f(95.f, 55.f));
		RedMain1.setPoint(2, Vector2f(75.f, 55.f));
		RedMain1.setPoint(3, Vector2f(0.f, 13.f));
		// Цвет
		RedMain1.setFillColor(Color::Red);
		window.draw(RedMain1);


		/*Наклонная красная нижний правый угол.*/
		ConvexShape RedMain2; // 260 150

		RedMain2.setPointCount(4);
		// Устанавливаем координаты вершин
		RedMain2.setPoint(0, Vector2f(260.f, 150.f));
		RedMain2.setPoint(1, Vector2f(260.f, 137.f));
		RedMain2.setPoint(2, Vector2f(185.f, 95.f));
		RedMain2.setPoint(3, Vector2f(165.f, 95.f));
		// Цвет
		RedMain2.setFillColor(Color::Red);
		window.draw(RedMain2);


		/*Наклонная красная нижний левый угол.*/
		ConvexShape RedMain3; // 260 150

		RedMain3.setPointCount(4);
		// Устанавливаем координаты вершин
		RedMain3.setPoint(0, Vector2f(0.f, 150.f));
		RedMain3.setPoint(1, Vector2f(20.f, 150.f));
		RedMain3.setPoint(2, Vector2f(110.f, 95.f));
		RedMain3.setPoint(3, Vector2f(90.f, 95.f));
		// Цвет
		RedMain3.setFillColor(Color::Red);
		window.draw(RedMain3);


		/*Наклонная красная верхний правый угол.*/
		ConvexShape RedMain4; // 260 150

		RedMain4.setPointCount(4);
		// Устанавливаем координаты вершин
		RedMain4.setPoint(0, Vector2f(260.f, 0.f));
		RedMain4.setPoint(1, Vector2f(240.f, 0.f));
		RedMain4.setPoint(2, Vector2f(150.f, 55.f));
		RedMain4.setPoint(3, Vector2f(170.f, 55.f));
		// Цвет
		RedMain4.setFillColor(Color::Red);
		window.draw(RedMain4);

		// Большая звезда

		ConvexShape star; 
		star.setPointCount(14);
		star.setFillColor(Color::White);

		star.setPoint(0, Vector2f(80, 80));
		star.setPoint(1, Vector2f(84, 92));
		star.setPoint(2, Vector2f(95, 88));
		star.setPoint(3, Vector2f(91, 97));
		star.setPoint(4, Vector2f(100, 102));
		star.setPoint(5, Vector2f(89, 104));
		star.setPoint(6, Vector2f(91, 114));
		star.setPoint(7, Vector2f(80, 106));
		star.setPoint(8, Vector2f(69, 114));
		star.setPoint(9, Vector2f(71, 104));
		star.setPoint(10, Vector2f(60, 102));
		star.setPoint(11, Vector2f(69, 97));
		star.setPoint(12, Vector2f(65, 88));
		star.setPoint(13, Vector2f(76, 92));

		star.setScale(1.8f, 2.1f);
		star.setPosition(-18, 85);
		window.draw(star);


		// Звезда 1 средняя

		ConvexShape star1;
		star1.setPointCount(14); 
		star1.setFillColor(Color::White); 

		star1.setPoint(0, Vector2f(80, 80));
		star1.setPoint(1, Vector2f(84, 92));
		star1.setPoint(2, Vector2f(95, 88));
		star1.setPoint(3, Vector2f(91, 97));
		star1.setPoint(4, Vector2f(100, 102));
		star1.setPoint(5, Vector2f(89, 104));
		star1.setPoint(6, Vector2f(91, 114));
		star1.setPoint(7, Vector2f(80, 106));
		star1.setPoint(8, Vector2f(69, 114));
		star1.setPoint(9, Vector2f(71, 104));
		star1.setPoint(10, Vector2f(60, 102));
		star1.setPoint(11, Vector2f(69, 97));
		star1.setPoint(12, Vector2f(65, 88));
		star1.setPoint(13, Vector2f(76, 92));

		star1.setScale(1.1f, 1.3f);
		star1.setPosition(370, 150);
		window.draw(star1);

		// Звезда 2 средняя

		ConvexShape star2;
		star2.setPointCount(14); 
		star2.setFillColor(Color::White); 

		star2.setPoint(0, Vector2f(80, 80));
		star2.setPoint(1, Vector2f(84, 92));
		star2.setPoint(2, Vector2f(95, 88));
		star2.setPoint(3, Vector2f(91, 97));
		star2.setPoint(4, Vector2f(100, 102));
		star2.setPoint(5, Vector2f(89, 104));
		star2.setPoint(6, Vector2f(91, 114));
		star2.setPoint(7, Vector2f(80, 106));
		star2.setPoint(8, Vector2f(69, 114));
		star2.setPoint(9, Vector2f(71, 104));
		star2.setPoint(10, Vector2f(60, 102));
		star2.setPoint(11, Vector2f(69, 97));
		star2.setPoint(12, Vector2f(65, 88));
		star2.setPoint(13, Vector2f(76, 92));

		star2.setScale(1.1f, 1.3f);
		star2.setPosition(370, -55);
		window.draw(star2);

		// Звезда 3 (маленькая)

		ConvexShape star3;
		star3.setPointCount(14); 
		star3.setFillColor(Color::White);

		star3.setPoint(0, Vector2f(80, 80));
		star3.setPoint(1, Vector2f(84, 92));
		star3.setPoint(2, Vector2f(95, 88));
		star3.setPoint(3, Vector2f(91, 97));
		star3.setPoint(4, Vector2f(100, 102));
		star3.setPoint(5, Vector2f(89, 104));
		star3.setPoint(6, Vector2f(91, 114));
		star3.setPoint(7, Vector2f(80, 106));
		star3.setPoint(8, Vector2f(69, 114));
		star3.setPoint(9, Vector2f(71, 104));
		star3.setPoint(10, Vector2f(60, 102));
		star3.setPoint(11, Vector2f(69, 97));
		star3.setPoint(12, Vector2f(65, 88));
		star3.setPoint(13, Vector2f(76, 92));

		star3.setScale(0.6f, 0.8f);
		star3.setPosition(320, 75);
		window.draw(star3);

		// Маленькая звезда 2

		ConvexShape star4;
		star4.setPointCount(14); 
		star4.setFillColor(Color::White);

		star4.setPoint(0, Vector2f(80, 80));
		star4.setPoint(1, Vector2f(84, 92));
		star4.setPoint(2, Vector2f(95, 88));
		star4.setPoint(3, Vector2f(91, 97));
		star4.setPoint(4, Vector2f(100, 102));
		star4.setPoint(5, Vector2f(89, 104));
		star4.setPoint(6, Vector2f(91, 114));
		star4.setPoint(7, Vector2f(80, 106));
		star4.setPoint(8, Vector2f(69, 114));
		star4.setPoint(9, Vector2f(71, 104));
		star4.setPoint(10, Vector2f(60, 102));
		star4.setPoint(11, Vector2f(69, 97));
		star4.setPoint(12, Vector2f(65, 88));
		star4.setPoint(13, Vector2f(76, 92));

		star4.setScale(0.6f, 0.8f);
		star4.setPosition(500, 40);
		window.draw(star4);


		// Мини звезда

		ConvexShape star5;
		star5.setPointCount(14); 
		star5.setFillColor(Color::White); 

		star5.setPoint(0, Vector2f(80, 80));
		star5.setPoint(1, Vector2f(84, 92));
		star5.setPoint(2, Vector2f(95, 88));
		star5.setPoint(3, Vector2f(91, 97));
		star5.setPoint(4, Vector2f(100, 102));
		star5.setPoint(5, Vector2f(89, 104));
		star5.setPoint(6, Vector2f(91, 114));
		star5.setPoint(7, Vector2f(80, 106));
		star5.setPoint(8, Vector2f(69, 114));
		star5.setPoint(9, Vector2f(71, 104));
		star5.setPoint(10, Vector2f(60, 102));
		star5.setPoint(11, Vector2f(69, 97));
		star5.setPoint(12, Vector2f(65, 88));
		star5.setPoint(13, Vector2f(76, 92));

		star5.setScale(0.5f, 0.6f);
		star5.setPosition(450, 125);
		window.draw(star5);

		// Отрисовка окна	
			window.display();


	}

	return 0;
}

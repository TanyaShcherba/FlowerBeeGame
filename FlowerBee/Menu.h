#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

void menu(RenderWindow& window) {
	Texture menuText, menuText1, menuText2, aboutText, menuBack;
	menuText.loadFromFile("images/text1.png");
	menuText1.loadFromFile("images/text2.png");
	menuText2.loadFromFile("images/text3.png");
	aboutText.loadFromFile("images/help.png");
	menuBack.loadFromFile("images/back.png");

	Sprite menu1(menuText), menu2(menuText1), menu3(menuText2), about(aboutText), menuBg(menuBack);

	bool isMenu = 1;
	int menuNum = 0;

	menu1.setPosition(275, 330);
	menu2.setPosition(265, 380);
	menu3.setPosition(320, 425);
	menuBg.setPosition(0, 0);

	
	while (isMenu)
	{
		Event event;					//Закрытие окна при нажатии X
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		

		if (IntRect(275, 330, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); menuNum = 1; }
		if (IntRect(265, 380, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); menuNum = 2; }
		if (IntRect(320, 425, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); window.draw(menuBg); window.draw(menu1); window.draw(menu2); window.draw(menu3); }
			if (menuNum == 3) { window.close();}
		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	
}

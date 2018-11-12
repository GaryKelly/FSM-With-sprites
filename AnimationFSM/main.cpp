#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>
#include <State.h>
using namespace std;
void changeSprite(int t_num, AnimatedSprite &t_sprite, sf::Texture &t_texture, Player &t_player);

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	std::cout << " 1: Idle\n 2: Walk\n 3: Climb\n 4: Jump\n 5:Hammer\n 6:Shovel\n 7:Sword\n";

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}
	int states = { 1 };

	Animation m_animation;



	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);

	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));

	// Setup the Player
	Player player(animated_sprite);
	Input input;

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) //idle
				{
					m_animation.idle();
					states = 1;
					changeSprite(states, animated_sprite, texture, player);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					m_animation.walking();
					states = 2;
					changeSprite(states, animated_sprite, texture, player);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
				{
					m_animation.climbing();
					states = 3;
					changeSprite(states, animated_sprite, texture, player);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
				{
					m_animation.jumping();
					states = 4;
					changeSprite(states, animated_sprite, texture, player);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
				{
					m_animation.hammering();
					states = 5;
					changeSprite(states, animated_sprite, texture, player);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
				{
					m_animation.shoveling();
					states = 6;
					changeSprite(states, animated_sprite, texture, player);

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
				{
					m_animation.swordsmanship();
					states = 7;
					changeSprite(states, animated_sprite, texture, player);
				}
				break;
			default:

				break;
			}


			// Handle input to Player
			player.handleInput(input);

			// Update the Player
			player.update(animated_sprite);

			// Clear screen
			window.clear();

			// Draw the Players Current Animated Sprite
			window.draw(player.getAnimatedSprite());

			// Update the window
			window.display();
		}

		//return EXIT_SUCCESS;
	};
}

void changeSprite(int t_num, AnimatedSprite & t_sprite, sf::Texture & t_texture, Player &t_player)
{
	AnimatedSprite sprite(t_texture);
	switch (t_num)
	{
	case 1:
		sprite.addFrame(sf::IntRect(3, 3, 84, 84));
		sprite.addFrame(sf::IntRect(88, 3, 84, 84));
		sprite.addFrame(sf::IntRect(173, 3, 84, 84));
		sprite.addFrame(sf::IntRect(258, 3, 84, 84));
		sprite.addFrame(sf::IntRect(343, 3, 84, 84));
		sprite.addFrame(sf::IntRect(428, 3, 84, 84));
		break;
	case 2:
		sprite.addFrame(sf::IntRect(3, 88, 84, 84));
		sprite.addFrame(sf::IntRect(88, 88, 84, 84));
		sprite.addFrame(sf::IntRect(173, 88, 84, 84));
		sprite.addFrame(sf::IntRect(258, 88, 84, 84));
		sprite.addFrame(sf::IntRect(343, 88, 84, 84));
		sprite.addFrame(sf::IntRect(428, 88, 84, 84));
		break;
	case 3:
		sprite.addFrame(sf::IntRect(3, 173, 84, 84));
		sprite.addFrame(sf::IntRect(88, 173, 84, 84));
		sprite.addFrame(sf::IntRect(173, 173, 84, 84));
		sprite.addFrame(sf::IntRect(258, 173, 84, 84));
		sprite.addFrame(sf::IntRect(343, 173, 84, 84));
		sprite.addFrame(sf::IntRect(428, 173, 84, 84));
		break;
	case 4:
		sprite.addFrame(sf::IntRect(3, 258, 84, 84));
		sprite.addFrame(sf::IntRect(88, 258, 84, 84));
		sprite.addFrame(sf::IntRect(173, 258, 84, 84));
		sprite.addFrame(sf::IntRect(258, 258, 84, 84));
		sprite.addFrame(sf::IntRect(343, 258, 84, 84));
		sprite.addFrame(sf::IntRect(428, 258, 84, 84));
		break;
	case 5:
		sprite.addFrame(sf::IntRect(3, 343, 84, 84));
		sprite.addFrame(sf::IntRect(88, 343, 84, 84));
		sprite.addFrame(sf::IntRect(173, 343, 84, 84));
		sprite.addFrame(sf::IntRect(258, 343, 84, 84));
		sprite.addFrame(sf::IntRect(343, 343, 84, 84));
		sprite.addFrame(sf::IntRect(428, 343, 84, 84));
		break;
	case 6:
		sprite.addFrame(sf::IntRect(3, 428, 84, 84));
		sprite.addFrame(sf::IntRect(88, 428, 84, 84));
		sprite.addFrame(sf::IntRect(173, 428, 84, 84));
		sprite.addFrame(sf::IntRect(258, 428, 84, 84));
		sprite.addFrame(sf::IntRect(343, 428, 84, 84));
		sprite.addFrame(sf::IntRect(428, 428, 84, 84));
		break;
	case 7:
		sprite.addFrame(sf::IntRect(3, 513, 84, 84));
		sprite.addFrame(sf::IntRect(88, 513, 84, 84));
		sprite.addFrame(sf::IntRect(173, 513, 84, 84));
		sprite.addFrame(sf::IntRect(258, 513, 84, 84));
		sprite.addFrame(sf::IntRect(343, 513, 84, 84));
		sprite.addFrame(sf::IntRect(428, 513, 84, 84));
		break;
	default:
		break;
	}
	t_player.update(sprite);
	t_sprite = sprite;
}

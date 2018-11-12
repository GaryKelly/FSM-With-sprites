#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>
#include <State.h>
using namespace std;


int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	std::cout << " 1: Idle\n 2: Walk\n 3: Climb\n 4: Jump\n 5:Hammer\n 6:Shovel\n 7:Sword\n";
	Animation idle;
	idle.idle();
	Animation walk;
	walk.walking();
	Animation jump;
	jump.jumping();
	Animation climb;
	climb.climbing();
	Animation hammer;
	hammer.hammering();
	Animation sword;
	sword.swordsmanship();
	Animation shovel;
	shovel.shoveling();
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

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
				/*	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
					animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
					animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
					animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
					animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
					animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));*/
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					m_animation.walking();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
				{
					m_animation.climbing();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
				{
					m_animation.jumping();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
				{
					m_animation.hammering();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
				{
					m_animation.shoveling();

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
				{
					m_animation.swordsmanship();
				}
				break;
			default:

				break;
			}


			// Handle input to Player
			player.handleInput(input);

			// Update the Player
			player.update();

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




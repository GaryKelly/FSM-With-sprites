#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

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

	Animation m_animation;

	//consts for sf int rect
	const int PIXELS{ 84 };
	const int LINE_THICKNESS{ 3 };
	const int IDLE{ 1 };
	const int WALKING{ 2 };
	const int CLIMBING{ 3 };
	const int JUMPING{ 4 };
	const int HAMMERING{ 5 };
	const int SHOVELING{ 6 };
	const int SWORDSMANSHIP{ 7 };

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);
	//if (true) // IDLE
	//{
	//	animated_sprite.addFrame(sf::IntRect(3, 3, 84, 84));
	//	animated_sprite.addFrame(sf::IntRect(88, 3, 84, 84));
	//	animated_sprite.addFrame(sf::IntRect(173, 3, 84, 84));
	//	animated_sprite.addFrame(sf::IntRect(258, 3, 84, 84));
	//	animated_sprite.addFrame(sf::IntRect(343, 3, 84, 84));
	//	animated_sprite.addFrame(sf::IntRect(428, 3, 84, 84));
	//}
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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					input.setCurrent(Input::Action::LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					input.setCurrent(Input::Action::RIGHT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					input.setCurrent(Input::Action::UP);
				}
				break;
			default:
				input.setCurrent(Input::Action::IDLE);
				break;
			}
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

	return EXIT_SUCCESS;
};
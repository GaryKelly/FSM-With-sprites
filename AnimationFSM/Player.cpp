#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>
#include <SFML\Graphics.hpp>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	
}

void Player::update(AnimatedSprite &t_sprite)
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite = t_sprite;
	m_animated_sprite.update();
}
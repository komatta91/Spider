#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <cassert>
#include "GameKeyMapper.h"
#include "GameAction.h"

int GameKeyMapper::getActionFor(int key) const
{
	switch (key)
	{
	case 'W' :
		return GameAction::FORWARD;
	case 'A'  :
		return GameAction::LEFT;
	case  'S' :
		return GameAction::BACK;
	case  'D' :
		return GameAction::RIGHT;
	case VK_UP :
		return GameAction::ROTATE_UP;
	case VK_DOWN  :
		return GameAction::ROTATE_DOWN;
	case  VK_LEFT :
		return GameAction::ROTATE_LEFT;
	case  VK_RIGHT :
		return GameAction::ROTATE_RIGHT;
	}
	assert(false);
	return -1;
}

int GameKeyMapper::getKeyFor(int action) const
{
	switch (action)
	{
	case GameAction::FORWARD  :
		return 'W';
	case GameAction::LEFT  :
		return 'A';
	case GameAction::BACK :
		return 'S';
	case GameAction::RIGHT :
		return 'D';
	case GameAction::ROTATE_UP  :
		return VK_UP;
	case GameAction::ROTATE_DOWN  :
		return VK_DOWN;
	case GameAction::ROTATE_LEFT :
		return VK_LEFT;
	case GameAction::ROTATE_RIGHT :
		return VK_RIGHT;
	}
	assert(false);
	return -1;
}

uint GameKeyMapper::getMaxActon() const
{
	return GameAction::MAX_VALUE;
}
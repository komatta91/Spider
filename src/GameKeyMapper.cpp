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
		return GameAction::Accelerate;
	case 'A'  :
		return GameAction::RotateLeft;
	case  'D' :
		return GameAction::RotateRight;
	}
	assert(false);
	return -1;
}

int GameKeyMapper::getKeyFor(int action) const
{
	switch (action)
	{
	case GameAction::Accelerate  :
		return 'W';
	case GameAction::RotateLeft  :
		return 'A';
	case GameAction::RotateRight :
		return 'D';
	}
	assert(false);
	return -1;
}

uint GameKeyMapper::getMaxActon() const
{
	return GameAction::MAX_VALUE;
}
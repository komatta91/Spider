#include "KeyInput.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <IKeyMapper.h>

KeyInput KeyInput::instance;

KeyInput::KeyInput()
{
}

bool KeyInput::initialize(IKeyMapper* keyMapper, int maxActionValue)
{
	if (keyMapper == 0 || maxActionValue < 0)
	{
		return false;
	}
	this->keyMapper = keyMapper;
	this->maxActionValue = maxActionValue;
	return true;
}

bool KeyInput::shutdown()
{
	return true;
}

void KeyInput::update()
{
	_actionsLastFrame = _actionsThisFrame;
	_actionsThisFrame = 0;
	_actionsEndedThisFrame = 0;
	_actionsStartedThisFrame = 0;

	int possibleActions = 1;
	while (possibleActions < maxActionValue)
	{
		int key = keyMapper->getKeyFor(possibleActions);
		if (GetAsyncKeyState(key))
		{
			_actionsThisFrame |= possibleActions;
			if (!((_actionsLastFrame & possibleActions) == possibleActions) && ((_actionsThisFrame & possibleActions) == possibleActions))
			{
				_actionsStartedThisFrame |= possibleActions;
			}
		}
		if ((_actionsLastFrame & possibleActions)  == possibleActions && !((_actionsThisFrame & possibleActions) == possibleActions))
		{
			_actionsEndedThisFrame |= possibleActions;
		}
		possibleActions <<= 1;
	}
}

int KeyInput::actionsThisFrame() const
{
	return _actionsThisFrame;
}

bool KeyInput::actionsHot(int actions) const
{
	return (_actionsThisFrame & actions) == actions;
}

bool KeyInput::actionsStarted(int actions) const
{
	return (_actionsStartedThisFrame & actions) == actions;
}

bool KeyInput::actionsEnded(int actions) const
{
	return (_actionsEndedThisFrame & actions) == actions;
}

KeyInput& KeyInput::getInstance()
{
	return instance;
}
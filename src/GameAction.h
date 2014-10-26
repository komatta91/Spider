#ifndef _GAME_ACTION_H_
#define _GAME_ACTION_H_

enum GameAction : int
{
	Accelerate  = 0x00000001,
	RotateLeft  = 0x00000002,
	RotateRight = 0x00000004,
	MAX_VALUE   = 0x00000008
};

#endif
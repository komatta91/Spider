#ifndef _GAME_KEY_MAPPER_H_
#define _GAME_KEY_MAPPER_H_
#include <IKeyMapper.h>

class GameKeyMapper : public IKeyMapper
{
public:
	int getActionFor(int key) const;
	int getKeyFor(int action) const;
	uint getMaxActon() const;
};

#endif
#ifndef _KMENGINE_I_KEY_MAPPER_H_
#define _KMENGINE_I_KEY_MAPPER_H_

#include <typedefs.h>

class IKeyMapper
{
public:
	virtual int getActionFor(int key) const = 0;
	virtual int getKeyFor(int action) const = 0;
	virtual uint getMaxActon() const = 0;
};

#endif
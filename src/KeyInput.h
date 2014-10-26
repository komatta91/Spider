#ifndef _KMENGINE_KEY_INPUT_H_
#define _KMENGINE_KEY_INPUT_H_

class IKeyMapper;
class KeyInput
{
	IKeyMapper* keyMapper;
	int maxActionValue;
	int _actionsThisFrame;
	int _actionsLastFrame;
	int _actionsStartedThisFrame;
	int _actionsEndedThisFrame;

	KeyInput();
	KeyInput(const KeyInput&);
	KeyInput& operator=(const KeyInput&);
	static KeyInput instance;
public:
	bool initialize(IKeyMapper* keyMapper, int maxActionValue);
	bool shutdown();
	void update();
	int actionsThisFrame() const;
	bool actionsHot(int actions) const;
	bool actionsStarted(int actions) const;
	bool actionsEnded(int actions) const;
	static KeyInput& getInstance();
};

#endif
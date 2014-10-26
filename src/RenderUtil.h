#pragma once
class RenderUtil
{
	RenderUtil(void);
public:
	static void initGraphics();
	static void clearScrean();
	static const unsigned char * openGlVersion();
};


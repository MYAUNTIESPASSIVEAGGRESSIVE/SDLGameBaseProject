#ifndef _ANIMATEDTEXTURE_H
#define _ANIMATEDTEXTURE_H

#include "Timer.h"
#include "Texture.h"

class AnimatedTexture : public Texture
{
public:

	// run animated once or loop
	enum WRAP_MODE { once = 0, loop = 1};

	// direction of the animation sheet
	enum ANIM_DIR { horizontal = 0, verticle = 1};

private:

	// timer ptr
	Timer* _mTimer;

	// start co-ords of the sheet
	int _mStartX;
	int _mStartY;

	// animation time, speed
	float _mAnimTimer;
	float _mAnimSpeed;

	// how long the animation is on a single frame
	float _mTimePerFrame;

	int _mFrameCount;

	WRAP_MODE _mWrapMode;

	ANIM_DIR _mAnimDir;

	bool _mAnimFinished;

public:

	AnimatedTexture(std::string filename, int x, int y, int w, int h, 
		int frameCount, float animSpeed, ANIM_DIR AnimDir);

	~AnimatedTexture();

	void WrapMode(WRAP_MODE mode);

	void Update();
};

#endif // !_ANIMATEDTEXTURE_H



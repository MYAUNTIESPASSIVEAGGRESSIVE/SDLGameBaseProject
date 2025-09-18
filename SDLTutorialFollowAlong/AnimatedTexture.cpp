#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h,
	int frameCount, float animSpeed, ANIM_DIR AnimDir) : Texture(filename, x, y, w, h)
{
	_mTimer = Timer::Instance();

	_mStartX = x;
	_mStartY = y;

	_mFrameCount = frameCount;
	_mAnimSpeed = animSpeed;
	_mTimePerFrame = _mAnimSpeed / _mFrameCount;
	_mAnimTimer = 0.0f;

	_mAnimDir = AnimDir;

	_mAnimFinished = false;

	_mWrapMode = loop;
}

AnimatedTexture::~AnimatedTexture()
{

}

// sets the mode of the animationed texture looping or not
void AnimatedTexture::WrapMode(WRAP_MODE mode)
{
	_mWrapMode = mode;
}

void AnimatedTexture::Update()
{
	// if the anim is NOT finished
	if (!_mAnimFinished)
	{
		// add to the timer
		_mAnimTimer += _mTimer->DeltaTime();

		// if the timer is above the set time of the animation
		if (_mAnimTimer >= _mAnimSpeed)
		{
			// if looing then reset timer
			if (_mWrapMode == loop)
				_mAnimTimer -= _mAnimSpeed;
			else
			{
				// if not looping set the anim as finished
				_mAnimFinished = true;
				_mAnimTimer = _mAnimSpeed - _mTimePerFrame;
			}
		}

		// if the direction is hoz or vert then take next frame from the start pos using either width or height
		if (_mAnimDir == horizontal)
		{
			// set the clip rect to be the startx + the animation timer/ time per frame by the width
			_tClipRect.x = _mStartX + (int)(_mAnimTimer / _mTimePerFrame) * _tWidth;
		}
		else {
			// set the clip rect to be the starty + the animation timer/ time per frame by the height
			_tClipRect.y = _mStartY + (int)(_mAnimTimer / _mTimePerFrame) * _tHeight;
		}
	}
}

#pragma once

#include "animations/Animation.h"

// Useful for simple one-off animations, you can supply the animation's apply(t) method right in the constructor as a lambda.
class LambdaAnimation : public Animation
{
public:
	LambdaAnimation(const std::function<void(float t)>& func, int duration) : mFunction(func), mDuration(duration) {}

  virtual ~LambdaAnimation() {}

	int getDuration() const override { return mDuration; }

	void apply(float t) override
	{
		mFunction(t);
	}

private:
	std::function<void(float t)> mFunction;
	int mDuration;
};

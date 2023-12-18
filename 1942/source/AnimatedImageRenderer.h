#pragma once
#include "ImageRenderer.h"
#include <vector>

class AnimatedImageRenderer : public ImageRenderer
{
protected:
	std::vector<Vector2> framesDelta;
	Vector2 initialSourceOffset;
	bool looping;

	int currentFrame;

	int fps;
	float frameTime;
	float currentFrameTime;

	public:
		AnimatedImageRenderer(
			Transform* transform,
			Vector2 sourceOffset,
			Vector2 sourceSize,
			std::string path,
			Vector2 size,
			std::vector<Vector2> framesDelta,
			bool looping,
			int fps
		) : ImageRenderer(transform, sourceOffset, sourceSize),
			framesDelta(framesDelta), 
			looping(looping),
			fps(fps), 
			currentFrame(0), 
			currentFrameTime(0.0f),
			initialSourceOffset(sourceOffset)
		{
			frameTime = 1.0f / fps;
		}
		void Update(float dt) override
		{
			currentFrameTime += dt;
			
			if (currentFrameTime >= frameTime)
			{
				currentFrameTime -= frameTime + floor(currentFrameTime / frameTime);
				if (looping)
				{
					currentFrame = (currentFrame + 1) % framesDelta.size();
				}
				else
				{
					currentFrame = (currentFrame + 1) >= framesDelta.size() ? currentFrame : currentFrame + 1;
				}
			}
			sourceRect.x = initialSourceOffset.x + framesDelta[currentFrame].x;
			sourceRect.y = initialSourceOffset.y + framesDelta[currentFrame].y;

		}
		
};

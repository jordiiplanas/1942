#include "SmallNormalPlane.h"

void SmallNormalPlane::UpdateMovementPattern(float dt)
{
	if (!changeMovement)
	{
		if (movementType == V)
		{
			if (transform->position.y > curveMovementLimit)
				changeMovement = true;
		}		
		else
		{
			if (transform->position.y > curveMovementLimit)
				changeMovement = true;
		}
	}
}

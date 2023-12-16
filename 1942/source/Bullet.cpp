#include "Bullet.h"

void Bullet::OnCollisionEnter(Object* other)
{

	if (dynamic_cast<Enemy*>(other))
	{
		//Destroy();
	}
}

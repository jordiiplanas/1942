#pragma once
#include "GameObject.h"
#include "EnemyBullet.h"
#include "AnimatedImageRenderer.h"
#include "InputManager.h"
#include "SupportPlane.h"
#include "AudioManager.h"

class Player : public GameObject
{
private:
	bool isRolling = false;
	float fireTime = 0.2f;
	float lastFireTime;
	bool doubleFire;
	int lives = 30;


	float timePassed = 0;
	float timeToDie = 0.5f;
	
	float timeRolling = 0;
	float timeToRoll = 0.5f;

	float timeToRespawn = 1;
	bool isDying = false;
	bool isRespawning = false;
	std::string currentAnimation = "idle";

	float shootDelay = 0.1f;
	float lastShootTime = 0;

	Vector2 initialPosition;
	SupportPlane* leftSupportPlane;
	SupportPlane* rightSupportPlane;

	int shootSoundID;
	int deathSoundID;
	int flipSoundID;
	int powerUpSoundID;

public:
	bool isShootingFourBullets = false;

	Player(Vector2 position) : GameObject(Vector2(32, 32)) {
		renderers.emplace("idle", new ImageRenderer(transform, Vector2(0,0), Vector2(32, 32)));
		std::vector<Vector2> rightDeltas
		{
			Vector2(32,0),Vector2(32 * 3,0),Vector2(32 * 5,0)
		};
		std::vector<Vector2> leftDeltas
		{
			Vector2(32 * 2,0),Vector2(32 * 4,0),Vector2(32 * 6,0)
		};
		std::vector<Vector2> deathDeltas
		{
			Vector2(0,0), Vector2(32,0), Vector2(64,0), Vector2(96,0), Vector2(128,0), Vector2(160,0)
		};
		std::vector<Vector2> rollDeltas
		{
			Vector2(0,32), Vector2(32,32), Vector2(64,32), Vector2(96,32), Vector2(128,32), Vector2(160,32), Vector2(192,32), Vector2(224,32)
			, Vector2(0,64), Vector2(32,64)
		};

		renderers.emplace("right", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), rightDeltas, false, 20));
		renderers.emplace("left", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), leftDeltas, false, 20));
		renderers.emplace("death", new AnimatedImageRenderer(transform, Vector2(0,112), Vector2(32, 32), deathDeltas, false, 20));
		renderers.emplace("roll", new AnimatedImageRenderer(transform, Vector2(0, 0), Vector2(32, 32), rollDeltas, false, 20));
		renderer = renderers["idle"];
		rigidbody->SetLinearDrag(10);
		shootSoundID = AUDIOMANAGER.LoadClip("resources/audios/Piu.mp3");
		deathSoundID = AUDIOMANAGER.LoadClip("resources/audios/puabuauauaua.mp3");
		flipSoundID = AUDIOMANAGER.LoadClip("resources/audios/flip.mp3");
		powerUpSoundID = AUDIOMANAGER.LoadClip("resources/audios/Chiclinn.mp3");
		SetScale(Vector2(1.5f, 1.5f));
		initialPosition = position;
		SetPosition(position);
	}

	void OnCollisionEnter(Object* other) override;
	bool IsDying() { return isDying; }
	void PlayDeathAnimation();
	void Shoot();
	void AddSupportPlane();
	void ShootFourBullets();
	void MoveSupportPlanes();
	void DisableSupportPlane(Object* other);
	void Update(float deltaTime) override;
};
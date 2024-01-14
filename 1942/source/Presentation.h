#pragma once
#include "GameObject.h"
#include "UiText.h"


class Presentation : public GameObject
{
private:
public:
	Presentation(Vector2 position) : GameObject(Vector2(128,128))
	{
		std::vector<Vector2> animacionEntrada
		{
			Vector2(0,0), Vector2(498,0),Vector2(498 * 2,0),Vector2(498 * 3,0),Vector2(498 * 4,0)
		};
		AnimatedImageRenderer* intro = new AnimatedImageRenderer(transform, Vector2(), Vector2(498, 361),animacionEntrada,true, 20 );
		intro->SetTexture(RENDERMANAGER.GetPresentationTexture());
		
		renderers.emplace("idle", intro);
		renderer = renderers["idle"];
		SetPosition(position);

	}

	void Render() override
	{
		GameObject::Render();
	}

	void Update(float dt) override
	{
		GameObject::Update(dt);
		SetScale(GetScale() + Vector2(0.03, 0.03));
		SetPosition(GetPosition()-Vector2(2,2));		
	}
};
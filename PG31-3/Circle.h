#pragma once
#include "IShape.h"

class Circle : public IShape
{
private:
	float radius;
	const float PI = 3.14159f;

public:
	Circle();
	Circle(const float& radius);

	/// <summary>
	/// ï`âÊ
	/// </summary>
	void Draw() override;

	/// <summary>
	/// ñ êœ
	/// </summary>
	float GetSize() override;
};


#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
private:
	float width;
	float height;

public:
	Rectangle();
	Rectangle(const float& width, const float& height);

	/// <summary>
	/// ï`âÊ
	/// </summary>
	void Draw() override;

	/// <summary>
	/// ñ êœ
	/// </summary>
	float GetSize() override;
};


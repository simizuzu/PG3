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
	/// �`��
	/// </summary>
	void Draw() override;

	/// <summary>
	/// �ʐ�
	/// </summary>
	float GetSize() override;
};


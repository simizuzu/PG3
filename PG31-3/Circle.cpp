#include "Circle.h"
#include <iostream>

Circle::Circle() : radius(0.0f){}

Circle::Circle(const float& radius) : radius(radius){}

void Circle::Draw()
{
	float area = radius * radius * PI;
	printf("�~�̖ʐς�%f�����Z���`���[�g���ł�\n", area);
}

float Circle::GetSize()
{
	return radius * radius * PI;
}

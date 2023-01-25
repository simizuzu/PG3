#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle() : width(0), height(0){}

Rectangle::Rectangle(const float& width, const float& height) :width(width), height(height){}

void Rectangle::Draw()
{
	float area = width * height;
	printf("��`�̖ʐς�%f�����Z���`���[�g���ł�\n", area);
}

float Rectangle::GetSize()
{
	return width * height;
}

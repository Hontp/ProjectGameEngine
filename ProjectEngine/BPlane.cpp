#include "BPlane.h"


BPlane::BPlane(glm::vec3 position, glm::vec2 dimensions)
{
	origin = position;
	size = dimensions;
}

BPlane::~BPlane()
{

}

bool BPlane::intersects(BPlane &plane)
{
	if (front() > plane.back())	return false;
	if (back() < plane.front()) return false;
	if (left() > plane.right()) return false;
	if (right() < plane.left()) return false;
	return true;
}

glm::vec2 BPlane::Size() const
{
	return size;
}

void BPlane::UpdateSize(glm::vec2 _size)
{
	size = _size;
}

float BPlane::back() const
{
	return origin.z - size.y / 2.0f;
}

float BPlane::left() const
{
	return origin.x - size.x / 2.0f;
}

float BPlane::right() const
{
	return origin.x + size.x / 2.0f;
}

float BPlane::front() const
{
	return origin.z + size.y / 2.0f;
}
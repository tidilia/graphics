#pragma once
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <math.h>
#define _USE_MATH_DEFINES 
#include <cmath>

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

class Transformation
{
public:
	void InitScaleTransform(float ScaleX, float ScaleY, float ScaleZ, glm::mat4x4& m);
	void InitRotateTransform(float RotateX, float RotateY, float RotateZ, glm::mat4x4& m);
	void InitTranslationTransform(float x, float y, float z, glm::mat4x4& m);
	void InitPersProjTransform(float FOV, float Width, float Height, float zNear, float zFar, glm::mat4x4& m);
	void InitCameraTransform(const glm::vec3& Target, const glm::vec3& Up, glm::mat4x4& m);
};


#pragma once

#define _USE_MATH_DEFINES 
#include <cmath>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

class Pipeline {
private: 
	glm::vec3 m_scale;
	glm::vec3 m_worldPos;
	glm::vec3 m_rotateInfo;
	glm::mat4x4 m_transformation;

	void InitScaleTransform(glm::mat4x4& m) const;
	void InitRotateTransform(glm::mat4x4& m) const;
	void InitTranslationTransform(glm::mat4x4& m) const;

public:
	Pipeline() {
		m_scale = glm::vec3(1.0f, 1.0f, 1.0f);
		m_worldPos = glm::vec3(0.0f, 0.0f, 0.0f);
		m_rotateInfo = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	void Scale(float scX, float scY, float scZ) {
		m_scale.x = scX;
		m_scale.y = scY;
		m_scale.z = scZ;
	}
	void WorldPos(float posX, float posY, float posZ) {
		m_worldPos.x = posX;
		m_worldPos.y = posY;
		m_worldPos.z = posZ;
	}
	void Rotate(float rotateX, float rotateY, float rotateZ) {
		m_rotateInfo.x = rotateX;
		m_rotateInfo.y = rotateY;
		m_rotateInfo.z = rotateZ;
	}
	const glm::mat4x4* GetTrans();
};


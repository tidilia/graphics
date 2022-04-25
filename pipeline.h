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


	struct {
		float FOV;
		float Width;
		float Height;
		float zNear;
		float zFar;
	} m_persProj;
	struct {
		glm::vec3 Pos;
		glm::vec3 Target;
		glm::vec3 Up;
	} m_camera;

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

	void SetPerspectiveProj(float FOV, float Width, float Height, float zNear, float zFar){
		m_persProj.FOV = FOV;
		m_persProj.Width = Width;
		m_persProj.Height = Height;
		m_persProj.zNear = zNear;
		m_persProj.zFar = zFar;
	}

	void SetCamera(const  glm::vec3& Pos, const  glm::vec3& Target, const  glm::vec3& Up){
		m_camera.Pos = Pos;
		m_camera.Target = Target;
		m_camera.Up = Up;
	}
};


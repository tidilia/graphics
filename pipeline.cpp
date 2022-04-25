#include "pipeline.h"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"

const glm::mat4x4* Pipeline::GetTrans(){
	glm::mat4x4 ScaleTrans, RotateTrans, TranslationTrans, PersProjTrans;
	InitScaleTransform(ScaleTrans);
	InitRotateTransform(RotateTrans);
	InitTranslationTransform(TranslationTrans);
    InitPerspectiveProj(PersProjTrans);

	m_transformation = PersProjTrans * TranslationTrans * RotateTrans * ScaleTrans;
	return &m_transformation;

}

void Pipeline::InitScaleTransform(glm::mat4x4& m) const{
	m[0][0] = m_scale.x; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = m_scale.y; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = m_scale.z; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

void Pipeline::InitRotateTransform(glm::mat4x4& m) const {
    glm::mat4x4  rx, ry, rz;

    const float x = ToRadian(m_rotateInfo.x);
    const float y = ToRadian(m_rotateInfo.y);
    const float z = ToRadian(m_rotateInfo.z);

    rx[0][0] = 1.0f; rx[0][1] = 0.0f; rx[0][2] = 0.0f; rx[0][3] = 0.0f;
    rx[1][0] = 0.0f; rx[1][1] = cosf(x); rx[1][2] = -sinf(x); rx[1][3] = 0.0f;
    rx[2][0] = 0.0f; rx[2][1] = sinf(x); rx[2][2] = cosf(x); rx[2][3] = 0.0f;
    rx[3][0] = 0.0f; rx[3][1] = 0.0f; rx[3][2] = 0.0f; rx[3][3] = 1.0f;

    ry[0][0] = cosf(y); ry[0][1] = 0.0f; ry[0][2] = -sinf(y); ry[0][3] = 0.0f;
    ry[1][0] = 0.0f; ry[1][1] = 1.0f; ry[1][2] = 0.0f; ry[1][3] = 0.0f;
    ry[2][0] = sinf(y); ry[2][1] = 0.0f; ry[2][2] = cosf(y); ry[2][3] = 0.0f;
    ry[3][0] = 0.0f; ry[3][1] = 0.0f; ry[3][2] = 0.0f; ry[3][3] = 1.0f;

    rz[0][0] = cosf(z); rz[0][1] = -sinf(z); rz[0][2] = 0.0f; rz[0][3] = 0.0f;
    rz[1][0] = sinf(z); rz[1][1] = cosf(z); rz[1][2] = 0.0f; rz[1][3] = 0.0f;
    rz[2][0] = 0.0f; rz[2][1] = 0.0f; rz[2][2] = 1.0f; rz[2][3] = 0.0f;
    rz[3][0] = 0.0f; rz[3][1] = 0.0f; rz[3][2] = 0.0f; rz[3][3] = 1.0f;

    m = rz * ry * rx;
}

void Pipeline::InitTranslationTransform(glm::mat4x4& m) const
{
    m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = m_worldPos.x;
    m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = m_worldPos.y;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = m_worldPos.z;
    m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
}

void Pipeline::InitPerspectiveProj(glm::mat4x4& m) const
{
    const float ar = m_persProj.Width / m_persProj.Height;
    const float zNear = m_persProj.zNear;
    const float zFar = m_persProj.zFar;
    const float zRange = zNear - zFar;
    const float tanHalfFOV = tanf(ToRadian(m_persProj.FOV / 2.0f));

    m[0][0] = 1.0f / (tanHalfFOV * ar); m[0][1] = 0.0f;             m[0][2] = 0.0f;                     m[0][3] = 0.0;
    m[1][0] = 0.0f;                     m[1][1] = 1.0f / tanHalfFOV;m[1][2] = 0.0f;                     m[1][3] = 0.0;
    m[2][0] = 0.0f;                     m[2][1] = 0.0f;             m[2][2] = (-zNear - zFar) / zRange; m[2][3] = 2.0f * zFar * zNear / zRange;
    m[3][0] = 0.0f;                     m[3][1] = 0.0f;             m[3][2] = 1.0f;                     m[3][3] = 0.0;
}
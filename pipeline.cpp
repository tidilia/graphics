#include "pipeline.h"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "transformation.h"

const glm::mat4x4* Pipeline::GetTrans(){
	glm::mat4x4 ScaleTrans, RotateTrans, TranslationTrans, PersProjTrans, CameraTranslationTrans, CameraRotateTrans;
    Transformation Trans;

    Trans.InitScaleTransform(m_scale.x, m_scale.y, m_scale.z, ScaleTrans);
    Trans.InitRotateTransform(m_rotateInfo.x, m_rotateInfo.y, m_rotateInfo.z, RotateTrans);
    Trans.InitTranslationTransform(m_worldPos.x, m_worldPos.y, m_worldPos.z, TranslationTrans);
    Trans.InitTranslationTransform(-m_camera.Pos.x, -m_camera.Pos.y, -m_camera.Pos.z, CameraTranslationTrans);
    Trans.InitCameraTransform(m_camera.Target, m_camera.Up, CameraRotateTrans);
    Trans.InitPersProjTransform(m_persProj.FOV, m_persProj.Width, m_persProj.Height, m_persProj.zNear, m_persProj.zFar, PersProjTrans);

    m_transformation = PersProjTrans * CameraRotateTrans * CameraTranslationTrans * TranslationTrans * RotateTrans * ScaleTrans;
    return &m_transformation;

}


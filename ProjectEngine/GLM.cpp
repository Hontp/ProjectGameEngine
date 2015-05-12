#include "GLM.h"


glm::mat4 GLM::CreateLookAtMatrix(glm::vec3 Position, glm::vec3 Target, glm::vec3 UpVector){
	glm::mat4 matrix = glm::lookAt(Position, Target, glm::vec3(0, 1, 0));
	return matrix;
}

glm::mat4 GLM::CreatePerspectiveMatrix(GLfloat FieldOfView, GLfloat AspectRatio, GLfloat NearPlane, GLfloat FarPlane){
	glm::mat4 matrix = glm::perspective(FieldOfView, AspectRatio, NearPlane, FarPlane);
	return matrix;
}

glm::vec3 GLM::CrossVectors(glm::vec3 X_Vector, glm::vec3 Y_Vector){
	glm::vec3 vector = glm::cross(X_Vector, Y_Vector);
	return vector;
}

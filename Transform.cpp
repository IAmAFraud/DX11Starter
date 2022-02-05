#include "Transform.h"

// Reduces code, and allows for operator overloads
using namespace DirectX;

Transform::Transform()
{
	// Set up our initial values
	SetPosition(0, 0, 0);
	SetRotation(0, 0, 0);
	SetScale(1, 1, 1);

	// Creates the initial matrix
	XMStoreFloat4x4(&worldMatrix, XMMatrixIdentity());
	
	// Set matrix bool
	matrixDirty = false;
}


void Transform::MoveAbsolute(float x, float y, float z)
{
	// Using the math library
	XMVECTOR pos = XMLoadFloat3(&position);
	XMVECTOR offset = XMVectorSet(x, y, z, 0);
	XMStoreFloat3(&position, pos + offset);

	// Updated matrix dirty
	matrixDirty = true;
}


void Transform::Rotate(float p, float y, float r)
{
	// Using the math library
	XMVECTOR pyr = XMLoadFloat3(&pitchYawRoll);
	XMVECTOR rot = XMVectorSet(p, y, r, 0);
	XMStoreFloat3(&pitchYawRoll, pyr + rot);

	// Updated matrix dirty
	matrixDirty = true;
}


void Transform::Scale(float x, float y, float z)
{
	// Using the math library
	XMVECTOR scl = XMLoadFloat3(&scale);
	XMVECTOR change = XMVectorSet(x, y, z, 0);
	XMStoreFloat3(&scale, XMVectorMultiply(scl, change));

	// Updated matrix dirty
	matrixDirty = true;
}


void Transform::SetPosition(float x, float y, float z)
{
	position = XMFLOAT3(x, y, z);

	// Updated matrix dirty
	matrixDirty = true;
}


void Transform::SetRotation(float p, float y, float r)
{
	pitchYawRoll = XMFLOAT3(p, y, r);

	// Updated matrix dirty
	matrixDirty = true;
}


void Transform::SetScale(float x, float y, float z)
{
	scale = XMFLOAT3(x, y, z);

	// Updated matrix dirty
	matrixDirty = true;
}


DirectX::XMFLOAT3 Transform::GetPosition(){ return position; }
DirectX::XMFLOAT3 Transform::GetRotation(){ return pitchYawRoll; }
DirectX::XMFLOAT3 Transform::GetScale(){ return scale; }


DirectX::XMFLOAT4X4 Transform::GetWorldMatrix()
{
	// Only updates the matrix if there was a change
	if (matrixDirty)
	{
		// Create individual transformation matrices
		XMMATRIX translationMatrix = XMMatrixTranslation(position.x, position.y, position.z);
		XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(pitchYawRoll.x, pitchYawRoll.y, pitchYawRoll.z);
		XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);

		// Combine transformations matrices and store result
		XMMATRIX worldMat = scaleMatrix * rotationMatrix * translationMatrix;
		XMStoreFloat4x4(&worldMatrix, worldMat);

		// Mark matrix as clean
		matrixDirty = false;
	}
	
	// Returns the world matrix
	return worldMatrix;
}

#pragma once
#include <DirectXMath.h>

class Transform
{
public:
	Transform();

	void MoveAbsolute(float x, float y, float z);
	void Rotate(float p, float y, float r);
	void Scale(float x, float y, float z);

	void SetPosition(float x, float y, float z);
	void SetRotation(float p, float y, float r);
	void SetScale(float x, float y, float z);

	DirectX::XMFLOAT3 GetPosition();
	DirectX::XMFLOAT3 GetRotation();
	DirectX::XMFLOAT3 GetScale();
	DirectX::XMFLOAT4X4 GetWorldMatrix();

private:
	// Raw transformation data
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT3 pitchYawRoll;
	DirectX::XMFLOAT3 scale;

	// Finalized Matrix
	DirectX::XMFLOAT4X4 worldMatrix;

	// Matrix Updated
	bool matrixDirty;
};

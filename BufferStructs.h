#pragma once

#include <DirectXMath.h>

// Struct for external data on vertex shader
//    colorTint: adds a color tint to the vertices in the scene
//    offset: Adds a position offset to each vertex
struct VertexShaderExternalData
{
	DirectX::XMFLOAT4 colorTint;
	DirectX::XMFLOAT3 offset;
};
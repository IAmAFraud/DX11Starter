#include "Material.h"

/// <summary>
/// Constructor for creating a material
/// </summary>
/// <param name="_colorTint">The color tint of the material</param>
/// <param name="_vertexShader">The vertex shader for the material</param>
/// <param name="_pixelShader">the pixel shader for the material</param>
Material::Material(DirectX::XMFLOAT4 _colorTint, std::shared_ptr<SimpleVertexShader> _vertexShader, std::shared_ptr<SimplePixelShader> _pixelShader, float _roughness)
{
	colorTint = _colorTint;
	vertexShader = _vertexShader;
	pixelShader = _pixelShader;
	roughness = _roughness;
}

// Deconstructor, currently empty
Material::~Material()
{
}

// Getters
DirectX::XMFLOAT4 Material::GetColorTint() { return colorTint; }
std::shared_ptr<SimpleVertexShader> Material::GetVertexShader() { return vertexShader; }
std::shared_ptr<SimplePixelShader> Material::GetPixelShader() { return pixelShader; }
float Material::GetRoughness() { return roughness; }

// Setters
void Material::SetColorTint(DirectX::XMFLOAT4 _colorTint) { colorTint = _colorTint; }
void Material::SetVertexShader(std::shared_ptr<SimpleVertexShader> _vertexShader) { vertexShader = _vertexShader; }
void Material::SetPixelShader(std::shared_ptr<SimplePixelShader> _pixelShader) { pixelShader = _pixelShader; }
void Material::SetRoughness(float _roughness) { roughness = _roughness; }
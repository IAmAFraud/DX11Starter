#pragma once

#include <DirectXMath.h>
#include <memory>
#include "SimpleShader.h"
class Material
{
	public:
		// Constructor/Deconstructor
		Material(DirectX::XMFLOAT4 _colorTint, std::shared_ptr<SimpleVertexShader> _vertexShader, std::shared_ptr<SimplePixelShader> _pixelShader, float _roughness);
		~Material();

		// Getters
		DirectX::XMFLOAT4 GetColorTint();
		std::shared_ptr<SimpleVertexShader> GetVertexShader();
		std::shared_ptr<SimplePixelShader> GetPixelShader();
		float GetRoughness();

		// Setters
		void SetColorTint(DirectX::XMFLOAT4 _colorTint);
		void SetVertexShader(std::shared_ptr<SimpleVertexShader> _vertexShader);
		void SetPixelShader(std::shared_ptr<SimplePixelShader> _pixelShader);
		void SetRoughness(float _roughness);

	private:
		// Fields
		DirectX::XMFLOAT4 colorTint;
		std::shared_ptr<SimpleVertexShader> vertexShader;
		std::shared_ptr<SimplePixelShader> pixelShader;
		float roughness;
};


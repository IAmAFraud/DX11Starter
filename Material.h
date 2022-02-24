#pragma once

#include <DirectXMath.h>
#include <memory>
#include "SimpleShader.h"
class Material
{
	public:
		// Constructor/Deconstructor
		Material(DirectX::XMFLOAT4 _colorTint, std::shared_ptr<SimpleVertexShader> _vertexShader, std::shared_ptr<SimplePixelShader> _pixelShader);
		~Material();

		// Getters
		DirectX::XMFLOAT4 GetColorTint();
		std::shared_ptr<SimpleVertexShader> GetVertexShader();
		std::shared_ptr<SimplePixelShader> GetPixelShader();

		// Setters
		void SetColorTint(DirectX::XMFLOAT4 _colorTint);
		void SetVertexShader(std::shared_ptr<SimpleVertexShader> _vertexShader);
		void SetPixelShader(std::shared_ptr<SimplePixelShader> _pixelShader);

	private:
		// Fields
		DirectX::XMFLOAT4 colorTint;
		std::shared_ptr<SimpleVertexShader> vertexShader;
		std::shared_ptr<SimplePixelShader> pixelShader;
};


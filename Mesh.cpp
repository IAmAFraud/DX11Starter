#include "Mesh.h"


Mesh::Mesh(Vertex* _vertices, int _numVertices, unsigned int* _indices, int _numIndices, Microsoft::WRL::ComPtr<ID3D11Device> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context)
{
	// Connect appropriate fields
	numIndices = _numIndices;
	context = _context;

	// Sets Up The Vertex Buffer
	// Creates the Vertex Buffer Description
	D3D11_BUFFER_DESC vbd = {};
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof(Vertex) * _numVertices;
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;

	// Create struct to hold vertex data
	D3D11_SUBRESOURCE_DATA initialVertexData = {};
	initialVertexData.pSysMem = _vertices;

	// Create the Vertex Buffer with the appropriate data
	_device->CreateBuffer(&vbd, &initialVertexData, vertexBuffer.GetAddressOf());

	// Sets up the Index Buffer
	// Creates the Index Buffer Description
	D3D11_BUFFER_DESC ibd = {};
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = sizeof(unsigned int) * numIndices;
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;

	// Create struct to hold index data
	D3D11_SUBRESOURCE_DATA initialIndexData = {};
	initialIndexData.pSysMem = _indices;

	// Create the Index Buffer with the appropriate data
	_device->CreateBuffer(&ibd, &initialIndexData, indexBuffer.GetAddressOf());
}


Mesh::~Mesh()
{

}


// Mesh::GetVertexBuffer


// Mesh::GetIndexBuffer


int Mesh::GetIndexCount()
{
	return numIndices;
}


void Mesh::Draw()
{
	// Sets the Buffers in context
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	context->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);
	context->IASetIndexBuffer(indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);

	// Draws the mesh to the screen
	context->DrawIndexed(
		numIndices,
		0,
		0);
}
#include "Camera.h"

using namespace DirectX;

/// <summary>
/// Constructor for the Camera
/// </summary>
/// <param name="x">Starting X</param>
/// <param name="y">Starting Y</param>
/// <param name="z">Starting Z</param>
/// <param name="aspectRatio">Screen Aspect Ratio</param>
Camera::Camera(float x, float y, float z, float aspectRatio) : transform()
{
    // Set up transform and matrices
    transform.SetPosition(x, y, z);
    UpdateViewMatrix();
    UpdateProjectionMatrix(aspectRatio);
}

/// <summary>
/// Camera Destructor (Currently Does Nothing)
/// </summary>
Camera::~Camera()
{
}

void Camera::Update(float dt)
{
    transform.MoveRelative(0, 0, -dt);

    UpdateViewMatrix();
}

/// <summary>
/// Updates the view matrix
/// </summary>
void Camera::UpdateViewMatrix()
{
    // Bring in necessary information from transform
    XMFLOAT3 pos = transform.GetPosition();
    XMFLOAT3 forward = transform.GetForward();
    XMFLOAT3 up = transform.GetUp();

    // Update and store the view matrix
    XMMATRIX view = XMMatrixLookToLH(XMLoadFloat3(&pos), XMLoadFloat3(&forward), XMLoadFloat3(&up));
    XMStoreFloat4x4(&viewMatrix, view);
}

/// <summary>
/// Updates the projection matrix
/// </summary>
/// <param name="aspectRatio">The aspect ratio of the screen</param>
void Camera::UpdateProjectionMatrix(float aspectRatio)
{
    // Creates a projection matrix with a 45 degree FOV
    XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, aspectRatio, 0.01f, 1000.0f);
    XMStoreFloat4x4(&projectionMatrix, proj);
}

// Getters
Transform* Camera::GetTransform() { return &transform; }
DirectX::XMFLOAT4X4 Camera::GetViewMatrix() { return viewMatrix; }
DirectX::XMFLOAT4X4 Camera::GetProjectionMatrix() { return projectionMatrix; }

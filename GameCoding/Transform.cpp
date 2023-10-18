#include "pch.h"
#include "Transform.h"

Transform::Transform()
{

}

Transform::~Transform()
{
}

void Transform::Init()
{
}

void Transform::Update()
{
	Matrix matScale = Matrix::CreateScale(_localScale);
	Matrix matRotation = Matrix::CreateRotationX(_localRotation.x);
	matRotation *= Matrix::CreateRotationY(_localRotation.y);
	matRotation *= Matrix::CreateRotationZ(_localRotation.z);
	Matrix matTranslation = Matrix::CreateTranslation(_localPosition);

	_matLocal = matScale * matRotation * matTranslation;

	if (HasParent())
	{
		_matWorld = _matLocal * _parent->GetWorldMatrix();
	} 
	else
	{
		_matWorld = _matLocal;
	}
}

void Transform::UpdateTransform()
{
}

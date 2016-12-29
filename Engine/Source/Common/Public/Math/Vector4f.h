#pragma once

#include <iostream>
#include <string>

#include <FrostyCommon.h>
#include <Math/Vector3f.h>

struct Matrix4f;
struct FROSTY_COMMON_API Vector4f
{
	float X, Y, Z, W;

	inline Vector4f() : Vector4f(0.0f, 0.0f, 0.0f, 0.0f) { }
	inline explicit Vector4f(float scalar) : Vector4f(scalar, scalar, scalar, scalar) { }
	inline Vector4f(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) { }

	Vector4f(const Vector3f& vector, float w);

	Vector4f& Add(const Vector4f& right);
	Vector4f& Subtract(const Vector4f& right);
	Vector4f& Multiply(const Vector4f& right);
	Vector4f& Divide(const Vector4f& right);

	Vector4f Multiply(const Matrix4f& matrix) const;

	float Dot(const Vector4f& vector);

	inline friend FROSTY_COMMON_API Vector4f operator+(Vector4f left, const Vector4f& right) { return left.Add(right); }
	inline friend FROSTY_COMMON_API Vector4f operator-(Vector4f left, const Vector4f& right) { return left.Subtract(right); }
	inline friend FROSTY_COMMON_API Vector4f operator*(Vector4f left, const Vector4f& right) { return left.Multiply(right); }
	inline friend FROSTY_COMMON_API Vector4f operator/(Vector4f left, const Vector4f& right) { return left.Divide(right); }

	inline Vector4f& operator+=(const Vector4f& right) { return this->Add(right); }
	inline Vector4f& operator-=(const Vector4f& right) { return this->Subtract(right); }
	inline Vector4f& operator*=(const Vector4f& right) { return this->Multiply(right); }
	inline Vector4f& operator/=(const Vector4f& right) { return this->Divide(right); }

	bool operator==(const Vector4f& right) const;
	bool operator!=(const Vector4f& right) const;

	std::string ToString() const;
	friend FROSTY_COMMON_API std::ostream& operator<<(std::ostream& stream, const Vector4f& right);

	static const Vector4f Zero;
	static const Vector4f One;
};



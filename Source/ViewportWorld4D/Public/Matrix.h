#pragma once

#include "CoreMinimal.h"

struct Matrix2D
{
private:
	float M[2][3];

public:
	Matrix2D(
		const float& a, const float& b, const float& tx,
		const float& c, const float& d, const float& ty)
	{
		M[0][0] = a; M[0][1] = b; M[0][2] = tx;
		M[1][0] = c; M[1][1] = d; M[1][2] = ty;
	};

	FVector operator* (const FVector& Vec) const;
};

struct ProjectionMatrix2D
{
	Matrix2D ProjectionMatrix{
		1, 0, 0,
		0, 1, 0
	};

	FVector operator* (const FVector& Vec) const;
};

struct RotationMatrixZ2D
{
private:
	
	float Degrees;

public:
	
	RotationMatrixZ2D(const float& InDegrees) {Degrees = InDegrees;}
	
	FVector operator* (const FVector& Vec) const;
};

// struct Matrix
// {
//
// 	
// };

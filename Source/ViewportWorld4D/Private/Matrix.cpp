#include "Matrix.h"

FVector Matrix2D::operator*(const FVector& Vec) const
{
	float x = (M[0][0] * Vec.X) + (M[0][1] * Vec.Y) + (M[0][2] * Vec.Z);
	float y = (M[1][0] * Vec.X) + (M[1][1] * Vec.Y) + (M[1][2] * Vec.Z);
	float z = 0;

	return FVector(x, y, z);
}

FVector ProjectionMatrix2D::operator*(const FVector& Vec) const
{
	return ProjectionMatrix * Vec;
}

FVector RotationMatrixZ2D::operator*(const FVector& Vec) const
{
	float Radians = FMath::DegreesToRadians(Degrees);

	Matrix2D RotMat{
		FMath::Cos(Radians), -FMath::Sin(Radians), 0,
		FMath::Sin(Radians),  FMath::Cos(Radians), 0
	};

	return RotMat * Vec;
}

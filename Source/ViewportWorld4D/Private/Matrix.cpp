#include "Matrix.h"

// FVector Matrix2D::operator*(const FVector& Vec) const
// {
// 	// float VM[3][1] = {{(float)Vec.X}, {(float)Vec.Y}, {(float)Vec.Z}};
// 	//  Matrix<3, 1> VecMatrix{VM};
//
// 	
// 	// float x = (M[0][0] * Vec.X) + (M[0][1] * Vec.Y) + (M[0][2] * Vec.Z);
// 	// float y = (M[1][0] * Vec.X) + (M[1][1] * Vec.Y) + (M[1][2] * Vec.Z);
// 	// float z = 0;
// 	//
// 	// return FVector(x, y, z);
//
// 	return *this * Matrix<3, 1>(Vec);
// }

FVector ProjectionMatrix2D::operator*(const FVector& Vec) const
{
	return ProjectionMatrix * Matrix<3, 1>(Vec);
}

FVector RotationMatrixZ2D::operator*(const FVector& Vec) const
{
	float Radians = FMath::DegreesToRadians(Degrees);

	float RotArr[2][3] = {
		{FMath::Cos(Radians), -FMath::Sin(Radians), 0},
		{FMath::Sin(Radians),  FMath::Cos(Radians), 0}
	};
	
	Matrix<2, 3> RotMat{RotArr};

	return RotMat * Matrix<3, 1>(Vec);
}

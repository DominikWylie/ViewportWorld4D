#pragma once

#include "CoreMinimal.h"

template<int Row, int Column>
struct Matrix
{

private:
	float M[Row][Column];

	template<int, int>
	friend struct Matrix;

public:

	Matrix(const float InM[Row][Column])
	{
		// cant M = InM; for c style arrays

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				M[i][j] = InM[i][j];
			}
		}
	}

	Matrix()
	{
		for (int i = 0; i < Row; ++i)
		{
			for (int j = 0; j < Column; ++j)
			{
				M[i][j] = 0.0f;
			}
		}
	}

	Matrix(const FVector& Vec)
	{
		static_assert(Row == 3 && Column == 1,
			"FVector can only construct Matrix<3,1>");

		M[0][0] = Vec.X;
		M[1][0] = Vec.Y;
		M[2][0] = Vec.Z;
	}

	template<int K>
	Matrix<Row, K> operator* (const Matrix<Column, K>& inMatrix) const
	{
		Matrix<Row, K> Result;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < K; j++)
			{
				float Sum = 0.f;

				for (int k = 0; k < Column; k++)
				{
					Sum += this->M[i][k] * inMatrix.M[k][j];
				}

				Result.M[i][j] = Sum;
			}
		}

		return Result;
	}

	operator FVector() const
	{
		static_assert((Row == 3 || Row == 2) && Column == 1, "Only Matrix<3,1> converts to FVector");

		if (Row == 3)
			return FVector(
			M[0][0],
			M[1][0],
			M[2][0]
			);

		return FVector(
			M[0][0],
			M[1][0],
			0
			);
	}
};

// struct Matrix2D
// {
// private:
// 	float M[2][3];
//
// public:
// 	Matrix2D(
// 		const float& a, const float& b, const float& tx,
// 		const float& c, const float& d, const float& ty)
// 	{
// 		M[0][0] = a; M[0][1] = b; M[0][2] = tx;
// 		M[1][0] = c; M[1][1] = d; M[1][2] = ty;
// 	};
//
// 	FVector operator* (const FVector& Vec) const;
// };

struct ProjectionMatrix2D
{
	float M2D[2][3] = {
		{1, 0, 0},
		{0, 1, 0}
	};
	
	Matrix<2, 3> ProjectionMatrix{M2D};

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

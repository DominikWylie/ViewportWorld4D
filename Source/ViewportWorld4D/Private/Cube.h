// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "NiagaraComponent.h"

#include "Cube.generated.h"

/**
 * 
 */
UCLASS()
class VIEWPORTWORLD4D_API ACube : public AActor
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:

	ACube();

	void InitCubePositions();
	
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VFX")
	// TArray<UNiagaraComponent*> Wire;

	UPROPERTY(EditDefaultsOnly, Category="Cube")
	UNiagaraSystem* NiagaraSystemPoints;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cube")
	TArray<UNiagaraComponent*> Points;

	TArray<FVector> PointPositions;

	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Cube")
	float Unit = 100.f;
};

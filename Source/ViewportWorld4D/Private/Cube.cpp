// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"
#include "Matrix.h"

//#include "Math/Matrix.h"

ACube::ACube()
{
	// PrimaryActorTick.bCanEverTick = true;
	
	USceneComponent* DedicatedRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DedicatedRoot"));
	RootComponent = DedicatedRoot;

	PointPositions = {
		FVector(-Unit, -Unit, 0),
		FVector(Unit, -Unit, 50),
		FVector(Unit, Unit, 100),
		FVector(-Unit, Unit, 150)
	};

	for (uint8 i = 0; i < 4; i++)
	{
		FString PointName = FString::Printf(TEXT("Point_%d"), i);
		UNiagaraComponent* TempPoint = CreateDefaultSubobject<UNiagaraComponent>(*PointName);
		TempPoint->SetupAttachment(RootComponent);
		Points.Add(TempPoint);
	}
	
	// for (uint8 i = 0; i < 12; i++)
	// {
	// 	Wire[i] = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Wire"));
	// 	Wire[i]->SetupAttachment(RootComponent);
	// }

}

void ACube::BeginPlay()
{
	Super::BeginPlay();

	InitCubePositions();

	for (uint8 i = 0; i < Points.Num(); i++)
	{
		Points[i]->SetVariableVec3(FName("User.Particles_Position"), (ProjectionMatrix2D() * PointPositions[i]));
	}

	
}

void ACube::InitCubePositions()
{
	check(Points.Num() == PointPositions.Num())

	for (uint8 i = 0; i < Points.Num(); i++)
	{
		Points[i]->SetAsset(NiagaraSystemPoints);
		Points[i]->SetVariableVec3(FName("User.Particles_Position"), PointPositions[i]);
		Points[i]->Activate();
	}
	
	// Wire[0]->SetVariableVec3(FName("User.BeamStart"), FVector(-Unit, Unit, -Unit));
	// Wire[0]->SetVariableVec3(FName("User.BeamEnd"), FVector(Unit, Unit, -Unit));
	//
	// Wire[0]->SetVariableVec3(FName("User.BeamStart"), FVector(-Unit, Unit, -Unit));
	// Wire[0]->SetVariableVec3(FName("User.BeamEnd"), FVector(Unit, Unit, -Unit));
	//
	// Wire[0]->SetVariableVec3(FName("User.BeamStart"), FVector(-Unit, Unit, -Unit));
	// Wire[0]->SetVariableVec3(FName("User.BeamEnd"), FVector(Unit, Unit, -Unit));
	//
	// Wire[0]->SetVariableVec3(FName("User.BeamStart"), FVector(-Unit, Unit, -Unit));
	// Wire[0]->SetVariableVec3(FName("User.BeamEnd"), FVector(Unit, Unit, -Unit));
	//
	// Wire[0]->SetVariableVec3(FName("User.BeamStart"), FVector(-Unit, Unit, -Unit));
	// Wire[0]->SetVariableVec3(FName("User.BeamEnd"), FVector(Unit, Unit, -Unit));
	//
	// Wire[0]->SetVariableVec3(FName("User.BeamStart"), FVector(-Unit, Unit, -Unit));
	// Wire[0]->SetVariableVec3(FName("User.BeamEnd"), FVector(Unit, Unit, -Unit));
}

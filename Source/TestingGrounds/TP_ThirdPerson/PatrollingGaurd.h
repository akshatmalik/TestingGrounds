// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGaurd.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGaurd : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Points")
		TArray<AActor *> Waypoints;
	
	
	
};

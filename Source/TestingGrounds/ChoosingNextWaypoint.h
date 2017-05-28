// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChoosingNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChoosingNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(VisibleAnywhere,Category="Blackboard")
	struct FBlackboardKeySelector IndexKey;

	UPROPERTY(VisibleAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WaypointKey;
};

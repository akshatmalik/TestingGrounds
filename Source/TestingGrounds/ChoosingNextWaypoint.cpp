// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChoosingNextWaypoint.h"


EBTNodeResult::Type UChoosingNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("LOGOGOG!"));
	return EBTNodeResult::Succeeded;
}


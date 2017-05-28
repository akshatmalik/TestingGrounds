// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChoosingNextWaypoint.h"
#include "AIController.h"
#include "PatrolPoints.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChoosingNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//Get patrol points
	auto AIOwner = OwnerComp.GetAIOwner();
	auto OwnerPawn = AIOwner->GetPawn();
	auto PatrolRoute = OwnerPawn->FindComponentByClass<UPatrolPoints>();
	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	auto PatrolPoint = PatrolRoute->Waypoints;
	if (PatrolPoint.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No patrol points"));
		return EBTNodeResult::Failed;
	}
	
	//Set next way Points
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoint[Index]);

	//Cycling through the index
	auto NextIndex = (Index + 1) % PatrolPoint.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	UE_LOG(LogTemp, Warning, TEXT("Index value %i!"), Index);
	return EBTNodeResult::Succeeded;
}


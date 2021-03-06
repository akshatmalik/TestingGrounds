// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "TestingGroundsCharacter.h"
#include "TestingGroundsProjectile.h"
#include "Animation/AnimInstance.h"
#include "Gun.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	
	

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	
	

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGun::OnFire()
{
	UE_LOG(LogTemp, Warning, TEXT("Contructed"));
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation =FP_MuzzleLocation->GetComponentLocation();

		UWorld* const World = GetWorld();
		if (World != NULL)
			
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawning"));
			// spawn the projectile at the muzzle
			World->SpawnActor<ATestingGroundsProjectile>(ProjectileClass, FP_MuzzleLocation->GetComponentLocation(), FP_MuzzleLocation->GetComponentRotation());
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation1p != NULL)
	{
		// Get the animation object for the arms mesh
		if (AnimInstance1p != NULL)
		{
			AnimInstance1p->Montage_Play(FireAnimation1p, 1.f);
		}
	}

	if (FireAnimation3p != NULL)
	{
		// Get the animation object for the arms mesh
		if (AnimInstance3p != NULL)
		{
			AnimInstance3p->Montage_Play(FireAnimation3p, 1.f);
		}
	}

	//MakeNoise(1.0f, GetWorld()->GetFirstPlayerController()->GetControlledPawn(), GetWorld()->GetFirstPlayerController()->GetControlledPawn()->GetActorLocation());

}
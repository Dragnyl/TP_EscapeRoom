// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoom_CM.h"
#include "OpenDoorRoom1.h"

#define OUT

// Sets default values for this component's properties
UOpenDoorRoom1::UOpenDoorRoom1()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = 90.0f;
	// ...
}


// Called when the game starts
void UOpenDoorRoom1::BeginPlay()
{
	Super::BeginPlay();
	
	// Find the owning Actor
	Owner = GetOwner();
	if (!Owner) { return; }
	
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	
	if (!PointLight)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
}


// Called every frame
void UOpenDoorRoom1::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (GetTotalMassOfActors() > 40.f) {
		PointLight->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else {
		PointLight->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {
		CloseDoor();
	}
}

void UOpenDoorRoom1::OpenDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoorRoom1::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

float UOpenDoorRoom1::GetTotalMassOfActors()
{
	float TotalMass = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}
		
	return TotalMass;
}
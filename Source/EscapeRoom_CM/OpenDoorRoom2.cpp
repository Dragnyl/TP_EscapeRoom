// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoom_CM.h"
#include "OpenDoorRoom2.h"

#define OUT

// Sets default values for this component's properties
UOpenDoorRoom2::UOpenDoorRoom2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = 90.0f;
	// ...
}


// Called when the game starts
void UOpenDoorRoom2::BeginPlay()
{
	Super::BeginPlay();

	// Find the owning Actor
	Owner = GetOwner();
	if (!Owner) { return; }

	if (!PressurePlate1)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!PressurePlate2)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!PressurePlate3)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	
	if (!PointLight1)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!PointLight2)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!PointLight3)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}	
}


// Called every frame
void UOpenDoorRoom2::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (GetTotalMassOfActors(PressurePlate1) < 1.f) {
		PointLight1->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger1 = true;
	}
	else {
		PointLight1->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger1 = false;
	}

	if (GetTotalMassOfActors(PressurePlate2) < 1.f) {
		PointLight2->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger2 = true;
	}
	else {
		PointLight2->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger2 = false;
	}

	if (GetTotalMassOfActors(PressurePlate3) < 1.f) {
		PointLight3->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger3 = true;
		
	}
	else {
		PointLight3->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger3 = false;
	}

	if (trigger1 && trigger2 && trigger3) {
		PointLight1->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		PointLight2->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		PointLight3->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {
		CloseDoor();
	}
	// ...
}

void UOpenDoorRoom2::OpenDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoorRoom2::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

float UOpenDoorRoom2::GetTotalMassOfActors(ATriggerVolume *Pressure)
{
	float TotalMass = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!Pressure) { return TotalMass; }
	Pressure->GetOverlappingActors(OUT OverlappingActors);
	// Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}

	return TotalMass;
}

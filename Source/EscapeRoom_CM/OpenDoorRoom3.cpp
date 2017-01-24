// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoom_CM.h"
#include "OpenDoorRoom3.h"

#define OUT

// Sets default values for this component's properties
UOpenDoorRoom3::UOpenDoorRoom3()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = 90.0f;
	combinaison = "";
	// ...
}


// Called when the game starts
void UOpenDoorRoom3::BeginPlay()
{
	Super::BeginPlay();

	increment = GetWorld()->GetTimeSeconds();
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
	if (!PressurePlate4)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!PressurePlateReset)
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
	if (!PointLight4)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!PointLightReset)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}	
}


// Called every frame
void UOpenDoorRoom3::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (CheckProjectile(PressurePlate1)) 
	{
		if (GetWorld()->GetTimeSeconds() - increment > Delay) {
			combinaison += "1";
			UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *combinaison);
			PointLight1->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
			increment = GetWorld()->GetTimeSeconds();
		}
	}

	if (CheckProjectile(PressurePlate2))
	{
		if (GetWorld()->GetTimeSeconds() - increment > Delay) {
			combinaison += "2";
			UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *combinaison);
			PointLight2->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
			increment = GetWorld()->GetTimeSeconds();
		}
	}

	if (CheckProjectile(PressurePlate3))
	{
		if (GetWorld()->GetTimeSeconds() - increment > Delay) {
			combinaison += "3";
			UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *combinaison);
			PointLight3->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
			increment = GetWorld()->GetTimeSeconds();
		}
	}

	if (CheckProjectile(PressurePlate4))
	{
		if (GetWorld()->GetTimeSeconds() - increment > Delay) {
			combinaison += "4";
			UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *combinaison);
			PointLight4->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
			increment = GetWorld()->GetTimeSeconds();
		}
	}

	if (CheckProjectile(PressurePlateReset))
	{
		Reset();
	}

	if (combinaison.Len() == 4 && combinaison.Equals("1234")) {
		PointLight1->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		PointLight2->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		PointLight3->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		PointLight4->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else if (combinaison.Len() == 4) {
		Reset();
	}
	else {
		if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > Delay) {
			CloseDoor();
		}
	}
	// ...
}

void UOpenDoorRoom3::OpenDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoorRoom3::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

void UOpenDoorRoom3::Reset()
{
	PointLight1->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
	PointLight2->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
	PointLight3->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
	PointLight4->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
	combinaison = "";
}

bool UOpenDoorRoom3::CheckProjectile(ATriggerVolume *Pressure)
{
	// Find all the overlapping actors
	bool res = false;
	FString name;
	TArray<AActor*> OverlappingActors;
	Pressure->GetOverlappingActors(OUT OverlappingActors);

	for (const auto& Actor : OverlappingActors)
	{
		name = *Actor->GetName();
		if (name.Contains("FirstPersonProjectile_C")) {
			UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *name);
			res = true;
		}
		
	}
	return res;
}


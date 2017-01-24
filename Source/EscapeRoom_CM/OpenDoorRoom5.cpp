// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeRoom_CM.h"
#include "OpenDoorRoom5.h"


// Sets default values for this component's properties
UOpenDoorRoom5::UOpenDoorRoom5()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = 90.0f;
	// ...
}


// Called when the game starts
void UOpenDoorRoom5::BeginPlay()
{
	Super::BeginPlay();

	// Find the owning Actor
	Owner = GetOwner();
	if (!Owner) { return; }

	if (!Plate1)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!Plate2)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!Plate3)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!Plate4)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!Plate5)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!Plate6)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	if (!Plate7)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName())
	}
	
	if (!SpotLight1)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!SpotLight2)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!SpotLight3)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!SpotLight4)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!SpotLight5)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!SpotLight6)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
	if (!SpotLight7)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing light"), *GetOwner()->GetName())
	}
}


// Called every frame
void UOpenDoorRoom5::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (GetTotalMassOfActors(Plate1) >= 10.f) {
		SpotLight1->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger1 = true;
	}
	else {
		SpotLight1->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger1 = false;
	}

	if (GetTotalMassOfActors(Plate2) >= 10.f) {
		SpotLight2->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger2 = true;
	}
	else {
		SpotLight2->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger2 = false;
	}

	if (GetTotalMassOfActors(Plate3) >= 10.f) {
		SpotLight3->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger3 = true;
	}
	else {
		SpotLight3->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger3 = false;
	}

	if (GetTotalMassOfActors(Plate4) >= 10.f) {
		SpotLight4->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger4 = true;
	}
	else {
		SpotLight4->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger4 = false;
	}

	if (GetTotalMassOfActors(Plate5) >= 10.f) {
		SpotLight5->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger5 = true;
	}
	else {
		SpotLight5->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger5 = false;
	}

	if (GetTotalMassOfActors(Plate6) >= 10.f) {
		SpotLight6->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger6 = true;
	}
	else {
		SpotLight6->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger6 = false;
	}

	if (GetTotalMassOfActors(Plate7) >= 10.f) {
		SpotLight7->SetLightColor(FLinearColor(0, 0, 255, 0)); //Bleu
		trigger7 = true;
	}
	else {
		SpotLight7->SetLightColor(FLinearColor(255, 0, 0, 0)); //Rouge
		trigger7 = false;
	}

	if (trigger1 && trigger2 && trigger3 && trigger4 && trigger5 && trigger6 && trigger7) {
		SpotLight1->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		SpotLight2->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		SpotLight3->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		SpotLight4->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		SpotLight5->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		SpotLight6->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		SpotLight7->SetLightColor(FLinearColor(0, 128, 0, 0)); //Vert
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
}

void UOpenDoorRoom5::OpenDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoorRoom5::CloseDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

float UOpenDoorRoom5::GetTotalMassOfActors(AActor *Pressure)
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
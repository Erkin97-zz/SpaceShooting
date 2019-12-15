// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"
#include <time.h>

using namespace std;

float PersonX = -1799.45105;
float PersonZ = 378.571228;


// Sets default values
AAsteroid::AAsteroid()
{

  srand(time(NULL));
   // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  
  VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
  VisualMesh->SetupAttachment(RootComponent);
  VisualMesh->SetSimulatePhysics(true);
  VisualMesh->SetEnableGravity(false);
  
  
  
  static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/Geometry/Meshes/Asteroid"));
  

  if (CubeVisualAsset.Succeeded())
  {
      VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
      VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
  }
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
  Super::BeginPlay();
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

  FVector NewLocation = GetActorLocation();
  if (NewLocation.X < PersonX) {
    Destroy();
    return;
  }
  FRotator NewRotation = GetActorRotation();
  float RunningTime = GetGameTimeSinceCreation();
  float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
  NewLocation.Z += DeltaHeight * FloatSpeed;    //Scale our height by a factor of 20
  NewLocation.X -= MovementSpeed;
  float DeltaRotation = DeltaTime * RotationSpeed;    //Rotate by 20 degrees per second
  NewRotation.Yaw += DeltaRotation;
  SetActorLocationAndRotation(NewLocation, NewRotation);
  
  if (Iteration > 0)
  {
      TimeToSpawn -= DeltaTime;
      if (TimeToSpawn < 0.f)
      {
          FVector VeryNewLocation = FVector((rand() % 3000) + 1500, (rand() % 3000) - 1000, rand() % 1000);
        
          
          // Spawn the new actor (Using GetClass() instead of AMySpawner so that if someone derives a new class
          // from AMySpawner we spawn an instance of that class instead)
          AAsteroid* NewActor = GetWorld()->SpawnActor<AAsteroid>(GetClass(), VeryNewLocation, NewRotation);
          NewActor->SetActorScale3D(FVector(0.1, 0.1, 0.1));
          NewActor->SetActorEnableCollision(true);

          // Housekeeping so that we dont spawn new actors forever
          Iteration = Iteration - 1;
      }
  }
}


#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "1_ReadWriteFile.generated.h"

UCLASS()
class U_1_ReadWriteFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//Open text file and read content
	UFUNCTION(BlueprintCallable, Category = "1 - Read Write File")
		static FString ReadStringFromFile(FString filePath, bool& bOutSuccess, FString& OutInfoMessage);

	//Create text file with content
	UFUNCTION(BlueprintCallable, Category = "1 - Read Write File")
		static void WriteStringToFile(FString filePath, FString String, bool& bOutSuccess, FString& OutInfoMessage);

	//Appent content to text file
	UFUNCTION(BlueprintCallable, Category = "1 - Read Write File")
		static void AppendStringToFile(FString filePath, FString String, bool& bOutSuccess, FString& OutInfoMessage);
};
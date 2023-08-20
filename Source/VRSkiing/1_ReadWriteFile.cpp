// Fill out your copyright notice in the Description page of Project Settings.
#include "1_ReadWriteFile.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"


FString U_1_ReadWriteFile::ReadStringFromFile(FString filePath, bool& bOutSuccess, FString& outInfoMessage) {
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath)) {
		bOutSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read String from File failed, file doesnt exist - '%s'"), *filePath);
		return "";
	}

	FString RetString = "";

	if (!FFileHelper::LoadFileToString(RetString, *filePath)) {
		bOutSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Read string from file failed, was not able to read file - '%s'"), *filePath);
		return "";
	}

	bOutSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Read String success"));
	return RetString;
}

void U_1_ReadWriteFile::WriteStringToFile(FString filePath, FString string, bool& bOutSuccess, FString& outInfoMessage) {
	if (!FFileHelper::SaveStringToFile(string, *filePath)) {
		bOutSuccess = false;
		outInfoMessage = FString::Printf(TEXT("Write string to file failed - '%s'"), *filePath);
		return;
	}

	bOutSuccess = true;
	outInfoMessage = FString::Printf(TEXT("Write success"));
}
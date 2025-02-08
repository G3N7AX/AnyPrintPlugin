// Copyright 2025 G3N7AX. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "DebugFunctionLibrary.generated.h"

/**
 * This library was created to provide an easier debugging process that will be logged to an Editor Utility Widget (EUW)
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLogUpdatedDelegate);

UCLASS()
class ANYPRINT_API UDebugFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// ====================================
	// Private Variables
	// ====================================
	
	static TArray<FString> LogEntries;

	// ====================================
	// Private Functions (Helpers)
	// ====================================
	
	static FString GetTimeStamp();
	static void SaveLogToFile(const FString& LogMessage);
	static void SaveLogsToArray();

	// ====================================
	// Private UFunctions
	// ====================================
	
	UFUNCTION(BlueprintCallable, Category = "Log")
	static void EmptyLog();

	UFUNCTION(BlueprintCallable, meta=(DevelopmentOnly), Category = "Log")
	static void PrintAnything(FString StringIn);

	UFUNCTION(BlueprintCallable, meta=(DevelopmentOnly), Category = "Log")
	static void PrintAnythingIndex(int Index, FString StringIn);

public:

	// ====================================
	// Public Functions
	// ====================================
	
	static FOnLogUpdatedDelegate OnLogUpdated;

	// ====================================
	// Public UFunctions
	// ====================================
	
	UFUNCTION(BlueprintCallable, Category = "Log")
	static TArray<FString> GetLogEntries();
	
};

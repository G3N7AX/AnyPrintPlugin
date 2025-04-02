// Copyright 2025 G3N7AX. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnyPrintFunctionLibrary.generated.h"

// ====================================
// Declare Delegates
// ====================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLogUpdatedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEmptyLogDelegate);

// ====================================
// LogEntry Struct
// ====================================

USTRUCT(BlueprintType)
struct FLogEntry
{
	GENERATED_BODY()

	/* Declare the LogEntry variable */
	UPROPERTY(BlueprintReadWrite, Category = "Logging")
	FString LogEntry;

	/* Declare the LogColor variable */
	UPROPERTY(BlueprintReadWrite, Category = "Logging")
	FLinearColor LogColor;

	/* Constructor */
	FLogEntry()
		/* Sets the LogEntry to an empty text and the color to white (default values) */
		/* This actually won't set the default color for some reason, but I'll leave it bs it needs to be initialized */
		: LogEntry(TEXT("")), LogColor(FLinearColor(1.f, 1.f, 1.f, 1.f)) {}

	/* Paramertized Constructor */
	FLogEntry(const FString& LogEntryIn, const FLinearColor& LogColorIn)
		: LogEntry(LogEntryIn), LogColor(LogColorIn) {}
};

// ====================================
// Function Library Class
// ====================================

UCLASS()
class ANYPRINTLIBRARY_API UAnyPrintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
private:

	// ====================================
	// Private Variables
	// ====================================
	
	static TArray<FLogEntry> LogEntries;

	// ====================================
	// Private UFunctions
	// ====================================
	
	UFUNCTION()
	static FString GetTimestamp();

public:

	// ====================================
	// Public Delegates
	// ====================================
	
	static FOnLogUpdatedDelegate OnLogUpdated;
	static FOnEmptyLogDelegate OnEmptyLog;

	// ====================================
	// Public UFunctions
	// ====================================
	
	UFUNCTION(BlueprintCallable, Category = "AnyPrint")
	static TArray<FLogEntry> GetLogEntries();

	UFUNCTION(BlueprintCallable, Category = "AnyPrint")
	static void EmptyLog();

	/* Default color for Logs is set here */
	UFUNCTION(BlueprintCallable, Category = "AnyPrint", meta = (DevelopmentOnly))
	static void PrintAnything(const FString& Log, FLinearColor LogColor = FLinearColor(1.f, 1.f, 1.f, 1.f));
};

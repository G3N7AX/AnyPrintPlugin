// Copyright 2025 G3N7AX. Licensed under the MIT License.

#include "AnyPrintFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManager.h"

// ====================================
// Declare Variables
// ====================================

TArray<FLogEntry> UAnyPrintFunctionLibrary::LogEntries;

// ====================================
// Declare Delegates
// ====================================

FOnLogUpdatedDelegate UAnyPrintFunctionLibrary::OnLogUpdated;
FOnEmptyLogDelegate UAnyPrintFunctionLibrary::OnEmptyLog;

// ====================================
// Helper Functions
// ====================================

/* Getter function to return the LogEntries[] (used by the AnyPrintWidget) */
TArray<FLogEntry> UAnyPrintFunctionLibrary::GetLogEntries()
{
	return LogEntries;
}

/* Creates and formats a Timestamp for the LogEntry */
FString UAnyPrintFunctionLibrary::GetTimestamp()
{
	/* Get the current time and save it to the Now variable */
	FDateTime Now = FDateTime::Now();

	/* Return the Timestamp formatted in Hours:Minutes:Seconds by splitting the Now variable that we just created */
	return FString::Printf(TEXT("%02d:%02d:%02d"),
		Now.GetHour(),			// Get current Hour
		Now.GetMinute(),		// Get current Minutes
		Now.GetSecond()			// Get current Seconds
	);
}

// ====================================
// Global Functions
// ====================================

/* Empties the LogEntries[] and AnyPrintLogs.txt file (used by AnyPrintWidget) */
void UAnyPrintFunctionLibrary::EmptyLog()
{
	/* Empties the LogEntries[] */
	LogEntries.Empty();
	
	/* Notify listeners */
	OnEmptyLog.Broadcast();
}

/* Prints the Log in the user-defined LogColor by using SaveLogEntry() */
void UAnyPrintFunctionLibrary::PrintAnything(const FString& Log, FLinearColor LogColor)
{
	/* Create the LogEntry by adding the Timestamp to the Log */
	FString LogEntry = FString::Printf(TEXT("%s: %s"), *GetTimestamp(), *Log);
	
	/* Store the LogEntry in the LogEntries[] */
	LogEntries.Add(FLogEntry(LogEntry, LogColor));

	/* Notify listeners */
	OnLogUpdated.Broadcast();
}

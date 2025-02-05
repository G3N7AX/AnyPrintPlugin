// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugFunctionLibrary.h"

FString LogEntry;
FString LogFolder;
FString LogFile;
FString TempLogFileContent;

// ====================================
// Declare Static Variable
// ====================================

FOnLogUpdatedDelegate UDebugFunctionLibrary::OnLogUpdated;
TArray<FString> UDebugFunctionLibrary::LogEntries;

// ====================================
// Helper Functions
// ====================================

/* Returns the current time for the Log TimeStamp */
FString UDebugFunctionLibrary::GetTimeStamp()
{
	/* Get the current time */
	FDateTime Time = FDateTime::Now();

	int Hours = Time.GetHour();				// Get hours of the current time
	int Minutes = Time.GetMinute();			// Get minutes of the current time
	int Seconds = Time.GetSecond();			// Get seconds of the current time

	/* Format the TimeStamp */
	FString TimeStamp = FString::Printf(TEXT("%02d:%02d:%02d"), Hours, Minutes, Seconds);
	
	return TimeStamp;
}

/* Saves the Print (Log Entry) to a file (Logs/LogFile.txt) */
void UDebugFunctionLibrary::SaveLogToFile(const FString& LogMessage)
{
	/* Get paths to LogFolder and LogFile */
	LogFolder = FPaths::Combine(FPaths::ProjectDir(), TEXT("Saved/Logs"));
	LogFile = FPaths::Combine(LogFolder, TEXT("PrintedLogs.txt"));
		
	/* Check if the LogFolder exists */
	if (IFileManager::Get().DirectoryExists(*LogFolder))
	{
		/* If the LogFolder exists, check if the LogFile exists */
		if (IFileManager::Get().FileExists(*LogFile))
		{
			/* Format the LogEntry with the TimeStamp and the passed in String */
			LogEntry = FString::Printf(TEXT("\n%s\n%s"), *GetTimeStamp(), *LogMessage);

			/* Loads the log so that it can be appended */
			FFileHelper::LoadFileToStringArray(LogEntries, *LogFile);

			/* Appends (or Adds) the LogEntry to the LogEntries[] */
			LogEntries.Add(LogEntry);

			/* Save the LogEntries[] to the LogFile */
			FFileHelper::SaveStringArrayToFile(LogEntries, *LogFile);
		}

		else
		{
			/* Formats the new log entry */
			LogEntry = FString::Printf(TEXT("\n%s\n%s"), *GetTimeStamp(), *LogMessage);
			
			UE_LOG(LogTemp, Error, TEXT("LogFile does not exist..."));
			UE_LOG(LogTemp, Error, TEXT("Creating LogFile"));

			/* Save the String to the LogFile (This basically create the file if it doesn't exist) */
			FFileHelper::SaveStringToFile(*LogEntry, *LogFile);
			
			UE_LOG(LogTemp, Warning, TEXT("else: %s"), *LogEntry);
		}
	}

	else
	{
		/* If the directory does not exist, create the directory and create parent directories (if needed) */
		IFileManager::Get().MakeDirectory(*LogFolder, true);
	}
	
	SaveLogsToArray();
	
	OnLogUpdated.Broadcast();
}

/* Saves each log in the file (LogFile.txt) to an array of strings (LogEntries[]) to be read even after the Engine has stopped */
void UDebugFunctionLibrary::SaveLogsToArray()
{
	FString FileContent;

	// Load the content of the log file into the FileContent string
	if (FFileHelper::LoadFileToString(FileContent, *LogFile))
	{
		if (LogEntries.IsEmpty())
		{
			// Parse the content into the LogEntries array
			FileContent.ParseIntoArray(LogEntries, TEXT("\n-"), true);
		}
		else
		{
			/* Clear existing entries and parse the file into an array (LogEntries[]) */
			LogEntries.Empty();
			FileContent.ParseIntoArray(LogEntries, TEXT("\n-"), true);
		}
	}
	
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load LogFile.txt"));
	}
}

// ====================================
// Global Functions
// ====================================

/* Returns the LogEntries[] to be read in the EUW */
TArray<FString> UDebugFunctionLibrary::GetLogEntries()
{
	return LogEntries;
}

/* Empties the LogFile and the LogEntries[] */
void UDebugFunctionLibrary::EmptyLog()
{
	FFileHelper::SaveStringToFile(TEXT(""), *LogFile);
	LogEntries.Empty();

	OnLogUpdated.Broadcast();

	UE_LOG(LogTemp, Warning, TEXT("Log Emptied"));
}

void UDebugFunctionLibrary::PrintAnything(FString StringIn)
{
	SaveLogToFile(StringIn);
}

void UDebugFunctionLibrary::PrintAnythingIndex(int Index, FString StringIn)
{
	FString IndexString = FString::FromInt(Index);

	FString StringCombined = IndexString + " " + StringIn;

	SaveLogToFile(StringCombined);
}
// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Chao mung toi game Trau Bo Dai Chien"));
    PrintLine(TEXT("Doan 4 ki tu")); // so co the thay doi
    PrintLine(TEXT("Nhan Enter de tiep tuc..."));
    HiddenWord = "cake";
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Win!"));
    }
    else
    {
        PrintLine(TEXT("Lose!"));
    }
}
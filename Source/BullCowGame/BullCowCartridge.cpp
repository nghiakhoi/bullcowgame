// Fill out your copyright notice in the Description page of Project Settingss.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();

    PrintLine(TEXT("Hidden Word là: %s"), *HiddenWord); //Debug line

    PrintLine(TEXT("Chao mung toi game Trau Bo Dai Chien"));
    PrintLine(TEXT("Doan %i ki tu"), HiddenWord.Len());
    PrintLine(TEXT("Nhap vao tu ban doan va nhan Enter de tiep tuc..."));
    // Nhac nguoi choi doan chu
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
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("Tu an co %i ki tu, thu lai sau nhe!"), HiddenWord.Len());
        }

        PrintLine(TEXT("Lose!"));
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = "cakes";
    Lives = 4;
}
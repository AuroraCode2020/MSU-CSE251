/*
∗ project3
∗ By: AuroraCode2020
*/

#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define __USE_XOPEN
#include <time.h>
#include <stdbool.h>

struct event
{
    bool value;
    char WhatToDo[100];
    time_t date, start, end;
};

void DisplayMenu();
struct event AddEvent(struct event *ec, int eventNum);
void SortEvent(struct event *ec, int eventNum);
void DisplayAllEvent(struct event *ec, int eventNum);
time_t InputDate(char *notice);
time_t InputTime(char *prompt, time_t date);
void InputString(char *str, int max);
void DisplayNowEvent(struct event *ec, int eventNum);
void PrintTime(struct tm t);
void DeleteEvent(struct event *ec, int eventNum);

#endif
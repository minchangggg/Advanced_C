#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "People.h"

void Menu(const char* filename, MemberNode* list, Member member, char* searchValue, char* uid);
void readData(const char* filename, MemberNode* list);
void writeData(const char* filename, MemberNode* list);

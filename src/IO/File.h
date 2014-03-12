#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "../Structure/String.h"
#include "../Core/OO.h"

typedef enum
{
    READONLY = 0,
    WRITEONLY = 1,
    READWRITE = 2,
    APPEND = 3,
    CREATE = 4
} OpenMode;

RClass(File)
{
    RInherit(RObject);
    int IsOpen;
    OpenMode FileMode;
    FILE* BaseStream;
    int64_t FilePtr;
    int64_t Length;
};

int File_Open(File* This, String* Path, OpenMode FileMode);
int File_OpenChars(File* This, char* Path, OpenMode FileMode);
void File_Close(File* This);
int File_Flush(File* This);

void File_SetPosition(File* This, int64_t Position);
int64_t File_GetPosition(File* This);
int64_t File_GetLength(File* This);

void File_Read_String(File* This, String* Dest);
int File_Read_Chars(File* This, char* Dest);
void File_Read_Buffer(File* This, void* Dest, int64_t ByteCount);

void File_Write_String(File* This, String* Sorc);
void File_Write_Chars(File* This, char* Sorc);
void File_Write_Buffer(File* This, char* Sorc, int64_t Length);

void File_ReadWord(File* This, String* Dest);
void File_ReadLine(File* This, String* Dest);
void File_ReadAll(File* This, String* Dest);

void File_WriteLine(File* This, String* Sorc);

//Template Reads & Writes
#if 0
#include "_File.h"
#endif
#define _RTAddress "IO/_File.h"
#define _ClassName
#define _Attr 1

#include "../Core/Include_T1AllTypes.h"

#endif


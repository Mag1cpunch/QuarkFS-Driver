#pragma once

#include "DirectoryEntryType.h"

typedef struct {
	char JMP[3];
	char Signature[3];
	unsigned short BytesPerSector;
	unsigned short SectorsPerCluster;
	unsigned long SectorCount;
	unsigned long RootEntryCount;
	unsigned char MediaType;

	// index table information
	unsigned long IndexesPerTable;
	unsigned long FirstTablePointer;
	unsigned long LastFreeIndexPointer;

	unsigned long LastRecordedEntriesLimit;
	unsigned long IndexLogPointer;

	unsigned char ExtendedBootCodeExist;

	unsigned char *BootCode;
	char ExtendedBootCodeJMP[3];
} SuperBlock_t;

typedef struct {
	char Name[256];
	DirectoryEntryType Type;
	unsigned char Permissions;
	char Owner[128];

	unsigned long CreationTime;
	unsigned long LastModificationTime;
	unsigned long LastAccessTime;
	unsigned long MetadataChangeTime;

	unsigned char Reserved[69];

	// for files only

	unsigned long FileSize;
	unsigned long FileSectorCount;

	unsigned char FirstDataBlockSize; // 0 - small, 1 - large
	unsigned long DataBlockPointer;
} SuperEntry_t;

typedef struct {
	unsigned long ParentIndex;

	unsigned char *Data;
	unsigned char *ExtendedData;

	unsigned long NextDataBlock;
} DataBlock_t;


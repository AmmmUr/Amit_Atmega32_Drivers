#ifndef Headers_h
#define Headers_h

typedef  unsigned int uint8;

struct SimpleDb {
    uint8 student_ID;
    uint8 student_year;
    uint8 course1_ID;
    uint8 course1_grade;
    uint8 course2_ID;
    uint8 course2_grade;
    uint8 course3_ID;
    uint8 course3_grade;
}arr[length];

bool SDB_isFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8,uint8,uint8*,uint8*);
void SDB_DeleteEntry(uint8);
void SDB_ReadEntry(uint8);
void SDB_GetIdList(uint8*,uint8*);
bool SDB_IsIdExist(uint8);
#endif

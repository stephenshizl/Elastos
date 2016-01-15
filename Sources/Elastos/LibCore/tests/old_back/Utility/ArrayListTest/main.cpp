#include "test.h"
#include <stdio.h>
#include <stdlib.h>

typedef int (CTest::*PTestEntry)(int argc, char *argv[]);

PTestEntry TestEntry[] =
{
    &CTest::test_Constructor,
    &CTest::test_ConstructorI,
    &CTest::test_ConstructorLjava_util_Collection,
    &CTest::test_addILjava_lang_Object,
    &CTest::test_addLjava_lang_Object,
    &CTest::test_addAllILjava_util_Collection,
    &CTest::test_addAllLjava_util_Collection,
    &CTest::test_clear,
    &CTest::test_clone,
    &CTest::test_containsLjava_lang_Object,
    &CTest::test_ensureCapacityI,
    &CTest::test_getI,
    &CTest::test_indexOfLjava_lang_Object,
    &CTest::test_isEmpty,
    &CTest::test_lastIndexOfLjava_lang_Object,
    &CTest::test_removeI,
    &CTest::test_setILjava_lang_Object,
    &CTest::test_size,
    &CTest::test_toArray,
    &CTest::test_toArrayLjava_lang_Object,
    &CTest::test_trimToSize_01,
    &CTest::test_trimToSize_02,
    &CTest::test_addAll,
    &CTest::test_removeLjava_lang_Object,
    &CTest::test_removeRangeII,
};

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("*ERROR* Require test case number\n");
        return -1;
    }

    int nIndex = atoi(argv[1]) - 1;
    int nLength = sizeof(TestEntry) / sizeof(TestEntry[0]);

    if (nIndex < 0 || nIndex >= nLength) {
        printf("*ERROR* Invalid testing case number\n");
        return -1;
    }

//    TPINIT;

    CTest TestObject;

    int nQuitCode = (TestObject.*TestEntry[nIndex])(argc, argv);

//    TPEND;

    return nQuitCode;
}

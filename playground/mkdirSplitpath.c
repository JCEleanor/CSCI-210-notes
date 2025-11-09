#include "types.h"

extern struct NODE *root;
extern struct NODE *cwd;

// make directory
void mkdir(char pathName[])
{

    struct NODE *parentDir;
    struct NODE *newDir;
    char *dirName = NULL;
    char *baseName = NULL;

    parentDir = splitPath(pathName, baseName, dirName);

    newDir = malloc(sizeof(struct NODE));

    strcpy(newDir->name, baseName);
    newDir->fileType = 'D';
    parentDir->childPtr = newDir;
    newDir->parentPtr = parentDir;

    return;
}

// handles tokenizing and absolute/relative pathing options
struct NODE *splitPath(char *pathName, char *baseName, char *dirName)
{

    struct NODE *returnNode;

    returnNode = cwd;

    strcpy(baseName, pathName); // seg fault here
    strcpy(dirName, pathName);

    return returnNode;
}

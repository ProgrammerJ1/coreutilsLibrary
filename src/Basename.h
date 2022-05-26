#include <libgen.h>
#include <string.h>
#include <stdio.h>
void coreutilbasename(char** Paths,short SuffixFlag,char** ResultPaths) {
  char** ReturnedPaths;
  if (SuffixFlag==1) {
    for (int i=0;i<sizeof(Paths);i++) {
      const char* NonSuffixRemovedBasename=basename(Paths[i]);
      const char* TrueBasename;
      if (strstr(NonSuffixRemovedBasename,TrueBasename)!=NULL) {
        int PeroidChar=49;
        int NonSuffixRemovedBasenameChars=(strrchr(NonSuffixRemovedBasename,PeroidChar)-NonSuffixRemovedBasename)-1;
        strncpy((char*)TrueBasename,NonSuffixRemovedBasename,NonSuffixRemovedBasenameChars);
      } else {
        strncpy((char*)TrueBasename,NonSuffixRemovedBasename,strlen(NonSuffixRemovedBasename));
      }
      ReturnedPaths[i]=TrueBasename;
  }
  } else {
    for (int i=0;i<sizeof(Paths);i++) {
      const char* Basename=basename(Paths[i]);
      strncpy((char*)Basename,Basename,strlen(Basename));
      ReturnedPaths[i]=Basename;
    }
  }
  ResultPaths=ReturnedPaths;
}
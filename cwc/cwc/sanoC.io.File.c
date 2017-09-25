#include "sanoC.io.File.h"
private(File)
{
    FILE* stream;
    char* name;
    char* filemode;
};


void File_open(File this,char* name, char* fm)
{
    __(File,this).name = name;
    __(File,this).filemode = fm;
    __(File,this).stream = fopen(name,fm);
  //  printf("%s, %s \n\n",__(File,this).name, fm);
}
void File_close(File this)
{
    fclose(__(File,this).stream);

}
void File_reopen(File this)
{
    freopen(__(File,this).name, __(File,this).filemode, __(File,this).stream);
}
void File_rename(File this,char* newName)
{
    rename(__(File,this).name, newName);
    __(File,this).name = newName;
}
void File_remove(File this)
{
    fclose(__(File,this).stream);
    remove(__(File,this).name);
    call_uninit(File,this);
}
void File_flush(File this)
{
    fflush(__(File,this).stream);
}


long File_get_size(File this)
{
    Stream s = __(File,this).stream;
    long size = 0, currentLocation = ftell(s);
    fseek(s,0,SEEK_END);
    size = ftell(s);
    fseek(s,currentLocation,SEEK_SET);
    return size;
}
char* File_readAllText(File this)
{
    Stream s = __(File,this).stream;
    long size = File_get_size(this);
    char*  buffer = malloc(size+1);
    fread(buffer,size,1,s);
    buffer[size] = 0;
   // printf("%d bytes:\n %s\n",size,buffer);
  //  throw(55);
    return buffer;
}

void File_WriteLines( File this, char* s)
{
    Stream fs = __(File,this).stream;
   // printf("%d\n\n",strlen(s));
    fwrite(s,strlen(s),1,fs);
}

init(File)
{
    call_implement_methods(File);
    registerClass(File);
    init_private(File)
    {
        __(File,this).stream = null;
        __(File,this).name = "";
        __(File,this).filemode = "";
    }

}
implement_methods(File)
{
    Inherit(Object, File);
    implement_method(open,File_open);
    implement_method(rename,File_rename);
    implement_method(reopen,File_reopen);
    implement_method(remove,File_remove);
    implement_method(flush,File_flush);
    implement_method(readAllText,File_readAllText);
    implement_method(writeLines,File_WriteLines);
    implement_method(length,File_get_size);
    implement_method(close,File_close);
}


uninit(File)
{
    clear_private(File)
}


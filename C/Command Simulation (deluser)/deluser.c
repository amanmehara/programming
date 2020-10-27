// Copyright 2020 Dev Mashru
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
    The following program simulates the deluser command. shadow and passwd files should be in the same folder pointed to by the "PFILE" environment variable.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int del(FILE *fp, FILE *temp, char username[])
{
    char c[1000];
    int f=0;
    while(fgets(c,sizeof(c),fp) != NULL)
    {
        if(!strstr(c,username))
        {
            fputs(c,temp);
        }
        else
            f=1;
    }
    return f;
}

int deluser(char username[])
{
    FILE *passwd=NULL,*shadow=NULL,*temp=NULL;
    char envvar[250],path1[250],path2[250],path[250];
    int f,strle;
    if(getenv("PFILE") == NULL)
    {
        #ifdef _WIN32
            printf("PFILE environment variable not set. Defaulting to %s\\Documents\n",getenv("USERPROFILE"));
            setenv("PFILE", strcat(getenv("USERPROFILE"),"\\Documents"),0);
        #elif __unix__
            printf("PFILE environment variable not set. Defaulting to %s/Documents\n",getenv("HOME"));
            setenv("PFILE",strcat(getenv("HOME"),"/Documents"),0);
        #endif
    }
    strcpy(envvar,getenv("PFILE"));
    strle=strlen(path);
    #ifdef _WIN32
        if(envvar[strle-1] != '\\')
            strcat(envvar,"\\");
    #elif __unix__
        if(envvar[strle-1] != '/')
            strcat(envvar,"/");
    #endif
    strcpy(path,envvar);
    strcpy(path1,envvar);
    strcpy(path2,envvar);
    strcat(path1,"passwd");
    strcat(path2,"shadow");
    passwd=fopen(path1,"r");
    shadow=fopen(path2,"r");
    if(passwd == NULL || shadow == NULL)
    {
        printf("Unable to the file(s)\n");
        exit(0);
    }
    else
    {
        temp=fopen(strcat(path,"temp"),"w+");
        if(temp == NULL)
            printf("Unable to create temperory file\n");
        else
        {
            f=del(passwd,temp,username);
            fclose(passwd);
            fclose(temp);
            remove(path1);
            rename(path,path1);
        }
        strcpy(path,envvar);
        temp=fopen(strcat(path,"temp"),"w+");
        if(temp == NULL)
            printf("Unable to create temporary file\n");
        else
        {
            f=del(shadow,temp,username);
            fclose(shadow);
            remove(path2);
            fclose(temp);
            rename(path,path2);
        }
    }
    return f;
}

int main(int argc, char **argv)
{
    if(argv[1] == NULL)
    {
        printf("Invalid number of arguments\n");
        exit(0);
    }
    if(deluser(argv[1]))
        printf("Removed '%s' successfully\n",argv[1]);
    else
        printf("Username '%s' non-existant\n",argv[1]);
    return 0;
}

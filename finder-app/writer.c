#include <syslog.h>
#include <stdio.h>

/*Accepts the following arguments: the first argument is a full path to a file (including filename) on the filesystem, referred to below as writefile; the second argument is a text string which will be written within this file, referred to below as writestr

Exits with value 1 error and print statements if any of the arguments above were not specified

Creates a new file with name and path writefile with content writestr, overwriting any existing file and creating the path if it doesn’t exist. Exits with value 1 and error print statement if the file could not be created.*/
int main(int argc, char *argv[]){
   //Code
    if( argc != 3){
        printf("Not enough argumets\n");

        return 1;
    }

    openlog("the writer function", LOG_CONS , LOG_USER );


    char* path = argv[1];
    char* text = argv[2];

    FILE *newfile = fopen(path, "w");

    if (newfile == NULL){
        syslog(LOG_ERR, "File cannot be opened");
        return 1;
    }
    else{
        int result = fprintf(newfile, "%s", text);
        if( result < 0 )
        {
            syslog(LOG_ERR, "Error writing to file");
            return 1;
        }
    }

    fclose(newfile);
    syslog(LOG_DEBUG, "Writing '%s' to %s", text, path);


   return 0;
}
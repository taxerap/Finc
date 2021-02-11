/*************************************************************************************************
*                                                                                                *
*                                            [ Finc ]                                            *
*                                                                                                *
**************************************************************************************************
*                                                                                                *
*                              A free, open-source utility program.                              *
*                            (c) 2020 Taxerap, some rights reserved.                             *
*                                                                                                *
*              Finc is a free software. You can freely do whatever you want with it              *
*     under the JUST DON'T BOTHER ME PUBLIC LICENSE (hereinafter referred to as the license)     *
*                                   published by mhtvsSFrpHdE.                                   *
*                                                                                                *
*  By the time this line is written, the version of the license document is 1, but you may use   *
* any later version of the document released by mhtvsSFrpHdE <https://github.com/mhtvsSFrpHdE>.  *
*                                                                                                *
*               Finc is created, intended to be useful, but without any warranty.                *
*                      For more information, please forward to the license.                      *
*                                                                                                *
*       You should have received a copy of the license along with the source code of this        *
*  program. If not, please see https://github.com/mhtvsSFrpHdE/ipcui/blob/master/LICENSE_JDBM.   *
*                                                                                                *
*          For more information about the project, please visit my Github repository at          *
*                                https://github.com/Taxerap/Finc.                                *
*                                                                                                *
*                             I don't know why I did this but yeah.                              *
*                                                                                                *
**************************************************************************************************/

#include "pch.h"

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

static const size_t FINC_MAX_PATH_LEN = 256ULL;

#ifdef FINC_TARGET_WINDOWS
    static const char FINC_SHELL_NL = '^';
#else
    static const char FINC_SHELL_NL = '\\';
#endif

///
/// \brief Scan and print files with extension
///
/// Scan and print all files with the given extension in the given directory into output.<BR />
/// This function searches recursively, so all the subdirectories will be searched too.
///
/// \param extension Extension to search for
/// \param directory Directory for searching
/// \param output Where to output. Feed stdout if you just want console output
///
void
finc_ScanAndPrint( const char *extension, const char *directory, FILE *output )
{
    DIR *dir = opendir(directory);
    struct dirent *f_entry = readdir(dir);
    struct stat64 f_stat;

    if (!dir || !f_entry)
        return;

    do
    {
        if (!strcmp(f_entry->d_name, ".") || !strcmp(f_entry->d_name, ".."))
            continue;

        char path[FINC_MAX_PATH_LEN];
        snprintf(path, FINC_MAX_PATH_LEN, "%s/%s", directory, f_entry->d_name);

        char *dot_occurrence = strrchr(f_entry->d_name, '.');
        if (dot_occurrence && !strcmp(dot_occurrence, extension) && strlen(dot_occurrence) == strlen(extension))
            fprintf(output, "%s%c\n", path, FINC_SHELL_NL);

        if (!stat64(path, &f_stat) && S_ISDIR(f_stat.st_mode))
            finc_ScanAndPrint(extension, path, output);
    } while ((f_entry = readdir(dir)));

    closedir(dir);
}

int
main( int argc, char *argv[] )
{
    FILE *output;
    if (argc <= 1)
        output = fopen("finc.txt", "w");
    else if (!strcmp(argv[1], "stdout"))
        output = stdout;
    else
        output = fopen(argv[1], "w");

    if (!output)
    {
        perror("Finc cannot open output file");
        abort();
    }

    finc_ScanAndPrint(".c", "src", output);

    if (output != stdout)
        fclose(output);
    return EXIT_SUCCESS;
}

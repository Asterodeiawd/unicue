/************************************************************************/
/*                                                                      */
/* Traveller 1.4                                                        */
/* A batch tool to convert files from ansi code-page to Unicode.        */
/* It is a part of Unicue Project.                                      */
/*                                                                      */
/* Author:  kuyur (kuyur@kuyur.net)                                    */
/* Published under GPLv3                                                */
/* http://www.gnu.org/licenses/gpl-3.0.en.html                          */
/*                                                                      */
/* Project URL: http://github.com/kuyur/unicue                          */
/*                                                                      */
/************************************************************************/

#include "stdafx.h"
#include <vector>
#include "cmdline.h"

void freeCParameters(CParameters &param)
{
    std::vector<wchar_t*>::iterator iter = param.folders.begin();
    for (; iter != param.folders.end(); ++iter)
    {
        delete [](*iter);
    }
    param.folders.clear();
}

CParameters parseCmdLine(const wchar_t *lpstrCmdLine)
{
    CParameters param;
    param.appMode = MODE_SETTING;
    if (NULL != lpstrCmdLine && wcslen(lpstrCmdLine) != 0)
    {
        param.appMode = MODE_PROCESS;
        // find input folder paths
        const wchar_t *next = wcschr(lpstrCmdLine, L'"');
        const wchar_t *end = lpstrCmdLine + wcslen(lpstrCmdLine);
        const wchar_t *first = NULL, *second = NULL;
        for (; next && (next != end); next = wcschr(next+1, L'"'))
        {
            if (first)
            {
                // found a folder path
                second = next;
                // copy
                int len = second - first - 1;
                wchar_t *folderPath = new wchar_t[len + 1];
                wmemcpy(folderPath, first+1, len);
                folderPath[len] = L'\0';
                param.folders.push_back(folderPath);
                // reset
                first = NULL;
            }
            else
            {
                first = next;
            }
        }
     }
    return param;
}

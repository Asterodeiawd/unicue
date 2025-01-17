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

#pragma once

#ifndef TRAVELLER_CONFIG_H
#define TRAVELLER_CONFIG_H

#include <windows.h>
#include <atlbase.h>
#include <atlapp.h>
#include <atlmisc.h>
#include "..\c4-lib\tinyxml.h"

typedef struct CConfig_tag
{
    BOOL isIgnoreUtf8;
    BOOL isIgnoreUtf8WithoutBom;
    BOOL isIgnoreHidden;
    BOOL isOverride;
    BOOL isBackupOrig;
    BOOL isAutoFixCueError;
    ATL::CString extensions;
    ATL::CString templateString;
    ATL::CString charmapConfig;
}CConfig;

BOOL LoadConfigFile(TiXmlDocument *xmlfile, CConfig &config);
BOOL SaveConfigFile(LPCTSTR configPath, const CConfig &config);
void SetDefault(CConfig &config);

#endif // TRAVELLER_CONFIG_H

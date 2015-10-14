/* 
 * File:   fonts.h
 * Author: WebMaster
 *
 * Created on 13 de octubre de 2015, 12:43
 */

#ifndef GWI_PLATFORM_WIN32_FONTS_H
#define	GWI_PLATFORM_WIN32_FONTS_H

#include <gwi.h>
#include <windows.h>
#include "private/handle.h"

#ifdef	__cplusplus
extern "C" {
#endif

static gwi_font *
gwi_win32_font_dialog(gwi_handle *handle) 
{
  CHOOSEFONT cf;
  LOGFONT  fl;
  cf.lStructSize = sizeof(cf);
  cf.hwndOwner   = handle->hwnd;
  cf.lpLogFont   = &fl;
  cf.Flags       = CF_EFFECTS|CF_FORCEFONTEXIST;
  cf.rgbColors   = RGB(0,0,0);
  cf.lpTemplateName = NULL;
  cf.nFontType      = REGULAR_FONTTYPE;
  if (ChooseFont(&cf)) {
    gwi_font *fnt;
    fnt = gwi_malloc(sizeof *fnt);
    if (!fnt) return NULL;
    fnt->handle = CreateFontIndirect(&fl);
    return fnt;
  }
  return NULL;
}

#ifdef	__cplusplus
}
#endif

#endif	/* GWI_PLATFORM_WIN32_FONTS_H */


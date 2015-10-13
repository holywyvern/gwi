/*
 * Copyright 2015 Ramiro Rojo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef GWI_PLATFORM_WIN32_COMMON_H
#define	GWI_PLATFORM_WIN32_COMMON_H

#include <gwi.h>
#include <windows.h>

#ifdef	__cplusplus
extern "C" {
#endif

static wchar_t *
gwi_utf8_to_utf16(const char *str)
{
  int size;
  wchar_t *buff;
  size = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
  if (!size) return NULL;
  buff = gwi_malloc((size + 1) * sizeof *buff);
  if (!MultiByteToWideChar(CP_UTF8, 0, str, -1, buff, size)) {
      gwi_free(buff);
      return NULL;
  }
  buff[size] = 0;
  return buff;
}

static char *
gwi_utf16_to_utf32(const wchar_t *str)
{
  int   size;
  char *buff;
  size = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
  if (!size)
      return NULL;
  buff = gwi_malloc((size + 1) * sizeof *buff);
  if (!WideCharToMultiByte(CP_UTF8, 0, str, -1, buff, size, NULL, NULL)) {
      return NULL;
  }
  buff[size] = 0;
  return buff;
}


#ifdef	__cplusplus
}
#endif

#endif	/* GWI_PLATFORM_WIN32_COMMON_H */


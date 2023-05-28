#define BUFSIZ 512

#ifndef FILE

struct _iobuf
	{
#ifdef pdp11		/* really #ifdef oldunix */
	char *_ptr;
	int _cnt;
#else
	int _cnt;
	char *_ptr;
#endif
	char *_base;
	int _bufsiz;
	short _flag;
	int _file;
	char *_fptr;		/* ANSI void * */
	char _tinybuf;		/* used when _IONBF */
	char *_filename;
	int (*_filbuf)();
	int (*_flsbuf)();
	int (*_readfunc)();
	int (*_writefunc)();
	long (*_seekfunc)();
	int (*_closefunc)();
	int (*_errfunc)();
	struct _iobuf *_next;
	/* spare? */
	};

#define FILE struct _iobuf

#endif

#define EOF (-1)

#define _IOFBF	    0
#define	_IOREAD	   01
#define	_IOWRT	   02
#define	_IONBF	   04
#define	_IOMYBUF  010
#define	_IOEOF	  020
#define	_IOERR	  040
#define	_IOSTRG	 0100
#define	_IOLBF	 0200
#define	_IORW	 0400
#define _IOFPTR	02000	/* I/O functions take _fptr instead of _file */
#define _IOSTFN	04000	/* filename statically allocated (don't free) */

#ifndef NULL
#define NULL 0
#endif

#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2

#define _NFILE 3	/* not used; only for compatibility */

extern FILE _iob[];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define getc(fp) ((fp)->_cnt-- > 0 ? (*(fp)->_ptr++ & 0377) : \
					_filbuf(fp))

#ifndef PUTCLBUF

#define putc(c, fp) ((fp)->_cnt-- > 0 ? (*(fp)->_ptr++ = (c)) : \
					_flsbuf(c, fp))

#else

#define putc(c, fp) ((fp)->_cnt-- > 0 ? \
		((*(fp)->_ptr = (c)) == '\n' && ((fp)->_flag & _IOLBF) ? \
					_flsbuf(*(fp)->_ptr, fp) : \
					*(fp)->_ptr++) \
		: _flsbuf(c, fp))

#endif

#define getchar() getc(stdin)
#define putchar(c) putc(c, stdout)

#define clearerr(fp) ((fp)->_flag &= ~(_IOEOF | _IOERR))
#define feof(fp) ((fp)->_flag & _IOEOF)
#define ferror(fp) ((fp)->_flag & _IOERR)

#define fileno(fp) ((fp)->_file)
#define _fileptr(fp) ((fp)->_fptr)

#ifndef __STDC__

extern FILE *fdopen();
extern char *fgets();
extern FILE *fopen();
extern FILE *freopen();
extern long int ftell();
extern char *gets();

#ifdef EXTENSIONS

extern char *saprintf();
extern FILE *stropen();
extern FILE *strnopen();
extern char *vsaprintf();

#endif

#else

#include <stdarg.h>		/* for va_list */

extern int fclose(FILE *);
extern FILE *fdopen(int, char *);
extern int fflush(FILE *);
extern int fgetc(FILE *);
extern char *fgets(char *, int, FILE *);
extern FILE *fopen(char *, char *);
extern int fprintf(FILE *, char *, ...);
extern int fputc(char, FILE *);
extern int fputs(char *, FILE *);
extern int fread(char *, unsigned int, int, FILE *);
extern FILE *freopen(char *, char *, FILE *);
extern int fscanf(FILE *, char *, ...);
extern int fseek(FILE *, long int, int);
extern long int ftell(FILE *);
extern int fwrite(char *, unsigned int, int, FILE *);
extern char *gets(char *);
/* getw? */
extern int printf(char *, ...);
extern int puts(char *);
/* putw? */
extern void rewind(FILE *);
extern int scanf(char *, ...);
extern int setbuf(FILE *, char *);
extern int setbuffer(FILE *, char *, int);	/* Berkeley */
extern int setlinebuf(FILE *);			/* Berkeley */
extern int setvbuf(FILE *, char *, int, int);
extern int sprintf(char *, char *, ...);
extern int sscanf(char *, char *, ...);
extern int ungetc(char, FILE *);
extern int vfprintf(FILE *, char *, va_list);
extern int vprintf(char *, va_list);
extern int vsprintf(char *, char *, va_list);

#ifdef EXTENSIONS

extern void fabort(FILE *);
extern int fdclose(FILE *);
extern int flushall(void);
extern int putpad(FILE *, char *, int, int, int);
extern char *saprintf(char *, ...);
extern int scanfiles(int (*)());
extern int seterrfn(FILE *, int (*)());
extern int setfuncs(FILE *, int (*)(), int (*)(), long int (*)(), int (*)());
extern int snprintf(char *, int, char *, ...);
extern FILE *stropen(char *, char *);
extern FILE *strnopen(char *, int, char *);
extern char *vsaprintf(char *, va_list);

#endif

#endif

/*Now we will start the description of the library of the course 'cs50'  */

/**
 * CS50 Library for C
 * https://github.com/cs50/libcs50
 *
 * Based on Eric Roberts' genlib.c and simpio.c.
 *
 * Copyright (c) 2022
 * All rights reserved
 *
 * BSD 3-Clause License
 * http://www.opensource.org/licenses/BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of CS50 nor the names of its contributors may be used
 *   to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CS50_H
#define CS50_H

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * Our own type for (pointers to) strings.
 */
typedef char *string;

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent char; if text is not a single char, user is prompted
 * to retry. If line can't be read, returns CHAR_MAX.
 */
char get_char(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent double as precisely as possible; if text does not represent
 * a double or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns DBL_MAX.
 */
double get_double(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent float as precisely as possible; if text does not represent
 * a float or if value would cause underflow or overflow, user is prompted
 * to retry. If line can't be read, returns FLT_MAX.
 */
float get_float(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent int; if text does not represent an int in [-2^31, 2^31 - 1)
 * or would cause underflow or overflow, user is prompted to retry. If line
 * can't be read, returns INT_MAX.
 */
int get_int(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent long; if text does not represent a long in
 * [-2^63, 2^63 - 1) or would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns LONG_MAX.
 */
long get_long(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns the
 * equivalent long long; if text does not represent a long long in
 * [-2^63, 2^63 - 1) or would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns LLONG_MAX.
 */
long long get_long_long(const char *format, ...) __attribute__((format(printf, 1, 2)));

/**
 * Prompts user for a line of text from standard input and returns
 * it as a string (char *), sans trailing line ending. Supports
 * CR (\r), LF (\n), and CRLF (\r\n) as line endings. If user
 * inputs only a line ending, returns "", not NULL. Returns NULL
 * upon error or no input whatsoever (i.e., just EOF). Stores string
 * on heap, but library's destructor frees memory on program's exit.
 */
string get_string(va_list *args, const char *format, ...) __attribute__((format(printf, 2, 3)));
#define get_string(...) get_string(NULL, __VA_ARGS__)

#endif

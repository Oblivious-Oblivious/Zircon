/**
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Nick Strupat
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef __ALIGNED_ALLOCATION_H_
#define __ALIGNED_ALLOCATION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#if defined(__APPLE__) || defined(__linux__)

#include <stdlib.h>

void *aligned_malloc(size_t size, size_t alignment) {
    void * pointer;
	posix_memalign(&pointer, alignment, size);
	return pointer;
}

#elif defined(_WIN32)

#include <crtdbg.h>
void * aligned_malloc(size_t size, size_t alignment) {
    /* This is reduced to a call to `_aligned_malloc`  when _DEBUG is not defined */
    return _aligned_malloc_dbg(size, alignment, __FILE__, __LINE__);
}

#else

/* https://sites.google.com/site/ruslancray/lab/bookshelf/interview/ci/low-level/write-an-aligned-malloc-free-function */

#include <stdlib.h>

void *aligned_malloc(size_t size, size_t alignment) {
    void *p1; /* original block */
	void **p2; /* aligned block */
	int offset = alignment - 1 + sizeof(void*);
	if((p1 = (void*)malloc(size + offset)) == NULL)
        return NULL;
	
    p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
	p2[-1] = p1;
	return p2;
}

#endif

#if defined(__APPLE__) || defined(__linux__)

#include<stdlib.h>

void aligned_free(void *pointer) {
	free(pointer);
}

#elif defined(_WIN32)

#include <crtdbg.h>

void aligned_free(void *pointer) {
	/* This is reduced to a call to `_aligned_free` when _DEBUG is not defined */
	_aligned_free_dbg(pointer);
}

#else

/* https://sites.google.com/site/ruslancray/lab/bookshelf/interview/ci/low-level/write-an-aligned-malloc-free-function */
#include <stdlib.h>

void aligned_free(void *pointer) {
	free(((void **)pointer)[-1]);
}

#ifdef __cplusplus
}
#endif

#endif

#endif

/*
 * memlib.c - a module that simulates the memory system.	Needed because it 
 *						allows us to interleave calls from the student's malloc package 
 *						with the system's malloc package in libc.

 메모리 시스템을 시뮬레이트 하는 모듈. 시스템 malloc 패키지를 학생의 malloc 패키지에 $@하기 위해 필요하다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include "memlib.h"
#include "config.h"

/* private variables */
static char *heap;			// 힙 첫번째 바이트에 포인터
static char *mem_brk;		//힙에 마지막 바이트에 포인터
static char *mem_max_addr;	//가장 큰 적합한 힙에 포인터

/* 
 * mem_init - initialize the memory system model
 */
void mem_init(void){
	int dev_zero = open("/dev/zero", O_RDWR);//dev/zero 파일을 읽기 쓰기 용으로 연다, 정수형 변수를 반환한다.
	heap = mm	ap((void *)0x800000000, /* suggested start*/
			MAX_HEAP,				/* length */
			PROT_WRITE,				/* permissions */
			MAP_PRIVATE,			/* private or shared? */
			dev_zero,				/* fd */
			0);						/* offset (dunno) */
			//0x800000000주소에 0오프셋을 가지고 MAX_HEAP바이트 만큼 대응시킨다. 이 페이지는 쓸 수 있으며 대응되는객체는 다른 프로세서와 공유할 수 없다.
	mem_max_addr = heap + MAX_HEAP; //mem_max_addr에 적합한 가장 큰 힙에 포인터를 넣어준다.
	mem_brk = heap;					/* heap is empty initially */ //힙은 처음에 비어진 값을 갖니다
}

/* 
 * mem_deinit - free the storage used by the memory system model
 */
void mem_deinit(void){//저장소를 메모리 시스템 모델로 풀어준다.
	munmap(heap, MAX_HEAP);
}

/*
 * mem_reset_brk - reset the simulated brk pointer to make an empty heap
 */
void mem_reset_brk(){
	mem_brk = heap;// brk 포인터를 리셋해 준다 비어있는 힙을 만들기 위해
}

/* 
 * mem_sbrk - simple model of the sbrk function. Extends the heap 
 *		by incr bytes and returns the start address of the new area. In
 *		this model, the heap cannot be shrunk.
 */
void *mem_sbrk(int incr) {//incr bytes만큼 heap을 확장하고 새 구역에 첫번째 주소를 반환한다. 여기서 힙은 줄어들 수 없다.
	char *old_brk = mem_brk;//힙에 마지막 바이트 포인터 문자

	if ( (incr < 0) || ((mem_brk + incr) > mem_max_addr)) {
		errno = ENOMEM;
		fprintf(stderr, "ERROR: mem_sbrk failed. Ran out of memory...\n");
		return (void *)-1;
	}
	mem_brk += incr;
	return (void *)old_brk;
}

/*
 * mem_heap_lo - return address of the first heap byte
 */
void *mem_heap_lo(){
	return (void *)heap;//첫번째 힙 바이트의 주소를 반환한다.
}

/* 
 * mem_heap_hi - return address of last heap byte
 */
void *mem_heap_hi(){
	return (void *)(mem_brk - 1);//마지막 힙 바이트의 주소를 반환한다.
}

/*
 * mem_heapsize() - returns the heap size in bytes
 */
size_t mem_heapsize() {
	return (size_t)((void *)mem_brk - (void *)heap);//heap 크기를 bytes로 반환한다&size_t로 형변환
}

/*
 * mem_pagesize() - returns the page size of the system
 */
size_t mem_pagesize(){//시스템에 페이지(블록) 크기를 반환한다.
	return (size_t)getpagesize();//
}

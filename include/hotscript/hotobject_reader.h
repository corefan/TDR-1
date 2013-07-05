#ifndef _H_HOT_OBJECT_READER
#define _H_HOT_OBJECT_READER

#include "hotpot/hp_platform.h"

#include "hotscript/hotobject.h"
#include "hotpot/hp_reader.h"

#ifndef _DEC_HOTOBJECTCONSTITERATORA
#define _DEC_HOTOBJECTCONSTITERATORA
typedef struct _HotObjectReader HotObjectReader;
#endif//_DEC_HOTOBJECTCONSTITERATORA


typedef struct _HotObjectConstStackNode
{
	const HotObject *ho;
	hpuint32 current_index;
	const HotObject *current_ho;
}HotObjectConstStackNode;

struct _HotObjectReader
{
	HPAbstractReader super;
	HotObjectConstStackNode stack[HOTOBJECT_MAX_STACK_DEEP];
	hpuint32 stack_num;

	char name[HOTOBJECT_MAX_NAME_LENGTH];
};

hpint32 hotobject_reader_seek(HPAbstractReader *super, hpuint32 index);
hpint32 hotobject_reader_init(HotObjectReader* self, const HotObject *hotobject);

#endif//_H_HOT_OBJECT_READER

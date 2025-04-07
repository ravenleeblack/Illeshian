#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>

// Add scope table includes


#include "scope_types.h"
#include "scope_api.h"
#include "scope_table.h"

#include "color.h"
#include "asm_types.h"
#include "error_types.h"
#include "express_handler.h"
#include "token_types.h"
#include "tool_types.h"
#include "type_types.h"
#include "configure.h"

#define bool int	
#define true 1
#define false 0

#define max_param      10
#define text_length    500

#define DEFAULT_PASSAGE_BUFFER 4096
#define PASSAGE_READ_FLAGS        0x01
#define PASSAGE_WRITE_FLAGS       0x02
#define PASSAGE_BIDIRECTIONAL_FLAGS 0x03
#define PASSAGE_MEMORY_FLAGS      0x04




















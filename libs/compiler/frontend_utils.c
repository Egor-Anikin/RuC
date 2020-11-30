/*
 *	Copyright 2020 Andrey Terekhov, Maxim Menshikov
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 */

#include "frontend_utils.h"
#include "uniio.h"
#include "keywords.h"
#include "scanner.h"


/** Занесение ключевых слов в reprtab */
void read_keywords(compiler_context *context)
{
	in_set_buffer(context->io, KEYWORDS);

	context->keywordsnum = 1;
	getnext(context);
	nextch(context);
	while (scan(context) != LEOF)
	{
		; // чтение ключевых слов
	}

	in_clear(context->io);
}

/*
 *	Copyright 2020 Andrey Terekhov, Egor Anikin
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

#pragma once

#include "workspace.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct environment environment;

/** Structure for connecting files */
typedef struct linker
{
	workspace *ws;				/**< Initial arguments */

	int included[MAX_PATHS];	/**< List of already added files */
	size_t count; 				/**< Number of added files */

	size_t current; 			/**< Index of the current file */
} linker;


/**
 *	Create linker structure
 *
 *	@param	lk		Linker structure
 *	@param	ws		Workspace structure	 
 *
 *	@return	@c 0 on success, @c -1 on failure
 */
linker lk_create(workspace *const ws);

/**
 *	Preprocess all files from workspace
 *
 *	@param	env		Preprocessor environment
 *
 *	@return	@c 0 on success, @c -1 on failure
 */
//int lk_preprocess_all(environment *const env);

/**
 *	Include current file from environment to target output
 *
 *	@param	env		Preprocessor environment
 *
 *	@return	@c 0 on success, @c -1 on failure
 */
int lk_include(environment *const env);

/**
 *	 Get current file name from linker
 *
 *	@param	lk	Preprocessor linker
 *
 *	@return	File
 */
const char *lk_get_current(const linker *const lk);

size_t lk_get_count(const linker *const lk);

int lk_get_included(const linker *const lk, size_t index);

int lk_open_source(environment *const env, const size_t index);

int lk_preprocess_file(environment *const env, const size_t number);

#ifdef __cplusplus
} /* extern "C" */
#endif

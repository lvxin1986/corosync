/*
 * Copyright (c) 2003-2004 MontaVista Software, Inc.
 *
 * All rights reserved.
 *
 * Author: Steven Dake (sdake@mvista.com)
 *
 * This software licensed under BSD license, the text of which follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the MontaVista Software, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "../include/ais_types.h"
#include "../include/saCkpt.h"
#include "aispoll.h"
#include "parse.h"

#ifndef CKPT_H_DEFINED
#define CKPT_H_DEFINED

struct saCkptCheckpointSection {
	struct list_head list;
	SaCkptSectionDescriptorT sectionDescriptor;
	void *sectionData;
	poll_timer_handle expiration_timer;
};

struct saCkptCheckpoint {
	struct list_head list;
	SaNameT name;
	SaCkptCheckpointCreationAttributesT checkpointCreationAttributes;
	struct list_head checkpointSectionsListHead;
	int referenceCount;
	int unlinked;
	poll_timer_handle retention_timer;
	int expired;
};

struct saCkptSectionIteratorEntry {
	int active;
	struct saCkptCheckpointSection *checkpointSection;
};

struct saCkptSectionIterator {
	struct list_head list;
	struct saCkptSectionIteratorEntry *sectionIteratorEntries;
	int iteratorCount;
	int iteratorPos;
};

struct libckpt_ci {
	struct list_head checkpoint_list;
	struct saCkptSectionIterator sectionIterator;
};

extern struct service_handler ckpt_service_handler;

#endif /* CKPT_H_DEFINED */

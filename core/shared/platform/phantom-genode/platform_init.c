/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "platform_api_vmcore.h"
#include <stddef.h>
#include <stdarg.h>

extern void wait_for_continue();

int
bh_platform_init()
{
    // printf("Waiting...\n");
    // wait_for_continue();
    return 0;
}

void
bh_platform_destroy()
{
}

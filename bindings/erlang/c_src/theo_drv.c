/*
 * Copyright (c) 2011 Iwata <iwata@quasiquote.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <string.h>
#include <erl_driver.h>

#include "config.h"
#include "theo.h"

typedef struct {
	ErlDrvPort port;
} theo_data;

static ErlDrvData
theo_drv_start(ErlDrvPort port, char *buff)
{
	theo_data *d = (theo_data *)driver_alloc(sizeof(theo_data));
        d->port = port;

        return (ErlDrvData)d;
}

static void
theo_drv_stop(ErlDrvData handle)
{
        driver_free((char *)handle);
}

static void
theo_drv_output(ErlDrvData handle, char *buff, int bufflen)
{
	theo_data *d = (theo_data *)handle;
	const char *ret = theo();

	driver_output(d->port, ret, strlen(ret));
}

ErlDrvEntry theo_driver_entry = {
	NULL,			/* F_PTR init, N/A */
	theo_drv_start,		/* L_PTR start, called when port is opened */
	theo_drv_stop,		/* F_PTR stop, called when port is closed */
	theo_drv_output,	/* F_PTR output, called when erlang has sent */
	NULL,			/* F_PTR ready_input, called when input descriptor ready */
	NULL,			/* F_PTR ready_output, called when output descrip
				   tor ready */
	"theo_drv",		/* char *driver_name, the argument to open_port */
	NULL,			/* F_PTR finish, called when unloaded */
	NULL,			/* handle */
	NULL,			/* F_PTR control, port_command callback */
	NULL,			/* F_PTR timeout, reserved */
	NULL			/* F_PTR outputv, reserved */
};

DRIVER_INIT(theo_drv) /* must match name in driver_entry */
{
	return &theo_driver_entry;
}

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "mlx_int.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/extensions/XI2.h>
#include <X11/extensions/XInput2.h>

#include <stdbool.h>

bool	x_mouse_init(t_mlx* mlx)
{
	Display*	display = ((t_xvar*)mlx->mlx_ptr)->display;
	//
	int major_opcode, first_event, first_error;
	if (!XQueryExtension(display, "XInputExtension", &major_opcode, &first_event, &first_error))
		return false;
	unsigned char mask[XIMaskLen(XI_LASTEVENT)] = {0, };
	XISetMask(mask, XI_RawMotion);

	XIEventMask event_mask;
	event_mask.deviceid = XIAllDevices;
	event_mask.mask_len = sizeof(mask);
	event_mask.mask = mask;

	XSelectInput(display, DefaultRootWindow(display), PointerMotionMask | ButtonPressMask);
	XISelectEvents(display, DefaultRootWindow(display), &event_mask, 1);
	XFlush(display);
	return true;
}

void	x_mouse_event_handler(t_game* game)
{
	Display*	display = ((t_xvar*)game->mlx.mlx_ptr)->display;

	while (XPending(display))
	{
		XEvent ev;
		XNextEvent(display, &ev);

		if (game->state != STATE_PLAYING)
			continue ;

		if (ev.type != GenericEvent)
			continue;

		if (!XGetEventData(display, &ev.xcookie))
			continue;

		if (ev.xcookie.evtype == XI_RawMotion)
		{
			XIRawEvent* raw = (XIRawEvent*)ev.xcookie.data;

			double dx = 0;
			double dy = 0;

			if (XIMaskIsSet(raw->valuators.mask, 0))
				dx = raw->raw_values[0];

			if (XIMaskIsSet(raw->valuators.mask, 1))
				dy = raw->raw_values[1];

			game->player.rotation_speed.x = -dx * MOTION_X_FACTOR;
			game->player.rotation_speed.y = -dy * MOTION_Y_FACTOR;
		}
		XFreeEventData(display, &ev.xcookie);
	}
}

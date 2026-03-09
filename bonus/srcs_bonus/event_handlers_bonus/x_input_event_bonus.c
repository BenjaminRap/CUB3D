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
	Window		window = ((t_win_list*)mlx->mlx_win)->window;
	
	XGCValues values;
	values.graphics_exposures = False;

	XChangeGC(display, ((t_win_list*)mlx->mlx_win)->gc, GCGraphicsExposures, &values);

	mlx->delete = XInternAtom(display, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(display, window, &mlx->delete, 1);

	int major_opcode, first_event, first_error;
	if (!XQueryExtension(display, "XInputExtension", &major_opcode, &first_event, &first_error))
		return false;
	unsigned char mask[XIMaskLen(XI_LASTEVENT)] = {0, };
	XISetMask(mask, XI_Motion);
	XISetMask(mask, XI_KeyPress);
	XISetMask(mask, XI_KeyRelease);
	XISetMask(mask, XI_ButtonPress);
	XISetMask(mask, XI_ButtonRelease);

	XIEventMask event_mask;
	event_mask.deviceid = XIAllDevices;
	event_mask.mask_len = sizeof(mask);
	event_mask.mask = mask;

	unsigned char raw_mask[XIMaskLen(XI_LASTEVENT)] = {0, };
	XISetMask(raw_mask, XI_RawMotion);

	XIEventMask event_raw_mask;
	event_raw_mask.deviceid = XIAllDevices;
	event_raw_mask.mask_len = sizeof(raw_mask);
	event_raw_mask.mask = raw_mask;

	XISelectEvents(display, window, &event_mask, 1);
	XISelectEvents(display, DefaultRootWindow(display), &event_raw_mask, 1);
	XFlush(display);
	return true;
}

void	handler_raw_motion(t_game* game, XIRawEvent* e)
{
	double dx = 0;
	double dy = 0;

	if (XIMaskIsSet(e->valuators.mask, 0))
		dx = e->raw_values[0];

	if (XIMaskIsSet(e->valuators.mask, 1))
		dy = e->raw_values[1];

	game->player.rotation_speed.x = -dx * MOTION_X_FACTOR;
	game->player.rotation_speed.y = -dy * MOTION_Y_FACTOR;
	return ;
}

void	x_mouse_event_handler(t_game* game)
{
	Display*	display = ((t_xvar*)game->mlx.mlx_ptr)->display;

	while (XPending(display))
	{
		XEvent ev;
		XNextEvent(display, &ev);

		if (ev.type == ClientMessage && (Atom)ev.xclient.data.l[0] == game->mlx.delete)
			destroy_handler(game);
		if (ev.type != GenericEvent)
			continue;

		if (!XGetEventData(display, &ev.xcookie))
			continue;

		if (ev.xcookie.evtype == XI_RawMotion)
		{
			handler_raw_motion(game, ev.xcookie.data);
			XFreeEventData(display, &ev.xcookie);
			continue ;
		}
		XIDeviceEvent*	e = ev.xcookie.data;
		int				detail = e->detail;
		double			x = e->event_x;
		double			y = e->event_y;
		e = NULL;
		XFreeEventData(display, &ev.xcookie);

		switch (ev.xcookie.evtype) {
			case XI_Motion:
				mouse_move_handler(x, y, game);
				break ;
			case XI_ButtonPress:
				mouse_press_handler(detail, x, y, game);
				break ;
			case XI_ButtonRelease:
				mouse_release_handler(detail, x, y, game);
				break ;
			case XI_KeyPress:
				key_press_handler(detail, game);
				break ;
			case XI_KeyRelease:
				key_release_handler(detail, game);
				break ;
		}
	}
}

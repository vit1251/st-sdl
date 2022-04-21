/* See LICENSE file for copyright and license details. */

/* appearance */
static char font[] = "/usr/local/share/fonts/SourceCodePro/SourceCodePro-Regular.ttf";
static int fontsize = 16;
static int borderpx = 2;
static char shell[] = "/bin/sh";

/* double-click timeout (in milliseconds) between clicks for selection */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

/* TERM value */
static char termname[] = "st-256color";

static unsigned int tabspaces = 8;
#define WORD_BREAK " "

/* Font mode */
enum fontmode {
	FM_QUICK      = 0,
	FM_NICE       = 1,
	FM_ULTRA_NICE = 2,
};

enum fontmode fontmode = FM_ULTRA_NICE;

/* Terminal colors (16 first used in escape sequence) */
SDL_Color colormap[] = {
	/* 8 normal colors */
	{   0,   0,   0, 0 },//black
	{ 128,   0,   0, 0 },//"red3",
	{   0, 128,   0, 0 },//"green3",
	{ 128, 128,   0, 0 },//"yellow3",
	{   0,   0, 128, 0 },//"blue2",
	{ 128,   0, 128, 0 },//"magenta3",
	{   0, 128, 128, 0 },//"cyan3",
	{ 192, 192, 192, 0 },//"gray90",

	/* 8 bright colors */
	{ 128, 128, 128, 0}, //"gray50",
	{ 255,   0,   0, 0 },//red
	{   0, 255,   0, 0 },//green
	{ 255, 255,   0, 0 },//"yellow",
	{   0,   0, 255, 0 },//"#0000ff",
	{ 255,   0, 255, 0 },//"magenta",
	{   0, 255, 255, 0 },//"cyan",
	{ 255, 255, 255, 0 },//"white",

	[255] = { 0, 0, 0, 0 },

	/* more colors can be added after 255 to use with DefaultXX */
	{ 204, 204, 204, 0},
	{  51,  51,  51, 0},
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, unfocused cursor
 */
static unsigned int defaultfg = 7;
static unsigned int defaultbg = 0;
static unsigned int defaultcs = 256;
static unsigned int defaultucs = 257;

/*
 * Special keys (change & recompile st.info accordingly)
 * Keep in mind that kpress() in st.c hardcodes some keys.
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 */

/* key, mask, output */
static Key key[] = {

//	{ SDLK_LEFT,      KMOD_ALT,  "\033[1;3D" },
//	{ SDLK_RIGHT,     KMOD_ALT,  "\033[1;3C" },

	{ SDL_SCANCODE_BACKSPACE, 0, "\177" },
	{ SDL_SCANCODE_INSERT,    0, "\033[2~" },
	{ SDL_SCANCODE_DELETE,    0, "\033[3~" },
	{ SDL_SCANCODE_HOME,      0, "\033[1~" },
	{ SDL_SCANCODE_END,       0, "\033[4~" },
	{ SDL_SCANCODE_PAGEUP,    0, "\033[5~" },
	{ SDL_SCANCODE_PAGEDOWN,  0, "\033[6~" },
	{ SDL_SCANCODE_F1,        0, "\033OP"   },
	{ SDL_SCANCODE_F2,        0, "\033OQ"   },
	{ SDL_SCANCODE_F3,        0, "\033OR"   },
	{ SDL_SCANCODE_F4,        0, "\033OS"   },
	{ SDL_SCANCODE_F5,        0, "\033[15~" },
	{ SDL_SCANCODE_F6,        0, "\033[17~" },
	{ SDL_SCANCODE_F7,        0, "\033[18~" },
	{ SDL_SCANCODE_F8,        0, "\033[19~" },
	{ SDL_SCANCODE_F9,        0, "\033[20~" },
	{ SDL_SCANCODE_F10,       0, "\033[21~" },
	{ SDL_SCANCODE_F11,       0, "\033[23~" },
	{ SDL_SCANCODE_F12,       0, "\033[24~" },
	
};

/* Internal shortcuts. */
#define MODKEY KMOD_ALT

static Shortcut shortcuts[] = {
	/* modifier	key				function	argument */
	{ MODKEY,	SDL_SCANCODE_KP_PLUS,		xzoom,		{.i = +1} },
	{ MODKEY,	SDL_SCANCODE_KP_MINUS,		xzoom,		{.i = -1} },
	{ MODKEY,	SDL_SCANCODE_KP_MULTIPLY,	changefontmode,	{.i = +1} },
	{ MODKEY,	SDL_SCANCODE_KP_DIVIDE,		changefontmode,	{.i = -1} },
};

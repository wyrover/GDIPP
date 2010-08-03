#pragma once

enum RENDERER_TYPE
{
	RENDERER_CLEARTYPE = 0,
	RENDERER_FREETYPE = 10,
	RENDERER_GETGLYPHOUTLINE = 20,
	RENDERER_DIRECTWRITE = 30,
	RENDERER_WIC = 31
};

enum PIXEL_GEOMETRY_TYPE
{
	PIXEL_GEOMETRY_RGB,
	PIXEL_GEOMETRY_BGR
};

enum LOCK_TYPE
{
	LOCK_GAMMA,
	LOCK_GLYPH_CACHE,
	LOCK_HOOK,
	LOCK_LINKED_FONT,
	LOCK_LRU,
	LOCK_REG_FONT,
	LOCK_SETTING_CACHE,
	LOCK_TEXT,
	LOCK_DEBUG,

	// count of lock types
	// NEVER use this type
	_LOCK_TYPE_COUNT_
};
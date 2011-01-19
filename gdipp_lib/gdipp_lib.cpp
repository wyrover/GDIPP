#include "stdafx.h"
#include "gdipp_lib.h"
#include "setting_cache.h"
#include "setting.h"
#include "minidump.h"

BOOL gdipp_get_dir_file_path(HMODULE h_module, const wchar_t *file_name, wchar_t *out_path)
{
	// append the file name after the module's resident directory name
	// if the module handle is NULL, use the current exe as the module

	DWORD dw_ret;
	BOOL b_ret;

	dw_ret = GetModuleFileNameW(h_module, out_path, MAX_PATH);
	if (dw_ret == 0)
		return FALSE;

	b_ret = PathRemoveFileSpecW(out_path);
	if (!b_ret)
		return FALSE;

	return PathAppendW(out_path, file_name);
}

gdipp_setting setting_instance;
gdimm_setting_cache gdimm_setting_cache_instance;

void gdipp_init_setting()
{
	return setting_instance.init_setting();
}

BOOL gdipp_load_setting(const wchar_t *setting_path)
{
	return setting_instance.load_setting(setting_path);
}

BOOL gdipp_save_setting(const wchar_t *setting_path)
{
	return setting_instance.save_setting(setting_path);
}

BOOL gdipp_insert_setting(const wchar_t *node_name, const wchar_t *node_text, const wchar_t *parent_xpath, const wchar_t *ref_node_xpath, wstring &new_node_xpath)
{
	return setting_instance.insert_setting(node_name, node_text, parent_xpath, ref_node_xpath, new_node_xpath);
}

BOOL gdipp_set_setting_attr(const wchar_t *node_xpath, const wchar_t *attr_name, const wchar_t *attr_value)
{
	return setting_instance.set_setting_attr(node_xpath, attr_name, attr_value);
}

BOOL gdipp_remove_setting(const wchar_t *node_xpath)
{
	return setting_instance.remove_setting(node_xpath);
}

const wchar_t *gdipp_get_gdimm_setting(const wchar_t *setting_name, const gdimm_setting_trait *setting_trait)
{
	return setting_instance.get_gdimm_setting(setting_name, setting_trait);
}

const font_setting_cache *gdipp_get_gdimm_setting_cache(const gdimm_setting_trait *setting_trait)
{
	return gdimm_setting_cache_instance.lookup(setting_trait);
}

const wchar_t *gdipp_get_demo_setting(const wchar_t *setting_name)
{
	return setting_instance.get_demo_setting(setting_name);
}

const vector<const wstring> &gdipp_get_demo_fonts()
{
	return setting_instance.get_demo_fonts();
}

const wchar_t *gdipp_get_service_setting(const wchar_t *setting_name)
{
	return setting_instance.get_service_setting(setting_name);
}

bool gdipp_is_process_excluded(const wchar_t *proc_name)
{
	return setting_instance.is_process_excluded(proc_name);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		gdipp_register_minidump_module(hModule);
		break;
	}

	return TRUE;
}
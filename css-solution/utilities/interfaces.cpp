#include "interfaces.h"

void interfaces::initalize()
{
	engine = get_interface<engine_client, interface_type::index>(ENGINE, "VEngineClient014");

	if (engine != nullptr)
		console::log("VEngineClient014 finded\n");
	else
		console::log("VEngineClient014 failed to found\n");

	vgui = get_interface<surface, interface_type::index>(VGUIMAT, "VGUI_Surface030");

	if (vgui != nullptr)
		console::log("VGUI_Surface030 finded\n");
	else
		console::log("VGUI_Surface030 failed to found\n");

	panel = get_interface<vgi_panel, interface_type::index>(VGUI2, "VGUI_Panel009");

	if (panel != nullptr)
		console::log("VGUI_Panel009 finded\n");
	else
		console::log("VGUI_Panel009 failed to found\n");

	client = get_interface<chlclient, interface_type::index>(CLIENT, "VClient017");

	if (client != nullptr)
		console::log("VClient017 finded\n");
	else
		console::log("VClient017 failed to found\n");

	clientmode = **(client_mode***)((*(DWORD**)client)[10] + 0x5);

	if (clientmode != nullptr)
		console::log("IClientMode finded\n");
	else
		console::log("IClientMode failed to found\n");

	entitylist = get_interface<entity_list, interface_type::index>(CLIENT, "VClientEntityList003");

	if (entitylist != nullptr)
		console::log("VClientEntityList003 finded\n");
	else
		console::log("VClientEntityList003 failed to found\n");

	console::log("interfaces initalized\n\n");
}
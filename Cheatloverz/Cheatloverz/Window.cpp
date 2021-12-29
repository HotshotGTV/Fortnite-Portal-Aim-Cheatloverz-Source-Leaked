/*
Cheatloverz 2 - Extreme Alien Technology
By Cheatloverz
*/

#include "GUI.h"
#include "Render.h"
#include "GUISpecifications.h"
#include "Interfaces.h"

void CWindow::Toggle()
{
	m_bIsOpen = !m_bIsOpen;
}

void CWindow::SaveToCurrentConfig()
{
	GUI.SaveWindowState(this, ConfigFilePath);
}

void CWindow::RegisterTab(CTab* Tab)
{
	if (Tabs.size() == 0)
	{
		SelectedTab = Tab;
	}
	Tab->parent = this;
	Tabs.push_back(Tab);
}

RECT CWindow::GetClientArea()
{
	RECT client;
	if (m_HasTabs)
		client.left = m_x + UI_TAB_WIDTH;
	else
		client.left = m_x;
	client.top = m_y + UI_WIN_TOPHEIGHT + UI_WIN_TITLEHEIGHT;

	if (m_HasTabs)
		client.right = m_iWidth - UI_TAB_WIDTH;
	else 
		client.right = m_iWidth;

	client.bottom = m_iHeight - UI_WIN_TOPHEIGHT - UI_WIN_TITLEHEIGHT;
	return client;
}

RECT CWindow::GetTabArea()
{
	RECT client;
	client.left = m_x;
	client.top = m_y + UI_WIN_TOPHEIGHT + UI_WIN_TITLEHEIGHT;
	client.right = UI_TAB_WIDTH;
	client.bottom = m_iHeight - UI_WIN_TOPHEIGHT - UI_WIN_TITLEHEIGHT;
	return client;
}

//====================================
//  Tabs :::^^^)))
// subscribe to youtube.com/dylanx
// https://steamcommunity.com/id/simplerealistic
//====================================

void CTab::RegisterControl(CControl* control)
{
	control->parent = parent;
	Controls.push_back(control);
}

int CTab::GetNextGroupboxY(CControl* control)
{
	return control->m_y + control->m_iHeight + 10;
}
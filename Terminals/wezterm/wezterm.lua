--[[
-- WEZTERM KEYBINDINGS DOCUMENTATION
-- =================================
-- Leader key: Ctrl + a | timeout: 4000
--
-- Keybindings:
--	1. Tab managment
--		- LEADER + c: Create a new tab in current domain
--		- LEADER + x: Close current pane
--		- LEADER + &: Close current tab
--		- LEADER + b: Switch to previous tab
--		- LEADER + n: switch to next tab
--		- LEADER + <number>: Switch to a specific tab | 0-9
--
--	2. Pane splitting
--		- LEADER + /: Split current pane horizontally
--		- LEADER + -: Split current pane vertically
--
--	3. Pane navigation
--		- LEADER + `: Move to last tab
--		- LEADER + LeftArrow: Move to pane on the left
--		- LEADER + DownArrow: Move to pane below
--		- LEADER + UpArrow: Move to pane above
--		- LEADER + RightArrow: Move to pane on the right
--
--	4. Pane Resizing
--		- LEADER + o: change the pane zoom state
--		- LEADER + z: maximize pane
--		- Every resize is by 5 units
--			- LEADER + h: Increase pane size to the left
--			- LEADER + j: Increase pane size downward
--			- LEADER + k: Increase pane size upward
--			- LEADER + l: Increase pane size to the right
--
--	5. Status Line
--		- Always active
--		- The title of the tab is its number.
--		- Status line indicates when the leader key is active | 🟨
--]]

-- Pull in the wezterm API
local wezterm = require 'wezterm';

-- configuration
local config = wezterm.config_builder()

term = "xterm-256color"

max_fps = 144

--color scheme
config.color_scheme = 'Oxocarbon Dark (Gogh)'
 -- colors = {
  --   background = "#0c0e14",
  -- }

config.window_decorations = "RESIZE"
config.window_background_opacity = 0.6
config.window_padding = {
	left = 3, right = 3,
	top = 3, bottom = 3,
}
config.inactive_pane_hsb = {
	saturation = 0.9,
	brightness = 0.7,
}

config.font = wezterm.font("Cascadia Mono")
config.font_size = 20.0

config.freetype_render_target = "Light"
config.freetype_load_target = "HorizontalLcd"

--tab bar
config.hide_tab_bar_if_only_one_tab = false
config.use_fancy_tab_bar = false
config.tab_bar_at_bottom = true
config.tab_and_split_indices_are_zero_based = true


--tmux status
wezterm.on("update-right-status", function(window, _)
	local SOLID_LEFT_ARROW = ""
	local ARROW_FOREGROUND = { Foreground = { Color = "#a9a9a9" } }
	local prefix = ""

	wezterm.on("format-tab-title", function(tab, pane, tabs, panes, config)
		return " " .. tostring(tab.tab_index) .. " "
	end)

	if window:leader_is_active() then
		prefix = " " .. utf8.char(0x1F7E1)
		SOLID_LEFT_ARROW = utf8.char(0xe0b2)
	end

	if window:active_tab():tab_id() ~= 0 then
		ARROW_FOREGROUND = { Foreground = { Color = "#696969" } }
	end --arrow based on if tab is first pane


	window:set_left_status(wezterm.format {
	{ Background = { Color = "#d3d3d3" } },
	{ Text = prefix },
	ARROW_FOREGROUND,
	{ Text = SOLID_LEFT_ARROW }
	})
end)

-- keybinds configuration
config.leader = { key = 'a', mods = 'CTRL', timeout_miliseconds = 4000 }
config.keys = {
	{
		mods = "LEADER",
		key = "c",
		action = wezterm.action.SpawnTab "CurrentPaneDomain"
	},
	{
		mods = "LEADER",
		key = "x",
		action = wezterm.action.CloseCurrentPane { confirm = true }
	},
	{
		mods = "LEADER",
		key = "&",
		action = wezterm.action.CloseCurrentTab { confirm = true }
	},
	{
		mods = "LEADER",
		key = "b",
		action = wezterm.action.ActivateTabRelative(-1)
	},
	{
		mods = "LEADER",
		key = "n",
		action = wezterm.action.ActivateTabRelative(1)
	},
	{
		mods = "LEADER",
		key = "/",
		action = wezterm.action.SplitHorizontal { domain = 'CurrentPaneDomain' },
	},
	{
		mods = "LEADER",
		key = "-",
		action = wezterm.action.SplitVertical { domain = "CurrentPaneDomain" }
	},
	{
		mods = "LEADER",
		key = "`",
		action = wezterm.action.ActivateLastTab
	},
	{
		mods = "LEADER",
		key = "LeftArrow",
		action = wezterm.action.ActivatePaneDirection "Left"
	},
	{
		mods = "LEADER",
		key = "DownArrow",
		action = wezterm.action.ActivatePaneDirection "Down"
	},
	{
		mods = "LEADER",
		key = "UpArrow",
		action = wezterm.action.ActivatePaneDirection "Up"
	},
	{
		mods = "LEADER",
		key = "RightArrow",
		action = wezterm.action.ActivatePaneDirection "Right"
	},
	{
		mods = "LEADER",
		key = "o",
		action = wezterm.action.TogglePaneZoomState
	},
	{
		mods = "LEADER",
		key = "z",
		action = wezterm.action.ToggleFullScreen
	},
	{
		mods = "LEADER",
		key = "h",
		action = wezterm.action.AdjustPaneSize { "Left", 5 }
	},
	{
		mods = "LEADER",
		key = "j",
		action = wezterm.action.AdjustPaneSize { "Down", 5 }
	},
	{
		mods = "LEADER",
		key = "k",
		action = wezterm.action.AdjustPaneSize { "Up", 5 }
	},
	{
		mods = "LEADER",
		key = "l",
		action = wezterm.action.AdjustPaneSize { "Right", 5 }
	},
}
--leader + number activate numbered tab
for i = 0, 9 do
	table.insert(config.keys, {
		mods = "LEADER",
		key = tostring(i),
		action = wezterm.action.ActivateTab(i),
	})
end

-- return the configuration
return config

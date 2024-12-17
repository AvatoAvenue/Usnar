return {
	"nvim-lualine/lualine.nvim",
	dependencies = {
		"nvim-tree/nvim-web-devicons"
	},
	config = function()
		require("lualine").setup({
			icons_enabled = false,
			sections = {
				lualine_a = {'mode'},
				lualine_b = {'branch', 'diff'},
				lualine_c = {'filename'},
				lualine_x = {},
				lualine_y = {'diagnostics'},
				lualine_z = {'filetype'},
			},
			inactive_sections = {
				lualine_a = {},
				lualine_b = {},
				lualine_c = {'branch'},
				lualine_x = {'filename'},
				lualine_y = {},
				lualine_z = {},
			},

		})
	end,
}

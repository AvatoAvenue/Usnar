return {
	{
		"folke/trouble.nvim",
		config = function()
			require("trouble").setup {
                use_lsp_diagnistic_signs = true,
			}

			vim.keymap.set("n", "<leader>tt", "<cmd>Trouble diagnostics<CR>")
            vim.keymap.set("n", "[t", function()
                require("trouble").next({ target = {"item_any"}, jump = true })
            end)
            vim.keymap.set("n", "]t", function()
                require("trouble").prev({target = {"item_any"}, jump = true})
            end)
		end,
	},
}

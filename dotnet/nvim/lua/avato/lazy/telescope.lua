return {
"nvim-telescope/telescope.nvim",
	dependencies = {
		"nvim-lua/plenary.nvim",
	},

	config = function()
		require("telescope").setup({})
		local builtin = require("telescope.builtin")

		vim.keymap.set("n", "<leader>sf", builtin.find_files, {})
		vim.keymap.set("n", "<leader>sg", builtin.git_files, {})

		vim.keymap.set("n", "<leader>ss", builtin.builtin, {})
		vim.keymap.set("n", "<leader>sl", builtin.live_grep, {})
		vim.keymap.set("n", "<leader>s.", builtin.oldfiles, {})
		vim.keymap.set("n", "<leader>s/", builtin.buffers, {})

		vim.keymap.set("n", "<leader>sw", function()
			local word = vim.fn.expand("<cword>")
			builtin.grep_string({ search = word })
		end)
		vim.keymap.set("n", "<leader>sW", function()
			local word = vim.fn.expand("<cWORD>")
			builtin.grep_string({ search = word})
		end)
		vim.keymap.set("n", "<leader>sn", function()
			builtin.grep_string({ search = vim.fn.input("Grep > ") })
		end)
	end}

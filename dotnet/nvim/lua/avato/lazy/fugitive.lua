return {
	"tpope/vim-fugitive",
	config = function()
		vim.keymap.set("n", "<leader>pg", vim.cmd.Git)

		local avato_Fugitive = vim.api.nvim_create_augroup("avato_Fugitive", {})

		local autocmd = vim.api.nvim_create_autocmd
		autocmd("BufWinEnter", {
			group = avato_Fugitive,
			pattern = "*",
			callback = function()
				if vim.bo.ft ~= "fugitive" then
					return
				end

				local bufnr = vim.api.nvim_get_current_buf()
				local opts = { buffer = bufnr, remap = false }
				vim.keymap.set("n", "<leader>pp", function()
					vim.cmd.Git("push")
				end, opts)

				-- rebase always
				vim.keymap.set("n", "<leader>pr", function()
					vim.cmd.Git("pull --rebase")
				end, opts)

				-- NOTE: It allows me to easily set the branch i am pushing and any tracking
				-- needed if i did not set the branch up correctly
				vim.keymap.set("n", "<leader>pt", ":Git push -u origin ", opts)
			end,
		})

		vim.keymap.set("n", "<leader>pu", "<cmd>diffget //2<CR>")
		vim.keymap.set("n", "<leader>ph", "<cmd>diffget //3<CR>")
	end,
}
